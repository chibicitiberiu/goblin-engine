#include "DebugHandlers.h"
#include <Windows.h>

namespace Goblin
{
	void WinAPIDebugHandler::write(std::string info)
	{
		OutputDebugStringA(info.c_str());
	}

	void StdOutDebugHandler::write(std::string info)
	{
		printf(info.c_str());
	}

	ConsoleDebugHandler::ConsoleDebugHandler(ConsoleWindow* wind)
		: window(wind)
	{
		assert(wind != NULL);
	}

	void ConsoleDebugHandler::write(std::string info)
	{
		this->window->addText(info);
	}
}