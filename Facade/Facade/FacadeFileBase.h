#pragma once
#include"FileWork.h"
#include"Translate.h"



class FacadeFileBase
{
public:
	FacadeFileBase()
	{
		words =  FileWork::Load("word.h");
		translateSystem.setLib(words);
	}
	enum TranslateType
	{
		EnToRU,RuToEn

	};
	void translate(const std::string& word,TranslateType type) {
		std::string translate;
		if(type == TranslateType::EnToRU)
		    translate = translateSystem.EnToRU(word);
		else if (type == TranslateType::RuToEn) {
			 translate = translateSystem.RUToEn(word);
		}
		if (translate.empty()) {
			std::cout << "Translate to word " << word << "does found" << std::endl;
		}
		else {
			std::cout << word << " - " << translate << std::endl;
		}
	}
	void addWord(std::string EN, std::string RU) {
		try {
			words->addWord(Parser::Parse(EN, RU));
		}
		catch (std::exception ex) {
			std::cout << ex.what() << std::endl;
		}
	}
	void deleteWord(const std::string& word) {
		try {
			words->deleteWord(word);
		}
		catch (std::exception ex) {
			std::cout << ex.what() << std::endl;
		}
	}
	~FacadeFileBase()
	{
		FileWork::Write("word.h", words);
	}
private:
		TranslateSystem translateSystem;
		CollectionWord* words;
};

