#include "Player.h"

Player::Player()
{
	state = new LockedState(this);
}

void Player::changeState(State* state)
{
	if (state != nullptr) {
		this->state = state;
	}
}

void Player::clickLock()
{
	state->clickLock();
}

void Player::clickPlay()
{
	state->clickPlay();
}

void Player::clickNext()
{
	state->clickNext();
}

void Player::clickPrevious()
{
	state->clickPrevious();
}

void Player::startPlayback()
{
	clickPlay();
}

void Player::stopPlayback()
{
	clickLock();
}

void Player::nextSong()
{
	clickNext();
}

void Player::previousSong()
{
	clickPrevious();
}

void Player::fastForward()
{
	clickNext();
}

void Player::rewind()
{
	clickPrevious();
}

ReadyState::ReadyState(Player* player) : State(player)
{
}

void ReadyState::clickLock()
{
	player->changeState(new LockedState(player));
}

void ReadyState::clickPlay()
{
	player->indexCurrentSong = 0;
	player->changeState(new LockedState(player));

}

void ReadyState::clickNext()
{
	clickPlay();
}

void ReadyState::clickPrevious()
{
	clickPlay();
}

State::State(Player* player) 
{
	this->player = player;
}



PlayingState::PlayingState(Player* player) : State(player)
{
}

void PlayingState::clickLock()
{
	player->changeState(new LockedState(player));
}

void PlayingState::clickPlay()
{
	player->changeState(new ReadyState(player));

}

void PlayingState::clickNext()
{
	if (player->indexCurrentSong != player->playlist.size() -1) {
		++player->indexCurrentSong;
	}
	else {
		player->indexCurrentSong = 0;
	}
}

void PlayingState::clickPrevious()
{
	if (player->indexCurrentSong != 0) {
		++player->indexCurrentSong;
	}
	else {
		player->indexCurrentSong = player->playlist.size() - 1;
	}
}

LockedState::LockedState(Player* player) : State(player)
{

}

void LockedState::clickLock()
{
	std::cout << "Player is locked please press play" << std::endl;

}

void LockedState::clickPlay()
{
	player->changeState(new PlayingState(player));
}

void LockedState::clickNext()
{
	std::cout << "Player is locked please press play" << std::endl;
}

void LockedState::clickPrevious()
{
	std::cout << "Player is locked please press play" << std::endl;
}
