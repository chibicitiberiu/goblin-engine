#pragma once
#include "../Core/IDebugHandler.h"
#include "ConsoleWindow.h"

namespace Goblin
{
	class DLLEXPORT WinAPIDebugHandler : public IDebugHandler
	{
	public:
		virtual void write(std::string info);
	};

	class DLLEXPORT StdOutDebugHandler : public IDebugHandler
	{
	public:
		virtual void write(std::string info);
	};

	class DLLEXPORT ConsoleDebugHandler : public IDebugHandler
	{
	private:
		GUI::ConsoleWindow* window;

	public:
		ConsoleDebugHandler(GUI::ConsoleWindow* wind);

		virtual void write(std::string info);
	};
}