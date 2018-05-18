/////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <ctime>
#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////
const int Size = 40;
const int Height = 600;
const int Width = 600;
const int FPS = 60;
int MouseX = Width / 2.0 - Size / 2.0;
int MouseY = Height / 2.0 - Size / 2.0;
int BoxX;
int BoxY;
int SnapX = 0;
int SnapY = 0;
bool Player1 = false;
bool Player2 = false;
bool FoundMatch;
bool Check(int Map[3][3]);
/////////////////////////////////////////////////////////////////////////
int main() {
	/////////////////////////////////////////////////////////////////////////
	al_init();
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_keyboard();
	al_install_mouse();
	srand(time(NULL));
	/////////////////////////////////////////////////////////////////////////
	ALLEGRO_DISPLAY *Display = al_create_display(Height, Width);
	ALLEGRO_EVENT_QUEUE *Event_Queue = al_create_event_queue();
	ALLEGRO_TIMER *Timer = al_create_timer(1.0 / FPS);
	ALLEGRO_BITMAP *Emerald = al_load_bitmap("X.png");  //al_create_bitmap(Size, Size);
	ALLEGRO_BITMAP *Diamond = al_load_bitmap("O.png");// al_create_bitmap(Size, Size);
	ALLEGRO_BITMAP *MouseXY = al_create_bitmap(Size, Size);
	/////////////////////////////////////////////////////////////////////////
	bool Redraw = true;
	bool Doexit = false;
	bool clicked = false;
	/////////////////////////////////////////////////////////////////////////
	al_set_target_bitmap(Emerald);
	al_set_target_bitmap(Diamond);
	al_set_target_bitmap(MouseXY);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_set_target_bitmap(al_get_backbuffer(Display));
	/////////////////////////////////////////////////////////////////////////
	al_register_event_source(Event_Queue, al_get_display_event_source(Display));
	al_register_event_source(Event_Queue, al_get_timer_event_source(Timer));
	al_register_event_source(Event_Queue, al_get_keyboard_event_source());
	al_register_event_source(Event_Queue, al_get_mouse_event_source());
	/////////////////////////////////////////////////////////////////////////
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_start_timer(Timer);
	/////////////////////////////////////////////////////////////////////////
	int Map[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Map[i][j] = 0;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << Map[i][j];
		cout << endl;
	}
	/////////////////////////////////////////////////////////////////////////
	int Decide = rand() % 2 + 1;
	if (Decide == 1) {
		Player1 = true;
		cout << "Player One Turn" << endl;
	}
	else {
		Player2 = true;
		cout << "Player Two Turn" << endl;
	}

	while (!Doexit) {
		/////////////////////////////////////////////////////////////////////////
		ALLEGRO_EVENT ev;
		al_wait_for_event(Event_Queue, &ev);
		/////////////////////////////////////////////////////////////////////////	
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			//cout << FoundMatch << endl;
			//cout << "Player1 = " << Player1 << endl;
		//	cout << "Player2 = " << Player2 << endl;
			//cout << "Clicked = " << clicked << endl;
			Redraw = true;
		}
		/////////////////////////////////////////////////////////////////////////
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
			MouseX = ev.mouse.x;
			MouseY = ev.mouse.y;
		}
		/////////////////////////////////////////////////////////////////////////
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_ESCAPE:
				Doexit = true;
				break;
			}
		}
		/////////////////////////////////////////////////////////////////////////
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			clicked = true;
			BoxX = MouseX;
			BoxY = MouseY;
			SnapX = BoxX % 200;
			BoxX -= SnapX;
			SnapY = BoxY % 200;
			BoxY -= SnapY;
			/*if (Player1 == true) {
				Player2 = true;
				Player1 = false;
			}
			else {
				Player2 = false;
				Player1 = true;
			}*/
				if (Map[BoxX / 200][BoxY / 200] == 0 && Player1 == true) {
					Map[BoxX / 200][BoxY / 200] = 1;
					Check(Map);
					if (Player1 == true) {
						Player2 = true;
						Player1 = false;
					}
					else {
						Player2 = false;
						Player1 = true;
					}
				}
				if (Map[BoxX / 200][BoxY / 200] == 0 && Player2 == true) {
					Map[BoxX / 200][BoxY / 200] = 2;
					//Check(Map);
					if (Player1 == true) {
						Player2 = true;
						Player1 = false;
					}
					else {
						Player2 = false;
						Player1 = true;
					}
				}
				else {
				cout << "Can't Be Place Here" << endl;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			clicked = false;
		}
		/////////////////////////////////////////////////////////////////////////
		if (Redraw && al_is_event_queue_empty(Event_Queue)) {
			Redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					al_draw_rectangle(i*200,j*200, i*200+200, j*200+200, al_map_rgb(50,80,90), 3);
					al_draw_rectangle(i * 200, j * 200, i * 200, j * 200, al_map_rgb(50, 80, 90), 5);
					if (Map[j][i] == 1) {
						al_draw_bitmap(Emerald, j * 200 + 50, i * 200 + 50, 0);
					}
					if (Map[j][i] == 2) {
						al_draw_bitmap(Diamond, j * 200 + 50, i * 200 + 50, 0);
					}
				}
			}
			if (clicked) { al_draw_rectangle(BoxX, BoxY, BoxX + 200, BoxY + 200, al_map_rgb(255, 255, 0), 3); }
			al_flip_display();
		}//end render
	}//end game loop
	 /////////////////////////////////////////////////////////////////////////
	al_destroy_bitmap(Emerald);
	al_destroy_bitmap(Diamond);
	al_destroy_bitmap(MouseXY);
	al_destroy_timer(Timer);
	al_destroy_display(Display);
	al_destroy_event_queue(Event_Queue);
	/////////////////////////////////////////////////////////////////////////
	return 0;
}//Main Loop
 /////////////////////////////////////////////////////////////////////////
bool Check(int Map[3][3]) {
	int count = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (Map[i][j] == Map[i][j + 1] && Map[i][j] == Map[i][j + 2]) {
				FoundMatch = true;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (Map[i + 1][j] == Map[i][j] && Map[i + 2][j] == Map[i][j]) {
				FoundMatch = true;
			}
		}
	}
	return FoundMatch;
}