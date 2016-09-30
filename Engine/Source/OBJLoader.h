#ifndef OBJLoader_h
#define OBJLoader_h

#include <stdio.h>
#include "header.h"

class OBJLoader
{
public:
	OBJLoader(char* filename);
	std::vector<glm::vec3> GetVertex();
};


#endif /* OBJLoader_hpp */
