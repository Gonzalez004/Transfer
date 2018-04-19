#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>

using namespace std;

int PlattformCollide(int x, int y, int dir, int map[25][25]);

int num = 262;
int lives = 3;
const int PACSIZE = 30;
const int WALLSIZE = 40;
const int DOT = 10;
int Score = 0;
int Clock = 0;
int ForClock = 50;
enum directions { Up, Down, Left, Right };
bool key[4] = { false, false, false, false };

int map[25][25] = {
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 
	1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1, 
	1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1, 
	1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 
	1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1, 
	1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1, 
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 
	1,1,1,1,1,0,1,0,1,1,2,0,0,0,2,1,1,0,1,0,1,1,1,1,1, 
	1,1,1,1,1,0,1,0,1,1,2,0,0,0,2,1,1,0,1,0,1,1,1,1,1, 
	1,1,1,1,1,0,1,0,1,1,2,2,2,2,2,1,1,0,1,0,1,1,1,1,1, 
	1,1,1,1,1,0,1,0,1,1,2,2,2,2,2,1,1,0,1,0,1,1,1,1,1, 
	2,2,2,2,2,0,1,0,1,1,2,2,2,2,2,1,1,0,1,0,2,2,2,2,2, 
	1,1,1,1,1,0,1,0,1,1,2,2,2,2,2,1,1,0,1,0,1,1,1,1,1, 
	1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,1, 
	1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1, 
	1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1, 
	1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,0,1, 
	1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,0,1, 
	1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1, 
	1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1, 
	1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 
};

class Ghost {
public:
	Ghost();
	int collision(int b2_x, int b2_y, int b2_w, int b2_h);
	void InitGhost(int x, int y, char color, int dir, bool dead, int GSpeed);
	bool IsDead();
	void DrawGhost();
	void PrintInfo();
	void Chase(int x, int y, int map[25][25]);
	bool GetPacman(int x, int y);
private:
	int HitWall;
	int Xpos;
	int Ypos;
	char Color;
	int Direction;
	bool Dead;
	int Speed;
	int Width;
	int Height;
};

int main() {
	Ghost Ghost1;
	Ghost1.InitGhost(484, 404, 'r', 1, false, 4.0); // Red Ghost
	Ghost Ghost2;
	Ghost2.InitGhost(484, 442, 'b', 1, false, 4.0); // Blue Ghost
	Ghost Ghost3;
	Ghost3.InitGhost(484, 566, 'p', 1, false, 4.0); // Purple Ghost
	Ghost Ghost4;
	Ghost4.InitGhost(484, 524, 'o', 1, false, 4.0); // Orange Ghost


	al_init();
	al_init_primitives_addon();
	al_install_audio();
	al_init_acodec_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *square = NULL;
	ALLEGRO_BITMAP *wall = NULL;
	ALLEGRO_BITMAP *Dot = NULL;

	ALLEGRO_SAMPLE *chomp = NULL;
	ALLEGRO_SAMPLE *Intro = NULL;
	ALLEGRO_SAMPLE *dead = NULL;
	ALLEGRO_SAMPLE *Lost = NULL;
	ALLEGRO_SAMPLE *song = NULL;
	ALLEGRO_SAMPLE *Winner = NULL;
	ALLEGRO_SAMPLE_INSTANCE *songInstance = NULL;


	ALLEGRO_FONT *font = al_load_ttf_font("Gameplay.ttf", 40, 0);
	ALLEGRO_FONT *font1 = al_load_ttf_font("Gameplay.ttf", 40, 0);
	ALLEGRO_FONT *font2 = al_load_ttf_font("Gameplay.ttf", 20, 0);

	int square_x = 766;
	int square_y = 486;
	
	bool redraw = true;
	bool doexit = false;

	timer = al_create_timer(.02);

	//Creates the Display and Position its
	display = al_create_display(1000, 1000);
	al_set_window_position(display, 420, 0);

	//create a little 32x32 square
	square = al_create_bitmap(PACSIZE, PACSIZE);
	al_set_target_bitmap(square);
	al_clear_to_color(al_map_rgb(255, 255, 0));
	//creating wall
	wall = al_create_bitmap(WALLSIZE, WALLSIZE);
	al_set_target_bitmap(wall);
	al_clear_to_color(al_map_rgb(0, 255, 255));
	//Creating Dot
	Dot = al_create_bitmap(DOT, DOT);
	al_set_target_bitmap(Dot);
	al_clear_to_color(al_map_rgb(255, 255, 0));

	al_set_target_bitmap(al_get_backbuffer(display));
	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();

	al_start_timer(timer);

	while (!doexit && lives > 0 && num > 0)
	{
		ForClock--;
		if (ForClock <= 0) {
			Clock++;
			ForClock = 50;
		}
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (map[square_x / 40][square_y / 40] == 0) {
				map[square_x / 40][square_y / 40] = 2;
				num = num - 1;
				Score++;
				cout << num << endl;
				//cout << Score << endl;
				cout << endl;
			}
			if (square_y <= -14) {
				square_x = 486;
				square_y = 960;
			}
			if (square_y > 966) {
				square_x = 487;
				square_y = -10;
			}
			if (key[0] && !PlattformCollide(square_x, square_y, Up, map)) {
				square_y -= 4.0;
			}
			if (key[1] && !PlattformCollide(square_x, square_y, Down, map)) {
				square_y += 4.0;
			}
			if (key[2] && !PlattformCollide(square_x, square_y, Left, map)) {
				square_x -= 4.0;
			}
			if (key[3] && !PlattformCollide(square_x, square_y, Right, map)) {
				square_x += 4.0;
			}
			
				if ((Ghost1.collision(square_x, square_y, 15, 15) == 0) == false) {
					Ghost1.InitGhost(484, 404, 'r', 1, false, 4.0); // Red Ghost
					Ghost2.InitGhost(484, 442, 'b', 1, false, 4.0); // Blue Ghost
					Ghost3.InitGhost(484, 566, 'p', 1, false, 4.0); // Purple Ghost
					Ghost4.InitGhost(484, 524, 'o', 1, false, 4.0); // Orange Ghost
					square_x = 766;
					square_y = 486;
					lives = lives - 1;
				}
				if ((Ghost2.collision(square_x, square_y, 15, 15) == 0) == false) {
					Ghost1.InitGhost(484, 404, 'r', 1, false, 4.0); // Red Ghost
					Ghost2.InitGhost(484, 442, 'b', 1, false, 4.0); // Blue Ghost
					Ghost3.InitGhost(484, 566, 'p', 1, false, 4.0); // Purple Ghost
					Ghost4.InitGhost(484, 524, 'o', 1, false, 4.0); // Orange Ghost
					square_x = 766;
					square_y = 486;
					lives = lives - 1;
				}
				if ((Ghost3.collision(square_x, square_y, 15, 15) == 0) == false) {
					Ghost1.InitGhost(484, 404, 'r', 1, false, 4.0); // Red Ghost
					Ghost2.InitGhost(484, 442, 'b', 1, false, 4.0); // Blue Ghost
					Ghost3.InitGhost(484, 566, 'p', 1, false, 4.0); // Purple Ghost
					Ghost4.InitGhost(484, 524, 'o', 1, false, 4.0); // Orange Ghost
					square_x = 766;
					square_y = 486;
					lives = lives - 1;
				}

				if ((Ghost4.collision(square_x, square_y, 15, 15) == 0) == false) {
					Ghost1.InitGhost(484, 404, 'r', 1, false, 4.0); // Red Ghost
					Ghost2.InitGhost(484, 442, 'b', 1, false, 4.0); // Blue Ghost
					Ghost3.InitGhost(484, 566, 'p', 1, false, 4.0); // Purple Ghost
					Ghost4.InitGhost(484, 524, 'o', 1, false, 4.0); // Orange Ghost
					square_x = 766;
					square_y = 486;
					lives = lives - 1;
				}
			Ghost1.Chase(square_x, square_y, map);
			Ghost2.Chase(square_x-10, square_y, map);
			Ghost3.Chase(square_x-20, square_y, map);
			Ghost4.Chase(square_x+20, square_y, map);
			redraw = true;
		}

		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
	
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[0] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				key[1] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				key[2] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[3] = true;
				break;
			}
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[0] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				key[1] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				key[2] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[3] = false;
				break;
			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			Ghost1.DrawGhost();
			Ghost2.DrawGhost();
			Ghost3.DrawGhost();
			Ghost4.DrawGhost();

			al_draw_bitmap(square, square_x, square_y, 0);

			for (int i = 0; i < 25; i++) {
				for (int j = 0; j < 25; j++) {
					//al_draw_rectangle(i*40,j*40, i*40+40, j*40+40, al_map_rgb(50,80,90 ), 3);
					if (map[j][i] == 1) {
						al_draw_bitmap(wall, j * 40, i * 40, 0);
					}
					if (map[j][i] == 0) {
						al_draw_bitmap(Dot, j * 40 + 15, i * 40 + 15, 0);
					}
				}
			}
			if (lives > 0) {
				al_draw_textf(font, al_map_rgb(0, 0, 0), 330, 350, NULL, "lives: %d", lives);
				al_draw_textf(font1, al_map_rgb(0, 0, 0), 330, 625, NULL, "Clock: %d", Clock);
			
			}
			/*if (num <= 0) {
				al_draw_filled_rectangle(0, 0, 1000, 1000, al_map_rgb(255, 255, 255));
				al_draw_text(font1, al_map_rgb(255, 0, 0), 150, 250, 0, "you win!");
			}
			if (lives <= 0) {
				al_draw_filled_rectangle(0, 0, 1000, 1000, al_map_rgb(255, 255, 255));
				al_draw_text(font1, al_map_rgb(255, 0, 0), 150, 250, 0, "you lose!");
			}*/

			al_flip_display();
		}
	}

	al_destroy_bitmap(Dot);
	al_destroy_bitmap(square);
	al_destroy_bitmap(wall);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}
int PlattformCollide(int x, int y, int dir, int map[25][25]) {
	enum directions { Up, Down, Left, Right };
	//Down collision
	if (((map[(x) / 40][(y + 30 + 5) / 40] == 1) && dir == Down) || ((map[(x + 30) / 40][(y + 30 + 5) / 40] == 1) && dir == Down) || ((map[(x + 15) / 40][(y + 30 + 5) / 40] == 1) && dir == Down)) {
		return 1;
	}
	//Up collision
	if (((map[(x) / 40][(y - 5) / 40] == 1) && dir == Up) || ((map[(x + 30) / 40][(y - 5) / 40] == 1) && dir == Up) || ((map[(x + 15) / 40][(y - 5) / 40] == 1) && dir == Up)) {
		return 1;
	}
	//Left collision
	if (((map[(x - 5) / 40][(y) / 40] == 1) && dir == Left) || ((map[(x - 5) / 40][(y + 30) / 40] == 1) && dir == Left) || ((map[(x - 5) / 40][(y + 15) / 40] == 1) && dir == Left)) {
		return 1;
	}
	//Right collision
	if (((map[(x + 35) / 40][(y) / 40] == 1) && dir == 3) || ((map[(x + 35) / 40][(y + 30) / 40] == 1) && dir == 3) || ((map[(x + 35) / 40][(y + 15) / 40] == 1) && dir == Right)) {
		return 1;
	}
	else
		return 0;
}

Ghost::Ghost() {
	HitWall = 0;
	Xpos = 0;
	Ypos = 0;
	Color = 'a';
	Direction = 0;
	Dead = 0;
	Speed = 0;
	Width = 0;
	Height = 0;
}


void Ghost::InitGhost(int x, int y, char color, int dir, bool dead, int GSpeed) {
	HitWall = false;
	Xpos = x;
	Ypos = y;
	Color = color;
	Direction = dir;
	Dead = false;
	Speed = GSpeed;
	Width = PACSIZE;
	Height = PACSIZE;


}
bool Ghost::IsDead() {
	return Dead;
}
void Ghost::DrawGhost() {
	if (Color == 'r')
		al_draw_filled_rectangle(Xpos, Ypos, Xpos + Height, Ypos + Width, al_map_rgb(255, 0, 0));
	else if (Color == 'b')
		al_draw_filled_rectangle(Xpos, Ypos, Xpos + Height, Ypos + Width, al_map_rgb(65, 105, 225));
	else if (Color == 'p')
		al_draw_filled_rectangle(Xpos, Ypos, Xpos + Height, Ypos + Width, al_map_rgb(255, 0, 255));
	else if (Color == 'o')
		al_draw_filled_rectangle(Xpos, Ypos, Xpos + Height, Ypos + Width, al_map_rgb(255, 140, 0));
}
void Ghost::PrintInfo() {
	cout << Color << endl;
	cout << Xpos << endl;
	cout << Ypos << endl;
}
void Ghost::Chase(int x, int y, int map[25][25]) {
	enum directions { Up, Down, Left, Right };
	/////////////////////////////////Left STATE (1)//////////////////////////////////////////////////////////////////
	//if we're moving Left and there's an opening above and pacman is above, move Up
	if ((Direction == Left) && !PlattformCollide(Xpos, Ypos, Up, map) && y<Ypos)
		while (!PlattformCollide(Xpos, Ypos, 2, map)) {
			Direction = Up;
			Ypos -= Speed;
			return;
		}
	//if we're moving Left and there's an opening below and pacman is below, move Down
	if ((Direction == Left) && !PlattformCollide(Xpos, Ypos, Down, map) && y>Ypos)
		while (!PlattformCollide(Xpos, Ypos, 4, map)) {
			Direction = Down;
			Ypos += Speed;
			return;
		}
	if (Direction == Left)//Left
		while (!PlattformCollide(Xpos, Ypos, Left, map)) {
			Xpos -= Speed;
			return;
		}
	////////////////////////////////Up STATE (2)///////////////////////////////////////////////////////////////
	//if we're moving Up and there's an opening Left and pacman is Left, move Left
	if ((Direction == Up) && !PlattformCollide(Xpos, Ypos, Left, map) && x<Xpos)
		while (!PlattformCollide(Xpos, Ypos, Left, map)) {
			Direction = Left;
			Xpos -= Speed;
			return;
		}
	//if we're moving Up and there's an opening Right and pacman is Right, move Right
	if ((Direction == Up) && !PlattformCollide(Xpos, Ypos, Right, map) && x>Xpos)
		while (!PlattformCollide(Xpos, Ypos, 3, map)) {
			Direction = Right;
			Xpos += Speed;
			return;
		}
	if (Direction == Up)//Up
		while (!PlattformCollide(Xpos, Ypos, 2, map)) {
			Ypos -= Speed;
			return;
		}
	/////////Right CASE (3)/////////////////////////////////////////////////////////////////////////////////////////////////////
	//if we're moving Right and there's an opening above and pacman is above, move Up
	if ((Direction == Right) && !PlattformCollide(Xpos, Ypos, Up, map) && y<Ypos)
		while (!PlattformCollide(Xpos, Ypos, 2, map)) {
			Direction = Up;
			Ypos -= Speed;
			return;
		}
	//if we're moving Right and there's an opening below and pacman is below, move Down
	if ((Direction == Right) && !PlattformCollide(Xpos, Ypos, Down, map) && y>Ypos)
		while (!PlattformCollide(Xpos, Ypos, Down, map)) {
			Direction = Down;
			Ypos += Speed;
			return;
		}
	if (Direction == Right)//Right
		while (!PlattformCollide(Xpos, Ypos, Right, map)) {
			Xpos += Speed;
			return;
		}
	//////////////Down CASE (4)/////////////////////////////////////////////////////////////////////////////////////
	//if we're moving Up and there's an opening Left and pacman is Left, move Left
	if ((Direction == Down) && !PlattformCollide(Xpos, Ypos, Left, map) && x<Xpos)
		while (!PlattformCollide(Xpos, Ypos, Left, map)) {
			Direction = Left;
			Xpos -= Speed;
			return;
		}
	//if we're moving Up and there's an opening Right and pacman is Right, move Right
	if ((Direction == Up) && !PlattformCollide(Xpos, Ypos, Right, map) && x>Xpos)
		while (!PlattformCollide(Xpos, Ypos, Right, map)) {
			Direction = Right;
			Xpos += Speed;
			return;
		}
	if (Direction == Down)//Down
		while (!PlattformCollide(Xpos, Ypos, Down, map)) {
			Ypos += Speed;
			return;
		}
	///////////////////////////////////////////////////////////////////////////////////////
	//if pacman is above and there's no wall there, move Up
	if ((y<Ypos) && !PlattformCollide(Xpos, Ypos, Up, map)) {
		Direction = Up;
		return;
	}
	//if pacman is below and there's no wall there, move Down
	if ((y>Ypos) && !PlattformCollide(Xpos, Ypos, Down, map)) {
		Direction = Down;
		return;
	}
	//if pacman is Right and there's no wall there, move Right
	if ((x>Xpos) && !PlattformCollide(Xpos, Ypos, Right, map)) {
		Direction = Right;
		return;
	}
	//if pacman is Left and there's no wall there, move Left
	if ((x<Xpos) && !PlattformCollide(Xpos, Ypos, Left, map)) {
		Direction = Left;
		return;
	}
	//if pacman is above and there's no wall there, move Up
	if (!PlattformCollide(Xpos, Ypos, Up, map)) {
		Direction = Up;
		return;
	}
	//if pacman is below and there's no wall there, move Down
	if (!PlattformCollide(Xpos, Ypos, Down, map)) {
		Direction = Down;
		return;
	}
	//if pacman is Right and there's no wall there, move Right
	if (!PlattformCollide(Xpos, Ypos, Right, map)) {
		Direction = Right;
		return;
	}
	//if pacman is Left and there's no wall there, move Left
	if (!PlattformCollide(Xpos, Ypos, Left, map)) {
		Direction = Left;
		return;
	}
}
bool Ghost::GetPacman(int x, int y) {
	return true;
}
int Ghost::collision(int b2_x, int b2_y, int b2_w, int b2_h)
{
	if ((Xpos > b2_x + b2_w - 1) || //box 2 is to the LEFT of box 1
		(Ypos > b2_y + b2_h - 1) || //box 2 is ABOVE box 1
		(b2_x  > Xpos + Width - 1) ||//box 2 is to the RIGHT of box1
		(b2_y > Ypos + Height - 1)) //box 2 is BELOW box 1
	{
		return 0;
	}
	else
	{
		return 1;
	}

}