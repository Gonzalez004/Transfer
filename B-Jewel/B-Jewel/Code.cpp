/////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <ctime>
#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>
using namespace std;
/////////////////////////////////////////////////////////////////////////
bool Clear(int Map[10][10]);
const int Size = 40;
const int Height = 500;
const int Width = 500;
const int FPS = 1;
int mouseX = Width / 2.0 - Size / 2.0;
int mouseY = Height / 2.0 - Size / 2.0;
int boxX;
int boxY;
int snapX = 0;
int snapY = 0;
void JemFall(int Map[10][10]);
void Replenish(int Map[10][10]);
int highlightX = 0;
int highlightY = 0;
bool highlight = false;
int leftovers = 0;
bool snapped = false;

int highlight2X = 0;
int highlight2Y = 0;
bool highlight2 = false;
int leftovers2 = 0;
bool snapped2 = false;
int temp;
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
	ALLEGRO_BITMAP *Emerald = al_load_bitmap("Emerald.png");
	ALLEGRO_BITMAP *Diamond = al_load_bitmap("Diamond.png");
	ALLEGRO_BITMAP *Ruby = al_load_bitmap("Ruby.png");
	ALLEGRO_BITMAP *Sapphire = al_load_bitmap("Sapphire.png"); 
	ALLEGRO_BITMAP *MouseXY = al_create_bitmap(Size, Size);
/////////////////////////////////////////////////////////////////////////
	bool Redraw = true;
	bool Doexit = false;
	bool clicked = false;
/////////////////////////////////////////////////////////////////////////
	al_set_target_bitmap(Emerald);
	al_set_target_bitmap(Diamond);
	al_set_target_bitmap(Ruby);
	al_set_target_bitmap(Sapphire);
	al_set_target_bitmap(MouseXY);
	al_clear_to_color(al_map_rgb(41, 18, 214));
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
	int Map[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Map[i][j] = rand() % 4 + 1;
			
		}
	}
	while (Clear(Map)) {
		JemFall(Map);
		Replenish(Map);
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << Map[i][j];
		cout << endl;
	}
/////////////////////////////////////////////////////////////////////////
	al_convert_mask_to_alpha(Emerald, al_map_rgb(255, 255, 255));
	al_convert_mask_to_alpha(Diamond, al_map_rgb(0, 0, 0));
	al_convert_mask_to_alpha(Ruby, al_map_rgb(255, 255, 255));
	al_convert_mask_to_alpha(Sapphire, al_map_rgb(255, 255, 255));
/////////////////////////////////////////////////////////////////////////
	
	while (!Doexit) {
/////////////////////////////////////////////////////////////////////////
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
			if (!snapped) {
				leftovers = highlightX % 50;
				highlightX -= leftovers;
				leftovers = highlightY % 50;
				highlightY -= leftovers;
				snapped = true;
			}
			if (!snapped2) {
				leftovers2 = highlight2X % 50;
				highlight2X -= leftovers2;
				leftovers2 = highlight2Y % 50;
				highlight2Y -= leftovers2;
				snapped = true;
			}


			Redraw = true;
		}
/////////////////////////////////////////////////////////////////////////
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
			mouseX = ev.mouse.x;
			mouseY = ev.mouse.y; 
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
		/*	clicked = true;
			boxX = mouseX;
			boxY = mouseY;
			snapX = boxX % 50;
			boxX -= snapX;
			snapY = boxY % 50;
			boxY -= snapY;
			cout << boxX << ", " << boxY << endl;*/
			if(highlight == true && ev.mouse.x > highlightX - 40 && ev.mouse.x < highlightX + 80 && ev.mouse.y > highlightY - 40 && ev.mouse.y < highlightY + 80) {
				//cout << "selected next slot!";
				highlight2 = true;
				highlight2X = ev.mouse.x;
				highlight2Y = ev.mouse.y;
				snapped2 = false;
				//swap the two boxes 
				temp = Map[highlight2X / 50][highlight2Y / 50];
				Map[highlight2X / 50][highlight2Y / 50] = Map[highlightX / 50][highlightY / 50];
				Map[highlightX / 50][highlightY / 50] = temp;
				while (Clear(Map)) {
					JemFall(Map);
					Replenish(Map);
					highlight = false;
					highlight2 = false;
				}
			}
			//otherwise, select a new box
		else
		{
			highlight = true;
			highlight2 = false;
			highlightX = ev.mouse.x;
			highlightY = ev.mouse.y;
			snapped = false;
		}
		}
/////////////////////////////////////////////////////////////////////////
		if (Redraw && al_is_event_queue_empty(Event_Queue)) {
			Redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
				//	al_draw_rectangle(i*50,j*50, i*50+50, j*50+50, al_map_rgb(50,80,90), 3);
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
			//if (clicked) { al_draw_rectangle(boxX, boxY, boxX + 50, boxY + 50, al_map_rgb(255, 255, 0), 3); }
			if (highlight) {
				al_draw_rectangle(highlightX, highlightY, highlightX + 50, highlightY + 50, al_map_rgb(255, 255, 255), 5);
			}
			if (highlight2) {
				al_draw_rectangle(highlight2X, highlight2Y, highlight2X + 50, highlight2Y + 50, al_map_rgb(0, 255, 255), 5);
			}
			//JemFall(Map);
			al_flip_display();
		}//end render
	}//end game loop
/////////////////////////////////////////////////////////////////////////
	al_destroy_bitmap(Emerald);
	al_destroy_bitmap(Diamond);
	al_destroy_bitmap(Ruby);
	al_destroy_bitmap(Sapphire);
	al_destroy_bitmap(MouseXY);
	al_destroy_timer(Timer);
	al_destroy_display(Display);
	al_destroy_event_queue(Event_Queue);
/////////////////////////////////////////////////////////////////////////
	return 0;
}//Main Loop
 /////////////////////////////////////////////////////////////////////////
/*void Clear(int Map[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (Map[i][j] == Map[i][j + 1] && Map[i][j] == Map[i][j + 2]) {
				Map[i][j] = 0; //rand() % 4 + 1;
			}
			if (Map[i + 1][j] == Map[i][j] && Map[i + 2][j] == Map[i][j]) {
				Map[i][j] = 0; //rand() % 4 + 1;
			}
		}
	}
}*/
bool Clear(int Map[10][10]) {
	int count = 1;
	bool foundMatch = false;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (Map[i][j] == Map[i][j + 1] && Map[i][j] == Map[i][j + 2]) {
				foundMatch = true;
				while (Map[i][j] == Map[i][j + count]) {
					Map[i][j + count] = 0;
					count++;
				}
				Map[i][j] = 0;
				count = 1;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if ((Map[i][j] == Map[i + 1][j]) && (Map[i][j] == Map[i + 2][j])) {
				foundMatch = true;
				while (Map[i][j] == Map[i + count][j]) {
					Map[i + count][j] = 0;
					count++;
				}
				Map[i][j] = 0;
				count = 1;
			}
		}
	}
	return foundMatch;
}
/////////////////////////////////////////////////////////////////////////
void JemFall(int Map[10][10]) {
	int counter = 1;
	for (int i = 9; i > 0; i--) {
		for (int j = 0; j < 10; j++) {
			if (Map[i][j] == 0) {
				while (Map[i - counter][j] == 0 && i - counter > 0) {
							counter++;
						}
				Map[i][j] = Map[i - counter][j];
				Map[i - counter][j] = 0;
				counter = 1;
				cout << "moving down" << endl;
			}
		}
	}
}
void Replenish(int Map[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (Map[i][j] == 0) {
				Map[i][j] = rand() % 4 + 1;
			}
		}
	}
}