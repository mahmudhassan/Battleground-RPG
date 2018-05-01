/**********************************************************************
* Author:			Alexander Ott
* Filename:			Lab08
* Date Created:		02/28/2016
************************************************************************/

#include "Zombie.h"

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
Zombie::Zombie()
{
	m_name = "Zombie";
	m_hit_points = 0;
	m_damage_range = 0;
	m_armor = 0;
	m_hp_roll = "1.20.5";
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
Zombie::Zombie(const Zombie & copy)
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
Zombie::~Zombie()
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
Zombie & Zombie::operator = (const Zombie & rhs)
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
int Zombie::NormalStrike()
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
int Zombie::Block()
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
void Zombie::Generate()
{
	m_name = "Zombie";
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
void Zombie::Display()
{
	cout << "This is the Zombie!" << endl;
}

void Zombie::BattleSound() const
{
	PlaySound(TEXT("Zombie_Yell.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void Zombie::BattleDisplay() const
{
	cout << "__________________"		 << "\t\t\tZOMBIE ZOMBIE ZOMBIE ZOMBIE ZOMBIE" << endl;
	cout << "__________________"		 << "\t\t\tZOMBIE ZOMBIE ZOMBIE ZOMBIE ZOMBIE" << endl;
	cout << "NAME: " << m_name			 << "\t\t\t\tZOMBIE ZOMBIE ZOMBIE ZOMBIE ZOMBIE" << endl;
	cout << "HEALTH: " << m_hit_points   << "\t\t\t\tZOMBIE ZOMBIE ZOMBIE ZOMBIE ZOMBIE" << endl;
	cout << "ATTACK: " << m_damage_range << "\t\t\t\tZOMBIE ZOMBIE ZOMBIE ZOMBIE ZOMBIE" << endl;
	cout << "DEFENSE: " << m_armor		 << "\t\t\t\tZOMBIE ZOMBIE ZOMBIE ZOMBIE ZOMBIE" << endl;
	cout << "__________________"		 << "\t\t\tZOMBIE ZOMBIE ZOMBIE ZOMBIE ZOMBIE" << endl;
	cout << "__________________"		 << "\t\t\tZOMBIE ZOMBIE ZOMBIE ZOMBIE ZOMBIE" << endl;
}

int Zombie::SpecialAttack()
{
	cout << "The Zombie ate your brains!" << endl;
	return 500;
}
