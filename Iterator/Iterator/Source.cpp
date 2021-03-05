#include<iostream>
#include"Iterator.h"

int main() {
	programTVshow* program = new programTVshow();
	program->addShow(new TVshow("Program1", 12));
	program->addShow(new TVshow("Program2", 13));
	program->addShow(new TVshow("Program3", 14));
	program->addShow(new TVshow("Program4", 18));
	program->addShow(new TVshow("Program5", 19));
	program->addShow(new TVshow("Program6", 19));
	Viwer viwer(program);
	viwer.viewEveningShow();
	
}