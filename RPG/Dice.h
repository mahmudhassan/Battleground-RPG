#pragma once

#include <random>

class Dice
{
	public:
		Dice();
		int Roll(int num_sides);

	private:
		int GetRandomNum(int min, int max);
		int m_sides;
};