#ifndef model_hpp
#define model_hpp

#include "header.h"
#include "ModelBase.h"

class TestModel: public ModelBase
{
public:
	TestModel();
	void Draw(DrawTool* tool);
	void Load(DrawTool* tool);
private:
	GLuint VAO;
	GLuint VBO;
	int _polyStart;
	int _polyEnd;
};

#endif /* model_hpp */
