/**********************************************************************
* Author:			Alexander Ott
* Filename:			Lab08
* Date Created:		02/28/2016
************************************************************************/

#include "Banshee.h"

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
Banshee::Banshee()
{
	m_name = "Banshee";
	m_hit_points = 0;
	m_damage_range = 0;
	m_armor = 0;
	m_hp_roll = "1.20.20";
	m_armor_roll = "1.6.20";
	m_damage_roll = "1.6.20";
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
Banshee::Banshee(const Banshee & copy)
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
Banshee::~Banshee()
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
Banshee & Banshee::operator = (const Banshee & rhs)
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
int Banshee::NormalStrike()
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
int Banshee::Block()
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
void Banshee::Generate()
{
	m_name = "Banshee";
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
void Banshee::Display()
{
	cout << "This is the Banshee!" << endl;
}

void Banshee::BattleDisplay() const
{
	cout << "__________________" << "\t\t\BANSHEE BANSHEE BANSHEE BANSHEE BANSHEE" << endl;
	cout << "__________________" << "\t\t\BANSHEE BANSHEE BANSHEE BANSHEE BANSHEE" << endl;
	cout << "NAME: " << m_name << "\t\t\t\BANSHEE BANSHEE BANSHEE BANSHEE BANSHEE" << endl;
	cout << "HEALTH: " << m_hit_points << "\t\t\t\BANSHEE BANSHEE BANSHEE BANSHEE BANSHEE" << endl;
	cout << "ATTACK: " << m_damage_range << "\t\t\t\BANSHEE BANSHEE BANSHEE BANSHEE BANSHEE" << endl;
	cout << "DEFENSE: " << m_armor << "\t\t\t\BANSHEE BANSHEE BANSHEE BANSHEE BANSHEE" << endl;
	cout << "__________________" << "\t\t\BANSHEE BANSHEE BANSHEE BANSHEE BANSHEE" << endl;
	cout << "__________________" << "\t\t\BANSHEE BANSHEE BANSHEE BANSHEE BANSHEE" << endl;
}

void Banshee::BattleSound() const
{
	PlaySound(TEXT("Banshee_scream.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

int Banshee::SpecialAttack()
{
	cout << "The Banshee shrieked, you now have a terribel headache!" << endl;
	return 5;
}
