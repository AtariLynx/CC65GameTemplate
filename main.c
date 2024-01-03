#include <6502.h>
#include <lynx.h>
#include <tgi.h>
#include <stdlib.h>
#include <conio.h>
#include <joystick.h> 
#include <string.h> 
#include <time.h> 
#include <peekpoke.h> 

#include "common.h"
#include "game.h"

// Globals here
unsigned char joy, old_joy;
unsigned char reset;
unsigned char halted;
unsigned char restarts;

void initialize() 
{
	tgi_install(&tgi_static_stddrv);
	tgi_init(); 
	joy_install(&joy_static_stddrv); 

	CLI();

	while (tgi_busy());

	tgi_setpalette(palette);
	 
	tgi_setcolor(COLOR_WHITE);
	tgi_setbgcolor(COLOR_BLACK);

	tgi_clear();
}

unsigned char read_input()
{
	unsigned char joy = joy_read(JOY_1);

	if (reset == true)
		return 0;

	if (kbhit())
	{
		switch (cgetc())
		{
		case 'F':
			tgi_flip();
			break;

		case 'P':
			if (halted)
			{
				halted = false;
			}
			else
			{
				halted = true;
			}
			break;

		case 'R':
			if (halted)
			{
				halted = false;
			}
			reset = true;
			break;

		case '1':
			break;

		case '2':
			break;

		case '3': 
			break;
		}
	}

	return joy;
}

int main(void) 
{	
	restarts = 0;
	reset = false;
	halted = false;

	initialize();

	// Never end from this loop 
	while (true)
	{
		lynx_load((int)&GAME_FILENR);
		play_game();
		restarts++;
	}

	return EXIT_SUCCESS;
}