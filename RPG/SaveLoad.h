#pragma once

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;

#include "LinkedList.h"

#include "PlayerCharacter.h"
#include "Opponent.h"

#include "Bandit.h"
#include "Zombie.h"
#include "Bear.h"
#include "Ghost.h"
#include "Vampire.h"
#include "Werewolf.h"
#include "Banshee.h"
#include "Goblin.h"
#include "Witch.h"
#include "Ogre.h"

class SaveLoad
{
	public:
		SaveLoad();
		~SaveLoad();
		LinkedList<PlayerCharacter> LoadCharacters();
		void LoadCreatures();
		LinkedList<Opponent *> & GenerateCreatureList();
		void SaveRound(LinkedList<Opponent *> & creatures, PlayerCharacter player);
		LinkedList<Opponent *> & LoadRound(LinkedList<Opponent *> & creatures, PlayerCharacter & player);

	private:
		void AddBandit(Opponent * temp_creature);
		void AddZombie(Opponent * temp_creature);
		void AddBear(Opponent * temp_creature);
		void AddGhost(Opponent * temp_creature);
		void AddVampire(Opponent * temp_creature);
		void AddWerewolf(Opponent * temp_creature);
		void AddBanshee(Opponent * temp_creature);
		void AddGoblin(Opponent * temp_creature);
		void AddWitch(Opponent * temp_creature);
		void AddOgre(Opponent * temp_creature);
		int FindFileSize(ifstream & str);
		void AssignCreatureType(Opponent * temp_creature);
		Opponent * m_link;
		Bandit * bandit;
		Zombie * zombie;
		Bear * bear;
		Ghost * ghost;
		Vampire * vampire;
		Werewolf * werewolf;
		Banshee* banshee;
		Goblin* goblin;
		Witch *witch;
		Ogre *ogre;
		LinkedList<Opponent *> m_battle_list;
		LinkedList<Opponent *> m_all_creature_list;
};