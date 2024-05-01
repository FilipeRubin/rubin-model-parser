#pragma once

namespace Rubin
{
	class NumericCharactersParser
	{
	public:
		static const size_t FLOAT_BUFFER_SIZE = 10U;
		NumericCharactersParser();
		void CheckAndAppendCharacter(char character);
		const char(&GetBuffer() const)[FLOAT_BUFFER_SIZE];
		bool IsEmpty() const;
		float ParseFloat() const;
		void ResetBuffer();
	private:
		char m_buffer[FLOAT_BUFFER_SIZE];
		unsigned int m_index;
		static inline bool IsValidNumericCharacter(char character);
	};
}