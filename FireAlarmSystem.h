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

struct WrapperFireAlarmSystem
{
    WrapperFireAlarmSystem() : fasPtr(new FireAlarmSystem()) {}
    ~WrapperFireAlarmSystem() { delete fasPtr; }
    FireAlarmSystem* fasPtr = nullptr;
};