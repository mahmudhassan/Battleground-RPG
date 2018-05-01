/**********************************************************************
* Author:			Alexander Ott
* Filename:			Lab08
* Date Created:		02/28/2016
************************************************************************/

#include "Ogre.h"

/**********************************************************************
*																	  *
**********************************************************************/
Ogre::Ogre()
{
	m_name = "Ogre";
	m_hit_points = 0;
	m_damage_range = 0;
	m_armor = 0;
	m_hp_roll = "2.20.10";
	m_armor_roll = "3.10.5";
	m_damage_roll = "3.10.1";
}

/**********************************************************************
*																	  *
**********************************************************************/
Ogre::Ogre(const Ogre & copy)
{
	*this = copy;
}

/**********************************************************************
*																	  *
**********************************************************************/
Ogre::~Ogre()
{ }

/**********************************************************************
*																	  *
**********************************************************************/
Ogre & Ogre::operator = (const Ogre & rhs)
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
int Ogre::NormalStrike()
{
	Dice dice;
	int temp_strike = 0;

	temp_strike = m_armor + dice.Roll(6);

	return temp_strike;
}

/**********************************************************************
*																	  *
**********************************************************************/
int Ogre::Block()
{
	Dice dice;
	int temp_block = 0;

	temp_block = m_armor + dice.Roll(6);

	return temp_block;
}

/**********************************************************************
*																	  *
**********************************************************************/
void Ogre::Generate()
{
	m_name = "Ogre";
	GenerateHitPoints();
	GenerateArmor();
	GenerateDamageRange();
}

/**********************************************************************
*																	  *
**********************************************************************/
void Ogre::Display()
{
	cout << "This is the Ogre!" << endl;
}

/**********************************************************************
*																	  *
**********************************************************************/
void Ogre::BattleSound() const
{
	PlaySound(TEXT("Ogre_grunt.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

/**********************************************************************
*																	  *
**********************************************************************/
void Ogre::BattleDisplay() const
{
	cout << "__________________" << "\t\t\tOGRE OGRE OGRE OGRE OGRE" << endl;
	cout << "__________________" << "\t\t\tOGRE OGRE OGRE OGRE OGRE" << endl;
	cout << "NAME: " << m_name << "\t\t\t\tOGRE OGRE OGRE OGRE OGRE" << endl;
	cout << "HEALTH: " << m_hit_points << "\t\t\t\tOGRE OGRE OGRE OGRE OGRE" << endl;
	cout << "ATTACK: " << m_damage_range << "\t\t\t\tOGRE OGRE OGRE OGRE OGRE" << endl;
	cout << "DEFENSE: " << m_armor << "\t\t\t\tOGRE OGRE OGRE OGRE OGRE" << endl;
	cout << "__________________" << "\t\t\tOGRE OGRE OGRE OGRE OGRE" << endl;
	cout << "__________________" << "\t\t\tOGRE OGRE OGRE OGRE OGRE" << endl;
}

int Ogre::SpecialAttack()
{
	cout << "The Ogre cruched everybone in your body!" << endl;
	return 1000;
}
