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
        station->letter_in = A;
        station->letter_out = A;
        return station;
    }

    return NULL;
}


Connection *new_connection(Station *target, Direction direction , Color color, Letter letter){
    if (target->letter_in >= MAX_LETTERS && direction == INBOUND)
        return NULL;
    if (target->letter_out >= MAX_LETTERS && direction == OUTBOUND)
        return NULL;

    Connection *connection = (Connection *)malloc(sizeof(Connection));
    if(connection){
        connection->target = target;
        connection->direction = direction;
        connection->color = color;
        connection->letter = letter;
        switch(direction){
            case INBOUND:{
                target->letter_in++;
            }break;
            case OUTBOUND:{
                target->letter_out++;
            } break;
        }
        return connection;
    }
    return NULL;
}


void connect_station(Station *inbound, Station *outbound){

    Connection *in_conn = new_connection(outbound,INBOUND,GREEN, inbound->letter_in);
    Connection *out_conn = new_connection(inbound, OUTBOUND, GREEN, outbound->letter_out);
    inbound->inbound_connection[in_conn->letter] = in_conn;
    outbound->outbound_connection[out_conn->letter] = out_conn;
}
