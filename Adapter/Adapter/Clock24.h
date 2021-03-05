#pragma once
#include<iostream>
class Minute {
public:
	Minute(const size_t& minute = 0, const size_t& MAX_MINUTE = 60);
	void tick();
	const size_t& getMinute() const;
	const size_t& getMaxMinute() const;
	void setMinute(const size_t& minute);
private:
	const size_t MAX_MINUTE = 60;
	size_t minute;
};

class Seconds
{
public:
	 Seconds(const size_t& seconds = 0, const size_t& MAX_SECONDS = 60);
	 void tick();
	 const size_t& getSeconds() const;
	 const size_t& getMaxSeconds() const;
	 void setSeconds(const size_t& seconds);
private:
	const size_t MAX_SECONDS = 60;
	size_t seconds;
};

class Hour
{
public:
	Hour(const size_t& hours = 0, const size_t& MAX_HOURS = 24);
	void tick();
	const size_t& getHours() const;
	const size_t& getMaxHours() const;
	void setHours(const size_t& hours);
private:
	const size_t MAX_HOURS = 24;
	size_t hours;
};

class Clock24
{
public:
	Clock24(const size_t& hours = 0, const size_t& minutes = 0, const size_t& seconds = 0);
	void setTime(const size_t& hours, const size_t& minutes, const size_t& seconds);
	void tick();
	const void print() const;
	const size_t getHours() const;
	const size_t getMinute() const;
	const size_t getSeconds() const;
private:
	Seconds seconds;
	Minute minutes;
	Hour hours;
};

