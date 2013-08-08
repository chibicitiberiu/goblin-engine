#pragma once
#include <typeinfo>
#include <string>
#include <cstdint>

namespace Goblin
{

	class Serializable
	{
	public:

		/// <summary>Serializes the current instance of this object.</summary>
		/// <param name="data">[out] The serialized bytes.</param>
		virtual void serialize(std::vector<uint8_t>& data) = 0;

		/// <summary>Deserializes the given data in the current instance of this object.</summary>
		/// <param name="data">The serialized bytes.</param>
		virtual void deserialize(std::vector<uint8_t> data) = 0;
	};

}