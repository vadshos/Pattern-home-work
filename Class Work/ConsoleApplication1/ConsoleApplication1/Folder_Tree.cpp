#include "Folder_Tree.h"


ItemFS::ItemFS(const std::string& name, const size_t& size) : name(name),size(size)
{
}

void ItemFS::setSize(const std::size_t& size)
{
	if (size >= 0) {
		this->size = size;
	}
}

void ItemFS::setName(const std::string& name)
{
	if (!name.empty()) {
		this->name = name;
	}
}

const std::string& ItemFS::getName() const
{
	return name;
}

const bool ItemFS::operator==(const ItemFS* item) const
{
	return name == item->getName();
}

Folder::Folder(const std::string& name) : ItemFS(name,0)
{
}

void Folder::add(ItemFS* item)
{
	auto it = std::find_if(list_Object.begin(), list_Object.end(), [&item](const ItemFS* itemSecond) {return item->getName() == itemSecond->getName(); });
	if (it != list_Object.end()) {
		std::string type = typeid(*it).name();
		auto it = type.find(typeid(*item).name());
		if (it != std::string::npos) {
			std::cout << typeid(*item).name() + 6 << " with name" << item->getName() << " was added before it create in this folder"<<std::endl;
			return;
		}
	}
	list_Object.push_back(item);
	setSize(item->getSize() + getSize());
}

void Folder::remove(const std::string& name)
{
	File f(name, 0);
	auto it = std::find_if(list_Object.begin(), list_Object.end(), [&f](const ItemFS* item) {return f.getName() == item->getName(); });
	if (it != list_Object.end()) {
		//list_Object.erase(it);
		return;
	}
	std::cout << "Item with this name didn't found" << std::endl;
}

const size_t ItemFS::getSize() const
{
	return size;
}

const void Folder::print() const
{
	std::cout <<getName() << " " << getSize() << std::endl;
}

 ItemFS* Folder::getItem(const size_t& index)
{
	if (index <= list_Object.size()) {

		return list_Object[index];
	}
	throw std::exception("bad Index");
}

std::ostream& operator<<(std::ostream& os, const File& item)
{
	os <<"Name : "<< item.getName() << " | size : " << item.getSize() << std::endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Folder& item)
{
	os <<"Name : " <<item.getName() << " | size : " << item.getSize() <<" Type Folder"<< std::endl;
	for (auto* i : item.list_Object)
	{
		os <<"\t"<< "Name : " << i->getName() << " | size : " << i->getSize() <<"| type : "<<typeid(*i).name()+6<< std::endl;
	}
	return os;
}

void File::print()
{
	std::cout<< "Name : " << getName() << " | size : " << getSize() << std::endl;

}

File::File(const std::string& name, const size_t& size) :ItemFS(name,size)
{
}
