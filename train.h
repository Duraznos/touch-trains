//
// Created by Christopher Bell on 5/8/15.
//
#include <stdio.h>
#include <stdlib.h>
#include "line.h"
#include "station.h"
#include "defs.h"



#ifndef TOUCH_TRAINS_TRAIN_H
#define TOUCH_TRAINS_TRAIN_H


typedef struct train{
    int                 id;
    Line               *line;
    direction           train_direction;
    Station            *cur_station;
} Train;

#define INVALID_DIRECTION 1
#define IMPOSSIBLE_DIRECTION 2

Train * new_train(Station *starting_station, direction init_direction);
void change_direction(Train *train);
void move_train(Train *train);

#endif //TOUCH_TRAINS_TRAIN_H
