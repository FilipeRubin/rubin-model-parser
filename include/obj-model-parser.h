#pragma once
#include "i-model-parser.h"

namespace Rubin
{
	class OBJModelParser : public IModelParser
	{
	public:
		ModelData ParseModel(const std::string source) override;
	private:

	};
}