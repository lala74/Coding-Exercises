#ifndef LIGHT_STATE_H
#define LIGHT_STATE_H 

#include <iostream>
#include <map>

class Light;

class ILightState
{
public:
    virtual ~ILightState() = default;
    virtual void Toggle(Light* light) = 0;
    virtual void Enter() = 0;
    virtual void Exit() = 0;
};

class LightOff : public ILightState
{
public:
    static ILightState& GetInstance();
    void Toggle(Light* light) override;
    void Enter() override;
    void Exit() override;

private:
    LightOff() = default;
};

class LightLow : public ILightState
{
public:
    static ILightState& GetInstance();
    void Toggle(Light* light) override;
    void Enter() override;
    void Exit() override;

private:
    LightLow() = default;
};

class LightMedium : public ILightState
{
public:
    static ILightState& GetInstance();
    void Toggle(Light* light) override;
    void Enter() override;
    void Exit() override;

private:
    LightMedium() = default;
};

class LightHigh : public ILightState
{
public:
    static ILightState& GetInstance();
    void Toggle(Light* light) override;
    void Enter() override;
    void Exit() override;

private:
    LightHigh() = default;
};

#endif
