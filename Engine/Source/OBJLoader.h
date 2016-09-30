#ifndef OBJLoader_h
#define OBJLoader_h

#include <stdio.h>
#include "header.h"

class OBJLoader
{
public:
	OBJLoader(char* filename);
	std::vector<glm::vec3> GetVertex();
	std::vector<glm::vec3> GetNormals();
	std::vector<glm::vec2> GetUVs();
private:
	std::vector<glm::vec3> vertexArray;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uv;
};


#endif /* OBJLoader_hpp */
