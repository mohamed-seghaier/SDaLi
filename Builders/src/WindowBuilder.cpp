/*
 * Created on Sat Feb 17 2024
 * By SEGHAIER Mohamed-Ali
 *
 * Copyright (c) 2024
 */

#include "WindowBuilder.h"

namespace SDaLi
{

WindowBuilder *WindowBuilder::reset()
{
    m_resetState = true;
    m_pWindowManager = nullptr;
    return this;
}

std::unique_ptr<WindowManager> WindowBuilder::build()
{
    if (m_resetState == true)
    {
        return std::move(m_pWindowManager);
    }
    else
    {
        std::cout << "WindowBuilder::WindowBuilder = Cannot build WindowManager.";
    }
    return nullptr;
}

}