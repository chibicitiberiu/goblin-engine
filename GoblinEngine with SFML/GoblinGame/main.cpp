#include "../Engine/Application.h"
#include "../Core/DebugStream.h"
#include <iostream>

int main()
{
	// Redirect stdout and stderr, we won't be able to show on the screen anyway
	FILE* stream;
	freopen_s(&stream, "stdout.log", "w", stdout);
	freopen_s(&stream, "stderr.log", "w", stderr);

	// Run game
	Goblin::Application app;
	
	try {
		app.main();
	}

	catch (Goblin::Exception& ex)
	{
		Goblin::debug<<"! PANIC: Unhandled exception!\n";
		Goblin::debug<<ex.toString()<<"\n";
	}

	return 0;
}