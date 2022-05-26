#ifndef SPACEWINDOW_H
#define SPACEWINDOW_H
#include "Space.h"
#include "SpaceObject.h"
#include "RGB.h"
#include "SDL2/SDL.h"

class Space;
class SpaceWindow
{
    public:
        static void grawCirc(SDL_Window*, SDL_Renderer*, float, float, float);
        static void update(SDL_Window*, SDL_Renderer*, std::vector<SpaceObject*>, float , float, float);
        static SDL_Window* getWindow();
        static SDL_Renderer* getRender(SDL_Window*);

};

#endif // SPACEWINDOW_H
