#pragma once
#include "Kitchen.h"

Kitchen::Kitchen()
{
    std::cout << "Kitchen being constructed!" << std::endl;
}

Kitchen::~Kitchen()
{
    std::cout << "Kitchen being destructed!" << std::endl;
}

void Kitchen::prepareBreakfast(int numberOfPeople)
{
    for (int i = 0; i < numberOfPeople; ++i)
    {
        coffeeMaker.makeDefaultCoffee();
    }
}

void Kitchen::emergencyShutdown()
{
    if (fireAlarmSystem.detectFire())
    {
        fireAlarmSystem.soundAlarm("Emergency! Fire detected in the kitchen!");
        fireAlarmSystem.alertFireDepartment(911);
        fireAlarmSystem.putOutFire();
    }
}