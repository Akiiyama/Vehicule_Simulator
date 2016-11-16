#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#undef main

#include "Vector.h"
#include "Road.h"
#include "Vehicule.h"

int main()
{
	SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Vehicule_Simulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(window);
    
	//glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70,(double)640/480,1,1000);
	
    glEnable(GL_DEPTH_TEST);
    
    Road* road = new Road();
    Vehicule* vehicule = new Vehicule();
    
    bool continuer = true;
    SDL_Event event;

	float delta = 0;
	int last_time = 0;
	int current_time;
    while (continuer)
    {
    	current_time = SDL_GetTicks();
    	delta = (current_time - last_time)/1000.f;
    	last_time = current_time;
    	
        while (SDL_PollEvent(&event))
	        switch(event.type)
	        {
	            case SDL_QUIT:
	                continuer = false;
	    	}
    	
    	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    	vehicule->process(delta);
    			
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(70,(double)640/480,1,1000);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
    
    	vehicule->draw_3D();
    	road->draw_3D();
    	
    	glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		glOrtho(0.0, 640, 480, 0.0, -1.0, 10.0);
		glMatrixMode(GL_MODELVIEW);
		
		glLoadIdentity();
		glDisable(GL_CULL_FACE);
		
		glClear(GL_DEPTH_BUFFER_BIT);
    	
    	vehicule->draw_2D();
    	road->draw_2D();
    	
		if (delta < 0.01)
    		SDL_Delay((0.01-delta)*1000);

        glFlush();
        SDL_GL_SwapWindow(window);
    }

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
