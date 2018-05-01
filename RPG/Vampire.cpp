/**********************************************************************
* Author:			Alexander Ott
* Filename:			Lab08
* Date Created:		02/28/2016
************************************************************************/

#include "Vampire.h"

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
Vampire::Vampire()
{
	m_name = "Vampire";
	m_hit_points = 0;
	m_damage_range = 0;
	m_armor = 0;
	m_hp_roll = "2.20.10";
	m_armor_roll = "2.10.10";
	m_damage_roll = "2.10.10";
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
Vampire::Vampire(const Vampire & copy)
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
Vampire::~Vampire()
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
Vampire & Vampire::operator = (const Vampire & rhs)
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
int Vampire::NormalStrike()
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
int Vampire::Block()
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
void Vampire::Generate()
{
	m_name = "Vampire";
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
void Vampire::Display()
{
	cout << "This is the Vampire!" << endl;
}

void Vampire::BattleSound() const
{
	PlaySound(TEXT("Vampire_sound.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void Vampire::BattleDisplay() const
{
	cout << "__________________" << "\t\t\tVAMPIRE VAMPIRE VAMPIRE VAMPIRE VAMPIRE" << endl;
	cout << "__________________" << "\t\t\tVAMPIRE VAMPIRE VAMPIRE VAMPIRE VAMPIRE" << endl;
	cout << "NAME: " << m_name << "\t\t\t\tVAMPIRE VAMPIRE VAMPIRE VAMPIRE VAMPIRE" << endl;
	cout << "HEALTH: " << m_hit_points << "\t\t\t\tVAMPIRE VAMPIRE VAMPIRE VAMPIRE VAMPIRE" << endl;
	cout << "ATTACK: " << m_damage_range << "\t\t\t\tVAMPIRE VAMPIRE VAMPIRE VAMPIRE VAMPIRE" << endl;
	cout << "DEFENSE: " << m_armor << "\t\t\t\tVAMPIRE VAMPIRE VAMPIRE VAMPIRE VAMPIRE" << endl;
	cout << "__________________" << "\t\t\tVAMPIRE VAMPIRE VAMPIRE VAMPIRE VAMPIRE" << endl;
	cout << "__________________" << "\t\t\tVAMPIRE VAMPIRE VAMPIRE VAMPIRE VAMPIRE" << endl;
}

int Vampire::SpecialAttack()
{
	cout << "The Vampire sucked your blood!" << endl;
	return 100;
}
