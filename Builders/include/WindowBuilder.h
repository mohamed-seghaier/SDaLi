/*
 * Created on Sat Feb 17 2024
 * By SEGHAIER Mohamed-Ali
 *
 * Copyright (c) 2024
 */

#pragma once

#include "WindowManager.h"

#include <memory>

namespace SDaLi::Window
{

class WindowBuilder
{
public:

    WindowBuilder();

    /**
     * @brief First function to be called before every build.
     *
     * @return WindowBuilder returns himself so the user can call every build function after this one.
     */
    WindowBuilder *reset ();

    WindowBuilder *buildHeight(const int32_t);
    WindowBuilder *buildWidth(const int32_t);
    WindowBuilder *buildAxisX(const int32_t);
    WindowBuilder *buildAxisY(const int32_t);

    /**
     * @brief Last function to be called in every build.
     *
     * @return WindowManager It returns the built object.
     */
    std::unique_ptr <WindowManager> build ();

    std::unique_ptr<WindowManager> m_pWindowManager;
private:
    bool m_resetState;
};


}