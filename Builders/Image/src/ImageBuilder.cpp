/*
 * Created on Sat Feb 28 2024
 * By SEGHAIER Mohamed-Ali
 *
 * Copyright (c) 2024
 */

#include <iostream>

#include "ImageBuilder.h"

namespace SDaLi::Builder
{

ImageBuilder::ImageBuilder():
    m_pImageManager(nullptr),
    m_resetState(false)
{
}

ImageBuilder *ImageBuilder::reset()
{
    m_pImageManager = std::make_unique<::SDaLi::Image::ImageManager>
                      ();
    // Need to know if the object has been reset
    m_resetState = true;

    return this;
}

std::unique_ptr<::SDaLi::Image::ImageManager> ImageBuilder::build ()
{
    if (m_resetState == true)
    {
        std::cout << "Image built\n";
        m_resetState = false;
        return std::move (m_pImageManager);
    }
    else
    {
        std::cout << "ImageBuilder::build = Cannot build ImageManager.\n";
    }
    return nullptr;
}

ImageBuilder *ImageBuilder::buildTexture (const std::string &inPath, SDL_Renderer *inpRenderer)
{
    m_pImageManager->setSdlTexture(inPath.c_str(), inpRenderer);
    return this;
}


}