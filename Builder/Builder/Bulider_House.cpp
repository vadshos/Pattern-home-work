#include "Bulider_House.h"

void House::setWindows(Part* windows)
{
	if (windows != nullptr) {
		list_part.push_back(windows);
		setPrice(getPrice() + windows->getPrice());

	}
}

void House::setDoor(Part* door)
{
	if (door != nullptr) {
		list_part.push_back(door);
		setPrice(getPrice() + door->getPrice());

	}
}

void House::setRoof(Part* roof)
{
	if (roof != nullptr) {
		list_part.push_back(roof);
		setPrice(getPrice() + roof->getPrice());

	}
}

void House::setFoundation(Part* foundation)
{
	if (foundation != nullptr) {
		list_part.push_back(foundation);
		setPrice(getPrice() + foundation->getPrice());

	}
}

void House::setWall(Part* wall)
{
	if (wall != nullptr) {
		list_part.push_back(wall);
		setPrice(getPrice() + wall->getPrice());

	}
}

void House::setPrice(const size_t price)
{
	if (price >= 0) {
		this->price = price;
	}
}

const size_t House::getPrice() const
{
	return price;
}

const void House::print() const
{
	std::vector<std::string> name{"Door","Wall","Foundation","Roof","Windows"};
	size_t index = 0;
	for (auto& i : list_part)
	{
		std::cout << name[index]<<" : " << i->getName() << " price : " << i->getPrice() << std::endl;
		++index;
	}
	std::cout << "Total price : " << getPrice()<<std::endl;
}

void Builder_House::reset()
{
	house = new House();
}

void Builder_House::setWindows(WindowsEnum windows)
{

	if (windows == WindowsEnum::PLASTIC) {
		house->setWindows(new PlasticWindows());
		
	}
	else if (windows == WindowsEnum::WOOD) {
		house->setWindows(new WoodWindows());
	}

}

void Builder_House::setDoor(DoorEnum door)
{
	if (door == DoorEnum::PLASTIC) {
		house->setDoor(new PlasticDoor());

	}
	else if (door == DoorEnum::WOOD) {
		house->setDoor(new WoodDoor());
	}
	else if (door == DoorEnum::METAL) {
		house->setDoor(new MetalDoor());
	}
}

void Builder_House::setRoof(RoofEnum roof)
{
	if (roof == RoofEnum::STATE) {
		house->setRoof(new StateRoof());

	}
	else if (roof == RoofEnum::METAL) {
		house->setRoof(new MetalRoof());
	}
	
}

void Builder_House::setFoundation(FoundationEnum foundation)
{
	if (foundation == FoundationEnum::FIELD) {
		house->setFoundation(new FieldFoundation());

	}
	else if (foundation == FoundationEnum::SLAB) {
		house->setFoundation(new SlabFoundation());
	}
}

void Builder_House::setWall(WallEnum wall)
{
	if (wall == WallEnum::BRICK) {
		house->setWall(new BrickWall());

	}
	else if (wall == WallEnum::PANEL) {
		house->setWall(new PanelWall());
	}
}

House* Builder_House::getResult()
{
	return house;
}

void Director::makeCheapHouse(IBuilder* builder)
{
	builder->reset();
	builder->setDoor(IBuilder::DoorEnum::WOOD);
	builder->setWall(IBuilder::WallEnum::PANEL);
	builder->setFoundation(IBuilder::FoundationEnum::SLAB);
	builder->setRoof(IBuilder::RoofEnum::STATE);
	builder->setWindows(IBuilder::WindowsEnum::WOOD);

}

void Director::makeReachHouse(IBuilder* builder)
{
	builder->reset();
	builder->setDoor(IBuilder::DoorEnum::METAL);
	builder->setWall(IBuilder::WallEnum::BRICK);
	builder->setFoundation(IBuilder::FoundationEnum::FIELD);
	builder->setRoof(IBuilder::RoofEnum::METAL);
	builder->setWindows(IBuilder::WindowsEnum::PLASTIC);
}
