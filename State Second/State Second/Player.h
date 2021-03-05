#pragma once
#include<iostream>
#include<vector>

class Player;
class State abstract
{
protected:

	Player* player;
public:

	State(Player* player);
	virtual void clickLock() = 0;
	virtual void clickPlay() = 0;
	virtual void clickNext() = 0;
	virtual void clickPrevious() = 0;
};

class Player
{
public:
	Player();

	void changeState(State * state);
	void clickLock();
	void clickPlay();
	void clickNext();
	void clickPrevious();
	void startPlayback();
	void stopPlayback();
	void nextSong();
	void previousSong();
	void fastForward();
	void rewind();
	size_t volume;
	std::vector<std::string> playlist{"song","song2","song3","song4","song5","song6","song7","song8","song9","song10"};
	size_t indexCurrentSong;
private:
	State* state;
};

class ReadyState : public State
{
public:
	ReadyState(Player* player);
	void clickLock();
	void clickPlay();
	void clickNext();
	void clickPrevious();
};

class PlayingState : public State
{
public:
	PlayingState(Player* player);
	void clickLock();
	void clickPlay();
	void clickNext();
	void clickPrevious();
};

class LockedState : public State
{
public:
	LockedState(Player* player);
	void clickLock();
	void clickPlay();
	void clickNext();
	void clickPrevious();
};
