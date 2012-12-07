//
//  BindingBridge.h
//  DataBindingBridge
//
//  Created by 菊池 紘 on 12/12/08.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef DataBindingBridge_BindingBridge_h
#define DataBindingBridge_BindingBridge_h
#include "IBindingInterface.h"

class IBindingInterface;

class BindingBridge
{
public:
    IBindingInterface *source;
    IBindingInterface *target;
    template<typename F> void BridgeData(F func) { func(source, target); }
};

#endif
