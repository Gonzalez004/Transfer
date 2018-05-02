#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <cmath>

int XPos = 425;
int YPos = 125;
int XPos2 = 425;
int YPos2 = 125;
int XPos3 = 425;
int YPos3 = 125;
int SpeedX = -4.0;
int SpeedY = 10.0;
int SpeedX2 = -4.0;
int SpeedY2 = 4.0;
int SpeedX3 = -4.0;
int SpeedY3 = 4.0;
int FPS = 60;
int Screen_H = 480;
int Screen_W = 640;
int Bouncer_Size = 32;
int Delay;
int Angle;
double Radius = 20;

int main() {

	al_init();
	al_init_primitives_addon();
	al_init_image_addon();
	al_init_acodec_addon();
	al_install_audio();
	ALLEGRO_DISPLAY *GameWindow = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *Timer = NULL;
	ALLEGRO_BITMAP *BackGround = NULL;
	ALLEGRO_BITMAP *Bouncer = NULL;
	ALLEGRO_BITMAP *Jim = NULL;
	ALLEGRO_BITMAP *Left = NULL;
	ALLEGRO_SAMPLE *Song = NULL;
	ALLEGRO_SAMPLE_INSTANCE *SongInstance = NULL;

	al_reserve_samples(2);
	Song = al_load_sample("Love.wav");
	SongInstance = al_create_sample_instance(Song);
	al_set_sample_instance_playmode(SongInstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(SongInstance, al_get_default_mixer());

	float Bouncer_X = XPos;
	float Bouncer_Y = YPos;
	float Bouncer_X2 = XPos2;
	float Bouncer_Y2 = YPos2;
	float Bouncer_X3 = XPos3;
	float Bouncer_Y3 = YPos3;
	float Bouncer_dx = SpeedX;
	float Bouncer_dy = SpeedY;
	float Bouncer_dx2 = SpeedX2;
	float Bouncer_dy2 = SpeedY2;
	float Bouncer_dx3 = SpeedX3;
	float Bouncer_dy3 = SpeedY3;

	bool Redraw = true;

	Timer = al_create_timer(0.02);

	GameWindow = al_create_display(Screen_W, Screen_H);

	Bouncer = al_create_bitmap(Bouncer_Size, Bouncer_Size);
	al_clear_to_color(al_map_rgb(255, 0, 0));

	//Bouncer = al_load_bitmap("kirby.png");
	Left = al_load_bitmap("Toy.png");
	Jim = al_load_bitmap("Smile.jpg");
	BackGround = al_load_bitmap("NoMore.jpg");

	al_set_target_bitmap(BackGround);

	al_set_target_bitmap(al_get_backbuffer(GameWindow));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(GameWindow));
	al_register_event_source(event_queue, al_get_timer_event_source(Timer));

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(Timer);

	al_play_sample(Song, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);

	while (true) {
		if (!Song) {
			printf("Audio clip sample not loaded!\n");
			return 1;
		}
		if (Delay % 2 == 0) {
			Angle++;
		}
		Delay++;

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
	/*		Bouncer_x = 20 + t;
			Bouncer_y = 250;
			Bouncer_x = 250 + 30 * (2 * cos(t) - cos(2 * t));
			Bouncer_y = 250 + 30 * (2 * sin(t) - sin(2 * t));
*/

			//////////////////////////////////////////////////////////////////////
			if (Bouncer_Y < 110 || Bouncer_Y > 150 && Delay % 4 == 0) {
				Bouncer_dy = -Bouncer_dy;
			}
			Bouncer_Y += Bouncer_dy;
			//////////////////////////////////////////////////////////////////////
			/*Bouncer_dx2 = 100 + sin(Angle*2)*Radius;
			Bouncer_dy2 = 130 + sin(Angle)*Radius;*/
			Bouncer_dx2 = 250 + 30 * (2 * cos(Angle) - cos(2 * Angle));
			Bouncer_dy2 = 250 + 30 * (2 * sin(Angle) - sin(2 * Angle));


			Bouncer_X2 = Bouncer_dx2;
			Bouncer_Y2 = Bouncer_dy2;
			//////////////////////////////////////////////////////////////////////
			Bouncer_dx3 = 250 + cos(Angle)*Radius;
			Bouncer_dy3 = 130 + sin(Angle)*Radius;

			Bouncer_X3 = Bouncer_dx3;
			Bouncer_Y3 = Bouncer_dy3;
			//////////////////////////////////////////////////////////////////////
			Redraw = true;
		}

		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		if (Redraw && al_is_event_queue_empty(event_queue)) {
			Redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(BackGround, 80, 50, 0);
			al_draw_bitmap(Jim, Bouncer_X3, Bouncer_Y3, 0);
			al_draw_bitmap(Left, Bouncer_X2, Bouncer_Y2, 0);
			al_draw_bitmap(Bouncer, Bouncer_X, Bouncer_Y, 0);
			al_flip_display();
		}
	}


	al_destroy_bitmap(Bouncer);
	al_destroy_bitmap(Jim);
	al_destroy_bitmap(Left);
	al_destroy_bitmap(BackGround);
	al_destroy_timer(Timer);
	al_destroy_display(GameWindow);
	al_destroy_sample_instance(SongInstance);
	al_destroy_sample(Song);
	al_destroy_event_queue(event_queue);

	return 0;


	//	al_install_audio();
	//#include <allegro5/allegro.h>
















































































































;
}