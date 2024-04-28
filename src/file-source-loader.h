#pragma once
#include "i-source-loader.h"

namespace Rubin
{
	class FileSourceLoader : public ISourceLoader
	{
	public:
		FileSourceLoader(const std::string& filePath);
		bool TryLoadSourceContent(std::string& out_sourceContent) override;
	private:
		std::string m_filePath;
	};
}
