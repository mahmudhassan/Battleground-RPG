#pragma once

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;

#include "LinkedList.h"
#include "GenericCreature.h"

#include "Dice.h"
#include "Potion.h"

class PlayerCharacter : public GenericCreature
{
	public:
		PlayerCharacter();
		PlayerCharacter(String name, int hit_points, int damage_range, int armor);
		PlayerCharacter & operator = (const PlayerCharacter & rhs);
		void CreateCharacter(String name);
		void Display() const;
		void BattleDisplay() const;
		void SaveCharacter();
		PlayerCharacter ReadCharacter(ifstream & file);
		void SaveRoundCharacter(ofstream & fout);
		void AddArmor(int add);
		void AddAttack(int add);
		void AddGold(int add);
		void AddExperience(int add);
		int GetGold() const;
		int GetXP() const;
		void LevelUp();
		void Buy(int gold);
		void AddPotion(Potion potion);
		void OpenBackpack();
		void BackpackMenu(PlayerCharacter & player);
		void UseItem();

	private:
		int PlayerDiceRoll(int attribute, int num_sides);
		void GenerateHitPoints();
		void GenerateArmor();
		void GenerateDamageRange();
		int m_gold;
		int m_experience;
		int m_level;
		int m_original_health;
		LinkedList<Items *> m_backpack;
};