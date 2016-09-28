#ifndef FileModel_h
#define FileModel_h

#include "header.h"
#include "ModelBase.h"

class FileModel: public ModelBase
{
public:
	FileModel(char* path);
	
	void Draw(DrawTool* tool);
	void Load(DrawTool* tool);
	
private:
	GLuint VAO;
	GLuint VBO;
	int _polyStart;
	int _polyEnd;
};

#endif /* FileModel_hpp */
