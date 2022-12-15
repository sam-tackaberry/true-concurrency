#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include "Utils.h"
#include "Picture.h"
#include "PicProcess.h"

void blur_function(void (*blur_func) (struct picture *picture));

// ---------- MAIN PROGRAM ---------- \\

  int main(int argc, char **argv){

    /* Outputs the average run time from 100 iterations of each blur implementation. */

    printf("Support Code for Running the Blur Optimisation Experiments... \n");

    printf("Sequential blur took on average:\n");
    blur_function(&blur_picture);

    printf("Maximumly parallelised blur took on average:\n");
    blur_function(&parallel_blur_picture);

    printf("Blur picture by column took on average:\n");
    blur_function(&blur_picture_by_col);

    printf("Blur picture by row took on average:\n");
    blur_function(&blur_picture_by_row);

    printf("Blur picture by quarter took on average:\n");
    blur_function(&blur_picture_by_quarter);

}

  void blur_function(void (*blur_func) (struct picture *pic)) 
  {
    long long sumTimes = 0;
    struct picture pic;
    struct timeval start, stop;
    /* Loops 100 times recording how long it takes to run the blur function. */
    for (int i = 0; i < 100; i++) {
        init_picture_from_file(&pic, "test_images/charles.jpg");
        gettimeofday(&start, NULL);
        blur_func(&pic);
        gettimeofday(&stop, NULL);
        sumTimes += (stop.tv_sec - start.tv_sec) * 1000 + (stop.tv_usec - start.tv_usec) / 1000;
    }
    sumTimes /= 100;
    printf("%llu milliseconds\n", sumTimes);
  }