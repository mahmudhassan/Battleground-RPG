#pragma once

#include <fstream>
using std::ifstream;

#include "LinkedList.h"
#include "PlayerCharacter.h"
#include "Potion.h"

class Shop
{
	public:
		Shop();
		Shop(const Shop & copy);
		~Shop();
		Shop & operator = (const Shop & rhs);
		void FillPotionsList();
		void DisplayPotions();
		void PotionsMenu(PlayerCharacter & player);

	private:
		int FindFileSize(ifstream & str);
		LinkedList<Potion> m_potion_list;
};