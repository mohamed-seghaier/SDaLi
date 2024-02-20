/*
 * Created on Sat Feb 17 2024
 * By SEGHAIER Mohamed-Ali
 *
 * Copyright (c) 2024
 */

#include "WindowManager.h"

SDaLi::WindowManager::WindowManager() :
    m_pRenderer(nullptr),
    m_pWindow(nullptr),
    m_height(0),
    m_width(0),
    m_x(0),
    m_y(0)
{
}




void SDaLi::WindowManager::createWindow()
{
    m_pWindow = SDL_CreateWindow("Dalics",
                                 m_x,
                                 m_y,
                                 m_width,
                                 m_height,
                                 SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP
                                );
    if (m_pWindow == nullptr)
    {
        SDL_Quit();
        EXIT_FAILURE;
    }
    std::cout << "Window created.\n";
    SDL_Delay (3000);
}

void SDaLi::WindowManager::render()
{
    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);

    if (m_pRenderer == nullptr)
    {
        std::cout << "Error WindowManager::Render () : Failed to create render. Abort.\n";
        SDL_Quit();
        EXIT_FAILURE;
    }
    std::cout << "Render created.\n";
}
