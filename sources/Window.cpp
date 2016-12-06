#include "../includes/Window.h"
#include <assert.h>
#include <iostream>
namespace maptomix {

using namespace std;

struct thread_data{
	Window * window; 
	SDL_Surface* image; 
	SDL_Event event; 

}; 


 void Window::loop_thread(thread_data *data){
	SDL_Event event = data->event; 
	Window *window = data->window; 
	SDL_Surface *image = data->image;
	bool stop = false; 
	while(!stop){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				stop = true; 
				cout << "quit " <<endl; 
			}

			}
		window->display_image(image); 
		}
//	delete window; 
}


Window::Window(const int w,const int h , const char* n) {
	width=w; 
	height=h;
	name =(string) n;


	m_window = SDL_CreateWindow(n,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,w,h,SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(m_window,-1,0);
	free_surface_texture = false;

	
}

Window::~Window(){
	if(free_surface_texture){
	SDL_DestroyTexture(texture);
	
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(m_window);
}

/*****************************************************************************************************************/

void Window::display_image(SDL_Surface* image){
	texture=SDL_CreateTextureFromSurface(renderer,image);
	assert(texture!=nullptr);
	SDL_RenderCopy(renderer,texture,NULL,NULL);
	SDL_RenderPresent(renderer);
	free_surface_texture=true;


}

/*****************************************************************************************************************/
/*****************************************************************************************************************/



void Window::loop(SDL_Surface* image){
	thread_data data ; 
	data.window = this;
        data.image = image; 
	data.event = event ; 	
	t_sdl = thread(loop_thread,&data); 
	
}




void Window::synchronize(){
	t_sdl.join(); 
       


}






/*****************************************************************************************************************/


/*****************************************************************************************************************/


/*****************************************************************************************************************/


/*****************************************************************************************************************/


}
