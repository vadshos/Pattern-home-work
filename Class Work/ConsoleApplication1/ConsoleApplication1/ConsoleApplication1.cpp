#include <iostream>
#include"Folder_Tree.h"

int main()
{
	Folder folder("New folder");
	folder.add(new File("txt.txt", 5));
	Folder* f = new Folder("txt.txt");
	f->add(new File("file.txt", 5));
	folder.add(f);
	std::cout << folder << std::endl;
	ItemFS* item = folder.getItem(1);
	std::cout << dynamic_cast<Folder&> (*item) << std::endl;

}