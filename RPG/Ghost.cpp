/**********************************************************************
* Author:			Alexander Ott
* Filename:			Lab08
* Date Created:		02/28/2016
************************************************************************/

#include "Ghost.h"

/**********************************************************************
* Purpose:
*
* Precondition:
*
*
* Postcondition:
*
*
**********************************************************************/
Ghost::Ghost()
{
	m_name = "Ghost";
	m_hit_points = 0;
	m_damage_range = 0;
	m_armor = 0;
	m_hp_roll = "1.20.0";
	m_armor_roll = "1.10.0";
	m_damage_roll = "1.10.0";
}

/**********************************************************************
* Purpose:
*
* Precondition:
*
*
* Postcondition:
*
*
**********************************************************************/
Ghost::Ghost(const Ghost & copy)
{
	*this = copy;
}

/**********************************************************************
* Purpose:
*
* Precondition:
*
*
* Postcondition:
*
*
**********************************************************************/
Ghost::~Ghost()
{ }

/**********************************************************************
* Purpose:
*
* Precondition:
*
*
* Postcondition:
*
*
**********************************************************************/
Ghost & Ghost::operator = (const Ghost & rhs)
{
	if (this != &rhs)
	{
		m_name = rhs.m_name;

		m_hit_points = rhs.m_hit_points;
		m_damage_range = rhs.m_damage_range;
		m_armor = rhs.m_armor;

		m_hp_roll = rhs.m_hp_roll;
		m_armor_roll = rhs.m_armor_roll;
		m_damage_roll = rhs.m_damage_roll;
	}

	return *this;
}

/**********************************************************************
* Purpose:
*
* Precondition:
*
*
* Postcondition:
*
*
**********************************************************************/
int Ghost::NormalStrike()
{
	Dice dice;
	int temp_strike = 0;

	temp_strike = m_armor + dice.Roll(6);

	return temp_strike;
}

/**********************************************************************
* Purpose:
*
* Precondition:
*
*
* Postcondition:
*
*
**********************************************************************/
int Ghost::Block()
{
	Dice dice;
	int temp_block = 0;

	temp_block = m_armor + dice.Roll(6);

	return temp_block;
}

/**********************************************************************
* Purpose:
*
* Precondition:
*
*
* Postcondition:
*
*
**********************************************************************/
void Ghost::Generate()
{
	m_name = "Ghost";
	GenerateHitPoints();
	GenerateArmor();
	GenerateDamageRange();
}

/**********************************************************************
* Purpose:
*
* Precondition:
*
*
* Postcondition:
*
*
**********************************************************************/
void Ghost::Display()
{
	cout << "This is the Ghost!" << endl;
}

void Ghost::BattleDisplay() const
{
	cout << "__________________" << "\t\t\GHOST GHOST GHOST GHOST GHOST" << endl;
	cout << "__________________" << "\t\t\GHOST GHOST GHOST GHOST GHOST" << endl;
	cout << "NAME: " << m_name << "\t\t\t\GHOST GHOST GHOST GHOST GHOST" << endl;
	cout << "HEALTH: " << m_hit_points << "\t\t\t\GHOST GHOST GHOST GHOST GHOST" << endl;
	cout << "ATTACK: " << m_damage_range << "\t\t\t\GHOST GHOST GHOST GHOST GHOST" << endl;
	cout << "DEFENSE: " << m_armor << "\t\t\t\GHOST GHOST GHOST GHOST GHOST" << endl;
	cout << "__________________" << "\t\t\GHOST GHOST GHOST GHOST GHOST" << endl;
	cout << "__________________" << "\t\t\GHOST GHOST GHOST GHOST GHOST" << endl;
}

void Ghost::BattleSound() const
{
	PlaySound(TEXT("Ghost_sound.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

int Ghost::SpecialAttack()
{
	cout << "The Ghost has haunted your memorys and put you in a daze!" << endl;
	return 5;
}
