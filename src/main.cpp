/*
 * Created on Sat Feb 17 2024
 * By SEGHAIER Mohamed-Ali
 *
 * Copyright (c) 2024
 */

#include <iostream>
#include "WindowBuilder.h"

int main()
{
    SDaLi::Window::WindowBuilder builder;
    auto window = builder.reset()
                  ->buildAxisX (SDL_WINDOWPOS_CENTERED)
                  ->buildAxisY (SDL_WINDOWPOS_CENTERED)
                  ->buildHeight (0)
                  ->buildWidth (0)
                  ->build();
    window->createWindow();
    window->render();
    return 0;
}