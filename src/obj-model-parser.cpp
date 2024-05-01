#include "obj-model-parser.h"
#include <array>
#include <vector>
#include <sstream>

using Rubin::ModelData;

void FindFloatsInLine(const std::string& line, float* destination, size_t destinationLength)
{
	char floatBuffer[10] = { '\0' };
	unsigned int floatBufferIndex = 0U;

	unsigned int destinationIndex = 0U;

	for (int i = 0; i < line.length(); i++)
	{
		const char& character = line[i];
		const bool& isFloatBufferEmpty = floatBuffer[0] == '\0';
		const bool& isLastCharacter = i == line.length() - 1;
		const bool& isValidNumericCharacter = (character > 47 and character < 58) or character == '-' or character == '.';

		if (isValidNumericCharacter)
		{
			floatBuffer[floatBufferIndex] = character;
			floatBufferIndex++;
		}
		if ((not isValidNumericCharacter or isLastCharacter) and not isFloatBufferEmpty)
		{
			destination[destinationIndex] = std::stof(std::string(floatBuffer));
			destinationIndex++;
			floatBufferIndex = 0U;
			std::memset(floatBuffer, 0, sizeof(floatBuffer));

			if (destinationIndex >= destinationLength)
			{
				break;
			}
		}
	}
}

ModelData Rubin::OBJModelParser::ParseModel(const std::string source)
{
	ModelData result;

    // Find positions
	std::istringstream sourceStream = std::istringstream(source);
	std::string line;

	std::unique_ptr<std::vector<VertexData>> vertices = std::make_unique<std::vector<VertexData>>();

	while (getline(sourceStream, line))
	{
		if (line.starts_with("v "))
		{
			vertices->push_back(VertexData());

			for (int i = 2; i < line.size(); i++)
			{
				const size_t& numberOfElements = sizeof(vertices->back().position) / sizeof(vertices->back().position[0]);
				FindFloatsInLine(line, vertices->back().position, numberOfElements);
			}
		}
	}

	result.SetData(std::move(vertices), std::move(std::make_unique<std::vector<unsigned int>>(std::vector<unsigned int>())));

	return result;
}
