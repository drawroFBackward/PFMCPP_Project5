/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4

 Don't #include what you don't use

 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.

 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'

 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )

 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5):

 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your
        wrapper class functions in-class, because that is what
        everyone does after watching the video where I implemented
        them in-class.

 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp:
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h

 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'?
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.

        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const {}
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.

 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */



#pragma once
#include <iostream>
#include <string>
#include "LeakedObjectDetector.h"
#include "CoffeeMaker.h"
#include "FireAlarmSystem.h"


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

struct House
{
    House();
    Keyboard keyboard;
    Kitchen kitchen;
	void partyTime(int numberOfPeople, int hours);
	void startMusicSession();
	~House();
	JUCE_LEAK_DETECTOR(House)
};

House::House()
{
    std::cout << "House being constructed!" << std::endl;
}

House::~House()
{
    std::cout << "House being destructed!" << std::endl;
}

void House::partyTime(int numberOfPeople, int hours)
{
	for (int i = 0; i < hours; ++i)
    {
        std::cout << "Hour " << i + 1 << " of the party!" << std::endl;
        kitchen.prepareBreakfast(numberOfPeople);
		keyboard.playMelody();
	}
	std::cout << "Party is over!" << std::endl;
}

void House::startMusicSession()
{
    keyboard.changeMode("Acoustic");
	keyboard.playSound(keyboard.key_1);
	keyboard.playSound(keyboard.key_2);
	//kinda wanted to do the below, but think it will be covered in later projects
	//for (int i = 1; i < 6; ++i)
    //{
	//	keyboard.playSound(keyboard.("key_" + std::to_string(i)));
	//}
}
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

 // writing Wrapper classes for each UDT





struct WrapperKeyboard
{
    WrapperKeyboard() : kbPtr(new Keyboard()) {}
    ~WrapperKeyboard() { delete kbPtr; }
    Keyboard* kbPtr = nullptr;
};

struct WrapperKitchen
{
    WrapperKitchen() : kPtr(new Kitchen()) {}
    ~WrapperKitchen() { delete kPtr; }
    Kitchen* kPtr = nullptr;
};

struct WrapperHouse
{
    WrapperHouse() : hPtr(new House()) {}
    ~WrapperHouse() { delete hPtr; }
    House* hPtr = nullptr;
};

int main()
{
	WrapperKitchen myKitchen;

	WrapperHouse myHouse;

	myHouse.hPtr->partyTime(3, 2);

	myHouse.hPtr->startMusicSession();

	myKitchen.kPtr->emergencyShutdown();

	myHouse.hPtr->keyboard.key_1.playKey(1);

	myHouse.hPtr->keyboard.key_1.stopKey();

    std::cout << "Playing key: " << myHouse.hPtr->keyboard.key_1.name << " with frequency: " << (myHouse.hPtr->keyboard.key_1.frequency + myHouse.hPtr->keyboard.key_1.tuning) << " Hz for" << 1 << "seconds" << std::endl;

	std::cout << "Stopping key: " << myHouse.hPtr->keyboard.key_1.name << std::endl;

	WrapperCoffeeMaker cm;

	cm.cmPtr->printCurrentIngredients();

	std::cout << "Current water: " << cm.cmPtr->water << ", Coffee Beans: X = " << cm.cmPtr->coffeeBeanX << ", Y = " << cm.cmPtr->coffeeBeanY << std::endl;

    std::cout << "good to go!" << std::endl;
}
