#include "sdlu.h"
#include <string.h>

/* SDLu v1.1.-1
 * (c) 2018, Csókás Bence Viktor
 */

bool _sdlu_init=false, _sdlu_dbg=false;

SDL_Renderer* sdlu_create_win_renderer(char* title, unsigned int w, unsigned int h){
	if(!_sdlu_init){
		if(SDL_Init(SDL_INIT_EVERYTHING)<0)
			return NULL;
		else
			_sdlu_init=true;
	}
	
	SDL_Window* wnd=SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);
	if(wnd==NULL) return NULL;
	return SDL_CreateRenderer(wnd, -1, SDL_RENDERER_SOFTWARE);
}

bool sdlu_is_debug(){
	return _sdlu_dbg;
}

int main(int argc, char* argv[]){
	for(int i=1;i<argc;i++)
		if(strcmp("--debug", argv[i])==0)
			_sdlu_dbg=true;
	
	sdlu_OnInit();
	SDL_Event evt;
	SDL_WaitEvent(&evt);
	while(evt.type != SDL_QUIT && !sdlu_MessageLoop(evt))
		SDL_WaitEvent(&evt);
	
	SDL_Quit();
	
	return 0;
}
