#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <SDL.h>

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return 1;
    }
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    SDL_Window *pWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                           SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (pWindow == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        // todo null checks
        SDL_Surface *pSurface = SDL_GetWindowSurface(pWindow);
        SDL_FillRect(pSurface, nullptr, SDL_MapRGB(pSurface->format, 0xff, 0xff, 0xff));
        SDL_UpdateWindowSurface(pWindow);
        SDL_Event e;
        bool quit = false;
        while (!quit)
        {
            while (SDL_PollEvent(&e))
            {
                if (e.type == SDL_QUIT)
                {
                    quit = true;
                }
                if (e.type == SDL_KEYDOWN)
                {
                    quit = true;
                }
                if (e.type == SDL_MOUSEBUTTONDOWN)
                {
                    quit = true;
                }
            }
        }
        //Destroy window
        SDL_DestroyWindow(pWindow);
    }
    //Quit SDL subsystems
    SDL_Quit();
    return 0;
}