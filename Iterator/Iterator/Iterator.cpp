#include "Iterator.h"

TVshow::TVshow(const std::string& name, const size_t& hour)
{
	setName(name);
	setHour(hour);
}

void TVshow::setHour(const size_t& hour)
{
	if (hour >= 0&& hour < 24) {
		this->hour = hour;
	}
}

void TVshow::setName(const std::string& name)
{
	if (!name.empty()) {
		this->name = name;
	}
}

const std::string& TVshow::getName() const
{
	return name;
}

const size_t& TVshow::getHour() const
{
	return hour;
}

const void TVshow::print() const
{
	std::cout << "Name : " << name <<" hour : "<<hour<<std::endl;
}

Iterator* programTVshow::CreateIterator(TypeIterator iterator)
{
	if (iterator == TypeIterator::EVENING) {
		return new IteratorTVshowEvening(this);
	}
	else if (iterator == TypeIterator::FULL) {
		return new IteratorTVshow(this);
	}
}

std::vector<TVshow*> programTVshow::getList() const
{
	return list_tvShow;
}

void programTVshow::addShow(TVshow* show)
{
	if (show) {
		list_tvShow.push_back(show);
	}
}

IteratorTVshow::IteratorTVshow(programTVshow* program)
{
	this->collection = program->getList();
}

 TVshow* IteratorTVshow::getNext()
{
	if (this->hasMore()) {
		return collection[index++];
	}
}

const bool IteratorTVshow::hasMore() const
{
	 if (index < collection.size()) {
		return true;
	}
	return false;
}

TVshow* IteratorTVshowEvening::getNext()
{
	if (this->hasMore()) {
		return collection[index++];
	}
}

const bool IteratorTVshowEvening::hasMore() const
{
	 if (index < collection.size()) {
		return true;
	}
	return false;
}

const void Viwer::viewAllShow() 
{
	Iterator* iterator = collection->CreateIterator(programTVshow::TypeIterator::FULL);
	TVshow* show;
	 while (iterator->hasMore())
	 {
		 show = iterator->getNext();
		 show->print();
	 }

}

const void Viwer::viewEveningShow()
{
	Iterator* iterator = collection->CreateIterator(programTVshow::TypeIterator::EVENING);
	TVshow* show;
	while (iterator->hasMore())
	{
		show = iterator->getNext();
		show->print();
	}
}
