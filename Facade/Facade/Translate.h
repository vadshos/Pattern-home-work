#pragma once
#include"CollectionWord.h"
class TranslateSystem
{
public:
	const std::string EnToRU(std::string word) {
		return Words->getTranslate(word);
   }
	const std::string RUToEn(std::string word) {
		return Words->getTranslate(word);
	}
	void setLib(CollectionWord* Words) {
		if (Words) {
			this->Words = Words;
		}
		else {
			throw std::exception("bad value");
		}
	}
private:
	CollectionWord* Words;
};

