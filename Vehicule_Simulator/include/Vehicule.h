#ifndef _VEHICULE_H_INCLUDED_
#define _VEHICULE_H_INCLUDED_

#include <vector>
#include "Vector.h"
#include "Entity.h"

class Vehicule
:public Entity
{
public:
	Vehicule();
	~Vehicule() = default;
	
	virtual void process(float const& delta);
	virtual void draw_3D();
	virtual void draw_2D();
private:
	void draw_body1();
	void draw_body2();
	void draw_wheels();
	void draw_speed_indicator();
	
	std::vector<maths::Vector3> cam_positions;
	int current_cam;
	
	float speed;
	float wheel_rotation;
};

#endif //_ROAD_H_INCLUDED_
