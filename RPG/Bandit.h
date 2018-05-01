#pragma once

#include "Opponent.h"
class Bandit : public Opponent
{
	public:
		Bandit();
		Bandit(const Bandit & copy);
		Bandit & operator = (const Bandit & rhs);
		~Bandit();

		int NormalStrike();
		int Block();
		void Generate();
		void Display();
		void BattleDisplay() const;
		void BattleSound() const;
		int SpecialAttack();
};