#include "Brokers.h"

void CourseDolars::subscribe(ISubscriber* subscriber)
{
	if (subscriber != nullptr) {
		brokers.push_back(subscriber);
		return;
	}
	throw std::exception("was transsfered nullptr");
}

bool  CourseDolars::unsubscribe(ISubscriber* subscriber)
{
	auto it = std::find(brokers.begin(), brokers.end(), subscriber);
	if (it != brokers.end()) {
		brokers.erase(it);
		return true;
	}
	return false;
}

void CourseDolars::notifySubscriber(StateCourse state)
{
	for (auto& i : brokers)
	{
		i->update(state);
	}
}

void CourseDolars::setCourse(const float& course)
{
	if (course > 0) {
		if (course > this->course) {
			notifySubscriber(StateCourse::UP);
		}
		else if (course < this->course) {
			notifySubscriber(StateCourse::DOWN);
		}
	}
	this->course = course;
}



void Broker::update(CourseDolars::StateCourse state)
{
	if (state == CourseDolars::StateCourse::DOWN) {
		std::cout << "Brokers buy dollars";
	}
	else if (state == CourseDolars::StateCourse::UP) {
		std::cout << "Brokers sell dollars";
	}
}
