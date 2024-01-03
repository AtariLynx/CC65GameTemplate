#include <6502.h>
#include <lynx.h>
#include <tgi.h>
#include <stdlib.h>
#include <conio.h>
#include <joystick.h>

#include "common.h" 
#include "game.h"

#pragma code-name ("GAME_CODE") 
#pragma data-name ("GAME_DATA")
#pragma rodata-name ("GAME_RODATA")
#pragma bss-name ("GAME_BSS")

extern unsigned char read_input();

// State
unsigned char wait_for_release;
unsigned char play_state;

void draw()
{
	char temp[4];
	tgi_clear();

	// Draw all sprites and text
	tgi_outtextxy(60, 45, "Game");

#ifdef debug 
	itoa(joy, temp, 10);
	tgi_gotoxy(0, 0);
	tgi_outtext("Joystick ");
	tgi_outtext(temp);
	itoa(restarts, temp, 10);
	tgi_gotoxy(0, 10);
	tgi_outtext("Restarts ");
	tgi_outtext(temp);
	itoa(framecount, temp, 10);
	tgi_gotoxy(0, 20);
	tgi_outtext("Frames ");
	tgi_outtext(temp);
#endif

	tgi_updatedisplay();
}

static char random(unsigned char min, unsigned char max)
{
	return (rand() % (max - min + 1)) + min;
}

void handle_input(void)
{
	if (wait_for_release == true)
	{
		if (joy == 0)
		{
			wait_for_release = false;
		}
		else
		{
			return;
		}
	}
	
	old_joy = joy;
}

void update()
{
	// Update all game entities here
	unsigned char current_frame = framecount;
}

unsigned char play_game()
{
	play_state = PLAY_CONTINUE;
	reset = false;
	wait_for_release = true;

	while (play_state == PLAY_CONTINUE)
	{
		joy = read_input();

		// External reset flag
		if (reset) 
		{
			reset = false;
			return PLAY_ABORTED;
		}

		if (halted)
		{
			if (!tgi_busy())
			{
				tgi_clear();
				tgi_outtextxy(48, 10, "Paused");
				tgi_updatedisplay();
			}
			continue;
		}

		handle_input();
		update();

		if (!tgi_busy())
		{
			draw();
		}
	};

	return play_state;
}