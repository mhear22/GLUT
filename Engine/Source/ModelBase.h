#ifndef ModelBase_h
#define ModelBase_h

#include "DrawTool.h"

class ModelBase
{
public:
	virtual void Draw(DrawTool* tool) = 0;
};


#endif
