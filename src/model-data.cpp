#include "model-data.h"

using Rubin::VertexData;

void Rubin::ModelData::SetData(std::unique_ptr<std::vector<VertexData>>&& vertices, std::unique_ptr<std::vector<unsigned int>>&& indices)
{
	m_vertices = std::move(vertices);
	m_indices = std::move(indices);
}

const std::vector<VertexData>& Rubin::ModelData::GetVerticesData() const
{
	return *m_vertices;
}

const std::vector<unsigned int>& Rubin::ModelData::GetIndices() const
{
	return *m_indices;
}
