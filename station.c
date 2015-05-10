//
// Created by Christopher Bell on 5/9/15.
//
#include "stdlib.h"
#include "station.h"

Station *new_station(){
    static int next_id = 1;
    Station *station = (Station *)malloc(sizeof(Station));
    if (station){
        station->id = next_id++;
        station->inbound_connection = NULL;
        station->outbound_connection = NULL;
        return station;
    }

    return NULL;
}


Connection *new_connection(Station *target, direction conn_direction ,color line_color){
    Connection *connection = (Connection *)malloc(sizeof(Connection));
    if(connection){
        connection->target = target;
        connection->conn_direction = conn_direction;
        connection->line_color = line_color;
        return connection;
    }
    return NULL;
}


void connect_station(Station *current, Connection *new_connection){
    switch(new_connection->conn_direction){
        case INBOUND:
        {
            current->inbound_connection = new_connection;
        } break;

        case OUTBOUND:
        {
            current->outbound_connection = new_connection;
        };
    }
}
