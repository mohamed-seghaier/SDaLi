/*
 * Created on Sat Feb 17 2024
 * By SEGHAIER Mohamed-Ali
 *
 * Copyright (c) 2024
 */

#include "WindowBuilder.h"

namespace SDaLi::Window
{

WindowBuilder::WindowBuilder():
    m_pWindowManager(nullptr),
    m_resetState(false)
{
}

WindowBuilder *WindowBuilder::reset()
{
    m_pWindowManager = std::make_unique<::SDaLi::Window::WindowManager>
                       ();
    // Need to know if the object has been reset
    m_resetState = true;

    return this;
}

WindowBuilder *WindowBuilder::buildHeight(const int32_t inValue)
{
    m_pWindowManager->setHeight(inValue);
    return this;
}

WindowBuilder *WindowBuilder::buildWidth(const int32_t inValue)
{
    m_pWindowManager->setWidth(inValue);
    return this;
}

WindowBuilder *WindowBuilder::buildAxisX(const int32_t inValue)
{
    m_pWindowManager->setAxisX(inValue);
    return this;
}

WindowBuilder *WindowBuilder::buildAxisY(const int32_t inValue)
{
    m_pWindowManager->setAxisY(inValue);
    return this;
}

std::unique_ptr <WindowManager> WindowBuilder::build()
{
    if (m_resetState == true)
    {
        return std::move (m_pWindowManager);
    }
    else
    {
        std::cout << "WindowBuilder::WindowBuilder = Cannot build WindowManager.\n";
    }
    return nullptr;
}

}