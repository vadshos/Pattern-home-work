#include "Clock12.h"

Clock12::Clock12(const size_t& hours, const size_t& minutes, const size_t& seconds) : AdapterFrom24StandartTo12Standart(hours,minutes,seconds)
{
	changeInterval();
}

void Clock12::print()
{
	std::vector<std::string> timeF{"a.m.*","a.m.","p.m.*","p.m"};
	AdapterFrom24StandartTo12Standart::print();
	std::cout <<" "<< *(timeF.begin() + (int)time);

}

void Clock12::tick()

{
	AdapterFrom24StandartTo12Standart::tick();
	changeInterval();
	
}

void Clock12::changeInterval(Time_format time)
{
	
	this->time = time;
}

void Clock12::changeInterval()
{
	if (AdapterFrom24StandartTo12Standart::getIfMorning())
	{
		if (time != Time_format::MORNING && getHours() != 0) {
			changeInterval(Time_format::MORNING);
		}
		else if (getHours() == 0) {
			changeInterval(Time_format::MIDNIGHT);
		}
	}
	else if (!AdapterFrom24StandartTo12Standart::getIfMorning()) {
		if (time != Time_format::AFTERNOON && getHours() != 0) {
			changeInterval(Time_format::AFTERNOON);
		}
		else if (getHours() == 0) {
			changeInterval(Time_format::NOON);
		}
	}
}
