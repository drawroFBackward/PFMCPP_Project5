#pragma once
#include "House.h"

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