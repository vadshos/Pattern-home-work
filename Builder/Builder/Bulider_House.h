#pragma once
#include<vector>
#include"Part.h"
class House
{
public:
	void setWindows(Part* windows);
	void setDoor(Part* door);
	void setRoof(Part* roof);
	void setFoundation(Part* foundation);
	void setWall(Part* wall);
	void setPrice(const size_t price);
	const size_t getPrice() const;
	const void print() const;
private:
	size_t price;
	std::vector<Part*> list_part;
};

__interface IBuilder 
{
public:
	void reset();
	enum class DoorEnum { METAL, PLASTIC, WOOD };
	enum class WindowsEnum { PLASTIC, WOOD };
	enum class WallEnum { PANEL, BRICK };
	enum class RoofEnum { STATE, METAL };
	enum class FoundationEnum { FIELD, SLAB };
	void setWindows(WindowsEnum windows);
	void setDoor(DoorEnum door);
	void setRoof(RoofEnum roof);
	void setFoundation(FoundationEnum foundation);
	void setWall(WallEnum wall);
};
class Builder_House :public IBuilder
{

public:
	void reset();
	void setWindows(WindowsEnum windows);
	void setDoor(DoorEnum door);
	void setRoof(RoofEnum roof);
	void setFoundation(FoundationEnum foundation);
	void setWall(WallEnum wall);
	House* getResult();
private:
	House* house;
};

class Director
{
public:
	void makeCheapHouse(IBuilder* builder);
	void makeReachHouse(IBuilder* builder);

};