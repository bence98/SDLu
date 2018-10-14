#include "sdlu.h"

/* SDLu v1.0.1
 * (c) 2018, Csókás Bence Viktor
 */

bool sdlu_init=false;

SDL_Renderer* sdlu_create_win_renderer(char* title, unsigned int w, unsigned int h){
	if(!sdlu_init){
		if(SDL_Init(SDL_INIT_EVERYTHING)<0)
			return NULL;
		else
			sdlu_init=true;
	}
	
	SDL_Window* wnd=SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);
	if(wnd==NULL) return NULL;
	return SDL_CreateRenderer(wnd, -1, SDL_RENDERER_SOFTWARE);
}

int main(int argc, char* argv[]){
	struct context* ctx=sdlu_OnInit();
	
	SDL_Event evt;
	SDL_WaitEvent(&evt);
	while(evt.type != SDL_QUIT && !sdlu_MessageLoop(evt, ctx))
		SDL_WaitEvent(&evt);
	
	free(ctx);
	SDL_Quit();
	
	return 0;
}
