//
// Created by Christopher Bell on 5/8/15.
//

#include "train.h"

Train *new_train(Station *start, direction train_direction){

    static int next_id = 1;
    Train *train = (Train *)malloc(sizeof(Train));
    if(train) {
        train->id = next_id++;
        train->train_direction = train_direction;
        train->cur_station = start;
        return train;
    }
    return NULL;
}



void change_direction(Train *train)
{
    switch (train->train_direction)
    {
        case INBOUND:{
            train->train_direction = OUTBOUND;
            printf("train %d is now headed outbound\n", train->id);
        } break;

        case OUTBOUND:{
            train->train_direction = INBOUND;
            printf("train %d is now headed inbound\n", train->id);
        };
    }

}

void move_train(Train *train){
    Station *next_station;
    switch(train->train_direction)
    {
        case INBOUND:{
            if (train->cur_station->inbound_connection){
                next_station = train->cur_station->inbound_connection->target;
                printf("train %d leaving station %d heading inbound for station %d\n", train->id, train->cur_station->id, next_station->id);
                train->cur_station = next_station;
            } else {
                printf("train %d can't move more inbound than station %d\n", train->id, train->cur_station->id);
                change_direction(train);
            }
        } break;
        case OUTBOUND:{
            if (train->cur_station->outbound_connection){
                next_station =  train->cur_station->outbound_connection->target;
                printf("train %d leaving station %d heading outbound for station %d\n", train->id, train->cur_station->id, next_station->id);
                train->cur_station = next_station;
            } else {
                printf("train %d can't move more outbound than station %d\n", train->id, train->cur_station->id);
                change_direction(train);
            }
        } ;
    }
}