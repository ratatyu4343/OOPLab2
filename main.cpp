#include <iostream>
#include <Vector.h>
#include <SpaceObject.h>
#include <Space.h>
#include "SDL2/SDL.h"

using namespace std;

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    Space* s = Space::get_space(6, 0.0001);
    for(int i = 0; i < 300; i++)
    {
        SpaceObject* ppp = new Planet(10, 5, RGB(0, 0 , 0));
        ppp->set_position(Vector(rand()%800 + 1,-(rand()%800 + 1)));
        s->addObject(ppp);
    }
    while(true)
    {
        s->modeling();
        s->draw(window, renderer);
    }

    return EXIT_SUCCESS;
    /*Space* s = Space::get_space(6, 0.1);
    Space* g = Space::get_space(2, 0.22);
    for(int i = 0; i < 100; i++)
    {
        SpaceObject* ppp = new Planet(10, 1, RGB(0, 0 , 0));
        ppp->set_position(Vector(rand()%1002, rand()%2202));
        s->addObject(ppp);
    }
    s->clickSnapShot();
    s->set_gconst(122);
    std::cout << s->get_gconst() << " |";
    s->clickRestore();
    std::cout << s->get_gconst() << " |";
    while(true)
    {
        s->clickModeling();
    }*/
}

