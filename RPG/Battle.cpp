/**********************************************************************
* Author:			Alexander Ott
* Filename:			Lab08
* Date Created:		02/28/2016
**********************************************************************/

#include "Battle.h"

/**********************************************************************
*																	  *
**********************************************************************/
void Battle::AttackSequence(Opponent * creature, PlayerCharacter & player)
{
	Dice dice;			// Currently testing special attacks!
	int rolled_num = dice.Roll(20);

	int temp_int = player.m_damage_range + rolled_num;

	if (rolled_num == 1)
	{
		cout << "Missed!" << endl;
		temp_int = creature->SpecialAttack();
		player.m_hit_points -= temp_int;
		cout << "You took " << temp_int << " damage." << endl;
	}
	else if (temp_int >= creature->m_armor)
	{
		cout << "Success!" << endl;
		cout << "Creature took " << (temp_int - creature->m_armor) << " damage." << endl;
		creature->m_hit_points -= (temp_int - creature->m_armor);
	}
	else if (rolled_num == 20)
	{
		cout << "Critical Hit!" << endl;
		cout << "Creature took " << ((temp_int + 10) - creature->m_armor) << " damage." << endl;
		creature->m_hit_points -= ((temp_int + 10 )- creature->m_armor);
	}
	else
	{
		player.m_hit_points -= (creature->m_armor - temp_int);
		cout << "Missed!" << endl;
		cout << "You took " << (creature->m_armor - temp_int) << " damage." << endl;
	}
}

/**********************************************************************
*																	  *
**********************************************************************/
void Battle::BlockSequence(Opponent * creature, PlayerCharacter & player)
{
	Dice dice;
	int rolled_num = dice.Roll(20);

	int temp_int = ((player.m_damage_range + dice.Roll(20)) - 10); 
	int temp_defense = creature->m_damage_range - (player.m_armor + 5);

	if (rolled_num == 1)
	{
		cout << "Block was ineffective" << endl;
		temp_int = creature->SpecialAttack();
		player.m_hit_points -= temp_int;
		cout << "You took " << temp_int << " damage." << endl;
	}
	else if (temp_int >= creature->m_armor)
	{
		cout << "Block was effective!" << endl;
		cout << "Creature took " << (temp_int - creature->m_armor) << " damage." << endl;
		creature->m_hit_points -= (temp_int - creature->m_armor);
	}
	else if (temp_defense > 0)
	{
		cout << "Block was ineffective" << endl;
		cout << "You took " << temp_defense << " damage." << endl;
		player.m_hit_points -= temp_defense;
	}
}

/**********************************************************************
*																	  *
**********************************************************************/
void Battle::BerserkSequence(Opponent * creature, PlayerCharacter & player)
{
	Dice dice;
	int rolled_num = dice.Roll(20);

	int temp_int = ((player.m_damage_range + dice.Roll(20)) + 5);
	int temp_defense = creature->m_damage_range - (player.m_armor - 10);

	if (rolled_num == 1)
	{
		cout << "Berserk was ineffective" << endl;
		temp_int = creature->SpecialAttack();
		player.m_hit_points -= temp_int;
		cout << "You took " << temp_int << " damage." << endl;
	}
	else if (temp_int >= creature->m_armor)
	{
		cout << "Berserk was effective!" << endl;
		cout << "Creature took " << (temp_int - creature->m_armor) << " damage." << endl;
		creature->m_hit_points -= (temp_int - creature->m_armor);
	}
	else if (temp_defense > 0)
	{
		cout << "Berserk was ineffective" << endl;
		cout << "You took " << temp_defense << " damage." << endl;
		player.m_hit_points -= temp_defense;
	}
}
