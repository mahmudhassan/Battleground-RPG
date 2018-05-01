/**********************************************************************
* Author:			Alexander Ott
* Filename:			Lab08
* Date Created:		02/28/2016
************************************************************************/

#include "Opponent.h"

/**********************************************************************
*
**********************************************************************/
Opponent::Opponent()
{
	m_name = "";
	m_hit_points = 0;
	m_damage_range = 0;
	m_armor = 0;

	m_hp_roll = "";
	m_armor_roll = "";
	m_damage_roll = "";
}

/**********************************************************************
*
**********************************************************************/
Opponent::Opponent(const Opponent & copy)
{
	*this = copy;
}

/**********************************************************************
*
**********************************************************************/
Opponent::~Opponent()
{ }

/**********************************************************************
*
**********************************************************************/
Opponent & Opponent::operator = (const Opponent & rhs)
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
*
**********************************************************************/
void Opponent::SaveOpponent()
{
	int string_len = 0;

	ofstream fout("Opponents.bin", ios::out | ios::binary | ios::app);

	string_len = m_name.StrLen();
	fout.write((char *)&string_len, sizeof(int));
	fout.write((char *)m_name.GetString(), m_name.StrLen());

	string_len = m_hp_roll.StrLen();
	fout.write((char *)&string_len, sizeof(int));
	fout.write((char *)m_hp_roll.GetString(), m_hp_roll.StrLen());

	string_len = m_armor_roll.StrLen();
	fout.write((char *)&string_len, sizeof(int));
	fout.write((char *)m_armor_roll.GetString(), m_armor_roll.StrLen());

	string_len = m_damage_roll.StrLen();
	fout.write((char *)&string_len, sizeof(int));
	fout.write((char *)m_damage_roll.GetString(), m_damage_roll.StrLen());
}

/**********************************************************************
*
**********************************************************************/
void Opponent::SaveRoundOpponent(ofstream & fout)
{
	int string_len = 0;

	string_len = m_name.StrLen();
	fout.write((char *)&string_len, sizeof(int));
	fout.write((char *)m_name.GetString(), m_name.StrLen());

	fout.write((char *)&m_hit_points, sizeof(int));

	fout.write((char *)&m_damage_range, sizeof(int));

	fout.write((char *)&m_armor, sizeof(int));
}

/**********************************************************************
*
**********************************************************************/
void Opponent::LoadRoundOpponent(ifstream & fin)
{
	m_name = ExtractString(fin);
	fin.read((char *)&m_hit_points, sizeof(int));
	fin.read((char *)&m_damage_range, sizeof(int));
	fin.read((char *)&m_armor, sizeof(int));
}

/**********************************************************************
*
**********************************************************************/
Opponent Opponent::LoadOpponent(ifstream & file)
{

	m_name = ExtractString(file);
	m_hp_roll = ExtractString(file);
	m_armor_roll = ExtractString(file);
	m_damage_roll = ExtractString(file);

	return *this;
}

/**********************************************************************
*
**********************************************************************/
String Opponent::ExtractString(ifstream & file)
{
	int string_len = 0;
	String extract_str;

	file.read((char *)&string_len, sizeof(int));

	char * temp_str = new char[string_len + 1];
	temp_str[string_len] = '\0';

	file.read((char *)temp_str, string_len);

	extract_str = temp_str;

	delete[] temp_str;

	return extract_str;
}

/**********************************************************************
*
**********************************************************************/
void Opponent::GenerateHitPoints()
{
	int values[3] = { 0,0,0 };

	m_hp_roll.ParseToIntArray(values);
	m_hit_points = CalcAttribute(values[0], values[1], values[2]);
}

/**********************************************************************
*
**********************************************************************/
void Opponent::GenerateArmor()
{
	int values[3] = { 0,0,0 };

	m_armor_roll.ParseToIntArray(values);
	m_armor = CalcAttribute(values[0], values[1], values[2]);
}

/**********************************************************************
*
**********************************************************************/
void Opponent::GenerateDamageRange()
{
	int values[3] = { 0,0,0 };

	m_damage_roll.ParseToIntArray(values);
	m_damage_range = CalcAttribute(values[0], values[1], values[2]);
}

/**********************************************************************
*
**********************************************************************/
int Opponent::CalcAttribute(int rolls, int sides, int bonus)
{
	Dice dice;

	return ((rolls * dice.Roll(sides) + bonus));
}

/**********************************************************************
*
**********************************************************************/
void Opponent::BattleDisplay() const
{
	cout << "__________________" << "\t\t\tCREATURE GOES HERE ###############" << endl;
	cout << "__________________" << "\t\t\tCREATURE GOES HERE ###############" << endl;
	cout << "__________________" << "\t\t\tCREATURE GOES HERE ###############" << endl;
	cout << "NAME: " << m_name << "\t\t\t\tCREATURE GOES HERE ###############" << endl;
	cout << "HEALTH: " << m_hit_points << "\t\t\t\tCREATURE GOES HERE ###############" << endl;
	cout << "ATTACK: " << m_damage_range << "\t\t\t\tCREATURE GOES HERE ###############" << endl;
	cout << "DEFENSE: " << m_armor << "\t\t\t\tCREATURE GOES HERE ###############" << endl;
	cout << "__________________" << "\t\t\tCREATURE GOES HERE ###############" << endl;
	cout << "__________________" << "\t\t\tCREATURE GOES HERE ###############" << endl;
	cout << "__________________" << "\t\t\tCREATURE GOES HERE ###############" << endl;
}

/**********************************************************************
*
**********************************************************************/
int Opponent::GoldDrop()
{
	return 100;
}

/**********************************************************************
*
**********************************************************************/
int Opponent::ExperienceDrop()
{
	return 15;
}

/**********************************************************************
*
**********************************************************************/
int Opponent::SpecialAttack()
{
	cout << "Creature used special attack!" << endl;
	return 20;
}
