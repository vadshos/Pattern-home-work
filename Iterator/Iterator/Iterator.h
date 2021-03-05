#pragma once
#include<iostream>
#include<vector>

class TVshow {
public:
	TVshow(const std::string& name, const size_t& hour);
	void setHour(const size_t& hour);
	void setName(const std::string& name);
	const std::string& getName() const;
	const size_t& getHour() const;
	const void print() const;
private:
	std::string name;
	size_t hour;
};

__interface Iterator
{
	TVshow* getNext();
	const bool hasMore() const;
};

__interface IterableCollection
{
	enum class TypeIterator { FULL, EVENING };
	Iterator* CreateIterator(TypeIterator iterator);
};

class programTVshow : public IterableCollection
{
public:
	Iterator* CreateIterator(TypeIterator iterator);
	std::vector<TVshow*> getList() const;
	void addShow(TVshow* show);
private:
	std::vector<TVshow*> list_tvShow;
};
class IteratorTVshow : public Iterator
{
public:
	IteratorTVshow(programTVshow* program);
	TVshow* getNext();
	const bool hasMore() const;
private:
	size_t index;
	std::vector<TVshow*> collection;
};

class IteratorTVshowEvening : public Iterator
{
public:
	IteratorTVshowEvening(programTVshow* program)
	{
		for (auto& i : program->getList())
		{
			if (i->getHour() > 17) {
				collection.push_back(i);
			}
		}
	}
    TVshow* getNext();
	const bool hasMore() const;
private:
	size_t index = 0;
	std::vector<TVshow*> collection;
};


class Viwer
{
public:
	Viwer(IterableCollection* collection) {
		if (collection) {
			this->collection = collection;
		}
	}
	const void viewAllShow() ;
	const void viewEveningShow();
private:
	IterableCollection* collection;
};