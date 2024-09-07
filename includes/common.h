#ifndef __COMMON_H__
#define __COMMON_H__

// Uncomment to enable EEPROM calls
#define EEPROM

unsigned __fastcall__ lynx_eeread_93c46(unsigned char addr);
unsigned __fastcall__ lynx_eewrite_93c46(unsigned addr, unsigned val);
//unsigned __fastcall__ lynx_eeread_93c86(unsigned char addr);
//unsigned __fastcall__ lynx_eewrite_93c86(unsigned addr, unsigned val);

extern unsigned char framecount;
extern unsigned char seconds;
extern unsigned char minutes;

extern int MAIN_FILENR;
extern int GAME_FILENR;

#define false	0
#define true	1

#define max(x,y) x > y ? x : y;

extern unsigned char read_input();
extern unsigned char joy, old_joy;
extern unsigned char reset;
extern unsigned char halted;
extern unsigned char restarts;

#endif