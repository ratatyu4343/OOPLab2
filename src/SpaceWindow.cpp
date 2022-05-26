#include "SpaceWindow.h"

SDL_Window* SpaceWindow::getWindow()
{
    return SDL_CreateWindow("SpaceModeling", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
}

SDL_Renderer* SpaceWindow::getRender(SDL_Window* window)
{
    return SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void SpaceWindow::update(SDL_Window* W, SDL_Renderer* R, std::vector<SpaceObject*> objects, float mash,  float x_ofset, float y_ofset)
{
    SDL_SetRenderDrawColor(R, 0, 0, 0, 0);
    SDL_RenderClear(R);
    for(auto obj : objects)
    {
        float x = obj->get_position().x()/mash + x_ofset;
        float y = obj->get_position().y()/mash + y_ofset;
        RGB col = obj->get_rgb();
        SDL_SetRenderDrawColor(R, col.get_R(), col.get_G(), col.get_B(), 1);
        grawCirc(W, R, obj->get_radius()/mash, x, y);
    }
    SDL_RenderPresent(R);
}

void SpaceWindow::grawCirc(SDL_Window* W, SDL_Renderer* R, float r, float x, float y)
{
    for (int w = 0; w < r * 2; w++)
    {
        for (int h = 0; h < r * 2; h++)
        {
            int dx = r - w;
            int dy = r - h;
            if ((dx*dx + dy*dy) <= (r * r))
            {
                SDL_RenderDrawPoint(R, x + dx, y + dy);
            }
        }
    }
}
