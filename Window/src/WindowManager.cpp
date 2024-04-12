/*
 * Created on Sat Feb 17 2024
 * By SEGHAIER Mohamed-Ali
 *
 * Copyright (c) 2024
 */

#include "WindowManager.h"

namespace SDaLi::Window
{
WindowManager::WindowManager() :
    m_pRenderer(NULL),
    m_pWindow(NULL),
    m_height(0),
    m_width(0),
    m_x(0),
    m_y(0)
{
}

SDL_Renderer *WindowManager::getSdlRenderer ()
{
    return m_pRenderer;
}

/**
void WindowManager::setRenderer (SDL_Window *inpWindow)
{
    SDL_Renderer *pRenderer = SDL_CreateRenderer(inpWindow,-1,SDL_RENDERER_ACCELERATED);

}
**/
void WindowManager::setAxisX (const int32_t inValue)
{
    m_x = inValue;
}

void WindowManager::setWindowName (const std::string &inValue)
{
    m_windowName = inValue;
}

void WindowManager::setAxisY (const int32_t inValue)
{
    m_y = inValue;
}

void WindowManager::setHeight (const int32_t inValue)
{
    m_height = inValue;
}

void WindowManager::setWidth (const int32_t inValue)
{
    m_width = inValue;
}

void WindowManager::fillDefaultValue()
{
    if (m_height == 0)
    {
        m_height = SCREEN_HEIGHT;
    }
    if (m_width == 0)
    {
        m_width = SCREEN_WIDTH;
    }
    if (m_windowName.empty ())
    {
        m_windowName = "SDaLi";
    }
}



void WindowManager::createWindow()
{
    fillDefaultValue ();
    m_pWindow = SDL_CreateWindow(m_windowName.c_str (),
                                 m_x,
                                 m_y,
                                 m_width,
                                 m_height,
                                 SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP
                                );
    if (m_pWindow == nullptr)
    {
        std::cout << "Error on WindowManager::CreateWindow : " << SDL_GetError() << "\n";
        SDL_Quit();
        EXIT_FAILURE;
    }
    std::cout << "Window created.\n";
    SDL_Delay (3000);
}

void WindowManager::render()
{
    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);

    if (m_pRenderer == nullptr)
    {
        std::cout << "Error WindowManager::Render () : " << SDL_GetError() << "/n";
        SDL_Quit();
        EXIT_FAILURE;
    }
    std::cout << "Render created.\n";
    SDL_SetRenderDrawColor(m_pRenderer, 1, 0, 0, SDL_ALPHA_OPAQUE);
}

}