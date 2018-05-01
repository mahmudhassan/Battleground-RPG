#pragma once

#include "Opponent.h"

class Bear : public Opponent
{
	public:
		Bear();
		Bear(const Bear & copy);
		~Bear();
		Bear & operator = (const Bear & rhs);

		int NormalStrike();
		int Block();
		void Generate();
		void Display();
		void BattleDisplay() const;
		void BattleSound() const;
		int SpecialAttack();
};
