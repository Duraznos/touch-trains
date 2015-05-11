#include <stdio.h>
#include "include.h"



int main()
{

    Station *station1 = new_station();
    Station *station2 = new_station();
    Station *station3 = new_station();
    Station *station4a = new_station();
    Station *station5a = new_station();
    Station *station4b = new_station();
    Station *station5b = new_station();

    connect_station(station1, station2);
    connect_station(station2, station3);
    connect_station(station3, station4a);
    connect_station(station4a, station5a);
    connect_station(station3, station4b);
    connect_station(station4b, station5b);

    Train *train1 = new_train(station1, INBOUND, A);

    for(int moves=0; moves <=10; moves++){
        move_train(train1);
    }

    return 0;
}