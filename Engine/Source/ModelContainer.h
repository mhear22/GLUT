#ifndef ModelContainer_h
#define ModelContainer_h

#include "header.h"
#include "ModelBase.h"
#include "DrawTool.h"

class ModelContainer
{
public:
	ModelContainer();
	void AddModel(ModelBase* model);
	void Draw(DrawTool* tool);
private:
	std::vector<ModelBase*> models;
};

#endif
