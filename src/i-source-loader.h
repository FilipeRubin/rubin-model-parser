#pragma once
#include <string>

namespace Rubin
{
	class ISourceLoader
	{
	public:
		virtual ~ISourceLoader() = default;
		virtual bool TryLoadSourceContent(std::string& out_sourceContent) = 0;
	};
}
