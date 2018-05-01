#pragma once

#include "Opponent.h"

class Zombie : public Opponent
{
	public:
		Zombie();
		Zombie(const Zombie & copy);
		~Zombie();
		Zombie & operator = (const Zombie & rhs);

		int NormalStrike();
		int Block();
		void Generate();
		void Display();
		void BattleDisplay() const;
		void BattleSound() const;
		int SpecialAttack();
};