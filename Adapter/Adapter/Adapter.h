#include"Clock24.h"

class AdapterFrom24StandartTo12Standart
{
public:
	bool getIfMorning() const;
	AdapterFrom24StandartTo12Standart(const size_t& hours = 0, const size_t& minutes = 0, const size_t& seconds = 0);
	void setTime(const size_t& hours, const size_t& minutes, const size_t& seconds);
	void tick();
	void print();
	const size_t getHours() const;
	const size_t getMinute() const;
	const size_t getSeconds() const;
private:
	Clock24 clock24;
};

