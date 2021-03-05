#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

__interface ISort {
	std::vector<std::string> sort(std::vector<std::string> v);
};

class SortByABC : public ISort {
public:
	std::vector<std::string> sort(std::vector<std::string> v);

};
class SortByLength : public ISort {
public:
	std::vector<std::string> sort(std::vector<std::string> v);

};
class Sort_Vector
{
public:
	Sort_Vector(ISort* Sort, const std::vector<std::string> v);
	void sort();
	void print();
	const std::vector<std::string> get()const ;
	void set(std::vector<std::string> v);
private:
	ISort* Sort;
	std::vector<std::string> v;
};

