#include "ModelContainer.h"

ModelContainer::ModelContainer()
{
	
}

void ModelContainer::AddModel(ModelBase* model)
{
	models.push_back(model);
}

void ModelContainer::Draw(DrawTool* tool)
{
	if(models.size() == 0)
		return;
	std::for_each(models.begin(), models.end(), [tool](ModelBase* item) {
		item->Draw(tool);
	});
}

