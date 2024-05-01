#pragma once

namespace Rubin
{
	struct VertexData
	{
		union
		{
			struct
			{
				float x, y, z;
			};
			float position[3]{ 0.f, 0.f, 0.f };
		};
		union
		{
			struct
			{
				float u, v;
			};
			float textureCoordinates[2]{ 0.f, 0.f };
		};
		union
		{
			struct
			{
				float nx, ny, nz;
			};
			float normal[3]{ 0.f, 0.f, 0.f };
		};
	};
}
