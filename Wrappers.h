#pragma once
#include <iostream>
#include "House.h"

struct WrapperCoffeeMaker
{
    WrapperCoffeeMaker();
    ~WrapperCoffeeMaker();
    CoffeeMaker* cmPtr = nullptr;
};

struct WrapperFireAlarmSystem
{
    WrapperFireAlarmSystem();
    ~WrapperFireAlarmSystem();
    FireAlarmSystem* fasPtr = nullptr;
};

struct WrapperKeyboard
{
    WrapperKeyboard();
    ~WrapperKeyboard();
    Keyboard* kbPtr = nullptr;
};

struct WrapperKitchen
{
    WrapperKitchen();
    ~WrapperKitchen();
    Kitchen* kPtr = nullptr;
};

struct WrapperHouse
{
    WrapperHouse();
    ~WrapperHouse();
    House* hPtr = nullptr;
};
