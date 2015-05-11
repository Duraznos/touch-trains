//
// Created by Christopher Bell on 5/9/15.
//

#ifndef TOUCH_TRAINS_DEFS_H
#define TOUCH_TRAINS_DEFS_H

typedef enum {INBOUND, OUTBOUND} Direction;

#define MAX_COLORS 5
typedef enum {GREEN, RED, ORANGE, BLUE, SILVER} Color;


#define MAX_LETTERS 5
typedef enum {A, B, C, D, E} Letter;

#define MAX_CONNECTIONS MAX_COLORS*MAX_LETTERS;

#endif //TOUCH_TRAINS_DEFS_H
