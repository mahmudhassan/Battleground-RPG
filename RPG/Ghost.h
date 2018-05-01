#pragma once

#include "Opponent.h"

class Ghost : public Opponent
{
	public:
		Ghost();
		Ghost(const Ghost & copy);
		Ghost & operator = (const Ghost & rhs);
		~Ghost();

		int NormalStrike();
		int Block();
		void Generate();
		void Display();
		void BattleDisplay() const;
		void BattleSound() const;
		int SpecialAttack();
};