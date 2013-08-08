#pragma once
#include <fstream>
#include <cstdint>
#include "Build.h"

namespace Goblin
{

	class DLLEXPORT MapGridIo
	{
	public:
		enum OpenMode {
			None, Read, Write
		};

	private:

		struct Header {

			int8_t identifier[8];
			uint32_t cellsX, cellsY;

		};

		// std::fstream file;
		OpenMode mode;

		
	public:
		MapGridIo();

		static MapGridIo open(std::string filename);
		static MapGridIo create(std::string filename);

		virtual ~MapGridIo(void);
	};

}