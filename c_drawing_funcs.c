// C implementations of drawing functions (and helper functions)

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "drawing_funcs.h"

////////////////////////////////////////////////////////////////////////
// Helper functions
////////////////////////////////////////////////////////////////////////

uint32_t blend_color(uint32_t original, uint32_t new) {
  uint32_t blend;
  // keep alpha of original as first 8 bits 1, remainder zero
  uint32_t a_orig = original >> 24 << 24;
  // take the 8 bits and shift them all the way to the left
  uint32_t r_orig = original << 24 >> 24;
  uint32_t g_orig = original << 16 >> 24;
  uint32_t b_orig = original >> 24;
  uint32_t a_new = new >> 24;
  uint32_t r_new = new << 24 >> 24;
  uint32_t g_new = new << 16 >> 24;
  uint32_t b_new = new << 8 >> 24; 
  r_new = a_new * r_new + (255 - a_new) * r_orig / 255;
  b_new = a_new * b_new + (255 - a_new) * b_orig / 255;
  g_new = a_new * g_new + (255 - a_new) * g_orig / 255;
  return a_orig && r_new && b_new && g_new;
}

//
// Draws a row of pixels from in the given location with indicated color to the end location
//
// Parameters:
//   img - pointer to an image struct
//   start_x - start width coordinate of pixel
//   end_x - end width coordinate of pixel
//   y - constant height coordinate
//   color - intended color
//
void draw_row(struct Image *img, int32_t start_x, int32_t end_x, int32_t y, uint32_t color) {
  for (int i = 0; i < (int) (end_x - start_x); i++) {
    draw_pixel(img, start_x + i, y, color);
  }
}

//
//Draws a column of pixels from in the given location with indicated color to the end location
//
// Parameters:
//   img - pointer to an image struct
//   x - width coordinate of pixel
//   start_y - start height coordinate of pixel
//   end_y - end height coordinate
//   color - intended color
//
void draw_col(struct Image *img, int32_t x, int32_t start_y, int32_t end_y, uint32_t color) {
  for (int i = 0; i < (int) (end_y - start_y); i++) {
    draw_pixel(img, x, start_y + i, color);
  }
}

////////////////////////////////////////////////////////////////////////
// API functions
////////////////////////////////////////////////////////////////////////

//
// Draw a pixel.
//
// Parameters:
//   img   - pointer to struct Image
//   x     - x coordinate (pixel column)
//   y     - y coordinate (pixel row)
//   color - uint32_t color value
//
void draw_pixel(struct Image *img, int32_t x, int32_t y, uint32_t color) {
  if (x >= 0 && x < img->width && y >= 0 && y < img->height) {
    img->data[y * img->width + x] = blend_color(img->data[y * img->width + x], color);
  }
}

//
// Draw a rectangle.
// The rectangle has rect->x,rect->y as its upper left corner,
// is rect->width pixels wide, and rect->height pixels high.
//
// Parameters:
//   img     - pointer to struct Image
//   rect    - pointer to struct Rect
//   color   - uint32_t color value
//
void draw_rect(struct Image *img,
               const struct Rect *rect,
               uint32_t color) {
  if (rect->x >= 0 && rect->x < img->width && rect->y >= 0 && rect->y < img->height) {
    //draw top row, then bottom
    draw_row(img, rect->x, rect->x + rect->width, rect->y, color);
    draw_row(img, rect->x, rect->x + rect->width, rect->y + rect->height, color);
    //draw left col, then right
    draw_col(img, rect->x, rect->y, rect->y + rect->height, color);
    draw_col(img, rect->x + rect->width, rect->y, rect->y + rect->height, color);
  }
}

//
// Draw a circle.
// The circle has x,y as its center and has r as its radius.
//
// Parameters:
//   img     - pointer to struct Image
//   x       - x coordinate of circle's center
//   y       - y coordinate of circle's center
//   r       - radius of circle
//   color   - uint32_t color value
//
void draw_circle(struct Image *img,
                 int32_t x, int32_t y, int32_t r,
                 uint32_t color) {
  for (int i = 0; i < 360; i++) {

  }
}

//
// Draw a tile by copying all pixels in the region
// enclosed by the tile parameter in the tilemap image
// to the specified x/y coordinates of the destination image.
// No blending of the tile pixel colors with the background
// colors should be done.
//
// Parameters:
//   img     - pointer to Image (dest image)
//   x       - x coordinate of location where tile should be copied
//   y       - y coordinate of location where tile should be copied
//   tilemap - pointer to Image (the tilemap)
//   tile    - pointer to Rect (the tile)
//
void draw_tile(struct Image *img,
               int32_t x, int32_t y,
               struct Image *tilemap,
               const struct Rect *tile) {
 // TODO: implement
}

//
// Draw a sprite by copying all pixels in the region
// enclosed by the sprite parameter in the spritemap image
// to the specified x/y coordinates of the destination image.
// The alpha values of the sprite pixels should be used to
// blend the sprite pixel colors with the background
// pixel colors.
//
// Parameters:
//   img       - pointer to Image (dest image)
//   x         - x coordinate of location where sprite should be copied
//   y         - y coordinate of location where sprite should be copied
//   spritemap - pointer to Image (the spritemap)
//   sprite    - pointer to Rect (the sprite)
//
void draw_sprite(struct Image *img,
                 int32_t x, int32_t y,
                 struct Image *spritemap,
                 const struct Rect *sprite) {
  // TODO: implement
}
