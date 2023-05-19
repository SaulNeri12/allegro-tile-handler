#include "include/tileset/tileset.h"
#include "include/bitmap2buffer.h"
// mi paleta "NES"
#include "include/palette.h"

void tileset_new_tileset(Tileset *tileset, uint8_t *palette, const char *filename, uint8_t total_tiles, uint8_t tile_width, uint8_t tile_height) {

	tileset->buffer = bitmap_to_tileset_buffer(filename);
	
	ALLEGRO_BITMAP *bmp = al_load_bitmap(filename);

	tileset->palette = palette;
	tileset->width = al_get_bitmap_width(bmp);
	tileset->height = al_get_bitmap_height(bmp);
	tileset->tile_width = tile_width;
	tileset->tile_height = tile_height;
	tileset->total_tiles = total_tiles;

	al_destroy_bitmap(bmp);
}


uint8_t *tileset_get_tile_by_row_col(Tileset *tileset, uint8_t row, uint8_t col) {
	
	if (!tileset) {
		fprintf(stderr, "tileset.tileset_get_tile_by_row_col [Line #%d] -> tileset struct is null!!!\n", __LINE__);
		exit(EXIT_FAILURE);
	}

	uint16_t start_x = col * tileset->tile_width;
	uint16_t start_y = row * tileset->tile_height;

	uint8_t *buf = al_malloc(sizeof(uint8_t) * (tileset->tile_width * tileset->tile_height));

	if (!buf) {
		fprintf(stderr, "tileset.tileset_get_tile_by_row_col [Line #%d] -> couldn't create tile buffer (malloc)!!!\n", __LINE__);
		exit(EXIT_FAILURE);
	}

	uint16_t pos = 0;

	for (uint16_t dy = start_y; dy < (start_y + tileset->tile_height); dy++) {
		for (uint16_t dx = start_x; dx < (start_x + tileset->tile_width); dx++) {
			buf[pos] = tileset->buffer[(dy * tileset->width) + dx];
			pos++;
		}
	}

	return buf;
}

void *tileset_render_tile_by_row_col(Tileset *tileset, uint8_t row, uint8_t col, float pixel_scale, float pixel_margin, float x, float y) {
	
	if (!tileset) {
		fprintf(stderr, "tileset.tileset_render_tile_by_row_col [Line #%d] -> tileset struct is null!!!\n", __LINE__);
		exit(EXIT_FAILURE);
	}

	uint16_t start_x = col * tileset->tile_width;
	uint16_t start_y = row * tileset->tile_height;

	float dx = 0, dy = 0;

	for (uint16_t by = start_y; by < (start_y + tileset->tile_height); by++) {
		for (uint16_t bx = start_x; bx < (start_x + tileset->tile_width); bx++) {
			
			uint8_t color_id = tileset->buffer[(by * tileset->width) + bx];
			
			if (color_id != 0xff) {
				
				ALLEGRO_COLOR color = al_map_rgb(
					PALETTE[tileset->palette[color_id]][RGBA_RED], 
					PALETTE[tileset->palette[color_id]][RGBA_GREEN], 
					PALETTE[tileset->palette[color_id]][RGBA_BLUE]
				);
				
				al_draw_filled_rectangle(dx + x, dy + y, dx + x + pixel_scale, dy + y + pixel_scale, color);
			}
			dx += pixel_scale + pixel_margin;
		}
		
		dx = 0;
		dy += pixel_scale + pixel_margin; // sin margen entre pixeles
	}
}

void tileset_render_tile_buffer(Tileset *tileset, uint8_t *tile_buffer, float x, float y, float pixel_scale, uint8_t pixel_margin) {

	if (!tileset) {
		fprintf(stderr, "tileset.tileset_render_tile_buffer [Line #%d] -> tileset struct is null!!!\n", __LINE__);
		exit(EXIT_FAILURE);
	}

	if (!tile_buffer) {
		fprintf(stderr, "tileset.tileset_render_tile_buffer [Line #%d] -> tile_buffer is null!!!\n", __LINE__);
		exit(EXIT_FAILURE);
	}

	float dx = 0, dy = 0;

	for (uint16_t row=0; row < tileset->tile_height; row++) {
		for (uint16_t col=0; col < tileset->tile_width; col++) {
			
			uint8_t color_id = tile_buffer[(row * tileset->tile_width) + col];
			
			if (color_id != 0xff) {
				
				ALLEGRO_COLOR color = al_map_rgb(
					PALETTE[tileset->palette[color_id]][RGBA_RED], 
					PALETTE[tileset->palette[color_id]][RGBA_GREEN], 
					PALETTE[tileset->palette[color_id]][RGBA_BLUE]
				);
				
				al_draw_filled_rectangle(dx + x, dy + y, dx + x + pixel_scale, dy + y + pixel_scale, color);
			}
			dx += pixel_scale + pixel_margin;
		}
		
		dx = 0;
		dy += pixel_scale + pixel_margin; // sin margen entre pixeles
	}
}






