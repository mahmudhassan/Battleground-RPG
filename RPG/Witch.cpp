/**********************************************************************
* Author:			Alexander Ott
* Filename:			Lab08
* Date Created:		02/28/2016
************************************************************************/

#include "Witch.h"

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
Witch::Witch()
{
	m_name = "Witch";
	m_hit_points = 0;
	m_damage_range = 0;
	m_armor = 0;
	m_hp_roll = "1.20.10";
	m_armor_roll = "3.6.10";
	m_damage_roll = "3.6.10";
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
Witch::Witch(const Witch & copy)
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
Witch::~Witch()
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
Witch & Witch::operator = (const Witch & rhs)
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
int Witch::NormalStrike()
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
int Witch::Block()
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
void Witch::Generate()
{
	m_name = "Witch";
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
void Witch::Display()
{
	cout << "This is the Witch!" << endl;
}

void Witch::BattleDisplay() const
{
	cout << "__________________" << "\t\t\WITCH WITCH WITCH WITCH WITCH" << endl;
	cout << "__________________" << "\t\t\WITCH WITCH WITCH WITCH WITCH" << endl;
	cout << "NAME: " << m_name << "\t\t\t\WITCH WITCH WITCH WITCH WITCH" << endl;
	cout << "HEALTH: " << m_hit_points << "\t\t\t\WITCH WITCH WITCH WITCH WITCH" << endl;
	cout << "ATTACK: " << m_damage_range << "\t\t\t\WITCH WITCH WITCH WITCH WITCH" << endl;
	cout << "DEFENSE: " << m_armor << "\t\t\t\WITCH WITCH WITCH WITCH WITCH" << endl;
	cout << "__________________" << "\t\t\WITCH WITCH WITCH WITCH WITCH" << endl;
	cout << "__________________" << "\t\t\WITCH WITCH WITCH WITCH WITCH" << endl;
 
}

void Witch::BattleSound() const
{
	PlaySound(TEXT("Witch Laughing.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

int Witch::SpecialAttack()
{
	cout << "The Witch cast a heinous curse on you!" << endl;
	return 30;
}
