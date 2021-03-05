#include <iostream>
#include"Brokers.h"

int main()
{
    ISubscriber* broker = new Broker();
    CourseDolars course;
    course.subscribe(broker);
    course.setCourse(23.5);
    course.setCourse(23.4);
    course.setCourse(25.4);
}

