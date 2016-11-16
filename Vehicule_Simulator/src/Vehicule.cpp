#include <iostream>
#include <cmath>
#include <SDL.h>
#include "Vehicule.h"

bool space_is_pressed = false;

Vehicule::Vehicule()
{
	this->speed = 0.f;
	this->translation = maths::Vector3(0, 1.5, 0);
	this->cam_positions = {maths::Vector3(0, 2, -4), maths::Vector3(-4, 2, 0), maths::Vector3(4, 2, 0), maths::Vector3(0, 2, 4), maths::Vector3(0, 20, -2)};
	this->current_cam = 0;
	load_Texture("texture/wheel.jpg");

}

void Vehicule::process(float const& delta)
{
	const Uint8* state = SDL_GetKeyboardState(nullptr);
	
    if (state[SDL_SCANCODE_UP] && this->speed < 0.3)
    {
    	this->speed += delta/5;
    	if (this->translation.z > 198 || this->translation.x > 198)
    		this->speed = 0;
	}	

    
    else if (state[SDL_SCANCODE_DOWN] && this-> speed > -0.05)
		{
    	this->speed -= delta/5;
    	if (this->translation.z < -198 || this->translation.x < -198)
    		this->speed = 0;
	}	

    
    else
    {
    	if (this->speed > 0)
    	{
    		speed -= delta * sqrt(speed);
    		speed = std::max(speed, 0.f);
		}
    		
    	else if (this->speed < 0)
    		speed += delta/5;
	}
    
    if (this->speed != 0)
    {
    	if (state[SDL_SCANCODE_RIGHT])
    		this->rotation.y -= delta * 90;
    
    	else if (state[SDL_SCANCODE_LEFT])
    		this->rotation.y += delta * 90;
	}
    
    float theta = this->rotation.y * 22 / (180*7);
    this->translation.z += speed * cos(theta);
    this->translation.x += speed * sin(theta);
    this->wheel_rotation += speed * 30 * 22 / 7.f;

    
    if (state[SDL_SCANCODE_SPACE])
    {
    	if (!space_is_pressed)
    	{
    		this->current_cam++;
    		this->current_cam %= this->cam_positions.size();
    		space_is_pressed = true;
		}
	}
	else
		space_is_pressed = false;

    
}

void Vehicule::draw_3D()
{	
	float theta = this->rotation.y * 22 / (180*7);

	maths::Vector3 cam = this->cam_positions[this->current_cam];

    gluLookAt(this->translation.x + (cam.x * cos(theta) + cam.z * sin(theta)), this->translation.y + cam.y, this->translation.z + (cam.z * cos(theta) - cam.x * sin(theta)), 
		this->translation.x, this->translation.y, this->translation.z, 0,1,0);

	
	
	glPushMatrix();
		
		glTranslatef(this->translation.x , this->translation.y, this->translation.z);
		glRotatef(this->rotation.y, 0, 1, 0);
		glScalef(1.7, 0.7, 0.8);
		
	//	glRotatef(this->rotation.y, 0, 1, 0);
		
		glPushMatrix();
    		draw_body1();
    	glPopMatrix();
    	
    	glPushMatrix();
    		draw_body2();
    	glPopMatrix();
    	
    	glPushMatrix();
    		draw_wheels();
    	glPopMatrix();
    	

    glPopMatrix();
}

void Vehicule::draw_2D()
{
	draw_speed_indicator();
}

void Vehicule::draw_body1()
{
	glTranslatef(0, 1, 0);
	glScalef(0.5, 0.7, 2);
	int length1 = 1, width1 = 1, height1 = 1;
	glColor3ub(255, 255, 255);
	glDisable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, this->textures_id[0]);
	glBegin(GL_QUADS);
		glTexCoord2d(0,0);	glVertex3d(width1, height1, length1); //TOP
		glTexCoord2d(0,1);	glVertex3d(width1, height1, -length1);
		glTexCoord2d(1,1);	glVertex3d(-width1, height1, -length1);
		glTexCoord2d(1,0);	glVertex3d(-width1, height1, length1);
		
		glTexCoord2d(0,0);	glVertex3d(width1, -height1, length1); //BOT
		glTexCoord2d(0,1);	glVertex3d(width1, -height1, -length1);
		glTexCoord2d(1,1);	glVertex3d(-width1, -height1, -length1);
		glTexCoord2d(1,0);	glVertex3d(-width1, -height1, length1);
		
		glTexCoord2d(0,0);	glVertex3d(width1, height1, length1); //RIGHT
		glTexCoord2d(0,1);	glVertex3d(width1, height1, -length1);
		glTexCoord2d(1,1);	glVertex3d(width1, -height1, -length1);
		glTexCoord2d(1,0);	glVertex3d(width1, -height1, length1);
		
		glTexCoord2d(0,0);	glVertex3d(-width1, height1, length1); //LEFT
		glTexCoord2d(0,1);	glVertex3d(-width1, height1, -length1);
		glTexCoord2d(1,1);	glVertex3d(-width1, -height1, -length1);
		glTexCoord2d(1,0);	glVertex3d(-width1, -height1, length1);
		
		glTexCoord2d(0,0);	glVertex3d(width1, height1, length1); //FRONT
		glTexCoord2d(0,1);	glVertex3d(width1, -height1, length1);
		glTexCoord2d(1,1);	glVertex3d(-width1, -height1, length1);
		glTexCoord2d(1,0);	glVertex3d(-width1, height1, length1);
		
		glTexCoord2d(0,0);	glVertex3d(width1, height1, -length1); //BACK
		glTexCoord2d(0,1);	glVertex3d(width1, -height1, -length1);
		glTexCoord2d(1,1);	glVertex3d(-width1, -height1, -length1);
		glTexCoord2d(1,0);	glVertex3d(-width1, height1, -length1);
	glEnd();
}

void Vehicule::draw_body2()
{
	glTranslatef(0, 2, -1.2);
	glScalef(0.5, 0.4, 0.8);
	int length1 = 1, width1 = 1, height1 = 1;
	glColor3ub(0, 255, 255);
	glDisable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, this->textures_id[0]);
	glBegin(GL_QUADS);
		glTexCoord2d(0,0);	glVertex3d(width1, height1, length1); //TOP
		glTexCoord2d(0,1);	glVertex3d(width1, height1, -length1);
		glTexCoord2d(1,1);	glVertex3d(-width1, height1, -length1);
		glTexCoord2d(1,0);	glVertex3d(-width1, height1, length1);
		
		glTexCoord2d(0,0);	glVertex3d(width1, -height1, length1); //BOT
		glTexCoord2d(0,1);	glVertex3d(width1, -height1, -length1);
		glTexCoord2d(1,1);	glVertex3d(-width1, -height1, -length1);
		glTexCoord2d(1,0);	glVertex3d(-width1, -height1, length1);
		
		glTexCoord2d(0,0);	glVertex3d(width1, height1, length1); //RIGHT
		glTexCoord2d(0,1);	glVertex3d(width1, height1, -length1);
		glTexCoord2d(1,1);	glVertex3d(width1, -height1, -length1);
		glTexCoord2d(1,0);	glVertex3d(width1, -height1, length1);
		
		glTexCoord2d(0,0);	glVertex3d(-width1, height1, length1); //LEFT
		glTexCoord2d(0,1);	glVertex3d(-width1, height1, -length1);
		glTexCoord2d(1,1);	glVertex3d(-width1, -height1, -length1);
		glTexCoord2d(1,0);	glVertex3d(-width1, -height1, length1);
		
		glTexCoord2d(0,0);	glVertex3d(width1, height1, length1); //FRONT
		glTexCoord2d(0,1);	glVertex3d(width1, -height1, length1);
		glTexCoord2d(1,1);	glVertex3d(-width1, -height1, length1);
		glTexCoord2d(1,0);	glVertex3d(-width1, height1, length1);
		
		glTexCoord2d(0,0);	glVertex3d(width1, height1, -length1); //BACK
		glTexCoord2d(0,1);	glVertex3d(width1, -height1, -length1);
		glTexCoord2d(1,1);	glVertex3d(-width1, -height1, -length1);
		glTexCoord2d(1,0);	glVertex3d(-width1, height1, -length1);
	glEnd();
}

void Vehicule::draw_speed_indicator()
{
	glLineWidth(5);
	glTranslated(600, 460, 0);
	
	float abs_speed = this->speed * 2;
	
	if (abs_speed < 0)
		abs_speed *= -1;
		
	glRotated(abs_speed * 100 - 90, 0, 0, 1);
	glColor3ub(255,255,255);
	glDisable(GL_TEXTURE_2D);
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(0,-100);
    glEnd();
    
    glLoadIdentity();
    glTranslated(20, 20, 0); // position of up left corner
    glTranslated(75, 75, 0); //center of minimap
    glTranslated(-this->translation.x * 75/200, -this->translation.z * 75/200, 0);
    glRotated(-this->rotation.y, 0, 0, 1);
    
    glColor3ub(0, 0, 0);
    glBegin(GL_TRIANGLES);
    	glVertex2d(0, -20);
    	glVertex2d(-5, -5);
    	glVertex2d(5, -5);
    glEnd();
}

void Vehicule::draw_wheels()
{
	double PI = 22/7.f;
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->textures_id[0]);
	glColor3ub(255, 255, 255);
	glScalef(0.8, 0.8, 0.8);
	glRotated(90, 0, 1, 0);

	glPushMatrix();
		glTranslatef(-1.3, 0, -0.7);
		glRotated(this->wheel_rotation, 0, 0, 1);
		draw_circle();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(1.3, 0, -0.7);
		glRotated(this->wheel_rotation, 0, 0, 1);
		draw_circle();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.3, 0, 0.7);
		glRotated(-this->wheel_rotation, 0, 0, 1);
		draw_circle();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(1.3, 0, 0.7);
		glRotated(-this->wheel_rotation, 0, 0, 1);
		draw_circle();
	glPopMatrix();
	
}
