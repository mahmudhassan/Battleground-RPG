#pragma once

#include "PlayerCharacter.h"
#include "Opponent.h"

class Battle
{
	public:
		void AttackSequence(Opponent * creature, PlayerCharacter & player);
		void BlockSequence(Opponent * creature, PlayerCharacter & player);
		void BerserkSequence(Opponent * creature, PlayerCharacter & player);
};