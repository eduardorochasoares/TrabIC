#include <fstream>
#include "Node.h"
#include <time.h>

double limit;
int hotels_number, costumer_number, points_number;
Node** costumers;
Node** hotels;
Node** points;
void readInstance();
int main(){

    return 0;
}

void readInstance(){

    std::ifstream file;
    file.open("pr07.k15.tsphs");
    Node* node;
    file>>hotels_number;
    file>>costumer_number;
    file>>limit;
    points_number = hotels_number + costumer_number;

    hotels = new Node*[hotels_number];
    for(int i = 0; i < hotels_number; i++)
        hotels[i] = new Node();
    costumers = new Node*[costumer_number];

    for(int i = 0; i < costumer_number; i++)
        costumers[i] = new Node();

     points = new Node*[hotels_number + costumer_number];
     for(int i = 0; i < costumer_number + hotels_number; i++)
        points[i] = new Node();

    double x, y, demand;
    for(int i  = 0; i < (hotels_number + costumer_number); ++i){
        if(i < hotels_number){
            file>>x;
            file>>y;
            demand = 0;
            node = new Node();
            node->setX(x);
            node->setY(y);
            node->setDemand(demand);
            hotels[i] =  node;
        }else{
            file>>x;
            file>>y;
            file>>demand;
            node = new Node();
            node->setX(x);
            node->setY(y);
            node->setDemand(demand);
            costumers[i - hotels_number] = node;
        }
        points[i] = node;

    }



}

