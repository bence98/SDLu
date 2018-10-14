#ifndef SDL_U_H
#define SDL_U_H

/* SDLu v1.0 
 * (c) 2018, Csókás Bence Viktor
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdbool.h>

/* *** Helper függvények *** */

/* Ablak és renderer létrehozása */
SDL_Renderer* sdlu_create_win_renderer(char* title, unsigned int w, unsigned int h);

/* *** Implementálandó függvények *** */

/* Inicializáció
 * @returns egy pointer, amit majd átadunk a loop függvénynek, kilépéskor pedig törlünk
 */
void* sdlu_OnInit();

/* Loop
 * @parameter event SDL üzenet
 * @parameter from_init pointer az sdlu_OnInit()-tól
 * @returns kilépési szándék
 */
bool sdlu_MessageLoop(SDL_Event event, void* from_init);

#endif //SDL_U_H
