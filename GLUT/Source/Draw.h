#include "header.h"

class Draw
{
public:
	void static TriangleWall();
	void static TriangleWall(int points);
	void static DebugWall2D();
	void static DebugWall3D();
	void static Hex(float x, float y, float scale);
	void static Square(float x, float y, float height, float width);

private:
	float static RandomFloat(float low, float high);
};