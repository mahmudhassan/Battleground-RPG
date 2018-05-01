/**********************************************************************
* Author:			Alexander Ott
* Filename:			Lab08
* Date Created:		02/28/2016
************************************************************************/

#include "Bandit.h"

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
Bandit::Bandit() 
{ 
	m_name = "Bandit";
	m_hit_points = 0;
	m_damage_range = 0;
	m_armor = 0;
	m_hp_roll = "4.20.5";
	m_armor_roll = "2.10.5";
	m_damage_roll = "2.10.2";
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
Bandit::Bandit(const Bandit & copy)
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
Bandit::~Bandit()
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
Bandit & Bandit::operator = (const Bandit & rhs)
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
int Bandit::NormalStrike()
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
int Bandit::Block()
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
void Bandit::Generate()
{
	m_name = "Bandit";
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
void Bandit::Display()
{
	cout << "This is the Bandit!" << endl;
}

void Bandit::BattleDisplay() const
{
	cout << "__________________" << "\t\t\tBANDIT BANDIT BANDIT BANDIT BANDIT" << endl;
	cout << "__________________" << "\t\t\tBANDIT BANDIT BANDIT BANDIT BANDIT" << endl;
	cout << "NAME: " << m_name << "\t\t\t\tBANDIT BANDIT BANDIT BANDIT BANDIT" << endl;
	cout << "HEALTH: " << m_hit_points << "\t\t\t\tBANDIT BANDIT BANDIT BANDIT BANDIT" << endl;
	cout << "ATTACK: " << m_damage_range << "\t\t\t\tBANDIT BANDIT BANDIT BANDIT BANDIT" << endl;
	cout << "DEFENSE: " << m_armor << "\t\t\t\tBANDIT BANDIT BANDIT BANDIT BANDIT" << endl;
	cout << "__________________" << "\t\t\tBANDIT BANDIT BANDIT BANDIT BANDIT" << endl;
	cout << "__________________" << "\t\t\tBANDIT BANDIT BANDIT BANDIT BANDIT" << endl;
}

void Bandit::BattleSound() const
{
	PlaySound(TEXT("Sword_Unsheathed.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

int Bandit::SpecialAttack()
{
	cout << "The Bandit stabbed you in the belly!" << endl;
	return 30;
}
