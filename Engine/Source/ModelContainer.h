#ifndef ModelContainer_h
#define ModelContainer_h

#include "header.h"
#include "ModelBase.h"
#include "DrawTool.h"

class ModelContainer
{
public:
	ModelContainer(DrawTool* drawTool);
	void AddModel(ModelBase* model);
	void Draw();
	void Load();
private:
	DrawTool* tool;
	std::vector<ModelBase*> models;
	int frame;
};

#endif
