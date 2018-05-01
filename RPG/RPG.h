#pragma once

#include <windows.h>
#include "mmsystem.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "SaveLoad.h"
#include "Battle.h"
#include "Shop.h"
class RPG
{
	public:
		void WelcomeMenu() const;
		int StartMenu();
		void StartSwitch();
		PlayerCharacter CreateNewCharacter();
		void CharacterCreateMenu();
		void CreationSwitch(int user_opt);
		void CharacterSelect();
		int CharactersMenu();

		int ShopMenu();
		int BattleMenu();
		void BattlePhase();

		void TransferMonsterList();
		bool IsKilled();
		void BeginGame();
		void KilledArt();
		void WinArt();
		void Credits();
		void ShowAllBattleDisplay();

	private:
		bool m_game_over;
		Shop shop;
		SaveLoad data_file;
		LinkedList<Opponent *> m_monsters;
		LinkedList<PlayerCharacter> m_characters;
		PlayerCharacter m_player;
};