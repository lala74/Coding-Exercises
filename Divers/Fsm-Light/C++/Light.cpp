#include "Light.h"

#include "LightState.h"

using namespace std;

Light::Light() : mCurrentState(&LightOff::GetInstance()) {}

void Light::setState(ILightState& newState)
{
    mCurrentState->Exit();
    mCurrentState = &newState;
    mCurrentState->Enter();
}

void Light::Toggle()
{
    mCurrentState->Toggle(this);
}
