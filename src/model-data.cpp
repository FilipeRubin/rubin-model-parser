#include "model-data.h"
#include <algorithm>

using Rubin::VertexData;

Rubin::ModelData::ModelData() :
	m_vertices(nullptr),
	m_verticesLength(0U),
	m_indices(nullptr),
	m_indicesLength(0U)
{
}

Rubin::ModelData::~ModelData()
{
	delete[] m_vertices;
	delete[] m_indices;
}

void Rubin::ModelData::SetData(const VertexData* const vertices, size_t verticesLength, const unsigned int* const indices, size_t indicesLength)
{
	delete[] m_vertices;
	delete[] m_indices;

	m_vertices = new VertexData[verticesLength];
	m_verticesLength = verticesLength;
	m_indices = new unsigned int[indicesLength];
	m_indicesLength = indicesLength;

	std::copy(vertices, vertices + verticesLength, m_vertices);
	std::copy(indices, indices + indicesLength, m_indices);
}

void Rubin::ModelData::GetVerticesCopy(VertexData*& out_vertices, size_t& out_verticesLength) const
{
	out_vertices = m_vertices;
	out_verticesLength = m_verticesLength;
}

void Rubin::ModelData::GetIndicesCopy(unsigned int*& out_indices, size_t& out_indicesLength) const
{
	out_indices = m_indices;
	out_indicesLength = m_indicesLength;
}
