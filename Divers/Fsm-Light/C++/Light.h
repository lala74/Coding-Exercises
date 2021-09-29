#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>
#include <map>

#include "LightState.h"

class ILightState;

class Light
{
public:
    Light();
    void Toggle();
    ILightState* GetCurrentState() { return mCurrentState; }

    void setState(ILightState& newState);

private:
    ILightState* mCurrentState;
};

#endif
