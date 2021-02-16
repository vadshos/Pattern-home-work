#include "Singelton.h"

Logging* Logging::instance = nullptr;

void Logging::addLog(const Log& log)
{

	std::ofstream out("datebase.dat", std::ios_base::binary | std::ios_base::app);
	if (!out)
	{
		std::cerr << "Error opening for writing\n";
		return;
	}

	out.write((char*)&log, sizeof(log));
	out.close();
}

void Logging::showLog() const
{

	std::ifstream in("datebase.dat", std::ios_base::binary);
	if (!in)
	{
		throw std::exception("Error opening file for read");
	}
	Log log;
	size_t index = 0;
	while (in.read((char*)&log, sizeof(log)))
	{
		++index;
		std::cout << index;
		std::cout<<"." << log << std::endl;
	}
}
