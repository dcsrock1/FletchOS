#ifndef __VGA_DRIVER_H__
#define __VGA_DRIVER_H__

typedef struct {
    int x;
    int y;
} screenPos;

#define SCREEN_COLUMS 80
#define SCREEN_ROWS 25

int xytoaddr(screenPos loc);
screenPos addrtoxy(int addr);

#endif