#include "FileModel.h"

FileModel::FileModel(char* filepath)
{
	FILE* file = std::fopen(filepath, "r");
	if(file == nullptr){
		throw "Could not find file exception";
	}
}

void FileModel::Draw(DrawTool* tool)
{
	
}

void FileModel::Load(DrawTool* tool)
{
	
}
