//
// Created by Christopher Bell on 5/9/15.
//
#include "defs.h"

#ifndef TOUCH_TRAINS_STATION_H
#define TOUCH_TRAINS_STATION_H


typedef struct station Station;
typedef struct connection Connection;

struct connection{
    Station    *target;
    Direction   direction;
    Letter      letter;
    Color       color;

};

struct station{
    int                 id;
    Letter              letter_in;
    Letter                letter_out;
    Connection         *inbound_connection[MAX_LETTERS];
    Connection         *outbound_connection[MAX_LETTERS];
};


Station *new_station();
Connection *new_connection(Station *target, Direction direction , Color color, Letter letter);
void connect_station(Station *inbound, Station *outbound);

#endif //TOUCH_TRAINS_STATION_H
