#pragma once

#include "Opponent.h"

class Banshee : public Opponent
{
	public:
		Banshee();
		Banshee(const Banshee & copy);
		Banshee & operator = (const Banshee & rhs);
		~Banshee();

		int NormalStrike();
		int Block();
		void Generate();
		void Display();
		void BattleDisplay() const;
		void BattleSound() const;
		int SpecialAttack();
};

