#include "Adapter.h"

bool AdapterFrom24StandartTo12Standart::getIfMorning() const
{
    return clock24.getHours() < 12;
}

AdapterFrom24StandartTo12Standart::AdapterFrom24StandartTo12Standart(const size_t& hours, const size_t& minutes, const size_t& seconds)
{
   setTime(hours, minutes, seconds);
}

void AdapterFrom24StandartTo12Standart::setTime(const size_t& hours, const size_t& minutes, const size_t& seconds)
{
    clock24.setTime(hours, minutes, seconds);
}

void AdapterFrom24StandartTo12Standart::tick()
{
    clock24.tick();
}

void AdapterFrom24StandartTo12Standart::print()
{
    std::cout << getHours() << ":" << getMinute() << ":" << getSeconds();

}

const size_t AdapterFrom24StandartTo12Standart::getHours() const
{
    if(clock24.getHours() <12)
    return clock24.getHours();
    else {
        return clock24.getHours() -12;
    }
}

const size_t AdapterFrom24StandartTo12Standart::getMinute() const
{
    return clock24.getMinute();
}

const size_t AdapterFrom24StandartTo12Standart::getSeconds() const
{
    return clock24.getSeconds();
}
