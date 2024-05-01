#include "obj-model-parser.h"
#include "numeric-characters-parser.h"
#include <array>
#include <sstream>
#include <vector>

using Rubin::ModelData;
using Rubin::NumericCharactersParser;

void FindFloatsInLine(const std::string& line, float* destination, size_t destinationLength)
{
	NumericCharactersParser numericCharactersParser;

	unsigned int destinationIndex = 0U;

	for (const char& character : line)
	{
		const bool& isLastLineCharacter = character == line.back();
		const bool& isValidCharacter = NumericCharactersParser::IsValidNumericCharacter(character);
		const bool& isFloatReadyToParse = (not isValidCharacter or isLastLineCharacter) and not numericCharactersParser.IsEmpty();

		if (isValidCharacter)
		{
			numericCharactersParser.AppendCharacter(character);
		}

		if (isFloatReadyToParse)
		{
			destination[destinationIndex] = numericCharactersParser.ParseFloat();
			numericCharactersParser.ResetBuffer();

			destinationIndex++;

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
