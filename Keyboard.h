#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

struct Keyboard
{
    Keyboard();
    int numberOfKeys = 88;
    int volume = 100;
    std::string mode = "Acoustic";
    double lcdScreen = 10.0;
    bool pedal = false;
    struct Key
    {
        Key(char keyName);
        char name;
        bool isPressed;
        float frequency;
        bool isBlackKey;
        float tuning;
        void playKey(int time);
        void stopKey();
        void tuneKey(float newTuning);
        void playTremolo();
        ~Key();
        JUCE_LEAK_DETECTOR(Key)
    };
    void playSound(Key& key);
    void changeMode(std::string newMode);
    void displayMode();
    void playMelody();
    ~Keyboard();
    JUCE_LEAK_DETECTOR(Keyboard)
        Key key_1 = Key('C'), key_2 = Key('D'), key_3 = Key('E'), key_4 = Key('F'), key_5 = Key('G');
};
