#pragma once
#include<iostream>
#include<vector>
__interface ISubscriber;
class CourseDolars {
public:
	enum class StateCourse { UP, DOWN };
	void subscribe(ISubscriber* subscriber);
	bool unsubscribe(ISubscriber* subscriber);
	void setCourse(const float& course);
private:
	void notifySubscriber(StateCourse state);
	float course = 0;
	std::vector<ISubscriber*> brokers;
};

__interface ISubscriber {
	virtual void update(CourseDolars::StateCourse state);
};




class Broker : public ISubscriber
{
public:

	virtual void update(CourseDolars::StateCourse state);
};
