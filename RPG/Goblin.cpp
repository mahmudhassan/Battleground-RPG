/**********************************************************************
* Author:			Alexander Ott
* Filename:			Lab08
* Date Created:		02/28/2016
************************************************************************/

#include "Goblin.h"

/**********************************************************************
*																	  *
**********************************************************************/
Goblin::Goblin()
{
	m_name = "Goblin";
	m_hit_points = 0;
	m_damage_range = 0;
	m_armor = 0;
	m_hp_roll = "1.20.1";
	m_armor_roll = "1.6.2";
	m_damage_roll = "1.6.2";
}

/**********************************************************************
*																	  *
**********************************************************************/
Goblin::Goblin(const Goblin & copy)
{
	*this = copy;
}

/**********************************************************************
*																	  *
**********************************************************************/
Goblin::~Goblin()
{ }

/**********************************************************************
*																	  *
**********************************************************************/
Goblin & Goblin::operator = (const Goblin & rhs)
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
*																	  *
**********************************************************************/
int Goblin::NormalStrike()
{
	Dice dice;
	int temp_strike = 0;

	temp_strike = m_armor + dice.Roll(6);

	return temp_strike;
}

/**********************************************************************
*																	  *
**********************************************************************/
int Goblin::Block()
{
	Dice dice;
	int temp_block = 0;

	temp_block = m_armor + dice.Roll(6);

	return temp_block;
}

/**********************************************************************
*																	  *
**********************************************************************/
void Goblin::Generate()
{
	m_name = "Goblin";
	GenerateHitPoints();
	GenerateArmor();
	GenerateDamageRange();
}

/**********************************************************************
*																	  *
**********************************************************************/
void Goblin::Display()
{
	cout << "This is the Goblin!" << endl;
}

/**********************************************************************
*																	  *
**********************************************************************/
void Goblin::BattleSound() const
{
	PlaySound(TEXT("Goblin_Laugh.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

/**********************************************************************
*																	  *
**********************************************************************/
void Goblin::BattleDisplay() const
{
	cout << "__________________" << "\t\t\tGOBLIN GOBLIN GOBLIN GOBLIN GOBLIN" << endl;
	cout << "__________________" << "\t\t\tGOBLIN GOBLIN GOBLIN GOBLIN GOBLIN" << endl;
	cout << "NAME: " << m_name << "\t\t\t\tGOBLIN GOBLIN GOBLIN GOBLIN GOBLIN" << endl;
	cout << "HEALTH: " << m_hit_points << "\t\t\t\tGOBLIN GOBLIN GOBLIN GOBLIN GOBLIN" << endl;
	cout << "ATTACK: " << m_damage_range << "\t\t\t\tGOBLIN GOBLIN GOBLIN GOBLIN GOBLIN" << endl;
	cout << "DEFENSE: " << m_armor << "\t\t\t\tGOBLIN GOBLIN GOBLIN GOBLIN GOBLIN" << endl;
	cout << "__________________" << "\t\t\tGOBLIN GOBLIN GOBLIN GOBLIN GOBLIN" << endl;
	cout << "__________________" << "\t\t\tGOBLIN GOBLIN GOBLIN GOBLIN GOBLIN" << endl;
}

int Goblin::SpecialAttack()
{
	cout << "The Goblin hit you over the head with a shovel!" << endl;
	return 5;
}
