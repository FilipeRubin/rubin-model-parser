#pragma once
#include "vertex-data.h"
#include <memory>
#include <vector>

namespace Rubin
{
	class ModelData
	{
	public:
		void SetData(std::unique_ptr<std::vector<VertexData>>&& vertices, std::unique_ptr<std::vector<unsigned int>>&& indices);
		const std::vector<VertexData>& GetVerticesData() const;
		const std::vector<unsigned int>& GetIndices() const;
	private:
		std::unique_ptr<std::vector<VertexData>> m_vertices;
		std::unique_ptr<std::vector<unsigned int>> m_indices;
	};
}
