#pragma once
#include <iostream>
#include "Kitchen.h"
#include "Keyboard.h"

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
