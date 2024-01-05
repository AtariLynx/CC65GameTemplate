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
	tgi_setframerate(75);
	tgi_init();
	joy_install(&joy_static_stddrv); 

	CLI();

	while (tgi_busy());

	//tgi_setpalette(palette);
	tgi_setpalette(tgi_getdefpalette());
	 
	tgi_setcolor(COLOR_WHITE);
	tgi_setbgcolor(COLOR_BLACK);

	tgi_clear();
}

unsigned char read_input()
{
	unsigned char data, count = 0;
	char text[20];
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
				// MIKEY.timer4.control = 0x18; // %00011000
				// MIKEY.timer4.reload = 12; //0x01;

				// MIKEY.serctl = 0x04|0x01;
				// // Dummy read
				// data = MIKEY.serdat;
				// MIKEY.serctl = 0x10|0x04|0x01|0x08; // 0x40|

				// // Clear receive buffer
				// while ((MIKEY.serctl & 0x40) == 0x40)
				// {
				// 	data = MIKEY.serdat;
				// }

				// MIKEY.serctl = 0x40 | 0x10 | 0x04 | 0x01 | 0x08;

				// while (true)
				// {
				// 	tgi_clear();
				// 	itoa(MIKEY.timer4.count, text, 10);
				// 	tgi_outtextxy(10, 40, text);
				// 	joy = joy_read(JOY_1);
				// 	itoa(joy, text, 10);
				// 	tgi_outtextxy(10, 50, text);
				// 	itoa(MIKEY.serctl, text, 16);
				// 	tgi_outtextxy(10, 60, text);
				// 	//itoa(receivecount, text, 10);
				// 	//tgi_outtextxy(10, 70, text);
				// 	tgi_outtextxy(10, 10, "Upload your game!");
				// 	tgi_updatedisplay();
				// 	while (tgi_busy());
				// }

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
		++restarts;
	}

	return EXIT_SUCCESS;
}