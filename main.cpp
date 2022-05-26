#include <iostream>
#include <Vector.h>
#include <SpaceObject.h>
#include <Space.h>
#include "SDL2/SDL.h"
#include "SpaceWindow.h"
#include "SDL2/SDL_main.h"

using namespace std;

int main(int argc, char* argv[])
{
    float x_ofset = 300;
    float y_ofset = 300;
    SDL_Window* wind = SpaceWindow::getWindow();
    SDL_Renderer* render = SpaceWindow::getRender(wind);
    Space* s = Space::get_space(10000, 0.0001);
    s->clickSnapShot();
    SDL_Event event;
    bool quit = false;
    Vector start;
    float mash = 1;
    char type = 'p';
    while(!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT){
                quit = true;
            }
            else if(event.type == SDL_MOUSEWHEEL)
            {
                if(event.wheel.y > 0)
                {
                    mash -= 0.25;
                    if(mash <= 0)
                    {
                        mash = 0.25;
                    }
                }
                else if(event.wheel.y < 0)
                {
                    mash += 0.25;
                }
            }
            else if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
            {
                start = Vector(event.motion.x, event.motion.y);
            }
            else if(event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
            {
                SpaceObject* p;
                if(type == 'p')
                {
                    p = new Planet(100, 15, RGB(rand()%255, rand()%255, rand()%255));
                }
                else if(type == 's')
                {
                    p = new Star(500000, 50, RGB(rand()%255, rand()%255, rand()%255));
                }
                else
                {
                    p = new BlackHole(80, RGB(rand()%255, rand()%255, rand()%255));
                }
                s->addObject(p);
                p->set_position(Vector((start.x() - x_ofset)*mash, (start.y() - y_ofset)*mash));
                p->set_speed(Vector((start.x()-event.motion.x)*150, (start.y()-event.motion.y)*150));
            }
            else if(event.type == SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_1:
                        type = 'p';
                        break;
                    case SDLK_2:
                        type = 's';
                        break;
                    case SDLK_3:
                        type = 'b';
                        break;
                    case SDLK_c:
                        s->clickSnapShot();
                        s->clearObjcts();
                        break;
                    case SDLK_s:
                        s->clickSnapShot();
                        break;
                    case SDLK_r:
                        s->clickRestore();
                        break;
                    case SDLK_UP:
                        y_ofset += 15;
                        break;
                    case SDLK_LEFT:
                        x_ofset += 15;
                        break;
                    case SDLK_RIGHT:
                        x_ofset -= 15;
                        break;
                    case SDLK_DOWN:
                        y_ofset -= 15;
                        break;
                }
            }
        }
        SpaceWindow::update(wind, render, s->getObjs(), mash, x_ofset, y_ofset);
        s->modeling();
    }
    return EXIT_SUCCESS;
}

