/**********************************************************************
* Author:			Alexander Ott
* Filename:			Lab08
* Date Created:		02/28/2016
************************************************************************/

#include "Bear.h"

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
Bear::Bear()
{
	m_name = "Bear";
	m_hit_points = 0;
	m_damage_range = 0;
	m_armor = 0;
	m_hp_roll = "1.20.10";
	m_armor_roll = "1.10.7";
	m_damage_roll = "1.20.10";
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
Bear::Bear(const Bear & copy)
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
Bear::~Bear()
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
Bear & Bear::operator = (const Bear & rhs)
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
int Bear::NormalStrike()
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
int Bear::Block()
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
void Bear::Generate()
{
	m_name = "Bear";
	GenerateHitPoints();
	GenerateArmor();
	GenerateDamageRange();
}

void Bear::Display()
{
	cout << "This is the Bear!" << endl;
}

void Bear::BattleDisplay() const
{
	cout << "__________________" << "\t\t\BEAR BEAR BEAR BEAR BEAR" << endl;
	cout << "__________________" << "\t\t\BEAR BEAR BEAR BEAR BEAR" << endl;
	cout << "NAME: " << m_name << "\t\t\t\BEAR BEAR BEAR BEAR BEAR" << endl;
	cout << "HEALTH: " << m_hit_points << "\t\t\t\BEAR BEAR BEAR BEAR BEAR" << endl;
	cout << "ATTACK: " << m_damage_range << "\t\t\t\BEAR BEAR BEAR BEAR BEAR" << endl;
	cout << "DEFENSE: " << m_armor << "\t\t\t\BEAR BEAR BEAR BEAR BEAR" << endl;
	cout << "__________________" << "\t\t\BEAR BEAR BEAR BEAR BEAR" << endl;
	cout << "__________________" << "\t\t\BEAR BEAR BEAR BEAR BEAR" << endl;
}

void Bear::BattleSound() const
{
	PlaySound(TEXT("Bear_Roar.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

int Bear::SpecialAttack()
{
	cout << "The Bear mauled you!" << endl;
	return 25;
}
