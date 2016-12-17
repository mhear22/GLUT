#include "OBJLoader.h"

OBJLoader::OBJLoader(char* filename)
{
	
}

std::vector<glm::vec3> OBJLoader::GetVertex()
{
	return vertexArray;
}

std::vector<glm::vec3> OBJLoader::GetNormals()
{
	return normals;
}

std::vector<glm::vec2> OBJLoader::GetUVs()
{
	return uv;
}
