#include "file-source-loader.h"
#include <fstream>
#include <sstream>

Rubin::FileSourceLoader::FileSourceLoader(const std::string& filePath) :
    m_filePath(filePath)
{
}

bool Rubin::FileSourceLoader::TryLoadSourceContent(std::string& out_sourceContent)
{
    std::ifstream file = std::ifstream(m_filePath);

    if (not file.is_open())
    {
        return false;
    }

    std::stringstream contentStream;
    std::string line;
    while (getline(file, line))
    {
        contentStream << line << '\n';
    }

    file.close();

    out_sourceContent = contentStream.str();

    return true;
}
