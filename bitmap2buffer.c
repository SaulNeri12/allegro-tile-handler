#include "include/bitmap2buffer.h"

uint8_t* bitmap_to_tileset_buffer(const char *filename) {
	ALLEGRO_BITMAP *bmp = al_load_bitmap(filename);

	if (!bmp) {
		fprintf(stderr, "[Bitmap2Buffer.bitmap_to_tileset] -> file not found!\n");
		exit(EXIT_FAILURE);
	}

	uint16_t width = al_get_bitmap_width(bmp);
	uint16_t height = al_get_bitmap_height(bmp);

	uint8_t *buf = al_calloc(width * height, sizeof(uint8_t));

	al_lock_bitmap(bmp, al_get_bitmap_format(bmp), ALLEGRO_LOCK_READONLY);
	
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	for (uint16_t y=0; y < height; y++) {
		
		for (uint16_t x=0; x < width; x++) {
			ALLEGRO_COLOR pixel_color = al_get_pixel(bmp, x, y);

	  		al_unmap_rgba(pixel_color, &r, &g, &b, &a);
			
			for (int8_t i=0; i < GRAYSCALE_LEN; i++) {
				if ((r == GRAYSCALE[i][RGBA_RED]) && (g == GRAYSCALE[i][RGBA_GREEN]) && (b == GRAYSCALE[i][RGBA_BLUE])) {
					buf[(y * width) + x] = i;
					break;
				} else {
					buf[(y * width) + x] = 0xff;
				}
			}
		}
	}

	al_destroy_bitmap(bmp);
	al_unlock_bitmap(bmp);
	
	return buf;
}

