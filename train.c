//
// Created by Christopher Bell on 5/8/15.
//

#include "train.h"

Train *new_train(Station *start, Direction train_direction, Letter letter){

    static int next_id = 1;
    Train *train = (Train *)malloc(sizeof(Train));
    if(train) {
        train->id = next_id++;
        train->direction = train_direction;
        train->cur_station = start;
        train->letter = letter;
        return train;
    }
    return NULL;
}



void change_direction(Train *train)
{
    switch (train->direction)
    {
        case INBOUND:{
            train->direction = OUTBOUND;
            printf("train %d is now headed outbound\n", train->id);
        } break;

        case OUTBOUND:{
            train->direction = INBOUND;
            printf("train %d is now headed inbound\n", train->id);
        };
    }

}

void move_train(Train *train){
    Station *next_station;
    switch(train->direction)
    {
        case INBOUND:{
            if (train->cur_station->inbound_connection[train->letter]){
                next_station = train->cur_station->inbound_connection[train->letter]->target;
                printf("train %d leaving station %d heading inbound for station %d\n", train->id, train->cur_station->id, next_station->id);
                train->cur_station = next_station;
            } else {
                printf("train %d can't move more inbound than station %d\n", train->id, train->cur_station->id);
                change_direction(train);
            }
        } break;
        case OUTBOUND:{
            if (train->cur_station->outbound_connection[train->letter]){
                next_station =  train->cur_station->outbound_connection[train->letter]->target;
                printf("train %d leaving station %d heading outbound for station %d\n", train->id, train->cur_station->id, next_station->id);
                train->cur_station = next_station;
            } else {
                printf("train %d can't move more outbound than station %d\n", train->id, train->cur_station->id);
                change_direction(train);
            }
        } ;
    }
}