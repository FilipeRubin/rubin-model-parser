#pragma once
#include "vertex-data.h"
#include <array>
#include <memory>
#include <string>
#include <vector>

namespace Rubin
{
	class VerticesBuilder
	{
	public:
		VerticesBuilder();
		void FindPositionInLine(const std::string& line);
		void FindTextureCoordinatesInLine(const std::string& line);
		void FindNormalInLine(const std::string& line);
		void FindVerticesInLine(const std::string& line);
	private:
		std::vector<std::array<float, 3>> m_positions;
		std::vector<std::array<float, 2>> m_textureCoordinates;
		std::vector<std::array<float, 3>> m_normals;
		std::unique_ptr<std::vector<VertexData>> m_builtVertices;
		void FindFloatsInLine(const std::string& line, float* destination, size_t destinationLength);
	};
}