#include<iostream>
#include <allegro5\allegro.h>
#include<string>
#include <ctime>
#include <stdio.h>
#include<allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <Windows.h>

using namespace std;

string Body();
string Color();
int Num1 = rand() % 15;
int Num2 = rand() % 14;
int room = 0;

ALLEGRO_FONT *font = al_load_ttf_font("Gameplay.ttf", 40, 0);

int main() {
	
	srand(time(NULL));

	al_init();
	al_install_keyboard();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_DISPLAY *GameWindow = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	
	bool key[4] = { false, false, false, false };
	bool doexit = false;
	bool redraw = true;

	timer = al_create_timer(.02);

	GameWindow = al_create_display(500, 500);
	al_set_window_position(GameWindow, 0, 0);
	al_set_window_title(GameWindow, "Ferny's Game"); 

	event_queue = al_create_event_queue();
	al_set_target_bitmap(al_get_backbuffer(GameWindow));
	al_register_event_source(event_queue, al_get_display_event_source(GameWindow));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	while (!doexit){
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (key[0]) {
				cout << "The Teacher says, " << Body() << " " << Color() << endl;
				room = Num1;
				key[0] = false;
			}
			
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_RIGHT:
				key[0] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_RIGHT:
				key[0] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			//////////////////////////////////////////////////////////
			if (key[0]) {
				switch (room) {
				case 0:
					al_draw_text(font, al_map_rgb(255, 0, 0), 40, 250, 0, "Head");
					al_flip_display();
					break;
				case 1:
					al_draw_text(font, al_map_rgb(255, 0, 0), 40, 250, 0, "Nose");
					al_flip_display();
					break;

				case 2:
					al_draw_text(font, al_map_rgb(255, 0, 0), 40, 250, 0, "Cheeks");
					al_flip_display();
					break;

				case 3:
					al_draw_text(font, al_map_rgb(255, 0, 0), 40, 250, 0, "Neck");
					al_flip_display();
					break;

				case 4:
					al_draw_text(font, al_map_rgb(255, 0, 0), 40, 250, 0, "Shoulder");
					al_flip_display();
					break;

				case 5:
					al_draw_text(font, al_map_rgb(255, 0, 0), 40, 250, 0, "Elbow");
					al_flip_display();
					break;

				case 6:
					al_draw_text(font, al_map_rgb(255, 0, 0), 40, 250, 0, "Left Hand");
					al_flip_display();
					break;

				case 7:
					al_draw_text(font, al_map_rgb(255, 0, 0), 40, 250, 0, "Toe");
					al_flip_display();
					break;

				case 8:
					al_draw_text(font, al_map_rgb(255, 0, 0), 40, 250, 0, "Feet");
					al_flip_display();
					break;
				case 9:
					al_draw_text(font, al_map_rgb(255, 0, 0), 40, 250, 0, "Knees");
					al_flip_display();
					break;

				case 10:
					al_draw_text(font, al_map_rgb(255, 0, 0), 40, 250, 0, "Hip");
					al_flip_display();
					break;
				case 11:
					al_draw_text(font, al_map_rgb(255, 0, 0), 40, 250, 0, "Wrist");
					al_flip_display();
					break;
				case 12:
					al_draw_text(font, al_map_rgb(255, 0, 0), 40, 250, 0, "Thighs");
					al_flip_display();
					break;
				case 13:
					al_draw_text(font, al_map_rgb(255, 0, 0), 40, 250, 0, "Butt");
					al_flip_display();
					break;
				case 14:
					al_draw_text(font, al_map_rgb(255, 0, 0), 40, 250, 0, "Stomach");
					al_flip_display();
					break;
				case 15:
					al_draw_text(font, al_map_rgb(255, 0, 0), 40, 250, 0, "Right Hand");
					al_flip_display();
					break;
					}
				}
			//////////////////////////////////////////////////////////
			al_flip_display();
		}
	}
	al_destroy_display(GameWindow);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
}

string Body() {
	string BodyPart[16] = { "Head","Nose","Cheeks","Neck","Shoulder","Elbow","Left Hand","Toe","Feet","Knees","Hip","Wrist","Thighs","Butt","Stomach", "Right Hand"};
	Num1 = rand() % 15;
	return BodyPart[Num1];
}
string Color() {
	string ColorName[12] = { "Red","Blue","Green","Yellow","Black","Brown","White","Orange","Purple","Pink","Gray","Cream"};
	Num2 = rand() % 14;
	return ColorName[Num2];
}