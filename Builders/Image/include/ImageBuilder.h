/*
 * Created on Sat Feb 28 2024
 * By SEGHAIER Mohamed-Ali
 *
 * Copyright (c) 2024
 */

#pragma once


#include "IBuilder.h"
#include "ImageManager.h"

namespace SDaLi::Builder
{

class ImageBuilder : public IBuilder <::SDaLi::Image::ImageManager>
{
public:
    ImageBuilder();

    virtual ImageBuilder *reset() override;

    /**
    * @brief Last function to be called in every build.
    *
    * @return WindowManager It returns the built object.
    */
    virtual std::unique_ptr <::SDaLi::Image::ImageManager> build () override;

    /**
     * @brief build the SDL_Texture member
     * 
     * @param inPath path to the PNG img
     * @return ImageBuilder* returns itself to chain build.
     */
    ImageBuilder *buildTexture(const std::string &inPath, SDL_Renderer *inpRenderer);

private:
    std::unique_ptr<::SDaLi::Image::ImageManager> m_pImageManager;

    bool m_resetState;

};
}