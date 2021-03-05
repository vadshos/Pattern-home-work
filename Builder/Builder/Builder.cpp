#include <iostream>
#include"Bulider_House.h"

int main()
{
    Builder_House* builder = new Builder_House();
    Director director;
    director.makeReachHouse(builder);
    House* house = builder->getResult();
    director.makeCheapHouse(builder);
    House* house2 = builder->getResult();
    house->print();
    std::cout << std::endl;
    house2->print();
}


