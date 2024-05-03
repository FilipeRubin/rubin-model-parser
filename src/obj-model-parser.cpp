#include "obj-model-parser.h"
#include "vertices-builder.h"
#include <sstream>

using Rubin::VertexData;
using Rubin::ModelData;
using Rubin::VerticesBuilder;

ModelData Rubin::OBJModelParser::ParseModel(const std::string source)
{
	std::istringstream sourceStream = std::istringstream(source);
	std::string line;

	VerticesBuilder verticesBuilder;

	while (getline(sourceStream, line))
	{
		if (line.starts_with("v "))
		{
			verticesBuilder.FindPositionInLine(line);
		}
		else if (line.starts_with("vt"))
		{
			verticesBuilder.FindTextureCoordinatesInLine(line);
		}
		else if (line.starts_with("vn"))
		{
			verticesBuilder.FindNormalInLine(line);
		}
		else if (line.starts_with("f"))
		{
			verticesBuilder.FindVerticesInLine(line);
		}
	}

	ModelData result;

	return result;
}
