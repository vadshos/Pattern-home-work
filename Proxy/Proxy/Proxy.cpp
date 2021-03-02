#include <iostream>

#include"Door.h"
#include "Proxy.h"

int main()
{
	SecureProxy secure(new Door());
	secure.close();
	secure.open("Petro", "12345");

}
