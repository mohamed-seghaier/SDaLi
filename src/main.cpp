/*
 * Created on Sat Feb 17 2024
 * By SEGHAIER Mohamed-Ali
 *
 * Copyright (c) 2024
 */

#include <iostream>
#include "WindowBuilder.h"
#include "ImageBuilder.h"

int main()
{
    SDaLi::Builder::WindowBuilder wBuilder;
    SDaLi::Builder::ImageBuilder imgBuilder;

    auto window = wBuilder.reset()
                          ->buildWindowName("Daloche")
                          ->buildAxisX (SDL_WINDOWPOS_CENTERED)
                          ->buildAxisY (SDL_WINDOWPOS_CENTERED)
                          ->buildHeight (0)
                          ->buildWidth (0)
                          ->buildWindow()
                          ->buildRenderer()
                          ->build();

    auto p = window->getSdlRenderer();
    if (!p)
    {
        std::cout << "problem !! \n";
    }
    auto img = imgBuilder.reset()
                          ->buildTexture("./img.png", p)
                          ->build();
    return 0;
}