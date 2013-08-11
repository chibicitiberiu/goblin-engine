#pragma once
#include "../Core/IDebugHandler.h"
#include "../Gui/ConsoleWindow.h"

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
		Gui::ConsoleWindow* window;

	public:
		ConsoleDebugHandler(Gui::ConsoleWindow* wind);

		virtual void write(std::string info);
	};
}