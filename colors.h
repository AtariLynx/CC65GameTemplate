#ifndef __COLORS_H__
#define __COLORS_H__

#define COLOR_BLACK             0x00	// 0,0,0
#define COLOR_RED               0x01	// 255,0,77     
#define COLOR_ROSE              0x02	// 255,119,168
#define COLOR_LIGHTGREY         0x03	// 194,195,199  
#define COLOR_PURPLE            0x04	// 131,118,156
#define COLOR_GOLD		        0x05	// 255,163,0
#define COLOR_BROWN	            0x06	// 95,87,79
#define COLOR_LIGHTORANGE       0x07	// 255,204,170
#define COLOR_YELLOW            0x08	// 255,240,36
#define COLOR_DARKGREEN			0x09	// 0,135,81
#define COLOR_GREEN             0x0A	// 0,231,86
#define COLOR_TAN				0x0B	// 171,82,54
#define COLOR_PLUM				0x0C	// 126,37,83
#define COLOR_BLUE              0x0D	// 41,173,255
#define COLOR_DARKBLUE			0x0E	// 29,43,83
#define COLOR_WHITE             0x0F	// 255,241,232

static char palette[] =
{
	// Green values (with RGB's for reference) rgb -> gbr
	0x0000 >> 8,	// 0,0,0		00 00 00	Black
	0x005f >> 8,	// 255,0,77		ff 00 4d	Red
	0x07bf >> 8,	// 255,119,168	ff 77 a8	Rose, pink
	0x0ccc >> 8,	// 194,195,199	c2 c3 c7	Light grey
	0x07a8 >> 8,	// 131,118,156	83 76 9c	Purple, dark purple
	0x0a0f >> 8,	// 255,163,0	ff a3 00	Gold, orange
	0x0556 >> 8,	// 95,87,79		5f 57 4f	Brown, dark grey
	0x0dbf >> 8,	// 255,204,170	ff cc aa    Light orange, light peach
	0x0f2f >> 8,	// 255,240,36	ff f0 24	Yellow
	0x0850 >> 8,	// 0,135,81		00 87 51	Dark green
	0x0e50 >> 8,	// 0,231,86		00 e7 56	Green
	0x053b >> 8,	// 171,82,54	ab 52 36	Tan, brown
	0x0258 >> 8,	// 126,37,83	7e 25 53	Plum, lavender
	0x0bf3 >> 8,	// 41,173,255	29 ad ff	Blue
	0x0352 >> 8,	// 29,43,83		1d 2b 53	Dark blue
	0x0fef >> 8,	// 255,241,232	ff f1 e8	White

	// Blue and red values
	0x0000 & 0xff,
	0x005f & 0xff,
	0x07bf & 0xff,
	0x0ccc & 0xff,
	0x07a8 & 0xff,
	0x0a0f & 0xff,
	0x0556 & 0xff,
	0x0dbf & 0xff,
	0x0f2f & 0xff,
	0x0850 & 0xff,
	0x0e50 & 0xff,
	0x053b & 0xff,
	0x0258 & 0xff,
	0x0bf3 & 0xff,
	0x0352 & 0xff,
	0x0fef & 0xff
};

#endif // !__COLORS_H__
