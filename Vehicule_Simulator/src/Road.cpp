#include "Road.h"

Road::Road()
{
	load_Texture("texture/map.jpg");
}

void Road::draw_3D()
{	
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
	glBindTexture(GL_TEXTURE_2D, this->textures_id[0]);
	glBegin(GL_QUADS);
		glTexCoord2d(0,0);	glVertex3d(200, 0.5, 200);
		glTexCoord2d(1,0);	glVertex3d(-200, 0.5, 200);
		glTexCoord2d(1,1);	glVertex3d(-200, 0.5, -200);
		glTexCoord2d(0,1);	glVertex3d(200, 0.5, -200);
	glEnd();
	glPopMatrix();
}

void Road::draw_2D()
{
	glLoadIdentity();
	glPushMatrix();
	glTranslated(20, 20, 0);
	glEnable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
	glBindTexture(GL_TEXTURE_2D, this->textures_id[0]);
	glBegin(GL_QUADS);
		glTexCoord2d(0,0);	glVertex2d(0,0);
		glTexCoord2d(1,0);	glVertex2d(150,0);
		glTexCoord2d(1,1);	glVertex2d(150, 150);
		glTexCoord2d(0,1);	glVertex2d(0, 150);
	glEnd();
	glPopMatrix();
}


