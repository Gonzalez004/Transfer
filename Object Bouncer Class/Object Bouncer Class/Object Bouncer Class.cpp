/*Remember the moving bitmaps program that moves and draws a bouncer to the screen ? This is the same thing, but with classes!
Create class FACE.Class face has variables for x position, y position, an x velocity, y velocity, and an Allegro Bitmap.
It has functions for initialize, draw, and move.
The move function adds the x velocity to the x position, and the y velocity to the y position, and then “bounces” the velocities by multiplying them by - 1.
Create 1 - 2 FACE objects, initialize them, draw them, and move them in a simple game loop.*/

#include <allegro5\allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include <iostream>

using namespace std;
const float FPS = 60;

class Rooms {
public:
	void InitiPic(int Xpos, int Ypos, int XVelocity, int YVelocity);
	void Move();
	void Draw(ALLEGRO_BITMAP *Image);
private:
	int X;
	int Y;
	int XV;
	int YV;
};

int main() {
	al_init();
	al_init_primitives_addon();
	al_init_image_addon();
	srand(time(NULL));

	ALLEGRO_DISPLAY *GameWindow = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *Kirb = al_load_bitmap("Kirby.png"); //loads bitmap from folders
	GameWindow = al_create_display(1000, 1000); 
	al_set_window_position(GameWindow, 0, 0);
	al_set_window_title(GameWindow, "Ferny's Game");
	bool redraw = true;

	timer = al_create_timer(1.0 / FPS);

	al_set_target_bitmap(al_get_backbuffer(GameWindow));

	event_queue = al_create_event_queue();


	al_register_event_source(event_queue, al_get_display_event_source(GameWindow));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);
	while (1) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		Rooms Room1; 
		Room1.InitiPic(50, 100, 4, -4);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			Room1.Move();
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			Room1.Draw(Kirb);
			al_flip_display();
		}
	}
	al_destroy_bitmap(Kirb);
	al_destroy_timer(timer);
	al_destroy_display(GameWindow);
	al_destroy_event_queue(event_queue);
}
void Rooms::InitiPic(int Xpos, int Ypos, int XVelocity, int YVelocity) {
	X = Xpos;
	Y = Ypos;
	XV = XVelocity;
	YV = YVelocity;
}
void Rooms::Draw(ALLEGRO_BITMAP *Image) {
	al_draw_bitmap(Image, X, Y, 0);
}
void Rooms::Move() {
	cout << X << " ," << Y << endl;
	if (X < 0 || Y > 1000 - 15) {
		//flip the x direction
		XV = -XV;
	}
	//if the box hits the top wall OR the bottom wall
	if (Y < 0 || Y > 1000 - 15) {
		//flip the y direction
		YV = -YV;
	}
	//really important code!
	//move the box in a diagonal
	X += XV;
	Y += YV;
}