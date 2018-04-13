#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <ctime>
#include <string>
#include <iostream>

using namespace std;

const float FPS = 60;
const int SCREEN_W = 1000;
const int SCREEN_H = 1000;
const int BOUNCER_SIZE = 32;
float bouncer_x = 500;
float bouncer_y = 500;
int A;
int B;
int C;
int D;
int Size = 10;
class Rooms {
public:
	void InitiPic(int Xpos, int Ypos);
	void Draw(ALLEGRO_BITMAP *Image);
	void Font(ALLEGRO_FONT *font, int XS, int XY, string Text);
private:
	int X;
	int Y;
	int XSize;
	int YSize;
	string T;
	
};

int main() {
	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_mouse();
	srand(time(NULL));
	ALLEGRO_BITMAP *Weights = al_load_bitmap("WeightRoom.png"); //loads bitmap from folders
	ALLEGRO_BITMAP *WorkShop = al_load_bitmap("WorkshopSize.png");
	ALLEGRO_BITMAP *Dinner = al_load_bitmap("DinnerSize.png");
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_FONT *GP = al_load_ttf_font("Gameplay.ttf", 25, 0);
	
	ALLEGRO_DISPLAY *GameWindow = NULL; //Create a Display Window
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	GameWindow = al_create_display(1800, 1000); //Create Your Game Window
	al_set_window_position(GameWindow, 0, 0); //Positions Widnow on Screen
	al_set_window_title(GameWindow, "Ferny's Game"); //Window Title
	bool redraw = true;
	
	timer = al_create_timer(1.0 / FPS);
	bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
	al_set_target_bitmap(bouncer);
	al_clear_to_color(al_map_rgb(255, 0, 255));

	al_set_target_bitmap(al_get_backbuffer(GameWindow));

	event_queue = al_create_event_queue();


	al_register_event_source(event_queue, al_get_display_event_source(GameWindow));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);
	while (1) {
	Rooms Room1;Room1.InitiPic(50, 100);
	Rooms Room2;Room2.InitiPic(50, 321);
	Rooms Room3;Room3.InitiPic(50, 498);

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {

			bouncer_x = ev.mouse.x;
			bouncer_y = ev.mouse.y;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			A = rand() % 50;
			B = rand() % 250;
			C = rand() % 250;
			D = rand() % 250;
			if (bouncer_x > 50 && bouncer_x < 401 && bouncer_y > 100 && bouncer_y < 321) {
				al_draw_rectangle(50, 100, 401, 321, al_map_rgb(B, C, D), Size);
				Room1.Font(GP, 351, 221, "Weight Room"); // 351 221
				cout << "clicked" << endl;
			}
			else if (bouncer_x > 50 && bouncer_x < 966 && bouncer_y > 321 && bouncer_y < 498) {
				al_draw_rectangle(50, 321, 966, 498, al_map_rgb(B, C, D), Size);
				Room2.Font(GP, 916, 177, "WorkShop Room"); // 351 221
				cout << "clicked" << endl;
			}
			else if (bouncer_x > 50 && bouncer_x < 650 && bouncer_y > 498 && bouncer_y < 615) {
				al_draw_rectangle(50, 498, 650, 615, al_map_rgb(B, C, D), Size);
				Room3.Font(GP, 600, 117, "Dinner Room"); // 351 221
				cout << "clicked" << endl;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			Room1.Draw(Weights);
			Room2.Draw(WorkShop);
			Room3.Draw(Dinner);
			al_flip_display();
		}
	}
	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(GameWindow);
	al_destroy_event_queue(event_queue);
}
void Rooms::InitiPic(int Xpos, int Ypos) {
	X = Xpos;
	Y = Ypos;
}
void Rooms::Draw(ALLEGRO_BITMAP *Image) {
	al_draw_bitmap(Image, X, Y, 0);
}
void Rooms::Font(ALLEGRO_FONT *font, int XS, int YS, string Text) {
	XSize = XS;
	YSize = YS;
	T = Text;
	al_draw_textf(font, al_map_rgb(250, 250, 250), X + XSize+10, Y + YSize- 30, NULL, "%s", T.c_str());//X + XSizeY + YSize
}