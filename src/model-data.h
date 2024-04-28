#pragma once
#include "vertex-data.h"

namespace Rubin
{
	class OBJData
	{
	public:
		OBJData();
		~OBJData();
		void SetData(const VertexData* const vertices, size_t verticesLength, const unsigned int* const indices, size_t indicesLength);
		void GetVerticesCopy(VertexData*& out_vertices, size_t& out_verticesLength) const;
		void GetIndicesCopy(unsigned int*& out_indices, size_t& out_indicesLength) const;
	private:
		VertexData* m_vertices;
		size_t m_verticesLength;
		unsigned int* m_indices;
		size_t m_indicesLength;
	};
}
