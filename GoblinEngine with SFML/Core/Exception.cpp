#include "Exception.h"
#include <sstream>

namespace Goblin
{
	Exception::Exception(std::string message)
		: msg(new std::string(message))
	{
	}

	Exception::Exception(std::string message, std::string source_file, unsigned int line)
		: msg(new std::string(message)), src_file(new std::string(source_file)), line(line)
	{
	}

	Exception::~Exception(void)
	{
	}

	std::string Exception::getMessage() const
	{
		return *this->msg;
	}

	std::string Exception::getSourceFile() const
	{
		return *this->src_file;
	}

	unsigned int Exception::getLine() const
	{
		return this->line;
	}

	std::string Exception::toString() const
	{
		std::stringstream s;

		// Have source file info?
		if (*this->src_file != "")
			s<<*this->src_file<<":"<<line<<": ";

		// Write message
		s<<*this->msg;

		// Done
		return s.str();
	}
}