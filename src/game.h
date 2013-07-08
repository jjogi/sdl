#ifndef _GAME_H_
#define _GAME_H_

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <iostream>
#include <vector>

#include "base/vec3.h"
#include "base/vec4.h"
#include "base/mat3.h"
#include "base/mat4.h"
#include "base/quat.h"

class game {
	private:
		bool running;
		SDL_Surface *surface;
		int width;
		int height;
		GLuint vaoHandle;

	public:
		std::vector<float> vertices;
		std::vector<float> normals;
		std::vector<int> elements;

		game();

		int OnExecute();

		bool OnInit();
		void OnEvent( SDL_Event *event );
		void OnLoop();
		void OnRender();
		void OnCleanup();

		void load_obj( const char *filename, std::vector<float> &vertices, std::vector<float> &normals, std::vector<int> &elements );
};

#endif

