#ifndef BITMAP_2_BUFFER_INCLUDED
#define BITMAP_2_BUFFER_INCLUDED

#include<allegro5/allegro_image.h>
#include<allegro5/allegro_color.h>
#include<allegro5/allegro.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
// mi paleta "NES"
#include "palette.h"

/**
 * converts bmp to tileset array buffer
 * @param bmp image
 */
uint8_t* bitmap_to_tileset_buffer(const char *filename);

#endif
