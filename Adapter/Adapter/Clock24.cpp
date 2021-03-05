#include "Clock24.h"

Minute::Minute(const size_t& minute, const size_t& MAX_MINUTE) : MAX_MINUTE(MAX_MINUTE) {
	setMinute(minute);
}

void Minute::tick()
{
	if (minute < MAX_MINUTE-2) {
		++minute;
	}
	else {
		minute = 0;
	}
}

const size_t& Minute::getMinute() const
{
	return minute;
}

const size_t& Minute::getMaxMinute() const
{
	return MAX_MINUTE;
}

void Minute::setMinute(const size_t& minute)
{
	if (minute < MAX_MINUTE) {
		this->minute = minute;
	}
	else {
		this->minute = (minute % MAX_MINUTE);
	}
}

Seconds::Seconds(const size_t& seconds, const size_t& MAX_SECONDS)
{
	setSeconds(seconds);
}

void Seconds::tick()
{
	if (seconds < MAX_SECONDS-1) {
		++seconds;
	}
	else {
		seconds = 0;
	}
}

const size_t& Seconds::getSeconds() const
{
	return seconds;
}

const size_t& Seconds::getMaxSeconds() const
{
	return MAX_SECONDS;
}

void Seconds::setSeconds(const size_t& seconds)
{
	if (seconds < MAX_SECONDS) {
		this->seconds = seconds;
	}
	else {
		this->seconds = (seconds % MAX_SECONDS);
	}
}

Hour::Hour(const size_t& hours , const size_t& MAX_HOURS )
{
	setHours(hours);
}

void Hour::tick()
{
	if (hours < MAX_HOURS-1) {
		++hours;
	}
	else {
		hours = 0;
	}
}

const size_t& Hour::getHours() const
{
	return hours;
}

const size_t& Hour::getMaxHours() const
{
	return MAX_HOURS;
}

void Hour::setHours(const size_t& hours)
{
	if (hours < MAX_HOURS-1) {
		this->hours = hours;
	}
	else {
		this->hours = (hours % MAX_HOURS);
	}
}

void Clock24::tick()
{
		seconds.tick();
		if (seconds.getSeconds() == 0) {
			minutes.tick();
			if (minutes.getMinute() == 0) {
				hours.tick();

			}
		}
		
}

const void Clock24::print() const
{
	std::cout << hours.getHours() << ":" << minutes.getMinute() << ":" << seconds.getSeconds();
}

const size_t Clock24::getHours() const
{
	return hours.getHours();
}

const size_t Clock24::getMinute() const
{
	return minutes.getMinute();
}

const size_t Clock24::getSeconds() const
{
	return seconds.getSeconds();
}

Clock24::Clock24(const size_t& hours, const size_t& minutes, const size_t& seconds) {
	setTime(hours, minutes, seconds);
}

void Clock24::setTime(const size_t& hours, const size_t& minutes, const size_t& seconds)
{
	this->hours.setHours(hours);
	this->minutes.setMinute(minutes);
	this->seconds.setSeconds(seconds);
}
