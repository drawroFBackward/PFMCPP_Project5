#pragma once
/*
#include "CoffeeMaker.h"
#include "FireAlarmSystem.h"
#include "Keyboard.h"
#include "Kitchen.h"
*/
#include "House.h"
#include "Wrappers.h"

WrapperCoffeeMaker::WrapperCoffeeMaker() : cmPtr(new CoffeeMaker()) {}
WrapperCoffeeMaker::~WrapperCoffeeMaker() { delete cmPtr; }

WrapperFireAlarmSystem::WrapperFireAlarmSystem() : fasPtr(new FireAlarmSystem()) {}
WrapperFireAlarmSystem::~WrapperFireAlarmSystem() { delete fasPtr; }

WrapperKeyboard::WrapperKeyboard() : kbPtr(new Keyboard()) {}
WrapperKeyboard::~WrapperKeyboard() { delete kbPtr; }

WrapperKitchen::WrapperKitchen() : kPtr(new Kitchen()) {}
WrapperKitchen::~WrapperKitchen() { delete kPtr; }

WrapperHouse::WrapperHouse() : hPtr(new House()) {}
WrapperHouse::~WrapperHouse() { delete hPtr; }