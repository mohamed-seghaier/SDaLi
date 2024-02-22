/*
 * Created on Sat Feb 17 2024
 * By SEGHAIER Mohamed-Ali
 *
 * Copyright (c) 2024
 */

#pragma once

#include "WindowManager.h"
#include "IBuilder.h"

#include <memory>

namespace SDaLi::Builder
{

class WindowBuilder : public IBuilder
{
public:

    WindowBuilder();

    /**
     * @brief First function to be called before every build.
     *
     * @return WindowBuilder returns himself so the user can call every build function after this one.
     */
    virtual WindowBuilder *reset () override ;

    WindowBuilder *buildHeight(const int32_t);
    WindowBuilder *buildWidth(const int32_t);
    WindowBuilder *buildAxisX(const int32_t);
    WindowBuilder *buildAxisY(const int32_t);

    /**
     * @brief Last function to be called in every build.
     *
     * @return WindowManager It returns the built object.
     */
    std::unique_ptr <::SDaLi::Window::WindowManager> build ();

    std::unique_ptr<::SDaLi::Window::WindowManager> m_pWindowManager;
private:
    bool m_resetState;
};


}