/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */

/*
 copied UDT 1:
 */
struct CoffeeMaker
{
    CoffeeMaker();
    int water = 100;
    int coffeeBeanX = 10;
    int coffeeBeanY = 10;
    int coffeeAmount = 0;
    std::string interface = "Touchscreen";
    int timer = 10;
    void makeCoffee(int amountOfWater, int amountOfCoffeeBeanX, int amountOfCoffeeBeanY);
    void receiveCoffeeRequest(int amountOfWater, int amountOfCoffeeBeanX, int amountOfCoffeeBeanY);
    void requestForRefill();
    void makeDefaultCoffee();
};

CoffeeMaker::CoffeeMaker()
{
    std::cout << "CoffeeMaker being constructed!" << std::endl;
}

void CoffeeMaker::makeCoffee(int amountOfWater, int amountOfCoffeeBeanX, int amountOfCoffeeBeanY)
{
    coffeeAmount += ((amountOfWater / 10) + (amountOfCoffeeBeanX + amountOfCoffeeBeanY) / 20) * timer;
}

void CoffeeMaker::receiveCoffeeRequest(int amountOfWater, int amountOfCoffeeBeanX, int amountOfCoffeeBeanY)
{
    if (amountOfWater > 0 && amountOfCoffeeBeanX > 0 && amountOfCoffeeBeanY > 0)
    {
        std::cout << "Coffee request received." << std::endl;
        makeCoffee(amountOfWater, amountOfCoffeeBeanX, amountOfCoffeeBeanY);
    }
    else
    {
        requestForRefill();
    }
}

void CoffeeMaker::requestForRefill()
{
    std::cout << "Refill ingredients." << std::endl;
}

void CoffeeMaker::makeDefaultCoffee()
{
    for (int i = 0; i < timer; ++i)
    {
        std::cout << "Making coffee" << std::endl;
        std::cout << "time left till coffee is ready = " << timer - i << std::endl;
        coffeeAmount += 3;
        --water;
        --coffeeBeanY;
        --coffeeBeanX;
        std::cout << "current coffee amount = " << coffeeAmount << std::endl;

        if (water == 0 || coffeeBeanX == 0 || coffeeBeanY == 0)
        {
            if (i == timer)
            {
                std::cout << "finished making coffee" << std::endl;
            }
            std::cout << "out of ingredients" << std::endl;
            return;
        }
        std::cout << "finished making coffee" << std::endl;
    }
}
/*
 copied UDT 2:
 */
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
};

FireAlarmSystem::FireAlarmSystem() : smokeLevel(20.0)
{
    std::cout << "FireAlarmSystem being constructed!" << std::endl;
}

bool FireAlarmSystem::detectFire()
{
    return smokeDetector == "Siemens" && smokeLevel > 50.0;
}

void FireAlarmSystem::soundAlarm(std::string announcement)
{
    if (detectFire())
    {
        std::cout << announcement << std::endl;
    }
}

void FireAlarmSystem::alertFireDepartment(int phoneLine)
{
    if (detectFire() && phoneLine > 0 && camera == "Canon")
    {
        std::cout << "Alerting fire department." << std::endl;
        // pretend to send camera footage and call fire department eg. callFireDept(phoneLine); sendFootage(camera, phoneLine);
    }
}

void FireAlarmSystem::putOutFire()
{
    while (detectFire())
    {
        smokeLevel -= 10.0;
        std::cout << "Putting out fire, current smoke level: " << smokeLevel << std::endl;
        if (smokeLevel <= 0.0)
        {
            std::cout << "Fire put out!" << std::endl;
            smokeLevel = 0.0;
            return;
        }
    }
}
/*
 copied UDT 3:
 */
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
        Key();
        char name;
        bool isPressed;
        float frequency;
        bool isBlackKey;
        float tuning;
        void playKey(int time);
        void stopKey();
        void tuneKey(float newTuning);
        void playTremolo();
    };
    void playSound(Key key);
    void changeMode(std::string newMode);
    void displayMode();
    void playMelody();

    Key key_1;
};

Keyboard::Keyboard()
{
    std::cout << "Keyboard being constructed!" << std::endl;
}

Keyboard::Key::Key() : name('C'), isPressed(false), frequency(261.63f), isBlackKey(false), tuning(0.0f)
{
    std::cout << "Key being constructed!" << std::endl;
}

void Keyboard::Key::playKey(int time)
{
    if (!isPressed)
    {
        isPressed = true;
        std::cout << "Playing key: " << name << " with frequency: " << frequency + tuning << " Hz for" << time << "seconds" << std::endl;
    }
}

void Keyboard::Key::stopKey()
{
    if (isPressed)
    {
        std::cout << "Stopping key: " << name << std::endl;
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

void Keyboard::playSound(Key key)
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
/*
 new UDT 4:
 with 2 member functions
 */
struct Kitchen
{
    Kitchen();
    CoffeeMaker coffeeMaker;
    FireAlarmSystem fireAlarmSystem;
    void startMorningRoutine();
	void emergencyProtocol();
};
/*
 new UDT 5:
 with 2 member functions
 */
struct House
{
    House();
    Keyboard keyboard;
    Kitchen kitchen;
    void relax();
	void dailyChores();
};
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
