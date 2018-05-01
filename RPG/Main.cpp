/**********************************************************************
* Author:			Alexander Ott
* Filename:			Lab08
* Date Created:		02/28/2016
* Lab/Assignment:	Lab08 - RPG
************************************************************************/

#define _CRTDBG_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS

#include <crtdbg.h>
#include "RPG.h"

#include "Potion.h"
#include "Shop.h"

void PlayGame();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	PlayGame();


	return 0;
}

void PlayGame()
{
	RPG rpg_game;
	rpg_game.BeginGame();
}