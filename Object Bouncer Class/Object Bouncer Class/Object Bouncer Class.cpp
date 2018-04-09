/*Remember the moving bitmaps program that moves and draws a bouncer to the screen ? This is the same thing, but with classes!
Create class FACE.Class face has variables for x position, y position, an x velocity, y velocity, and an Allegro Bitmap.
It has functions for initialize, draw, and move.
The move function adds the x velocity to the x position, and the y velocity to the y position, and then “bounces” the velocities by multiplying them by - 1.
Create 1 - 2 FACE objects, initialize them, draw them, and move them in a simple game loop.*/

#include <allegro5/allegro.h>
#include <allegro5\allegro_image.h>
#include <iostream>

	using namespace std;

	class Face {
	public:
		void Initi(int X, int Y, int XV, int YV);
		void Draw(ALLEGRO_BITMAP *Image);
		void Move();
	private:
		int X_Pos;
		int Y_Pos;
		int X_Velocity;
		int Y_Velocity;

};

	int main()
	{
		ALLEGRO_DISPLAY *Display = NULL;
		ALLEGRO_EVENT_QUEUE *event_queue = NULL;
		ALLEGRO_TIMER *Timer = NULL;
		//ALLEGRO_BITMAP *Bouncer1 = NULL;
		ALLEGRO_BITMAP *Bouncer2 = NULL;

		bool redraw = true;

		bool doexit = false;

		al_init();
		al_init_image_addon();

		ALLEGRO_BITMAP *Bouncer1 = al_load_bitmap("Kirby.png");

		al_install_keyboard();

		Timer = al_create_timer(.01);

		Display = al_create_display(640, 480);

		al_set_target_bitmap(al_get_backbuffer(Display));
		/////////////////////////////////////////////////
		Face F1; 
		//F1.Initi(50, 50, 4, -4);
		Face F2; 
		//F2.Initi(100, 100, 4, -4);
		//////////////Insert Here////////////////////////
		
		/*Bouncer1 = al_create_bitmap(15, 15);
		al_set_target_bitmap(Bouncer1);
		al_clear_to_color(al_map_rgb(500, 0, 0));*/
	
		Bouncer2 = al_create_bitmap(15, 15);
		al_set_target_bitmap(Bouncer2);
		al_clear_to_color(al_map_rgb(0, 500, 0));
		/////////////////////////////////////////////////
		event_queue = al_create_event_queue();

		al_register_event_source(event_queue, al_get_display_event_source(Display));
		al_register_event_source(event_queue, al_get_timer_event_source(Timer));
		al_register_event_source(event_queue, al_get_keyboard_event_source());

		al_clear_to_color(al_map_rgb(0, 0, 0));

		al_flip_display();

		al_start_timer(Timer);

		while (!doexit)
		{

			ALLEGRO_EVENT ev;
			al_wait_for_event(event_queue, &ev);

			if (ev.type == ALLEGRO_EVENT_TIMER) {
				F1.Move();
				F2.Move();
				/*if (Bouncer_X < 0 || Bouncer_X > 640 - 15) {
					Bouncer_dx = -Bouncer_dx;
				}
				if (Bouncer_Y < 0 || Bouncer_Y > 480 - 15) {
					Bouncer_dy = -Bouncer_dy;
				}
				Bouncer_X += Bouncer_dx;
				Bouncer_Y += Bouncer_dy;*/

				redraw = true;
			}
		
			else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
				switch (ev.keyboard.keycode) {
				case ALLEGRO_KEY_ESCAPE:
					doexit = true;
					break;
				}
			}
			if (redraw && al_is_event_queue_empty(event_queue)) {
				redraw = false;

				al_clear_to_color(al_map_rgb(0, 0, 0));
				F1.Initi(50, 50, 4, -4);
				F1.Draw(Bouncer1);
				F2.Initi(100, 100, 4, -4);
				F2.Draw(Bouncer2);
				al_flip_display();
			}
		}

		al_destroy_bitmap(Bouncer1);
		al_destroy_bitmap(Bouncer2);
		al_destroy_timer(Timer);
		al_destroy_display(Display);
		al_destroy_event_queue(event_queue);

		return 0;
	}
	void Face::Initi(int X, int Y, int XV, int YV) {
		X_Pos = X;
		Y_Pos = Y;
		X_Velocity = XV;
		Y_Velocity = YV;
	}
	void Face::Draw(ALLEGRO_BITMAP *Image) {
		al_draw_bitmap(Image, X_Pos, Y_Pos, 0);
	}
	void Face::Move() {
		if (X_Pos < 0 || Y_Pos > 640 - 15) {
		X_Velocity = -X_Velocity;
		}
		if (Y_Pos < 0 || Y_Pos > 480 - 15) {
			Y_Velocity = -Y_Velocity;
		}
		X_Pos += X_Velocity;
		Y_Pos += Y_Velocity;
	}