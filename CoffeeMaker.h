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
    JUCE_LEAK_DETECTOR(CoffeeMaker)
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

struct WrapperCoffeeMaker
{
    WrapperCoffeeMaker() : cmPtr(new CoffeeMaker()) {}
    ~WrapperCoffeeMaker() { delete cmPtr; }
    CoffeeMaker* cmPtr = nullptr;
};