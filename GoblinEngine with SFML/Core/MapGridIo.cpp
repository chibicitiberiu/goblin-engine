#include "MapGridIo.h"

namespace Goblin
{

	MapGridIo::MapGridIo(void)
		: mode(None)
	{
	}

	MapGridIo MapGridIo::open(std::string filename)
	{
		MapGridIo io;

		// Open file in read mode
		//io.file.open(filename, std::ios::in);
		io.mode = Read;

		//if (!io.file) // Failed to open
			throw 0;

		// Done
		return io;
	}

	MapGridIo MapGridIo::create(std::string filename)
	{
		return MapGridIo();
	}


	MapGridIo::~MapGridIo(void)
	{
		//file.close();
	}

}