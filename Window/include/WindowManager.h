/*
 * Created on Sat Feb 17 2024
 * By SEGHAIER Mohamed-Ali
 *
 * Copyright (c) 2024
 */

#pragma once

#include <cstdint>
#include <iostream>
#include <memory>
#include <SDL2/SDL.h>

namespace SDaLi::Window
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

    


public:

    // GETTERS

    SDL_Renderer *getSdlRenderer ();

    //SETTERS

    /**
     * @brief Set Height Value.
     *
     */
    void setHeight(const int32_t);

    /**
     * @brief Set Width Value.
     *
     */
    void setWidth(const int32_t);
    void setAxisX(const int32_t);
    void setAxisY(const int32_t);

    void setWindowName (const std::string &inValue);

private:

    /**
     * @brief Set default Values for height and width at 1920 | 1080
     *
     */
    void fillDefaultValue ();

    // Window entity
    SDL_Window *m_pWindow;

    // Simple renderer
    SDL_Renderer *m_pRenderer;

private:

    std::string m_windowName = "";

    // Window's height
    int32_t m_height;

    // Window's width
    int32_t m_width;

    // Window's x axis
    int32_t m_x;

    // Window's y axis
    int32_t m_y;

};

}