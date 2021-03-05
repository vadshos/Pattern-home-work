#include <iostream>
#include"Sort_Vector.h"

int main()
{
	Sort_Vector v(new SortByLength(), { "Asdf","bsdfh" });
	v.sort();
	v.print();
}