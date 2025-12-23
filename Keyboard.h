#pragma once
#include <iostream>

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

Keyboard::Keyboard()
{
    std::cout << "Keyboard being constructed!" << std::endl;
}

Keyboard::~Keyboard()
{
    std::cout << "Keyboard being destructed!" << std::endl;
}

Keyboard::Key::Key(char keyName) : isPressed(false), frequency(261.63f), isBlackKey(false), tuning(0.0f)
{
    name = keyName;
    std::cout << "Key being constructed!" << std::endl;
}

Keyboard::Key::~Key()
{
    std::cout << "Key being destructed!" << std::endl;
}

void Keyboard::Key::playKey(int time)
{
    if (!isPressed)
    {
        isPressed = true;
        std::cout << "Playing key: " << this->name << " with frequency: " << this->frequency + this->tuning << " Hz for" << time << "seconds" << std::endl;
    }
}

void Keyboard::Key::stopKey()
{
    if (isPressed)
    {
        std::cout << "Stopping key: " << this->name << std::endl;
        isPressed = false;
    }
}

void Keyboard::Key::tuneKey(float newTuning)
{
    tuning += newTuning;
}

void Keyboard::Key::playTremolo()
{
    for (int i = 0; i < 5; ++i)
    {
        playKey(1);
        stopKey();
    }
}//had no clue this was what it was called XD

void Keyboard::playSound(Key& key)
{
    if (mode == "Acoustic" && pedal)
    {
        key.playKey(5);
    }
    else if (mode == "Acoustic" && !pedal)
    {
        key.playKey(2);
        key.stopKey();
    }
}

void Keyboard::changeMode(std::string newMode)
{
    mode = newMode;
}

void Keyboard::displayMode()
{
    std::cout << "Current mode: " << mode << " displayed on LCD screen size: " << lcdScreen << " inches" << std::endl;
}

void Keyboard::playMelody()
{
    std::string melody = "CDEFGABC";
    for (std::string::size_type i = 0; i < melody.size(); ++i)
    {
        std::cout << "Playing note: " << melody[i] << std::endl;
    }
}

struct WrapperKeyboard
{
    WrapperKeyboard() : kbPtr(new Keyboard()) {}
    ~WrapperKeyboard() { delete kbPtr; }
    Keyboard* kbPtr = nullptr;
};