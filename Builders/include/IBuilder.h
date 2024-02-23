/*
 * Created on Thu Feb 22 2024
 * By SEGHAIER Mohamed-Ali
 *
 * Copyright (c) 2024
 */

#pragma once

#include <memory>

namespace SDaLi::Builder
{
template <typename T>
class IBuilder
{
public:
    virtual IBuilder *reset () = 0 ;

    virtual std::unique_ptr<T> build() = 0;

};
}