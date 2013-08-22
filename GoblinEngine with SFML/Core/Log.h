#pragma once
#include <sstream>
#include <vector>
#include <time.h>
#include "IDebugHandler.h"
#include "SmartPtr.h"
#include "Exception.h"

namespace Goblin {

	/// <summary>Internal type. In a debug stream, will be replaced by the current time stamp.</summary>
	class DLLEXPORT _LogTimeStamp
	{
	};

	/// <summary>Internal type. Handles debugging messages.</summary>
	class DLLEXPORT _DebugStream
	{
	private:
		typedef std::vector<SmartPtr<IDebugHandler>> DebugHandlerVector;
		DebugHandlerVector* handlers;

	public:

		/// <summary>Default constructor.</summary>
		_DebugStream()
		{
			handlers = new DebugHandlerVector();
		}

		/// <summary>Destructor.</summary>
		~_DebugStream()
		{
			delete handlers;
		}

		/// <summary>Adds a debug handler.</summary>
		/// <param name="handler">The debug handler.</param>
		/// <exception cref="AssertionFailedException">Thrown if handler is NULL.</exception>
		void addHandler(SmartPtr<IDebugHandler> handler)
		{
			ASSERT(handler.ptr() != NULL, "Handler cannot be null!");
			handlers->push_back(handler);
		}

		/// <summary>Writes debugging information to the stream.</summary>
		/// <param name="t">The debugging information.</param>
		template <typename T>
		_DebugStream& operator<< (const T& t)
		{
			std::stringstream str;
			str<<t;

			for (auto it = handlers->begin(); it != handlers->end(); it++)
			{
				(*it)->write(str.str());
			}

			return *this;
		}

		/// <summary>Writes debugging information to the stream (log time stamp).</summary>
		/// <param name="t">The time stamp object.</param>
		template <>
		_DebugStream& operator<< <_LogTimeStamp> (const _LogTimeStamp& _unused)
		{
			// Get current time
			time_t t = time(NULL);

			// Get time structure
			struct tm t_struct;
			localtime_s(&t_struct, &t);

			// Get text representation
			char buffer[256];
			strftime(buffer, 256, "[%Y-%m-%d %H:%M:%S] ", &t_struct);
		
			// Output
			return (*this)<<buffer;
		}
	};

	/// <summary>Debugging stream</summary>
	extern DLLEXPORT _DebugStream debug;

	/// <summary>A constant which will be replaced by a log time stamp.</summary>
	extern DLLEXPORT _LogTimeStamp log;
}