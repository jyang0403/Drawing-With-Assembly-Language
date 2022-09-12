#ifndef DRAWING_FUNCS_H
#define DRAWING_FUNCS_H

#include <stdint.h>
#include "image.h"

struct Rect {
  int32_t x, y, width, height;
};

/*
 * Draws a pixel in the given location with indicated color
 *
 * Parameters:
 *   img - pointer to an image struct
 *   x - width coordinate of pixel
 *   y - height coordinate
 *   color - intended color
 */
void draw_pixel(struct Image *img, int32_t x, int32_t y, uint32_t color);

/*
 * Draws a row of pixels from in the given location with indicated color to the end location
 *
 * Parameters:
 *   img - pointer to an image struct
 *   start_x - start width coordinate of pixel
 *   end_x - end width coordinate of pixel
 *   y - constant height coordinate
 *   color - intended color
 */
void draw_row(struct Image *img, int32_t start_x, int32_t end_x, int32_t y, uint32_t color);

/*
 * Draws a column of pixels from in the given location with indicated color to the end location
 *
 * Parameters:
 *   img - pointer to an image struct
 *   x - width coordinate of pixel
 *   start_y - start height coordinate of pixel
 *   end_y - end height coordinate
 *   color - intended color
 */
void draw_col(struct Image *img, int32_t x, int32_t start_y, int32_t end_y, uint32_t color);

/*
 * Draws a rectangle starting from x,y as the top left corner
 *
 * Parameters:
 *   img - pointer to an image struct
 *   rect - pointer to a rect struct
 *   color - intended color
 */
void draw_rect(struct Image *img,
               const struct Rect *rect,
               uint32_t color);

/*
 * Draws a circle starting from x,y as the center
 *
 * Parameters:
 *   img - pointer to an image struct
 *   x - width coorindate for center 
 *   y - height coordinate
 *   r - radius of circle
 *   color - intended color
 */
void draw_circle(struct Image *img,
                 int32_t x, int32_t y, int32_t r,
                 uint32_t color);

void draw_tile(struct Image *img,
               int32_t x, int32_t y,
               struct Image *tilemap,
               const struct Rect *tile);

void draw_sprite(struct Image *img,
                 int32_t x, int32_t y,
                 struct Image *spritemap,
                 const struct Rect *sprite);

#endif // DRAWING_FUNCS_H
