#pragma once
#include"Word.h"
class Parser
{
public:
	static Word* Parse(std::string EN, std::string RU) {
		if (!EN.empty() && !RU.empty()) {
			return new  Word(EN, RU);
		}
		throw  std::exception("bad value");
	}
};

