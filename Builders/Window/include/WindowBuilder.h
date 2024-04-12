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

class WindowBuilder : public IBuilder <SDaLi::Window::WindowManager>
{
public:

    WindowBuilder();

    /////////////////////////////////////////
    //////// DISABLE COPY AND MOVE //////////
    /////////////////////////////////////////
    WindowBuilder(WindowBuilder &) = delete;  ////
    WindowBuilder(WindowBuilder &&) = delete; ////
    /////////////////////////////////////////
    /////////////////////////////////////////

    /**
     * @brief First function to be called before every build.
     *
     * @return WindowBuilder returns himself so the user can chain call all builders.
     */
    virtual WindowBuilder *reset () override ;


    WindowBuilder *buildRenderer();

    WindowBuilder *buildWindow();
    
    /**
     * @brief call WindowManager::setHeight
     *
     * @return WindowBuilder returns himself so the user can chain call all builders.
     */
    WindowBuilder *buildHeight(const int32_t);

    /**
     * @brief call WindowManager::setWidth
     *
     * @return WindowBuilder returns himself so the user can chain call all builders.
     */
    WindowBuilder *buildWidth(const int32_t);

    /**
     * @brief call WindowManager::setWindowName
     *
     * @return WindowBuilder returns himself so the user can chain call all builders.
     */
    WindowBuilder *buildWindowName (const std::string &);

    /**
     * @brief call WindowManager::setAxisX
     *
     * @return WindowBuilder returns himself so the user can chain call all builders.
     */
    WindowBuilder *buildAxisX(const int32_t);

    /**
    * @brief call WindowManager::setAxisY
    *
    * @return WindowBuilder returns himself so the user can chain call all builders.
    */
    WindowBuilder *buildAxisY(const int32_t);

    /**
     * @brief Last function to be called in every build.
     *
     * @return WindowManager It returns the built object.
     */
    virtual std::unique_ptr <::SDaLi::Window::WindowManager> build () override;

private:

    std::unique_ptr<::SDaLi::Window::WindowManager> m_pWindowManager;
    bool m_resetState;
};


}