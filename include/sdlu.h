#ifndef SDL_U_H
#define SDL_U_H

/* SDLu v1.0.2
 * (c) 2018, Csókás Bence Viktor
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdbool.h>

/* *** Helper függvények *** */

/* Ablak és renderer létrehozása */
SDL_Renderer* sdlu_create_win_renderer(char* title, unsigned int w, unsigned int h);

/* *** Implementálandó függvények *** */

/* Állapotstruktúra
 * Ide kerül minden, amit az Init-ből a Loop-ba kell átadni
 */
struct context;

/* Inicializáció
 * @returns egy pointer, amit majd átadunk a Loop függvénynek, kilépéskor pedig törlünk
 */
struct context* sdlu_OnInit();

/* Loop
 * @parameter event SDL üzenet
 * @parameter ctx a pointer az Init függvénytől
 * @returns kilépési szándék
 */
bool sdlu_MessageLoop(SDL_Event event, struct context* ctx);

#endif //SDL_U_H
