#include <iostream>
#include <ctime>
#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>
void Clear(int Map[10][10]);

using namespace std;
const int Size = 40;
const int Height = 500;
const int Width = 500;
const int FPS = 60;
int mouseX = Width / 2.0 - Size / 2.0;
int mouseY = Height / 2.0 - Size / 2.0;


int main() {
	al_init();
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_keyboard();
	al_install_mouse();
	srand(time(NULL));

	ALLEGRO_DISPLAY *Display = al_create_display(Height, Width);
	ALLEGRO_EVENT_QUEUE *Event_Queue = al_create_event_queue();
	ALLEGRO_TIMER *Timer = al_create_timer(1.0 / FPS);
	ALLEGRO_BITMAP *Emerald = al_load_bitmap("Emerald.png"); //al_create_bitmap(Size, Size);
	ALLEGRO_BITMAP *Diamond = al_load_bitmap("Diamond.png"); //al_create_bitmap(Size, Size);
	ALLEGRO_BITMAP *Ruby = al_load_bitmap("Ruby.png"); //al_create_bitmap(Size, Size);
	ALLEGRO_BITMAP *Sapphire = al_load_bitmap("Sapphire.png"); //al_create_bitmap(Size, Size);
	ALLEGRO_BITMAP *MouseXY = al_create_bitmap(Size, Size);

	bool Redraw = true;
	bool Doexit = false;
	bool clicked = false;
	int boxX;
	int boxY;
	int snapX = 0;
	int snapY = 0;

	al_set_target_bitmap(Emerald);
	//al_clear_to_color(al_map_rgb(21, 214, 72));
	al_set_target_bitmap(Diamond);
	//al_clear_to_color(al_map_rgb(214, 214, 20));
	al_set_target_bitmap(Ruby);
	//al_clear_to_color(al_map_rgb(214, 19, 19));
	al_set_target_bitmap(Sapphire);
	//al_clear_to_color(al_map_rgb(41, 18, 214));
	al_set_target_bitmap(MouseXY);
	al_clear_to_color(al_map_rgb(41, 18, 214));
	al_set_target_bitmap(al_get_backbuffer(Display));

	al_register_event_source(Event_Queue, al_get_display_event_source(Display));
	al_register_event_source(Event_Queue, al_get_timer_event_source(Timer));
	al_register_event_source(Event_Queue, al_get_keyboard_event_source());
	al_register_event_source(Event_Queue, al_get_mouse_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(Timer);

	int Map[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Map[i][j] = rand() % 4 + 1;
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << Map[i][j];
		cout << endl;
	}

	al_convert_mask_to_alpha(Emerald, al_map_rgb(255, 255, 255));
	al_convert_mask_to_alpha(Diamond, al_map_rgb(255, 255, 255));
	al_convert_mask_to_alpha(Ruby, al_map_rgb(255, 255, 255));
	al_convert_mask_to_alpha(Sapphire, al_map_rgb(255, 255, 255));

	while (!Doexit) {
		//Checks Game Board for any Allegro Variable that are three or more.
		//in any given row or colloum. Then regenerates another Variable.
		Clear(Map);
		/////////////////////////////////////////////////////////////////////////
		/*int Map[10][10];
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				Map[i][j] = rand() % 4 + 1;
			}
		}
		for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << Map[i][j];
		cout << endl;
		}*/
		/////////////////////////////////////////////////////////////////////////
		ALLEGRO_EVENT ev;
		al_wait_for_event(Event_Queue, &ev);
		/////////////////////////////////////////////////////////////////////////	
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			Redraw = true;
		}
		/////////////////////////////////////////////////////////////////////////
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
			mouseX = ev.mouse.x; //- 20;
			mouseY = ev.mouse.y; //-20;
		}
		/////////////////////////////////////////////////////////////////////////
			//else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			//	for (int i = 0; i < 10; i++) {
			//		for (int j = 0; j < 10; j++) {
			//			if (Map[mouseX / 50][mouseY / 50] == 1 ||
			//				Map[mouseX / 50][mouseY / 50] == 2 || 
			//				Map[mouseX / 50][mouseY / 50] == 3 ||
			//				Map[mouseX / 50][mouseY / 50] == 4) {
			//					al_draw_rectangle(i, j, i + 50, j + 50, al_map_rgb(50, 80, 90), 3);
			//				//al_draw_rectangle(i,j, mouseX+50, mouseY+50, al_map_rgb(50,80,90), 3);
			//				cout << "Clicked" << endl;
			//				//al_draw_rectangle(i * 50, j * 50, i * 50 + 50, j * 50 + 50, al_map_rgb(50, 80, 90), 3);
			//			}
			//		}
			//	}
			//}
		/////////////////////////////////////////////////////////////////////////
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_ESCAPE:
				Doexit = true;
				break;
			}
		}

		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			/*for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
			if (Map[mouseX / 50][mouseY / 50] == 1 || Map[mouseX / 50][mouseY / 50] == 2 ||
			Map[mouseX / 50][mouseY / 50] == 3 || Map[mouseX / 50][mouseY / 50] == 4) {
			*/
			//al_draw_rectangle(mouseX, mouseY, mouseX + 50, mouseY + 50, al_map_rgb(255, 255, 0), 3);
			clicked = true;
			boxX = mouseX;
			boxY = mouseY;


			snapX = boxX % 50;
			boxX -= snapX;
			snapY = boxY % 50;
			boxY -= snapY;


			cout << "Clicked" << endl;
			//al_draw_rectangle(i,j, mouseX+50, mouseY+50, al_map_rgb(50,80,90), 3);
			//al_draw_rectangle(i * 50, j * 50, i * 50 + 50, j * 50 + 50, al_map_rgb(50, 80, 90), 3);
		}
/////////////////////////////////////////////////////////////////////////
		if (Redraw && al_is_event_queue_empty(Event_Queue)) {
			Redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					//al_draw_rectangle(i*50,j*50, i*50+50, j*50+50, al_map_rgb(50,80,90), 3);
					al_draw_rectangle(i * 50, j * 50, i * 50, j * 50, al_map_rgb(50, 80, 90), 5);
					if (Map[j][i] == 1) {
						al_draw_bitmap(Emerald, j * 50 + 5, i * 50 + 5, 0);
					}
					if (Map[j][i] == 2) {
						al_draw_bitmap(Diamond, j * 50 + 5, i * 50 + 5, 0);
					}
					if (Map[j][i] == 3) {
						al_draw_bitmap(Ruby, j * 50 + 5, i * 50 + 5, 0);
					}
					if (Map[j][i] == 4) {
						al_draw_bitmap(Sapphire, j * 50 + 5, i * 50 + 5, 0);
					}
				}
			}
			if (clicked)
				al_draw_rectangle(boxX, boxY, boxX + 50, boxY + 50, al_map_rgb(255, 255, 0), 3);
			al_flip_display();
		}//end render
	}//end game loop
/////////////////////////////////////////////////////////////////////////
	al_destroy_bitmap(Emerald);
	al_destroy_bitmap(Diamond);
	al_destroy_bitmap(Ruby);
	al_destroy_bitmap(Sapphire);
	al_destroy_timer(Timer);
	al_destroy_display(Display);
	al_destroy_event_queue(Event_Queue);
	al_destroy_bitmap(MouseXY);
/////////////////////////////////////////////////////////////////////////
	return 0;
}//Main Loop
 /////////////////////////////////////////////////////////////////////////
void Clear(int Map[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (Map[i][j] == Map[i][j + 1] && Map[i][j] == Map[i][j + 2]) {
				Map[i][j] = rand() % 4 + 1;
			}
			if (Map[i + 1][j] == Map[i][j] && Map[i + 2][j] == Map[i][j]) {
				Map[i][j] = rand() % 4 + 1;
			}
		}
	}
}
/////////////////////////////////////////////////////////////////////////