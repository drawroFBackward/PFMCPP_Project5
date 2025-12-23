#pragma once
#include <iostream>

struct CoffeeMaker;

struct WrapperCoffeeMaker
{
    WrapperCoffeeMaker();
    ~WrapperCoffeeMaker();
    CoffeeMaker* cmPtr = nullptr;
};

struct FireAlarmSystem;

struct WrapperFireAlarmSystem
{
    WrapperFireAlarmSystem();
    ~WrapperFireAlarmSystem();
    FireAlarmSystem* fasPtr = nullptr;
};

struct Keyboard;

struct WrapperKeyboard
{
    WrapperKeyboard();
    ~WrapperKeyboard();
    Keyboard* kbPtr = nullptr;
};

struct Kitchen;

struct WrapperKitchen
{
    WrapperKitchen();
    ~WrapperKitchen();
    Kitchen* kPtr = nullptr;
};

struct House;

struct WrapperHouse
{
    WrapperHouse();
    ~WrapperHouse();
    House* hPtr = nullptr;
};
