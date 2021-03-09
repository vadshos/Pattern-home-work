#pragma once
#include"Word.h"
#include<vector>
class CollectionWord
{
public:
	void addWord(Word* word) {
		if (word) {
			words.push_back(word);
		}
	}
	void deleteWord(const std::string word) {
		auto it = std::find(words.begin(), words.end(), new Word(word, word));

		if (it != words.end()) {
			words.erase(it);
		}else{
			throw std::exception("word dind't find");

		}
	}
	const std::string& getTranslate(const std::string word) {
	
		auto it = std::find(words.begin(), words.end(),new Word(word,word));
		if (it != words.end()) {
			Word* w = *it;
			if (w->getRU() == word) {
				return w->getEN();
			}
			return w->getRU();
		}
		throw std::exception("word dind't find");
	}
	std::vector<Word*> getVector() {
		return words;
	}
private:
	std::vector<Word*> words;
};

