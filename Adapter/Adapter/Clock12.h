#pragma once
#include"Adapter.h"
#include<vector>

class Clock12 : public AdapterFrom24StandartTo12Standart
{
public:

 	enum class Time_format { MIDNIGHT, MORNING, NOON, AFTERNOON };
	Clock12(const size_t& hours = 0, const size_t& minutes = 0, const size_t& seconds = 0);
	void print();
	void tick();
	void changeInterval(Time_format time);
	void changeInterval();
private:
	Time_format time;

};

