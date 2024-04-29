#include "obj-model-parser.h"
#include <array>
#include <vector>
#include <sstream>

using Rubin::ModelData;

ModelData Rubin::OBJModelParser::ParseModel(const std::string source)
{
    // Find positions
	std::istringstream sourceStream = std::istringstream(source);
	std::string line;

	std::vector<std::array<float, 3>> positions;

	while (getline(sourceStream, line))
	{
		if (line.starts_with("v "))
		{
			std::array<char, 10> floatBuffer;
			unsigned int bufferIndex = 0U;

			for (int i = 2; i < line.size(); i++)
			{
				const char& character = line[i];

				if (character != ' ')
				{
					floatBuffer[bufferIndex] = character;
					bufferIndex++;
				}
			}
		}
	}
}
