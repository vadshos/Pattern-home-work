﻿#pragma once
#include <iostream>
#include <fstream>
#include <vector>


struct Log
{
	enum class Flag { Crunchify_FLAG_DEBUG, Crunchify_FLAG_WARN, Crunchify_FLAG_INFO, Crunchify_FLAG_ERROR, Crunchify_FLAG_FATAL };
	Log(const std::string message = "NO message",Flag flag =Flag::Crunchify_FLAG_DEBUG) {
	    std::vector<std::string> Flag_char{ " ---------- "," ^^^^^^^^^^ "," ********** ", " ########## ", " $$$$$$$$$$ " };
		if (!message.empty() && message.size() < 236) {
			std::string temp = Flag_char[(size_t)flag];
			temp += message;
			temp+= Flag_char[(size_t)flag];
			strcpy_s(this->message, temp.c_str());
		}
	}
	friend std::ostream& operator<<(std::ostream& os, const Log& log) {
		os<< log.message<<std::endl;
		return os;
	};
private:
	char message[256];
};

class Logging
{
private:
	static Logging* instance;
protected:
	Logging() = default;
public:
	void addLog(const Log& log);
	void showLog() const;
	Logging(const Logging&) = delete; // заборона копіювати 
	Logging & operator = (const Logging&) = delete; // заборона присвоювати
	static Logging* getInstance() {

		if (instance == nullptr) {
			instance = new Logging();
		}
		return instance;

	};
	
};







