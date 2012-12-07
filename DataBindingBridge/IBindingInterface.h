//
//  IBindingInterface.h
//  DataBindingBridge
//
//  Created by 菊池 紘 on 12/12/08.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef DataBindingBridge_IBindingInterface_h
#define DataBindingBridge_IBindingInterface_h
#include "BindingBridge.h"

class IBindingInterface
{
public:
    BindingBridge* bridge;
    virtual void setval() = 0;
    virtual void call_bridge() = 0;
};

#endif
