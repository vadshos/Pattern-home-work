#include "TrafficLights.h"

TrafficLights::TrafficLights()
{
	state = Color::RED;
	color = new Red(this);
}

void TrafficLights::on()
{
	while (true)
	{
		print();
		Sleep(15000);
		system("cls");
		changeState();
	}
}

void TrafficLights::changeState()
{
	color->changeState();
}

void TrafficLights::setState(IColor* color)
{
	this->color = color;
}

const void TrafficLights::print() const
{
	std::vector<std::string> c { "RED", "YELLOW", "GREEN" };
	std::cout << c[(int)state];

}

void TrafficLights::setColor(Color state)
{
	this->state = state;
}

Green::Green(TrafficLights* trafficLights) : IColor(trafficLights)
{
}

void Green::changeState()
{
	trafficLights->setColor(TrafficLights::Color::RED);
	trafficLights->setState(new Red(trafficLights));

}

Yellow::Yellow(TrafficLights* trafficLights) :IColor(trafficLights)
{
}

void Yellow::changeState()
{
	trafficLights->setColor(TrafficLights::Color::GREEN);
	trafficLights->setState(new Green(trafficLights));

}

Red::Red(TrafficLights* trafficLights) : IColor(trafficLights)
{
}

void Red::changeState()
{
	trafficLights->setColor(TrafficLights::Color::YELLOW);
	trafficLights->setState(new Yellow(trafficLights));

}

IColor::IColor(TrafficLights* trafficLights) 
{
	if (trafficLights) {
		this->trafficLights = trafficLights;
	}
}

void IColor::setTrafficLigth(TrafficLights* trafficLights)
{
	this->trafficLights = trafficLights;
}
