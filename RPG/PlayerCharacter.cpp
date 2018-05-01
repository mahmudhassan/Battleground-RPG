/**********************************************************************
* Author:			Alexander Ott
* Filename:			Lab08
* Date Created:		02/28/2016
************************************************************************/
#include <iostream>
using std::cout;
using std::endl;

#include "PlayerCharacter.h"

/**********************************************************************
*																	  *
**********************************************************************/
PlayerCharacter::PlayerCharacter()
{ 
	m_armor = 0;
	m_hit_points = 0;
	m_damage_range = 0;
	m_gold = 0;
	m_experience = 0;
	m_level = 1;
	m_original_health = 0;
	m_name = "";
}

/**********************************************************************
*																	  *
**********************************************************************/
PlayerCharacter::PlayerCharacter(String name, int hit_points, int damage_range, int armor)
{ 
	m_name = name;
	m_hit_points = hit_points;
	m_damage_range = damage_range;
	m_armor = armor;
}

/**********************************************************************
*																	  *
**********************************************************************/
PlayerCharacter & PlayerCharacter::operator = (const PlayerCharacter & rhs)
{
	if (this != &rhs)
	{
		m_name = rhs.m_name;
		m_hit_points = rhs.m_hit_points;
		m_damage_range = rhs.m_damage_range;
		m_armor = rhs.m_armor;
	}

	return *this;
}

/**********************************************************************
*																	  *
**********************************************************************/
int PlayerCharacter::PlayerDiceRoll(int attribute, int num_sides)
{
	int random = 0;
	Dice temp;

	random = temp.Roll(num_sides);

	return random;
}

/**********************************************************************
*																	  *
**********************************************************************/
void PlayerCharacter::GenerateHitPoints()
{
	m_hit_points = 10000 + PlayerDiceRoll(0, 10);
}

/**********************************************************************
*																	  *
**********************************************************************/
void PlayerCharacter::GenerateArmor()
{
	m_armor = 10000 + PlayerDiceRoll(0, 5);
}

/**********************************************************************
*																	  *
**********************************************************************/
void PlayerCharacter::GenerateDamageRange()
{
	m_damage_range = 10000 + PlayerDiceRoll(0, 5);
}

/**********************************************************************
*																	  *
**********************************************************************/
void PlayerCharacter::CreateCharacter(String name)
{
	m_name = name;
	GenerateHitPoints();
	GenerateDamageRange();
	GenerateArmor();
	m_original_health = m_hit_points;
}

/**********************************************************************
*																	  *
**********************************************************************/
void PlayerCharacter::Display() const
{
	cout << "NAME: " << m_name << endl;
	cout << "HEALTH: "<< m_hit_points << endl;
	cout << "ATTACK: " << m_damage_range << endl;
	cout << "DEFENSE: " << m_armor << endl;
}


/**********************************************************************
*																	  *
**********************************************************************/
void PlayerCharacter::BattleDisplay() const
{
	cout << "PLAYER ONE  PLAYER ONE  PLAYER ONE\t\t\t" << "__________________" << endl;
	cout << "PLAYER ONE  PLAYER ONE  PLAYER ONE\t\t\t" << "NAME: " << m_name << "" << endl;
	cout << "PLAYER ONE  PLAYER ONE  PLAYER ONE\t\t\t" << "HEALTH: " << m_hit_points << "" << endl;
	cout << "PLAYER ONE  PLAYER ONE  PLAYER ONE\t\t\t" << "ATTACK: " << m_damage_range << "" << endl;
	cout << "PLAYER ONE  PLAYER ONE  PLAYER ONE\t\t\t" << "DEFENSE: " << m_armor << "" << endl;
	cout << "PLAYER ONE  PLAYER ONE  PLAYER ONE\t\t\t" << "GOLD: " << m_gold << "" << endl;
	cout << "PLAYER ONE  PLAYER ONE  PLAYER ONE\t\t\t" << "XP: " << m_experience << "" << endl;
	cout << "PLAYER ONE  PLAYER ONE  PLAYER ONE\t\t\t" << "LEVEL: " << m_level << endl;

}

/**********************************************************************
*																	  *
**********************************************************************/
void PlayerCharacter::SaveCharacter()
{
	int name_len = m_name.StrLen();
	ofstream fout("Characters.bin", ios::out | ios::binary | ios::app);

	fout.write((char *)&name_len, sizeof(int));
	fout.write((char *)m_name.GetString(), name_len);

	fout.write((char *)&m_hit_points, sizeof(int));
	fout.write((char *)&m_damage_range, sizeof(int));
	fout.write((char *)&m_armor, sizeof(int));
}

/**********************************************************************
*																	  *
**********************************************************************/
void PlayerCharacter::SaveRoundCharacter(ofstream & fout)
{
	int name_len = m_name.StrLen();

	fout.write((char *)&name_len, sizeof(int));
	fout.write((char *)m_name.GetString(), name_len);

	fout.write((char *)&m_hit_points, sizeof(int));
	fout.write((char *)&m_damage_range, sizeof(int));
	fout.write((char *)&m_armor, sizeof(int));
}

/**********************************************************************
*																	  *
**********************************************************************/
PlayerCharacter PlayerCharacter::ReadCharacter(ifstream & file)
{
	int name_len = 0;
	char * c_str = '\0';

	if (file.is_open())
	{
		file.read((char *)&name_len, sizeof(int));

		c_str = new char[name_len + 1];
		file.read((char *)c_str, name_len);

		c_str[name_len] = '\0';
		m_name = c_str;

		file.read((char *)&m_hit_points, sizeof(int));
		file.read((char *)&m_damage_range, sizeof(int));
		file.read((char *)&m_armor, sizeof(int));
	}
	else
		cout << "File Could Not Open" << endl;

	delete[] c_str;

	return *this;
}

/**********************************************************************
*																	  *
**********************************************************************/
void PlayerCharacter::AddArmor(int add)
{
	cout << "OLD STATS" << endl;
	cout << "DEFENSE: " << m_armor << endl;
	m_armor += add;
	cout << "\nNEW STATS" << endl;
	cout << "DEFENSE: " << m_armor << endl;
}

/**********************************************************************
*																	  *
**********************************************************************/
void PlayerCharacter::AddAttack(int add)
{
	m_damage_range += add;
}

/**********************************************************************
*																	  *
**********************************************************************/
void PlayerCharacter::AddGold(int add)
{
	m_gold += add;
}

/**********************************************************************
*																	  *
**********************************************************************/
int PlayerCharacter::GetGold() const
{
	return m_gold;
}

/**********************************************************************
*																	  *
**********************************************************************/
void PlayerCharacter::AddExperience(int add)
{
	m_experience += add;
}

/**********************************************************************
*																	  *
**********************************************************************/
int PlayerCharacter::GetXP() const
{
	return m_experience;
}

/**********************************************************************
*																	  *
**********************************************************************/
void PlayerCharacter::LevelUp()
{
	Dice dice;

	cout << ":::LEVEL UP:::" << endl;
	cout << "OLD STATS" << endl;
	cout << "HEALTH: " << m_hit_points << endl;
	cout << "ATTACK: " << m_damage_range << endl;
	cout << "DEFENSE: " << m_armor << endl;
	m_original_health += dice.Roll(20);
	m_hit_points = m_original_health;
	m_armor += dice.Roll(10);
	m_damage_range += dice.Roll(10);
	cout << "\nNEW STATS" << endl;
	cout << "HEALTH: " << m_hit_points << endl;
	cout << "ATTACK: " << m_damage_range << endl;
	cout << "DEFENSE: " << m_armor << endl;

	++m_level;

	m_experience -= 100;
}

/**********************************************************************
*																	  *
**********************************************************************/
void PlayerCharacter::Buy(int gold)
{
	m_gold -= gold;
}

/**********************************************************************
*																	  *
**********************************************************************/
void PlayerCharacter::AddPotion(Potion potion)
{
	Potion * new_potion = new Potion;

	*new_potion = potion;

	m_backpack.CreatePushFront(new_potion);
}

/**********************************************************************
*																	  *
**********************************************************************/
void PlayerCharacter::OpenBackpack()
{
	system("cls");

	for (int i = 0; i < m_backpack.GetNumNodes(); ++i)
	{
		cout << "\t(" << i << ")" << endl;
		m_backpack.GetIthElement(i)->Display();
		cout << endl;
	}
}

void PlayerCharacter::BackpackMenu(PlayerCharacter & player)
{
	int user_opt = -1;
	
	if (m_backpack.GetNumNodes() > 0)
	{
		OpenBackpack();

		cout << "<1> USE ITEM | <2> BACK" << endl;

		cin >> user_opt;
		
		switch (user_opt)
		{
		case 1:
			UseItem();
			break;
		case 2:
			break;
		}

		system("pause");
	}
	else
	{
		cout << "Backpack is empty!" << endl;
		system("pause");
	}
}

void PlayerCharacter::UseItem()
{
	int user_opt = -1;
	int stat_bonus = 0;

	cout << "Which item would you like to use?" << endl;
	cin >> user_opt;

	stat_bonus = m_backpack.GetIthElement(user_opt)->UseItem();

	if (m_backpack.GetIthElement(user_opt)->GetName() == "Health Potion")
	{
		m_hit_points += stat_bonus;
	}
	else if(m_backpack.GetIthElement(user_opt)->GetName() == "Strength Potion")
		m_damage_range += stat_bonus;
	else if (m_backpack.GetIthElement(user_opt)->GetName() == "Endurance Potion")
		m_armor += stat_bonus;

	m_backpack.Swap(user_opt);
	m_backpack.PopFront();
}

