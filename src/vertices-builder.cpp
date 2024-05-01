#include "vertices-builder.h"
#include "numeric-characters-parser.h"

Rubin::VerticesBuilder::VerticesBuilder() :
	m_builtVertices(std::make_unique<std::vector<VertexData>>())
{
}

void Rubin::VerticesBuilder::FindPositionInLine(const std::string& line)
{
	m_positions.emplace_back(0.0f, 0.0f, 0.0f);
	FindFloatsInLine(line, m_positions.back().data(), 3U);
}

void Rubin::VerticesBuilder::FindTextureCoordinatesInLine(const std::string& line)
{
	m_textureCoordinates.emplace_back(0.0f, 0.0f);
	FindFloatsInLine(line, m_textureCoordinates.back().data(), 2U);
}

void Rubin::VerticesBuilder::FindNormalInLine(const std::string& line)
{
	m_normals.emplace_back(0.0f, 0.0f, 0.0f);
	FindFloatsInLine(line, m_normals.back().data(), 3U);
}

void Rubin::VerticesBuilder::FindVerticesInLine(const std::string& line)
{
}

void Rubin::VerticesBuilder::FindFloatsInLine(const std::string& line, float* destination, size_t destinationLength)
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
