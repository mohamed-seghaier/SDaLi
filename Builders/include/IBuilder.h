/*
 * Created on Sat Feb 17 2024
 * By SEGHAIER Mohamed-Ali
 *
 * Copyright (c) 2024
 */

namespace SDaLi
{

class IBuilder
{
public:
    virtual IBuilder reset ();
    virtual IBuilder build ();

};

}