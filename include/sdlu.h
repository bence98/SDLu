#ifndef SDL_U_H
#define SDL_U_H

/* SDLu v1.1.-1
 * (c) 2018, Csókás Bence Viktor
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdbool.h>

/* *** Helper függvények *** */

/* Ablak és renderer létrehozása */
SDL_Renderer* sdlu_create_win_renderer(char* title, unsigned int w, unsigned int h);

/* Hibakeresés mód (`--debug` kapcsoló) */
bool sdlu_is_debug();

/* *** Implementálandó függvények *** */

/* Inicializáció, globális változók beállítása (pl. renderer objektum) */
void sdlu_OnInit();

/* Loop
 * @parameter event SDL üzenet
 * @returns kilépési szándék
 */
bool sdlu_MessageLoop(SDL_Event event);

#endif //SDL_U_H
