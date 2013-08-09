#include "../Engine/Application.h"
#include <iostream>

int main()
{
	FILE* stream;
	freopen_s(&stream, "stdout.txt", "w", stdout);
	freopen_s(&stream, "stderr.txt", "w", stderr);
	
	std::cout<<"This should go to stdout.txt.\n";
	std::cerr<<"This should go to stderr.txt.\n";

	Goblin::Application app;

	return app.main();
}