#pragma once
#include<iostream>
#include<vector>


class ItemFS abstract
{
public:
	ItemFS(const std::string& name, const size_t& size);
	void setSize(const std::size_t& size);
	void setName(const std::string& name);
	virtual const size_t getSize() const;
	virtual const std::string& getName() const;
	const bool operator==(const ItemFS* item) const;

protected:
	size_t size;
	std::string name;
};

class File : public ItemFS
{
public:
	void print();
	File(const std::string& name, const size_t& size);
	friend std::ostream& operator<<(std::ostream& os, const File& item);
private:
};

class Folder : public ItemFS
{
public:
	Folder(const std::string& name);
	void add(ItemFS* item);
	void remove(const std::string& name);
	const void print() const;
	ItemFS* getItem(const size_t& index);
	friend std::ostream& operator<<(std::ostream& os,const Folder& item);
private:
	std::vector<ItemFS*> list_Object;
};


