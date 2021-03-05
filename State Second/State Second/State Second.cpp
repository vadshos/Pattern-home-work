#include <iostream>
#include"Player.h"

int main()
{
	Player player;
	player.clickPlay();
	player.clickNext();
	std::cout << player.playlist[player.indexCurrentSong]<<std::endl;
	player.clickLock();
	player.clickNext();

}


