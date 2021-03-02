#include <iostream>
#include"Device.h"

int main()
{
	Device* tv = new TV();
	Remote* remote = new AdvancedRemote(tv);
	remote->channelUp();
}
