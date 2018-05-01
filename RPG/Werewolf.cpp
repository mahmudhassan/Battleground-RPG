/**********************************************************************
* Author:			Alexander Ott
* Filename:			Lab08
* Date Created:		02/28/2016
************************************************************************/

#include "Werewolf.h"

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
Werewolf::Werewolf()
{
	m_name = "Werewolf";
	m_hit_points = 0;
	m_damage_range = 0;
	m_armor = 0;
	m_hp_roll = "2.20.15";
	m_armor_roll = "1.10.0";
	m_damage_roll = "2.10.15";
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
Werewolf::Werewolf(const Werewolf & copy)
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
Werewolf::~Werewolf()
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
Werewolf & Werewolf::operator = (const Werewolf & rhs)
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
int Werewolf::NormalStrike()
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
int Werewolf::Block()
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
void Werewolf::Generate()
{
	m_name = "Werewolf";
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
void Werewolf::Display()
{
	cout << "This is the Werewolf!" << endl;
}

void Werewolf::BattleSound() const
{
	PlaySound(TEXT("Wolf_howling.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void Werewolf::BattleDisplay() const
{
	cout << "__________________" << "\t\t\tWEREWOLF WEREWOLF WEREWOLF WEREWOLF WEREWOLF" << endl;
	cout << "__________________" << "\t\t\tWEREWOLF WEREWOLF WEREWOLF WEREWOLF WEREWOLF" << endl;
	cout << "NAME: " << m_name << "\t\t\t\tWEREWOLF WEREWOLF WEREWOLF WEREWOLF WEREWOLF" << endl;
	cout << "HEALTH: " << m_hit_points << "\t\t\t\tWEREWOLF WEREWOLF WEREWOLF WEREWOLF WEREWOLF" << endl;
	cout << "ATTACK: " << m_damage_range << "\t\t\t\tWEREWOLF WEREWOLF WEREWOLF WEREWOLF WEREWOLF" << endl;
	cout << "DEFENSE: " << m_armor << "\t\t\t\tWEREWOLF WEREWOLF WEREWOLF WEREWOLF WEREWOLF" << endl;
	cout << "__________________" << "\t\t\tWEREWOLF WEREWOLF WEREWOLF WEREWOLF WEREWOLF" << endl;
	cout << "__________________" << "\t\t\tWEREWOLF WEREWOLF WEREWOLF WEREWOLF WEREWOLF" << endl;
}

int Werewolf::SpecialAttack()
{
	cout << "The Werewolf huffed and puffed an blew your house down!" << endl;
	return 60;
}
