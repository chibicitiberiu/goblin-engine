#pragma once
#include "Build.h"
#include <string>

/// <summary>Creates an instance of exception_class, with source file and line.</summary>
/// <param name="exception_class">The exception class.</param>
/// <param name="message">The exception message.</param>
#define EXCEPTION(exception_class,message) exception_class(message,__FILE__,__LINE__)

namespace Goblin
{
	/// <summary>Base exception class.</summary>
	class DLLEXPORT Exception
	{
	private:
		std::string* msg;
		std::string* src_file;
		unsigned int line;

	public:

	// Constructors, destructor
		/// <summary>Constructor.</summary>
		/// <param name="message">The exception message.</param>
		Exception(std::string message);

		/// <summary>Constructor.</summary>
		/// <param name="message">The exception message.</param>
		/// <param name="source_file">Source file where the exception originated.</param>
		/// <param name="line">The line on which the exception was thrown.</param>
		Exception(std::string message, std::string source_file, unsigned int line);

		/// <summary>Destructor.</summary>
		virtual ~Exception(void);

	// Getters
		/// <summary>Gets the line on which the exception was thrown.</summary>
		/// <returns>The line on which the exception was thrown.</returns>
		virtual unsigned int getLine() const;

		/// <summary>Gets the exception message.</summary>
		/// <returns>The exception message.</returns>
		virtual std::string getMessage() const;

		/// <summary>Gets source file where the exception originated.</summary>
		/// <returns>The source file where the exception originated.</returns>
		virtual std::string getSourceFile() const;

		/// <summary>Convert this exception into a string representation.</summary>
		/// <returns>A string that represents the string representation of this exception.</returns>
		virtual std::string toString() const;

	};
}