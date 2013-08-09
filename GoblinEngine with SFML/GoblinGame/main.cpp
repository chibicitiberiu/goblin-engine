#include "../Engine/Application.h"
#include <iostream>

int main()
{
	// Redirect stdout and stderr, we won't be able to show on the screen anyway
	FILE* stream;
	freopen_s(&stream, "stdout.log", "w", stdout);
	freopen_s(&stream, "stderr.log", "w", stderr);

	// Run game
	Goblin::Application app;
	return app.main();
}