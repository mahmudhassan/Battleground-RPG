#pragma once

#include "Opponent.h"

class Ogre : public Opponent
{
	public:
		Ogre();
		Ogre(const Ogre & copy);
		Ogre & operator = (const Ogre & rhs);
		~Ogre();

		int NormalStrike();
		int Block();
		void Generate();
		void Display();
		void BattleDisplay() const;
		void BattleSound() const;
		int SpecialAttack();
};
