#pragma once
#include "model-data.h"
#include <string>

namespace Rubin
{
	class IModelParser
	{
		virtual ~IModelParser() = default;
		virtual ModelData ParseModel(const std::string source) = 0;
	};
}