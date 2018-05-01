#pragma once

#include <windows.h>
#include "mmsystem.h"

#include <fstream>
using std::ios;
using std::ofstream;
using std::ifstream;

#include "String.h"

#include "Dice.h"

class Opponent
{
	public:
		Opponent();
		Opponent(const Opponent & copy);
		virtual ~Opponent();
		virtual Opponent & operator = (const Opponent & rhs);

		virtual void SaveOpponent();
		void SaveRoundOpponent(ofstream & fout);
		void LoadRoundOpponent(ifstream & fin);

		virtual Opponent LoadOpponent(ifstream & file);
		virtual void GenerateHitPoints();
		virtual void GenerateArmor();
		virtual void GenerateDamageRange();
		virtual void BattleDisplay() const;
		virtual void BattleSound() const {};
		virtual int GoldDrop();
		virtual int ExperienceDrop();
		virtual int SpecialAttack();

		String m_name;
		int m_hit_points;
		int m_damage_range;
		int m_armor;
		String m_hp_roll;
		String m_armor_roll;
		String m_damage_roll;

	private:				
		String ExtractString(ifstream & file);
		int CalcAttribute(int rolls, int sides, int bonus);
};