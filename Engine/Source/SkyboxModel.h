#ifndef SkyboxModel_h
#define SkyboxModel_h

#include "header.h"
#include "ModelBase.h"

class SkyboxModel: public ModelBase
{
public:
	SkyboxModel();
	void Draw(DrawTool* tool);
	void Load(DrawTool* tool);
private:
	GLuint VAO;
	GLuint VBO;
	int _polyStart;
	int _polyEnd;
};

#endif
