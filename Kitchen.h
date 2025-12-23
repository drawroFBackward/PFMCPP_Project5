#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"
#include "CoffeeMaker.h"
#include "FireAlarmSystem.h"

struct Kitchen
{
    Kitchen();
    CoffeeMaker coffeeMaker;
    FireAlarmSystem fireAlarmSystem;
    void prepareBreakfast(int numberOfPeople);
    void emergencyShutdown();
    ~Kitchen();
    JUCE_LEAK_DETECTOR(Kitchen)
};
