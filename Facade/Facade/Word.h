#pragma once
#include<iostream>

class Word
{
public:
	Word(const std::string& EN, const std::string& RU) {
		setEN(EN);
		setRU(RU);
	}
	void setEN(const std::string EN) {
		if (!EN.empty()) {
			this->EN = EN;
		}
	}
	void setRU(const std::string RU) {
		if (!RU.empty()) {
			this->RU = RU;
		}
	}
	const std::string& getEN() const {
		return EN;
	}
	const std::string& getRU() const {
		return RU;
	}
	bool operator== (const Word w) {
		if (this->EN == w.EN|| this->RU == w.RU) {
			return true;
		}
		return false;
	}
private :
	std::string EN;
	std::string RU;
};

