#include "numeric-characters-parser.h"
#include <string>

Rubin::NumericCharactersParser::NumericCharactersParser() :
	m_buffer({ '\0' }),
	m_index(0U)
{
}

void Rubin::NumericCharactersParser::AppendCharacter(char character)
{
	if (m_index < FLOAT_BUFFER_SIZE)
	{
		m_buffer[m_index] = character;
		m_index++;
	}
}

const char(&Rubin::NumericCharactersParser::GetBuffer() const)[FLOAT_BUFFER_SIZE]
{
	return m_buffer;
}

float Rubin::NumericCharactersParser::ParseFloat() const
{
	return std::stof(m_buffer);
}

unsigned int Rubin::NumericCharactersParser::ParseUnsignedInt() const
{
	return std::stoul(m_buffer);
}

bool Rubin::NumericCharactersParser::IsEmpty() const
{
	return m_index == 0U;
}

void Rubin::NumericCharactersParser::ResetBuffer()
{
	std::memset(m_buffer, 0, sizeof(m_buffer));
	m_index = 0U;
}

inline bool Rubin::NumericCharactersParser::IsValidNumericCharacter(char character)
{
	return (character > 47 and character < 58) or character == '-' or character == '.';
}