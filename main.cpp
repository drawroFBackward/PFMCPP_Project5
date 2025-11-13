/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */




#include <iostream>
#include <LeakedObjectDetector.h>
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
    ~CoffeeMaker();
	void printCurrentIngredients();
};

CoffeeMaker::CoffeeMaker()
{
    std::cout << "CoffeeMaker being constructed!" << std::endl;
}

CoffeeMaker::~CoffeeMaker()
{
    std::cout << "CoffeeMaker being destructed!" << std::endl;
	std::cout << "Leftover water: " << water << std::endl;
	std::cout << "Leftover Coffee Beans : X = " << coffeeBeanX << ", Y = " << coffeeBeanY << std::endl;
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

void CoffeeMaker::printCurrentIngredients()
{
    std::cout << "Current water: " << this->water << ", Coffee Beans: X = " << this->coffeeBeanX << ", Y = " << this->coffeeBeanY << std::endl;
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
	~FireAlarmSystem();
};

FireAlarmSystem::FireAlarmSystem() : smokeLevel(20.0)
{
    std::cout << "FireAlarmSystem being constructed!" << std::endl;
}

FireAlarmSystem::~FireAlarmSystem()
{
    std::cout << "FireAlarmSystem being destructed!" << std::endl;
    if (detectFire())
    {
        std::cout << "Fire was not put out before system shutdown!" << std::endl;
    }
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
    };
    void playSound(Key key);
    void changeMode(std::string newMode);
    void displayMode();
    void playMelody();
	~Keyboard();

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
	void prepareBreakfast(int numberOfPeople);
	void emergencyShutdown();
	~Kitchen();
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
/*
 new UDT 5:
 with 2 member functions
 */
struct House
{
    House();
    Keyboard keyboard;
    Kitchen kitchen;
	void partyTime(int numberOfPeople, int hours);
	void startMusicSession();
	~House();
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

int main()
{
	Kitchen myKitchen;

	House myHouse;

	//myHouse.partyTime(3, 2);

	//myHouse.startMusicSession();

	//myKitchen.emergencyShutdown();

	myHouse.keyboard.key_1.playKey(1);

	myHouse.keyboard.key_1.stopKey();

    std::cout << "Playing key: " << myHouse.keyboard.key_1.name << " with frequency: " << (myHouse.keyboard.key_1.frequency + myHouse.keyboard.key_1.tuning) << " Hz for" << 1 << "seconds" << std::endl;

	std::cout << "Stopping key: " << myHouse.keyboard.key_1.name << std::endl;

	CoffeeMaker cm;

	cm.printCurrentIngredients();

	std::cout << "Current water: " << cm.water << ", Coffee Beans: X = " << cm.coffeeBeanX << ", Y = " << cm.coffeeBeanY << std::endl;

    std::cout << "good to go!" << std::endl;
}
