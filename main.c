#include <stdio.h>
#include "include.h"



int main()
{

    Station *station1 = new_station();
    Station *station2 = new_station();
    Station *station3 = new_station();
    Connection *station1_in = new_connection(station1, INBOUND, GREEN);
    Connection *station1_out = new_connection(station1, OUTBOUND, GREEN);
    Connection *station2_in = new_connection(station2, INBOUND, GREEN);
    Connection *station2_out = new_connection(station2, OUTBOUND, GREEN);
    Connection *station3_in = new_connection(station3, INBOUND, GREEN);
    Connection *station3_out = new_connection(station3, OUTBOUND, GREEN);

    connect_station(station1, station2_out);
    connect_station(station1, station3_in);
    connect_station(station2, station1_in);
    connect_station(station2, station3_out);
    connect_station(station3, station2_in);
    connect_station(station3, station1_out);

    Train *train1 = new_train(station1, OUTBOUND);
    for(int moves=0; moves <=10; moves++){
        move_train(train1);
    }

    return 0;
}