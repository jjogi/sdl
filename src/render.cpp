#include "game.h"

void
game::OnRender()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
//	glLoadIdentity();

//	glTranslated( width / 2, height / 2, 0 );
//	glScaled(150, 150, 0);
//	glRotated(180, 0, 0, 1);
//glRotated(degree, 0, 1, 0);

//	glBegin( GL_TRIANGLES );
//		glColor3f( 1, 0, 0 );
//		for ( int i = 0; i < elements.size(); ++i )
//		{
//			glVertex3d( vertices[elements[i]].x, vertices[elements[i]].y, vertices[elements[i]].z );
//		}
//	glEnd();

	glBindVertexArray( vaoHandle );
	glDrawElements( GL_TRIANGLES, elements.size(), GL_UNSIGNED_INT, 0 );

	SDL_GL_SwapBuffers();

//	SDL_Delay( 30 );
}

