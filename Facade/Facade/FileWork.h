#pragma once
#include"CollectionWord.h"
#include"Parser.h"


#include<string>
#include<fstream>

class FileWork
{
public:
	static CollectionWord* Load(const std::string FileName) {
		std::ifstream load(FileName);
		if (load.is_open())
		{
		CollectionWord colection;
		 while (load.eof())
		 {
			 std::string RU;
			 std::string EN;
			 getline(std::cin,RU);
			 getline(std::cin,EN);
			 colection.addWord(Parser::Parse(EN, RU));
		 }
		return &colection;
		}
		throw std::exception("bad name file");
	}
	static bool Write(const std::string FileName, CollectionWord* colection) {
		std::ofstream write(FileName);
		if (write.is_open())
		{
				int index = 0;
				for (auto& i : colection->getVector())
				{
					write << i->getRU();
					write << i->getEN();
				}
			return true;
		}
		return false;

	}
};

