#pragma once
#include <typeinfo>
#include <string>
#include <cstdint>
#include "Build.h"

namespace Goblin
{

	class DLLEXPORT ISerializable
	{
	public:

		/// <summary>Serializes the current instance of this object.</summary>
		/// <param name="data">[out] The serialized bytes.</param>
		virtual void serialize(std::vector<uint8_t>& data) = 0;

		/// <summary>Deserializes the given data in the current instance of this object.</summary>
		/// <param name="data">The serialized bytes.</param>
		virtual void deserialize(const std::vector<uint8_t>& data) = 0;
	};

}