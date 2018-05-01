#pragma once

#include <fstream>
using std::ifstream;
using std::ofstream;

#include "Items.h"

class Potion : public Items
{
	public:
		Potion();
		Potion(String name, int cost, String potency, String description);
		Potion(const Potion & copy);
		~Potion();
		Potion & operator = (const Potion & rhs);
		String GetPotency() const;
		String GetDescription() const;
		void Display() const;
		void SavePotion();
		Potion LoadPotion(ifstream & file);
		int UseItem();


	private:
		String ExtractString(ifstream & file);
		String m_potency;
		String m_description;
};