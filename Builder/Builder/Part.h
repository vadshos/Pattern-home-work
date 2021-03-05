#pragma once
#include<iostream>

class Part abstract
{
public:
	Part(const size_t& price, const std::string& name);
	virtual const size_t& getPrice() const;
	virtual const std::string& getName() const;
protected:
	size_t price;
	std::string name;

};


class Windows abstract  : public Part
{
public:
	Windows(const size_t& price, const std::string& name) ;
};

class PlasticWindows : public Windows
{
public:
	PlasticWindows(const size_t price = 3600, const std::string& name = "plastic windows");
};

class WoodWindows : public Windows
{
public:
	WoodWindows(const size_t price = 1200, const std::string& name = "wood windows");
};


class Door abstract : public Part
{
public:
	Door(const size_t& price, const std::string& name);
};

class PlasticDoor : public Door
{
public:
	PlasticDoor(const size_t price = 4800, const std::string& name = "plastic door");
};

class WoodDoor : public Door
{
public:
	WoodDoor(const size_t price = 4200, const std::string& name = "wood door");
};

class MetalDoor : public Door
{
public:
	MetalDoor(const size_t price = 8100, const std::string& name = "metal door");
};


class Foundation abstract : public Part
{
public:
	Foundation(const size_t& price, const std::string& name);
};

class SlabFoundation : public Foundation
{
public:
	SlabFoundation(const size_t price = 124800, const std::string& name = "slab foundations");
};

class FieldFoundation : public Foundation
{
public:
	FieldFoundation(const size_t price = 104200, const std::string& name = "field foundation");
};


class Wall abstract : public Part
{
public:
	Wall(const size_t& price, const std::string& name);
};

class BrickWall : public Wall
{
public:
	BrickWall(const size_t price = 20300, const std::string& name = " brick wall");
};

class PanelWall : public Wall
{
public:
	PanelWall(const size_t price = 12800, const std::string& name = " panel wall");
};


class Roof abstract : public Part
{
public:
	Roof(const size_t& price, const std::string& name);
};

class StateRoof : public Roof
{
public:
	StateRoof(const size_t price = 87300, const std::string& name = " brick wall");
};

class MetalRoof : public Roof
{
public:
	MetalRoof(const size_t price = 156400, const std::string& name = " panel wall");
};