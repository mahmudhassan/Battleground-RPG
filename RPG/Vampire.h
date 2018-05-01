#pragma once

#include "Opponent.h"

class Vampire : public Opponent
{
	public:
		Vampire();
		Vampire(const Vampire & copy);
		Vampire & operator = (const Vampire & rhs);
		~Vampire();

		int NormalStrike();
		int Block();
		void Generate();
		void Display();
		void BattleDisplay() const;
		void BattleSound() const;
		int SpecialAttack();
};