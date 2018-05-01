#pragma once

#include "Opponent.h"

class Witch : public Opponent
{
	public:
		Witch();
		Witch(const Witch & copy);
		Witch & operator = (const Witch & rhs);
		~Witch();

		int NormalStrike();
		int Block();
		void Generate();
		void Display();
		void BattleDisplay() const;
		void BattleSound() const;
		int SpecialAttack();
};