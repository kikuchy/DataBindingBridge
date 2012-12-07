//
//  main.cpp
//  DataBindingBridge
//
//  Created by 菊池 紘 on 12/12/08.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "ClassA.h"

int main (int argc, const char * argv[])
{
    ClassA* a = new ClassA();
    ClassA* b = new ClassA();
    ClassABridgeInterface* ai = new ClassABridgeInterface();
    ClassABridgeInterface* bi = new ClassABridgeInterface();
    BindingBridge *bridge = new BindingBridge();
    ai->instance = a;
    bi->instance = b;
    ai->bridge = bi->bridge = bridge;
    bridge->source = ai;
    bridge->target = bi;
    a->interface = ai;
    b->interface = bi;
    std::cout << a->intval() << std::endl;
    std::cout << b->intval() << std::endl;
    a->intval(30);
    std::cout << a->intval() << std::endl;
    std::cout << b->intval() << std::endl;
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

