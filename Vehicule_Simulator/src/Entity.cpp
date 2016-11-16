#include <iostream>
#include <cmath>
#include <SDL_image.h>
#include "Entity.h"

Entity::Entity()
{
	this->translation = maths::Vector3(0.f, 0.f, 0.f);
	this->rotation = maths::Vector3(0.f, 0.f, 0.f);
	this->scale = maths::Vector3(1.f, 1.f, 1.f);
}

void Entity::process(float const& delta)
{
}

void Entity::draw_3D()
{
	
}

void Entity::draw_2D()
{
	
}

void Entity::load_Texture(std::string path)
{
	SDL_Surface* surf = IMG_Load(path.c_str());

	if (!surf)
	{
		std::cout << "Cannot load texture : file "<< path << " does not exist" << std::endl;
		return;
    }
	GLuint tex_id;
	glGenTextures(1, &tex_id);
	glBindTexture(GL_TEXTURE_2D, tex_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surf->w, surf->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surf->pixels);

	SDL_FreeSurface(surf);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	this->textures_id.push_back(tex_id);
}

void Entity::draw_circle()
{
	int points = 20;
	float x ,y ,fi;
	float PI = (22.f/7.f);
	glBegin(GL_TRIANGLE_FAN);
		for (int i = 0; i < points+2; i++)
		{
			fi = 2*PI/points*i;
			x = cos(fi);
			y = sin(fi);
			
			glTexCoord2d(0.5 + x/2, 0.5 + y/2);	glVertex3d(x, y, 0);
			
		}
	glEnd();
}

Entity::~Entity()
{
}

