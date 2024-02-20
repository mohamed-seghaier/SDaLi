/*
 * Created on Sat Feb 17 2024
 * By SEGHAIER Mohamed-Ali
 *
 * Copyright (c) 2024
 */

#include "WindowManager.h"

#include <memory>

namespace SDaLi
{

class WindowBuilder
{
public:

    /**
     * @brief First function to be called before every build.
     *
     * @return WindowBuilder returns himself so the user can call every build function after this one.
     */
    WindowBuilder *reset ();

    /**
     * @brief Last function to be called in every build.
     *
     * @return WindowManager It returns the built object.
     */
    std::unique_ptr<WindowManager> build ();

private:
    bool m_resetState;
    std::unique_ptr<WindowManager> m_pWindowManager;
};


}