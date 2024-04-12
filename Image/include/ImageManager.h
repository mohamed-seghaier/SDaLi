/*
 * Created on Sat Feb 28 2024
 * By SEGHAIER Mohamed-Ali
 *
 * Copyright (c) 2024
 */

#pragma once

#include "SDL2/SDL_image.h"

namespace SDaLi::Image
{

class ImageManager
{
public:
    ImageManager();

    /**
     * @brief m_pTexture setter
     * 
     * @param inPath path to the PNG.
     */
    void setSdlTexture (const char *inPath, SDL_Renderer *inpRenderer);

private:
    SDL_Texture *m_pTexture;

};

}