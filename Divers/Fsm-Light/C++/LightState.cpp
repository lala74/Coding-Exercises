#include "LightState.h"
#include "Light.h"
#include <iostream>

using namespace std;

// LightOff
ILightState& LightOff::GetInstance() {
    static LightOff singleton;
    return singleton;
}

void LightOff::Toggle(Light *light) {
    light->setState(LightLow::GetInstance());
}

void LightOff::Enter() {
    cout << "Enter Light Off" << endl;
}
void LightOff::Exit() {
    cout << "Exit Light Off" << endl;
}

// LightLow
ILightState& LightLow::GetInstance() {
    static LightLow singleton;
    return singleton;
}

void LightLow::Toggle(Light *light) {
    light->setState(LightMedium::GetInstance());
}

void LightLow::Enter() {
    cout << "Enter Light Low" << endl;
}
void LightLow::Exit() {
    cout << "Exit Light Low" << endl;
}

// LightMedium
ILightState& LightMedium::GetInstance() {
    static LightMedium singleton;
    return singleton;
}

void LightMedium::Toggle(Light *light) {
    light->setState(LightHigh::GetInstance());
}

void LightMedium::Enter() {
    cout << "Enter Light Medium" << endl;
}
void LightMedium::Exit() {
    cout << "Exit Light Medium" << endl;
}

// LightHigh
ILightState& LightHigh::GetInstance() {
    static LightHigh singleton;
    return singleton;
}

void LightHigh::Toggle(Light *light) {
    light->setState(LightOff::GetInstance());
}

void LightHigh::Enter() {
    cout << "Enter Light High" << endl;
}
void LightHigh::Exit() {
    cout << "Exit Light High" << endl;
}

