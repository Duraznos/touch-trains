//
// Created by Christopher Bell on 5/9/15.
//
#include "defs.h"

#ifndef TOUCH_TRAINS_STATION_H
#define TOUCH_TRAINS_STATION_H


typedef struct station Station;
typedef struct connection Connection;

struct connection{
    Station*            target;
    color               line_color;
    direction           conn_direction;
};

struct station{
    int                 id;
    Connection         *inbound_connection;
    Connection         *outbound_connection;
};


Station *new_station();
Connection *new_connection(Station *target, direction conn_direction ,color line_color);
void connect_station(Station *current, Connection *new_connection);

#endif //TOUCH_TRAINS_STATION_H
