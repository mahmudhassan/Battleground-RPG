#pragma once

#include "Opponent.h"

class Goblin : public Opponent
{
	public:
		Goblin();
		Goblin(const Goblin & copy);
		Goblin & operator = (const Goblin & rhs);
		~Goblin();

		int NormalStrike();
		int Block();
		void Generate();
		void Display();
		void BattleDisplay() const;
		void BattleSound() const;
		int SpecialAttack();
};


