//
//  ClassA.cpp
//  DataBindingBridge
//
//  Created by 菊池 紘 on 12/12/08.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "ClassA.h"

int ClassA::intval()
{
    return intval_;
}

void ClassA::intval(int value)
{
    intval_ = value;
    interface->source_value(value);
    interface->call_bridge();
}

void ClassA::intval_nocb(int value)
{
    intval_ = value;
}