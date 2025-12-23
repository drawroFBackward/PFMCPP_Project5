#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

struct FireAlarmSystem
{
    FireAlarmSystem();
    std::string smokeDetector = "Siemens";
    std::string speaker = "There's a fire";
    int serialNumber = 1;
    std::string camera = "Canon";
    double smokeLevel;
    bool detectFire();
    void soundAlarm(std::string announcement);
    void alertFireDepartment(int phoneLine);
    void putOutFire();
    ~FireAlarmSystem();
    JUCE_LEAK_DETECTOR(FireAlarmSystem)
};
