#include "include/palette.h"

/*
 * [Pixel Color Value Memory (used to identify the pixel color of sprites and tiles performed by "bitmap2buffer")]
 *
 * Extra Color 2 (red)	-> #a80020	rgb(168, 0, 32)
 * Extra Color 1 (brown)-> #881400	rgb(136, 20, 0)
 * white		-> #ffffff	rgb(255, 255, 255)
 * white gray		-> #e6e6e6	rgb(230, 230, 230)
 * light gray		-> #bcbcbc	rgb(188, 188, 188)
 * gray			-> #7c7c7c	rgb(124, 124, 124)
 * dark gray		-> #484848	rgb(72, 72, 72)
 * black		-> #000000	rgb(0, 0, 0)
 * */

uint8_t GRAYSCALE[GRAYSCALE_LEN][RGBA_LEN] = {
	{0x00, 0x00, 0x00, 0xff},	// 0x0 (1) black
	{0x48, 0x48, 0x48, 0xff},	// 0x1 (2) dark gray
	{0x7c, 0x7c, 0x7c, 0xff},	// 0x2 (3) gray
	{0xbc, 0xbc, 0xbc, 0xff},	// 0x3 (4) light gray
	{0xe6, 0xe6, 0xe6, 0xff},	// 0x4 (5) white gray
	{0xff, 0xff, 0xff, 0xff},	// 0x5 (6) white
	{0xa8, 0x10, 0x00, 0xff},	// 0x6 (7) EXTRA COLOR (NOT GRAYSCALE) red
	{0x88, 0x14, 0x00, 0xff}	// 0x7 (8) EXTRA COLOR (NOT GRAYSCALE) (brown)
};

// TODO: Indicar el nombre de todos los colores 

/* game palette */
uint8_t PALETTE[PAL_LEN][RGBA_LEN] = {
	{0x00, 0x00, 0x00, 0xff},	// 0x00 black
	{0xff, 0xff, 0xff, 0xff},	// 0x01 white
	{0xe6, 0xe6, 0xe6, 0xff}, 	// 0x02 white gray
	{0xbc, 0xbc, 0xbc, 0xff},	// 0x03 light gray
	{0x7c, 0x7c, 0x7c, 0xff},	// 0x04 gray
	{0xa4, 0xe4, 0xfc, 0xff},	// 0x05 sky white light blue
	{0x3c, 0xbc, 0xfc, 0xff},	// 0x06 sky light blue
	{0x00, 0x78, 0xf8, 0xff},	// 0x07 sky blue
	{0x00, 0x00, 0xfc, 0xff},	// 0x08 sky dark blue
	{0xb8, 0xb8, 0xb8, 0xff},	// 0x09 white light marine blue
	{0x68, 0x88, 0xfc, 0xff},	// 0x0A light marine blue 
	{0x00, 0x58, 0xf8, 0xff},	// 0x0B medium marine blue
	{0x00, 0x00, 0xbc, 0xff},	// 0x0C marine blue
	{0xd8, 0xb8, 0xf8, 0xff},	// 0x0D 
	{0x98, 0x78, 0xf8, 0xff},	// 0x0E
	{0x68, 0x44, 0xfc, 0xff},	// 0x0F
	{0x44, 0x28, 0xbc, 0xff},	// 0x10
	{0xf8, 0xb8, 0xf8, 0xff},	// 0x11
	{0xf8, 0x78, 0xf8, 0xff},	// 0x12
	{0xd8, 0x00, 0xcc, 0xff},	// 0x13
	{0x94, 0x00, 0x84, 0xff},	// 0x14
	{0xf8, 0xa4, 0xc0, 0xff},	// 0x15
	{0xf8, 0x58, 0x98, 0xff},	// 0x16
	{0xe4, 0x00, 0x58, 0xff},	// 0x17
	{0xa8, 0x00, 0x20, 0xff},	// 0x18
	{0xf0, 0xd0, 0xb0, 0xff},	// 0x19
	{0xf8, 0x78, 0x58, 0xff},	// 0x1A
	{0xf8, 0x38, 0x00, 0xff},	// 0x1B
	{0xa8, 0x10, 0x00, 0xff},	// 0x1C
	{0xfc, 0xe0, 0xa8, 0xff},	// 0x1D
	{0xfc, 0xa0, 0x44, 0xff},	// 0x1E
	{0xe4, 0x5c, 0x10, 0xff},	// 0x1F
	{0x88, 0x14, 0x00, 0xff},	// 0x20
	{0xf8, 0xd8, 0x78, 0xff},	// 0x21
	{0xf8, 0xf8, 0x00, 0xff},	// 0x22
	{0xac, 0x7c, 0x00, 0xff},	// 0x23
	{0x50, 0x30, 0x00, 0xff},	// 0x24
	{0xd8, 0xf8, 0x78, 0xff},	// 0x25
	{0xb8, 0xf8, 0x18, 0xff},	// 0x26
	{0x00, 0xb8, 0x00, 0xff},	// 0x27
	{0x00, 0x78, 0x00, 0xff},	// 0x28
	{0xb8, 0xf8, 0xb8, 0xff},	// 0x29
	{0x58, 0xd8, 0x54, 0xff},	// 0x2A
	{0x00, 0xa8, 0x00, 0xff},	// 0x2B
	{0x00, 0x68, 0x00, 0xff},	// 0x2C
	{0xb8, 0xf8, 0xd8, 0xff},	// 0x2D
	{0x58, 0xf8, 0x98, 0xff},	// 0x2E
	{0x00, 0xa8, 0x44, 0xff},	// 0x2F
	{0x00, 0x58, 0x00, 0xff},	// 0x30
	{0x00, 0xfc, 0xfc, 0xff},	// 0x31
	{0x00, 0xe8, 0xd8, 0xff},	// 0x32
	{0x00, 0x88, 0x88, 0xff},	// 0x33
	{0x00, 0x40, 0x58, 0xff},	// 0x34 dark cyan
	{0xf8, 0xd8, 0xf8, 0xff},	// 0x35
	{0x48, 0x48, 0x48, 0xff},	// 0x36
};








