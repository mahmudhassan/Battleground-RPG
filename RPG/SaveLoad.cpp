/**********************************************************************
* Author:			Alexander Ott
* Filename:			Lab08
* Date Created:		02/28/2016
************************************************************************/

#include "SaveLoad.h"

/**********************************************************************
*																	  *
**********************************************************************/
SaveLoad::SaveLoad()
{ }

/**********************************************************************
*																	  *
**********************************************************************/
SaveLoad::~SaveLoad()
{
	m_battle_list.PtrPurge();
	m_all_creature_list.PtrPurge();
}

/**********************************************************************
*																	  *
**********************************************************************/
LinkedList<PlayerCharacter> SaveLoad::LoadCharacters()
{
	LinkedList<PlayerCharacter> temp_list;
	PlayerCharacter temp_character;

	ifstream fin("Characters.bin", ios::in | ios::binary);

	int size = FindFileSize(fin);

	while(fin.tellg() < size)
	{
		temp_character.ReadCharacter(fin);
		temp_list.CreatePushFront(temp_character);
	}

	fin.close();

	return temp_list;
}

/**********************************************************************
*																	  *
**********************************************************************/
int SaveLoad::FindFileSize(ifstream & str)
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
LinkedList<Opponent *> & SaveLoad::GenerateCreatureList()
{
	Opponent * temp_creature = nullptr;
	Dice dice;

	LoadCreatures();
	int num_creatures = (m_all_creature_list.GetNumNodes() - 1);

	for (int i = 0; i < 20; ++i)
	{
		temp_creature = m_all_creature_list.GetIthElement(dice.Roll(num_creatures));
		AssignCreatureType(temp_creature);
	}

	return m_battle_list;
}

/**********************************************************************
*																	  *
**********************************************************************/
void SaveLoad::LoadCreatures()
{
	ifstream fin("Opponents.bin", ios::in | ios::binary);

	int size = FindFileSize(fin);

	while (fin.tellg() < size)
	{
		m_link = new Opponent;
		m_link->LoadOpponent(fin);

		Node<Opponent *> * new_link = m_all_creature_list.CreateNode(m_link);
		m_all_creature_list.PushFront(new_link);
	}
	fin.close();
}

/**********************************************************************
*																	  *
**********************************************************************/
void SaveLoad::AssignCreatureType(Opponent * temp_creature)
{
	String temp_check = temp_creature->m_name;

	if (temp_check == "Bandit")
		AddBandit(temp_creature);
	else if (temp_check == "Zombie")
		AddZombie(temp_creature);
	else if (temp_check == "Bear")
		AddBear(temp_creature);
	else if (temp_check == "Ghost")
		AddGhost(temp_creature);
	else if (temp_check == "Vampire")
		AddVampire(temp_creature);
	else if (temp_check == "Werewolf")
		AddWerewolf(temp_creature);
	else if (temp_check == "Banshee")
		AddBanshee(temp_creature);
	else if (temp_check == "Goblin")
		AddGoblin(temp_creature);
	else if (temp_check == "Witch")
		AddWitch(temp_creature);
	else if (temp_check == "Ogre")
		AddOgre(temp_creature);
}

/**********************************************************************
*																	  *
**********************************************************************/
void SaveLoad::AddBandit(Opponent * temp_creature)
{		
	bandit = new Bandit;

	if (temp_creature->m_armor == 0 && temp_creature->m_hit_points == 0)
	{
		bandit->m_armor_roll = temp_creature->m_armor_roll;
		bandit->m_hp_roll = temp_creature->m_hp_roll;
		bandit->m_damage_roll = temp_creature->m_damage_roll;

		bandit->Generate();
		m_battle_list.CreatePushFront(bandit);
	}
	else
	{
		bandit->m_armor = temp_creature->m_armor;
		bandit->m_hit_points = temp_creature->m_hit_points;
		bandit->m_damage_range = temp_creature->m_damage_range;

		m_battle_list.CreatePushBack(bandit);
	}


}

/**********************************************************************
*																	  *
**********************************************************************/
void SaveLoad::AddZombie(Opponent * temp_creature)
{
	zombie = new Zombie;

	if (temp_creature->m_armor == 0 && temp_creature->m_hit_points == 0)
	{
		zombie->m_armor_roll = temp_creature->m_armor_roll;
		zombie->m_hp_roll = temp_creature->m_hp_roll;
		zombie->m_damage_roll = temp_creature->m_damage_roll;

		zombie->Generate();
		m_battle_list.CreatePushFront(zombie);
	}
	else
	{
		zombie->m_armor = temp_creature->m_armor;
		zombie->m_hit_points = temp_creature->m_hit_points;
		zombie->m_damage_range = temp_creature->m_damage_range;

		m_battle_list.CreatePushBack(zombie);
	}
}

/**********************************************************************
*																	  *
**********************************************************************/
void SaveLoad::AddBear(Opponent * temp_creature)
{
	bear = new Bear;

	if (temp_creature->m_armor == 0 && temp_creature->m_hit_points == 0)
	{
		bear->m_armor_roll = temp_creature->m_armor_roll;
		bear->m_hp_roll = temp_creature->m_hp_roll;
		bear->m_damage_roll = temp_creature->m_damage_roll;

		bear->Generate();

		m_battle_list.CreatePushFront(bear);
	}
	else
	{
		bear->m_armor = temp_creature->m_armor;
		bear->m_hit_points = temp_creature->m_hit_points;
		bear->m_damage_range = temp_creature->m_damage_range;

		m_battle_list.CreatePushBack(bear);
	}
}

/**********************************************************************
*																	  *
**********************************************************************/
void SaveLoad::AddGhost(Opponent * temp_creature)
{
	ghost = new Ghost;

	if (temp_creature->m_armor == 0 && temp_creature->m_hit_points == 0)
	{
		ghost->m_armor_roll = temp_creature->m_armor_roll;
		ghost->m_hp_roll = temp_creature->m_hp_roll;
		ghost->m_damage_roll = temp_creature->m_damage_roll;

		ghost->Generate();

		m_battle_list.CreatePushFront(ghost);
	}
	else
	{
		ghost->m_armor = temp_creature->m_armor;
		ghost->m_hit_points = temp_creature->m_hit_points;
		ghost->m_damage_range = temp_creature->m_damage_range;

		m_battle_list.CreatePushBack(ghost);
	}
}

/**********************************************************************
*																	  *
**********************************************************************/
void SaveLoad::AddVampire(Opponent * temp_creature)
{
	vampire = new Vampire;

	if (temp_creature->m_armor == 0 && temp_creature->m_hit_points == 0)
	{
		vampire->m_armor_roll = temp_creature->m_armor_roll;
		vampire->m_hp_roll = temp_creature->m_hp_roll;
		vampire->m_damage_roll = temp_creature->m_damage_roll;

		vampire->Generate();
		m_battle_list.CreatePushFront(vampire);
	}
	else
	{
		vampire->m_armor = temp_creature->m_armor;
		vampire->m_hit_points = temp_creature->m_hit_points;
		vampire->m_damage_range = temp_creature->m_damage_range;

		m_battle_list.CreatePushBack(vampire);

	}
}

/**********************************************************************
*																	  *
**********************************************************************/
void SaveLoad::AddWerewolf(Opponent * temp_creature)
{
	werewolf = new Werewolf;

	if (temp_creature->m_armor == 0 && temp_creature->m_hit_points == 0)
	{
		werewolf->m_armor_roll = temp_creature->m_armor_roll;
		werewolf->m_hp_roll = temp_creature->m_hp_roll;
		werewolf->m_damage_roll = temp_creature->m_damage_roll;

		werewolf->Generate();
		
		m_battle_list.CreatePushFront(werewolf);
	}
	else
	{
		werewolf->m_armor = temp_creature->m_armor;
		werewolf->m_hit_points = temp_creature->m_hit_points;
		werewolf->m_damage_range = temp_creature->m_damage_range;

		m_battle_list.CreatePushBack(werewolf);

	}
}

/**********************************************************************
*																	  *
**********************************************************************/
void SaveLoad::AddBanshee(Opponent * temp_creature)
{
	banshee = new Banshee;

	if (temp_creature->m_armor == 0 && temp_creature->m_hit_points == 0)
	{
		banshee->m_armor_roll = temp_creature->m_armor_roll;
		banshee->m_hp_roll = temp_creature->m_hp_roll;
		banshee->m_damage_roll = temp_creature->m_damage_roll;

		banshee->Generate();

		m_battle_list.CreatePushFront(banshee);
	}
	else
	{
		banshee->m_armor = temp_creature->m_armor;
		banshee->m_hit_points = temp_creature->m_hit_points;
		banshee->m_damage_range = temp_creature->m_damage_range;

		m_battle_list.CreatePushBack(banshee);
	}
}

/**********************************************************************
*																	  *
**********************************************************************/
void SaveLoad::AddGoblin(Opponent * temp_creature)
{
	goblin = new Goblin;

	if (temp_creature->m_armor == 0 && temp_creature->m_hit_points == 0)
	{
		goblin->m_armor_roll = temp_creature->m_armor_roll;
		goblin->m_hp_roll = temp_creature->m_hp_roll;
		goblin->m_damage_roll = temp_creature->m_damage_roll;

		goblin->Generate();

		m_battle_list.CreatePushFront(goblin);
	}
	else
	{
		goblin->m_armor = temp_creature->m_armor;
		goblin->m_hit_points = temp_creature->m_hit_points;
		goblin->m_damage_range = temp_creature->m_damage_range;

		m_battle_list.CreatePushBack(goblin);
	}
}

/**********************************************************************
*																	  *
**********************************************************************/
void SaveLoad::AddWitch(Opponent * temp_creature)
{
	witch = new Witch;

	if (temp_creature->m_armor == 0 && temp_creature->m_hit_points == 0)
	{
		witch->m_armor_roll = temp_creature->m_armor_roll;
		witch->m_hp_roll = temp_creature->m_hp_roll;
		witch->m_damage_roll = temp_creature->m_damage_roll;

		witch->Generate();

		m_battle_list.CreatePushFront(witch);
	}
	else
	{
		witch->m_armor = temp_creature->m_armor;
		witch->m_hit_points = temp_creature->m_hit_points;
		witch->m_damage_range = temp_creature->m_damage_range;

		m_battle_list.CreatePushBack(witch);
	}
}

/**********************************************************************
*																	  *
**********************************************************************/
void SaveLoad::AddOgre(Opponent * temp_creature)
{
	ogre = new Ogre;

	if (temp_creature->m_armor == 0 && temp_creature->m_hit_points == 0)
	{
		ogre->m_armor_roll = temp_creature->m_armor_roll;
		ogre->m_hp_roll = temp_creature->m_hp_roll;
		ogre->m_damage_roll = temp_creature->m_damage_roll;

		ogre->Generate();
		m_battle_list.CreatePushFront(ogre);
	}
	else
	{
		ogre->m_armor = temp_creature->m_armor;
		ogre->m_hit_points= temp_creature->m_hit_points;
		ogre->m_damage_range = temp_creature->m_damage_range;

		m_battle_list.CreatePushBack(ogre);
	}
}

/**********************************************************************
*																	  *
**********************************************************************/
void SaveLoad::SaveRound(LinkedList<Opponent *> & creatures, PlayerCharacter player)
{
		// Open the file to write new list to.
	ofstream fout("RoundCreaturesList.bin", ios::out | ios::binary);
	
	for (int i = 0; i < creatures.GetNumNodes(); ++i)
		creatures.GetIthElement(i)->SaveRoundOpponent(fout);

		// Write character to file.
	ofstream player_stream("CharactersRound.bin", ios::out | ios::binary);

	player.SaveRoundCharacter(player_stream);

	player_stream.close();
	fout.close();
}

/**********************************************************************
*																	  *
**********************************************************************/
LinkedList<Opponent *> & SaveLoad::LoadRound(LinkedList<Opponent *> & creatures, PlayerCharacter & player)
{	
	m_battle_list.PtrPurge();

	ifstream fin("RoundCreaturesList.bin", ios::in | ios::binary | ios::app);
	int size = FindFileSize(fin);

	while (fin.tellg() < size)
	{
		m_link = new Opponent;
		m_link->LoadRoundOpponent(fin);

		AssignCreatureType(m_link);
	}

	ifstream player_fin("CharactersRound.bin", ios::in | ios::binary);
	player.ReadCharacter(player_fin);


	fin.close();
	player_fin.close();

	return m_battle_list;
}
