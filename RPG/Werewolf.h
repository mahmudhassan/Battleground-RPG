#pragma once

#include "Opponent.h"

class Werewolf : public Opponent
{
	public:
		Werewolf();
		Werewolf(const Werewolf & copy);
		Werewolf & operator = (const Werewolf & rhs);
		~Werewolf();

		int NormalStrike();
		int Block();
		void Generate();
		void Display();
		void BattleDisplay() const;
		void BattleSound() const;
		int SpecialAttack();
};
