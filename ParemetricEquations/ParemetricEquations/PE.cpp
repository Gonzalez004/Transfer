#include <stdio.h>
#include <allegro5/allegro.h>
#include <cmath>

const float FPS = 100;
const int SCREEN_W = 640;
const int SCREEN_H = 800;

const int BOUNCER_SIZE = 2;

int main() {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_dx = -4.0, bouncer_dy = 4.0;
	bool redraw = true;
	double t = 1;

	al_init();

	timer = al_create_timer(1.0 / FPS);

	display = al_create_display(SCREEN_W, SCREEN_H);


	bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);

	al_set_target_bitmap(bouncer);

	al_clear_to_color(al_map_rgb(255, 0, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	while (1)
	{

		t++;
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (bouncer_x < 0 || bouncer_x > SCREEN_W - BOUNCER_SIZE) {
				bouncer_dx = -bouncer_dx;
			}

			if (bouncer_y < 0 || bouncer_y > SCREEN_H - BOUNCER_SIZE) {
				bouncer_dy = -bouncer_dy;
			}

			//////////////////////////////////////////////////////////////////////////////////////////////
			//here's the parametric equations that determine the shape!!
			bouncer_x = 250 + 10 * (16 * (sin(t)*(cos(t))*(tan(t))));
			bouncer_y = 250 + (10 * (13 * cos(t) - 5 * tan(2 * t) - 2 * sin(3 * t) - cos(4 * t)))*-1;
			/////////////////////////////////////////////////////////////////////////////////////////////////////
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_set_target_bitmap(bouncer);

			//mess with this last line here to change colors
			al_clear_to_color(al_map_rgb(200, t, 100));
			al_set_target_bitmap(al_get_backbuffer(display));
			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);

			al_flip_display();
		}
	}

	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}
//bouncer_x = 20 + t;
//bouncer_y = 250;
//1.
//bouncer_x = 250 + 30 * (2 * cos(t) - cos(2 * t));
//bouncer_y = 250 + 30 * (2 * sin(t) - sin(2 * t));
//
//2.
//bouncer_x = 250 + 5 * (21 * cos(t) - 25 * cos(3.1*t));
//bouncer_y = 250 + 5 * (21 * sin(t) - 25 * sin(3.1*t));
//
//3.
//bouncer_x = 250 + 45 * (1.6*cos(t) - (.6*cos((1.6*t) / .6)));
//bouncer_y = 250 + 45 * (1.6*sin(t) - (.6*sin((1.6*t) / .6)));
//
//4.
//bouncer_x = 250 + 45 * (1.6*cos(t) - (1.2*cos((1.6*t) / .6)));
//bouncer_y = 250 + 45 * (1.6*sin(t) - (1.2*sin((1.6*t) / .6)));
//
//5.
//bouncer_x = 250 + 10 * (16 * (sin(t)*(sin(t))*(sin(t))));
//bouncer_y = 250 + (10 * (13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t)))*-1;
//
//6.
//bouncer_x = 250 + .25*(cos(t) + t * sin(t));
//bouncer_y = 250 + (.25*(sin(t) - t * cos(t)))*-1;

