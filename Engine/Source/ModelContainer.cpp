#include "ModelContainer.h"

ModelContainer::ModelContainer(DrawTool* drawTool)
{
	tool = drawTool;
	models = std::vector<ModelBase*>();
	frame = 0;
}

void ModelContainer::AddModel(ModelBase* model)
{
	models.push_back(model);
}

void ModelContainer::Load()
{
	for(int i = 0; i < models.size(); i++)
	{
		models.at(i)->Load(tool);
	}
}

void ModelContainer::Draw()
{

	auto size = models.size();
	if(size == 0)
		return;

	for(int i = 0; i != models.size(); i++)
	{
		models.at(i)->Draw(tool);
	}
}

