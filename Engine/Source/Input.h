#ifndef input_hpp
#define input_hpp

#include "header.h"
#include "Camera.h"

class Input
{
public:
	Input(Camera* cam);
	void Draw();
private:
	Camera* camera;
};

#endif
