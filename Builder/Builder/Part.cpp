#include "Part.h"

PlasticWindows::PlasticWindows(const size_t price, const std::string& name) : Windows(price,name)
{
    this->name = name;
}


Part::Part(const size_t& price, const std::string& name  )
{
    if (price > 0) {
        this->price = price;
    }
    if (!name.empty()) {
        this->name = name;
    }
}

const size_t& Part::getPrice() const
{
    return price;
}

const std::string& Part::getName() const
{
    return name;
}

Windows::Windows(const size_t& price, const std::string& name) : Part(price,name)
{
}

WoodWindows::WoodWindows(const size_t price, const std::string& name) : Windows(price,name)
{
}

Door::Door(const size_t& price, const std::string& name) : Part(price,name)
{
}

PlasticDoor::PlasticDoor(const size_t price, const std::string& name) : Door(price,name)
{
}

WoodDoor::WoodDoor(const size_t price, const std::string& name) : Door(price,name)
{
}

MetalDoor::MetalDoor(const size_t price, const std::string& name) : Door(price,name)
{
}

Foundation::Foundation(const size_t& price, const std::string& name) :Part(price,name)
{
}

SlabFoundation::SlabFoundation(const size_t price, const std::string& name) : Foundation(price,name)
{
}

FieldFoundation::FieldFoundation(const size_t price, const std::string& name) : Foundation(price,name)
{
}

Wall::Wall(const size_t& price, const std::string& name)  :Part(price,name)
{
}

BrickWall::BrickWall(const size_t price, const std::string& name) :Wall(price,name)
{
}

PanelWall::PanelWall(const size_t price, const std::string& name) : Wall(price,name)
{
}

Roof::Roof(const size_t& price, const std::string& name) : Part(price,name)
{
}

StateRoof::StateRoof(const size_t price, const std::string& name) : Roof(price,name)
{
}

MetalRoof::MetalRoof(const size_t price, const std::string& name) : Roof(price,name)
{
}
