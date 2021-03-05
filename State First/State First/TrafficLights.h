#pragma once
#include<iostream>
#include<vector>
#include"windows.h"
class IColor;
class TrafficLights
{
public:
	TrafficLights();
	void on();
	enum class Color{RED,YELLOW,GREEN};
	void changeState();
	void setState(IColor* color);
	const void print() const;
	void setColor(Color state);
private:
	Color state;
	IColor* color;
};

class IColor abstract
{
public:
	IColor(TrafficLights* trafficLights);
	void setTrafficLigth(TrafficLights* trafficLights);
	virtual void changeState()  abstract;
public:
	TrafficLights* trafficLights;
};

class Green : public IColor
{
public:
	Green(TrafficLights* trafficLights);
	virtual void changeState();

};

class Yellow : public IColor
{
public:
	Yellow(TrafficLights* trafficLights);
	virtual void changeState();

};

class Red : public IColor
{
public:
	Red(TrafficLights* trafficLights);
	virtual void changeState();

};