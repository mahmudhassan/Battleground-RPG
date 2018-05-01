/**********************************************************************
* Author:			Alexander Ott
* Filename:			Lab08
* Date Created:		02/28/2016
************************************************************************/

#include "Shop.h"

/**********************************************************************
*
**********************************************************************/
Shop::Shop()
{ 
	FillPotionsList();
}

/**********************************************************************
*
**********************************************************************/
Shop::Shop(const Shop & copy)
{ }

/**********************************************************************
*
**********************************************************************/
Shop::~Shop()
{ }

/**********************************************************************
*
**********************************************************************/
Shop & Shop::operator = (const Shop & rhs)
{ 
	return *this;
}

/**********************************************************************
*																	  *
**********************************************************************/
int Shop::FindFileSize(ifstream & str)
{
	int size = 0;

	str.seekg(0, (ios::end));
	size = (int)(str.tellg());
	str.seekg(0(ios::beg));

	return size;
}

/**********************************************************************
*																	  *
**********************************************************************/
void Shop::FillPotionsList()
{
	Potion temp_potion;
	ifstream fin("Potions.bin", ios::in | ios::binary);
	int size = FindFileSize(fin);

	while (fin.tellg() < size)
	{
		temp_potion.LoadPotion(fin);
		m_potion_list.CreatePushFront(temp_potion);
	}

	fin.close();
}

void Shop::DisplayPotions()
{
	for (int i = 0; i < m_potion_list.GetNumNodes(); ++i)
	{
		cout << "\t(" << i << ")" << endl;
		m_potion_list.GetIthElement(i).Display();
		cout << endl;
	}
}

void Shop::PotionsMenu(PlayerCharacter & player)
{
	int user_opt = -1;

	system("cls");
	DisplayPotions();

	cout << "<1> BUY POTION | <2> BACK " << endl;
	cin >> user_opt;
	
	switch (user_opt)
	{
	case 1:
		cout << "Choose by Number: ";
		cin >> user_opt;

		if (player.GetGold() >= m_potion_list.GetIthElement(user_opt).GetCost())
		{
			player.Buy(m_potion_list.GetIthElement(user_opt).GetCost());
			player.AddPotion(m_potion_list.GetIthElement(user_opt));
			system("pause");
			system("cls");
		}
		else
		{
			cout << "You do not have enough gold!" << endl;
			system("pause");
			system("cls");
		}
		break;

	case 2:
		system("cls");
		break;

	default:
		system("cls");
		break;
	}
}


