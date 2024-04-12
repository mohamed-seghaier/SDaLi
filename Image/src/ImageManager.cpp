/*
 * Created on Sat Feb 28 2024
 * By SEGHAIER Mohamed-Ali
 *
 * Copyright (c) 2024
 */

#include "ImageManager.h"
#include <iostream>

namespace SDaLi::Image
{

ImageManager::ImageManager()
{

}

void ImageManager::setSdlTexture (const char *inPath, SDL_Renderer *inpRenderer)
{
    SDL_Surface *tmpSurface = IMG_Load (inPath);
    if (!tmpSurface)
    {
        std::cout << "Error on creating surface : " << SDL_GetError()<< "\n";
        return;
    }

    m_pTexture = SDL_CreateTextureFromSurface (inpRenderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    if (!m_pTexture)
    {
        std::cout << "Error on creating texture : "<< SDL_GetError() << "\n";
    }
}

} // namespace SDaLi::Image

