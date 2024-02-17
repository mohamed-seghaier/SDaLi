/*
 * Created on Sat Feb 17 2024
 * By SEGHAIER Mohamed-Ali
 *
 * Copyright (c) 2024
 */

#pragma once

#include <cstdint>
#include <SDL2/SDL.h>

#include "Builder.h"


namespace SDaLi
{
#define SCREEN_HEIGHT 1080
#define SCREEN_WIDTH 1920

class WindowManager
{
public:
    /**
     * @brief Constructor.
     *
     */
    WindowManager ();

    // Disable copy and assignment
    WindowManager (WindowManager&) = delete;
    WindowManager (WindowManager&&) = delete;
    // Disable copy and assignment

    /**
     * @brief Fill the SDL_Window member
     *
     */
    void createWindow ();

    /**
     * @brief Fill the SDL_Renderer member
     *
     */
    void render ();
private:

    // Window entity
    SDL_Window *window;

    // Simple renderer
    SDL_Renderer *renderer;
private:
    // Window's x axis
    int32_t x;

    // Window's y axis
    int32_t y;

    // Window's height
    int32_t height;

    // Window's width
    int32_t width;

};

}