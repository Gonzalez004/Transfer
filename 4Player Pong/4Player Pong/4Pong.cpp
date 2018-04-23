#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

using namespace std;

int collision(int b1_x, int b1_y, int b1_w, int b1_h, int b2_x, int b2_y, int b2_w, int b2_h);
int RedScore;
int BlueScore;

int main(int argc, char **argv)
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *square = NULL;
	ALLEGRO_BITMAP *square1 = NULL;
	ALLEGRO_BITMAP *square2 = NULL;
	ALLEGRO_BITMAP *square3 = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;

	float square_x = 20;
	float square_y = 395;

	float square1_x = 1865;
	float square1_y = 395;

	float square2_x = 100;
	float square2_y = 395;

	float square3_x = 1785 - 110;
	float square3_y = 395;

	float bouncer_x = 800;
	float bouncer_y = 500;

	float bouncer_dx = -4.0, bouncer_dy = 4.0;
	
	bool key[4] = { false, false, false, false };
	bool key1[4] = { false, false, false, false };
	bool key2[4] = { false, false, false, false };
	bool key3[4] = { false, false, false, false };

	bool redraw = true;
	bool doexit = false;

	al_init();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	timer = al_create_timer(.01);
	display = al_create_display(1900, 900); //640 480
	event_queue = al_create_event_queue();

	square = al_create_bitmap(15, 110);
	al_set_target_bitmap(square);
	al_clear_to_color(al_map_rgb(500, 0, 0));

	square1 = al_create_bitmap(15, 110);
	al_set_target_bitmap(square1);
	al_clear_to_color(al_map_rgb(0, 0, 500));

	square2 = al_create_bitmap(110, 15);
	al_set_target_bitmap(square2);
	al_clear_to_color(al_map_rgb(0, 0, 500));

	square3 = al_create_bitmap(110, 15);
	al_set_target_bitmap(square3);
	al_clear_to_color(al_map_rgb(500, 0, 0));
	
	bouncer = al_create_bitmap(15, 15);
	al_set_target_bitmap(bouncer);
	al_clear_to_color(al_map_rgb(50, 510, 50));

	ALLEGRO_FONT *font = al_load_ttf_font("Gameplay.ttf", 25, 0);

	al_set_target_bitmap(al_get_backbuffer(display));

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	while (!doexit)
	{

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			cout << bouncer_dx << ", "<< bouncer_dy << endl;

			if (bouncer_x < 0 || bouncer_x > 1900 - 15) {
				bouncer_dx = -bouncer_dx;
			}
			if (bouncer_y < 0 || bouncer_y > 900 - 15) {
				bouncer_dy = -bouncer_dy;
			}

			if (bouncer_x < 0) {
				RedScore++;
				if (bouncer_dx > 1 && bouncer_dx < 10) {
					bouncer_dx = bouncer_dx - 2;
				}
				else {
					bouncer_dx = bouncer_dx + 2;
				}
				if (bouncer_dy > 1 && bouncer_dy < 10) {
					bouncer_dy = bouncer_dy - 2;
				}
				else {
					bouncer_dy = bouncer_dy + 2;
				}
			}
			if (bouncer_x > 1900 - 15) {
				BlueScore++;
			}

			bouncer_x += bouncer_dx;
			bouncer_y += bouncer_dy;

			redraw = true;
		}

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			///////////////////////////////////////////////////////////////////////
			if (key[0] && square_y >= 0) {
				square_y -= 4.0;
			}
			if (key[1] && square_y <= 900 - 110) {
				square_y += 4.0;
			}
			///////////////////////////////////////////////////////////////////////
			if (key1[0] && square1_y >= 0) {
				square1_y -= 4.0;
			}
			if (key1[1] && square1_y <= 900 - 110) {
				square1_y += 4.0;
			}
			///////////////////////////////////////////////////////////////////////
			if (key2[0] && square2_y >= 0 + 110) {
				square2_y -= 4.0;
			}
			if (key2[1] && square2_y <= 900 - 110) {
				square2_y += 4.0;
			}
			///////////////////////////////////////////////////////////////////////
			if (key3[0] && square3_y >= 0 + 110) {
				square3_y -= 4.0;
			}
			if (key3[1] && square3_y <= 900 - 110) {
				square3_y += 4.0;
			}
			///////////////////////////////////////////////////////////////////////
			redraw = true;
		}


		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
				///////////////////////////////////////////////////////////////////////
			case ALLEGRO_KEY_W:
				key[0] = true;
				break;
			case ALLEGRO_KEY_S:
				key[1] = true;
				break;
				///////////////////////////////////////////////////////////////////////
			case ALLEGRO_KEY_UP:
				key1[0] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				key1[1] = true;
				break;
				///////////////////////////////////////////////////////////////////////
			case ALLEGRO_KEY_U:
				key2[0] = true;
				break;
			case ALLEGRO_KEY_J:
				key2[1] = true;
				break;
				///////////////////////////////////////////////////////////////////////
			case ALLEGRO_KEY_PAD_8:
				key3[0] = true;
				break;
			case ALLEGRO_KEY_PAD_5:
				key3[1] = true;
				break;
				///////////////////////////////////////////////////////////////////////
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
				///////////////////////////////////////////////////////////////////////
			case ALLEGRO_KEY_W:
				key[0] = false;
				break;
			case ALLEGRO_KEY_S:
				key[1] = false;
				break;
				///////////////////////////////////////////////////////////////////////
			case ALLEGRO_KEY_UP:
				key1[0] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				key1[1] = false;
				break;
				///////////////////////////////////////////////////////////////////////
			case ALLEGRO_KEY_U:
				key2[0] = false;
				break;
			case ALLEGRO_KEY_J:
				key2[1] = false;
				break;
				///////////////////////////////////////////////////////////////////////
			case ALLEGRO_KEY_PAD_8:
				key3[0] = false;
				break;
			case ALLEGRO_KEY_PAD_5:
				key3[1] = false;
				break;
				///////////////////////////////////////////////////////////////////////
			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}

		if (collision(bouncer_x, bouncer_y, 15, 15, square_x, square_y, 15, 110) == 1) {
			bouncer_dx = -bouncer_dx;
			if (bouncer_dx > 1 && bouncer_dx < 10) {
				bouncer_dx = bouncer_dx + 2;
			}
			else {
				bouncer_dx = bouncer_dx - 2;
			}
			if (bouncer_dy > 1 && bouncer_dy < 10) {
				bouncer_dy = bouncer_dy + 2;
			}
			else {
				bouncer_dy = bouncer_dy - 2;
			}
		}
		if (collision(bouncer_x, bouncer_y, 15, 15, square1_x, square1_y, 15, 110) == 1) {
			bouncer_dx = -bouncer_dx;
		}
		if (collision(bouncer_x, bouncer_y, 15, 15, square2_x, square2_y, 110, 15) == 1) {
			bouncer_dy = -bouncer_dy;
			if (bouncer_dx > 1 && bouncer_dx < 10) {
				bouncer_dx = bouncer_dx + 2;
			}
			else {
				bouncer_dx = bouncer_dx - 2;
			}
			if (bouncer_dy > 1 && bouncer_dy < 10) {
				bouncer_dy = bouncer_dy + 2;
			}
			else {
				bouncer_dy = bouncer_dy - 2;
			}
		}
		if (collision(bouncer_x, bouncer_y, 15, 15, square3_x, square3_y, 110, 15) == 1) {
			bouncer_dy = -bouncer_dy;
		}
	
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_textf(font, al_map_rgb(400, 100, 150), 800, 300, NULL, "Blue Score: %d", RedScore);
			al_draw_textf(font, al_map_rgb(400, 100, 150), 900, 600, NULL, "Red Score: %d", BlueScore);
			al_draw_bitmap(square, square_x, square_y, 0);
			al_draw_bitmap(square1, square1_x, square1_y, 0);
			al_draw_bitmap(square2, square2_x, square2_y, 0);
			al_draw_bitmap(square3, square3_x, square3_y, 0);
			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);

			al_flip_display();
		}
	}

	al_destroy_bitmap(square);
	al_destroy_bitmap(square1);
	al_destroy_bitmap(square2);
	al_destroy_bitmap(square3);
	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}
int collision(int b1_x, int b1_y, int b1_w, int b1_h, int b2_x, int b2_y, int b2_w, int b2_h)
{
	if ((b1_x > b2_x + b2_w - 1) || //box 2 is to the LEFT of box 1
		(b1_y > b2_y + b2_h - 1) || //box 2 is ABOVE box 1
		(b2_x  > b1_x + b1_w - 1) ||//box 2 is to the RIGHT of box1
		(b2_y > b1_y + b1_h - 1)) //box 2 is BELOW box 1
	{
		return 0;
	}
	else
	{
		return 1;
	}

}
