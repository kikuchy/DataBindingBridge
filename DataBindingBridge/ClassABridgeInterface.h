//
//  ClassABridgeInterface.h
//  DataBindingBridge
//
//  Created by 菊池 紘 on 12/12/08.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef DataBindingBridge_ClassABridgeInterface_h
#define DataBindingBridge_ClassABridgeInterface_h
#include "ClassA.h"
#include "IBindingInterface.h"

class ClassABridgeInterface;

class ClassA
{
    int intval_;
    
public:
    int intval(void);
    void intval(int value);
    void intval_nocb(int value);
    ClassABridgeInterface *interface;
};

class ClassABridgeInterface : public IBindingInterface
{
    int sourceValue_;
    
public:
    ClassA *instance;
    void source_value(int val) { sourceValue_ = val; }
    void setval(){
        instance->intval(sourceValue_);
    }
    void call_bridge(){
        class BridgeIntval{
        public:
            void operator()(IBindingInterface* isource, IBindingInterface* itarget){
                ClassABridgeInterface *source = (ClassABridgeInterface *)isource;
                ClassABridgeInterface *target = (ClassABridgeInterface *)itarget;
                target->instance->intval_nocb(source->instance->intval());
            }
        };
        BridgeIntval bbb;
        bridge->BridgeData<BridgeIntval>(bbb);
    }
};

#endif
