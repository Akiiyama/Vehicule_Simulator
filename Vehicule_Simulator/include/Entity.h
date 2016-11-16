#ifndef _ENTITY_H_INCLUDED_
#define _ENTITY_H_INCLUDED_

#include <vector>
#include <string>
#include <GL/glu.h>
#include "Vector.h"

class Entity
{
public:
	Entity();
	~Entity();
	
	virtual void process(float const& delta);
	virtual void draw_3D();
	virtual void draw_2D();
	
protected:
	void load_Texture(std::string path);
	void draw_circle();
	
	maths::Vector3			translation;
	maths::Vector3			rotation;
	maths::Vector3			scale;
	
	std::vector<GLuint>		textures_id;
	std::vector<maths::Vector3>	colors;
};

#endif //_ENTITY_H_INCLUDED_
