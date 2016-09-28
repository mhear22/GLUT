#include "FileModel.h"

FileModel::FileModel(char* filepath)
{
	std::fstream file;
	file.open(filepath);
	std::string s = "";
	file >> s;
	if(s == ""){
		
	}
}

void FileModel::Draw(DrawTool* tool)
{
	
}

void FileModel::Load(DrawTool* tool)
{
	
}
