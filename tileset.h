#ifndef TILESET_H_INCLUDED
#define TILESET_H_INCLUDED

#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro.h>
#include<stdint.h>
#include<stdlib.h>

typedef struct {
	uint8_t *buffer;
	uint8_t height;
	uint8_t width;
	uint8_t tile_width;
	uint8_t tile_height;
	uint8_t total_tiles;
	uint8_t *palette;
} Tileset;

/**
 * Creates a new tileset structure
 * @param tileset Tileset structure
 * @param palette 2-dimensional array containing the available colors defined in the "palette.h" header
 * @param filename png or bmp file name
 * @param total_tiles 
 * @param tile_width Width of each tile present in the file.
 * @param tile_width Height of each tile present in the file.
 */
void tileset_new_tileset(
		Tileset *tileset, 
		uint8_t *palette, 
		const char *filename, 
		uint8_t total_tiles, 
		uint8_t tile_width, 
		uint8_t tile_height
);

/**
 * Returns a buffer containing the pixel data of the tile given a row and column position in tileset
 * @param tileset Tileset structure
 * @param row Tile row position in tileset
 * @param col Tile column position in tileset
 */
uint8_t *tileset_get_tile_by_row_col(
		Tileset *tileset, 
		uint8_t row, 
		uint8_t col
);

/**
 * Renders the tile given a row and column position onto the coordinates x and y
 * @param tileset Tileset structure
 * @param row Tile row position in tileset
 * @param col Tile column position in tileset
 * @param pixel_scale Pixel scale (multiplies the size of the tile's own pixel)
 * @param pixel_margin Pixel margin (Pixel spacing, measured in pixels) 0 is no margin
 */
void *tileset_render_tile_by_row_col(
		Tileset *tileset, 
		uint8_t row, 
		uint8_t col, 
		float pixel_scale, 
		float pixel_margin, 
		float x, 
		float y
);

/**
 * Renders the tile given a tile buffer onto the coordinates x and y
 * @param tileset Tileset structure
 * @param tile_buffer 8 bit integers buffer
 * @param pixel_scale Pixel scale (multiplies the size of the tile's own pixel)
 * @param pixel_margin Pixel margin (Pixel spacing, measured in pixels) 0 is no margin
 */
void tileset_render_tile_buffer(
		Tileset *tileset, 
		uint8_t *tile_buffer, 
		float x,
		float y, 
		float pixel_scale, 
		uint8_t pixel_margin
);

#endif










