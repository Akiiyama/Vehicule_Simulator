#ifndef _ROAD_H_INCLUDED_
#define _ROAD_H_INCLUDED_

#include "Entity.h"

class Road
:public Entity
{
public:
	Road();
	~Road() = default;
	
	virtual void draw_3D();
	virtual void draw_2D();
};

#endif //_ROAD_H_INCLUDED_
