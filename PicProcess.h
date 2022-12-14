#ifndef PICLIB_H
#define PICLIB_H

#include "Picture.h"
#include "Utils.h"
  
struct picture_information {
  struct picture *picture;
  struct picture *tmp;
  int i;
  int j;
};

// picture transformation routines
void invert_picture(struct picture *pic);
void grayscale_picture(struct picture *pic);
void rotate_picture(struct picture *pic, int angle);
void flip_picture(struct picture *pic, char plane);
void blur_picture(struct picture *pic);

void parallel_blur_picture(struct picture *pic);
bool new_individual_thread(pthread_t *thread, struct picture *pic, struct picture *tmp, int i, int j);
void blur_pixel(struct picture_information *inf);

void blur_picture_by_col(struct picture *pic);
bool new_col_thread(pthread_t *thread, struct picture *pic, struct picture *tmp, int i);
void blur_col(struct picture_information *inf);

void blur_picture_by_row(struct picture *pic);
bool new_row_thread(pthread_t *thread, struct picture *pic, struct picture *tmp, int j);
void blur_row(struct picture_information *inf);

#endif

