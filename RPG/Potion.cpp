/**********************************************************************
* Author:			Alexander Ott
* Filename:			Lab08
* Date Created:		02/28/2016
************************************************************************/

#include "Potion.h"

/**********************************************************************
*
**********************************************************************/
Potion::Potion() : m_potency(""), m_description("")
{ }

/**********************************************************************
*
**********************************************************************/
Potion::Potion(String name, int cost, String potency, String description)
		: m_potency(potency), m_description(description)
{
	m_name = name;
	m_cost = cost;
}

/**********************************************************************
*
**********************************************************************/
Potion::Potion(const Potion & copy) : m_potency(""), m_description("")
{
	*this = copy;
}

/**********************************************************************
*
**********************************************************************/
Potion::~Potion()
{
	m_name = "";
	m_cost = 0;
	m_potency = "";
	m_description = "";
}

/**********************************************************************
*
**********************************************************************/
Potion & Potion::operator = (const Potion & rhs)
{
	if (this != &rhs)
	{
		m_name = rhs.m_name;
		m_cost = rhs.m_cost;
		m_potency = rhs.m_potency; 
		m_description = rhs.m_description;
	}

	return *this;
}

/**********************************************************************
*
**********************************************************************/
String Potion::GetPotency() const
{
	return m_potency;
}

/**********************************************************************
*
**********************************************************************/
String Potion::GetDescription() const
{
	return m_description;
}

/**********************************************************************
*
**********************************************************************/
void Potion::Display() const
{
	cout << "NAME: " << m_name << endl;
	cout << "COST: " << m_cost << " Gold" << endl;
	cout << "POTENCY: " << m_potency << endl;
	cout << "DESCRIPTION: " << m_description << endl;
}

/**********************************************************************
*
**********************************************************************/
void Potion::SavePotion()
{
	int str_len = 0;
	ofstream fout("Potions.bin", ios::out | ios::binary | ios::app);

	str_len = m_name.StrLen();
	fout.write((char *)&str_len, sizeof(int));
	fout.write((char *)m_name.GetString(), str_len);

	fout.write((char *)&m_cost, sizeof(int));

	str_len = m_potency.StrLen();
	fout.write((char *)&str_len, sizeof(int));
	fout.write((char *)m_potency.GetString(), str_len);

	str_len = m_description.StrLen();
	fout.write((char *)&str_len, sizeof(int));
	fout.write((char *)m_description.GetString(), str_len);
}

Potion Potion::LoadPotion(ifstream & file)
{
	m_name = ExtractString(file);
	file.read((char *)&m_cost, sizeof(int));
	m_potency = ExtractString(file);
	m_description = ExtractString(file);

	return *this;
}

String Potion::ExtractString(ifstream & file)
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

int Potion::UseItem()
{
	int stat_boost = 0;
	Dice dice;

	stat_boost = 10 + dice.Roll(10);

	return stat_boost;
}
