/**********************************************************************
* Author:			Alexander Ott
* Filename:			Lab08
* Date Created:		02/28/2016
**********************************************************************/

#include "RPG.h"

/**********************************************************************
*																	  *
**********************************************************************/
void RPG::WelcomeMenu() const
{
	PlaySound(TEXT("Menu_music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	cout << " ,ggg, ,ggg,_,ggg,                                                                                  ,ggggggggggg,           " << endl;
	cout << "dP  Y8dP  Y88P  Y8b                                         I8                                     dP   88      Y8,             ,dPYb, ,dPYb," << endl;
	cout << "Yb, `88'  `88'  `88                                         I8                                     Yb,  88      `8b             IP'`Yb IP'`Yb" << endl;
	cout << " `   88    88    88                                      88888888                                      88      ,8P             I8  8I I8  8I" << endl;
	cout << "    88    88    88                                         I8                                          88aaaad8P               I8  8  I8  8 " << endl;
	cout << "    88    88    88    ,ggggg,     ,ggg,,ggg,     ,g,       I8     ,ggg,    ,gggggg,    ,g,             88    Y8ba    ,gggg,gg  I8 dP  I8 dP " << endl;
	cout << "    88    88    88   dP    Y8ggg ,8   8P   8,   ,8'8,      I8    i8   8i   dP    8I   ,8'8,            88       8b  dP    Y8I  I8dP   I8dP  " << endl;
	cout << "   88    88    88  i8     ,8I   I8   8I   8I  ,8   Yb    ,I8,   I8, ,8I  ,8     8I  ,8   Yb           88      ,8P i8     ,8I  I8P    I8P   " << endl;
	cout << "   88    88    Y8,,d8,   ,d8   ,dP   8I   Yb,,8 _   8)  ,d88b,   YbadP  ,dP     Y8,,8 _   8)          88_____,d8 ,d8,   ,d8b,,d8b,_ ,d8b,_ " << endl;
	cout << "  88    88     Y8P Y8888P     8P    8I    Y8P   YY8P8P88P  Y88888P Y8888P       Y8P   YY8P8P        88888888P   P Y8888P  Y88P  Y888P  Y88" << endl;
                                                                      
	system("pause");
	system("cls");
}

/**********************************************************************
*																	  *
**********************************************************************/
int RPG::StartMenu()
{
	int user_opt = 0;
	do {

		cout << "___________________________" << endl;
		cout << endl;
		cout << "CHOOSE ONE OF THE FOLLOWING" << endl;
		cout << "___________________________" << endl;
		cout << "   (1) CREATE CHARACTER" << endl;
		cout << "   (2) SELECT CHARACTER" << endl;
		cin >> user_opt;

	} while (user_opt < 1 || user_opt > 2);

	return user_opt;
}

/**********************************************************************
*																	  *
**********************************************************************/
void RPG::StartSwitch()
{
	int user_opt = StartMenu();

	switch (user_opt)
	{
	case 1:
		CharacterCreateMenu();
		break;
	case 2:
		CharacterSelect();
		break;
	default:
		break;
	}
}

/**********************************************************************
*																	  *
**********************************************************************/
PlayerCharacter RPG::CreateNewCharacter()
{
	PlayerCharacter temp;
	String name;

	cout << "ENTER NAME: ";
	
	cin >> name;
	
	temp.CreateCharacter(name);

	return temp;
}

/**********************************************************************
*																	  *
**********************************************************************/
void RPG::CharacterCreateMenu()
{
	int user_opt = 0;
	
		// Generates stats for the m_player.
	m_player = CreateNewCharacter();
	m_player.Display();

	cout << "___________________________" << endl;
	cout << endl;
	cout << "CHOOSE ONE OF THE FOLLOWING" << endl;
	cout << "___________________________" << endl;
	cout << "   (1) KEEP CHARACTER" << endl;
	cout << "(2) GENERATE NEW CHARACTER" << endl;

	cin >> user_opt;

	CreationSwitch(user_opt);
}

/**********************************************************************
*																	  *
**********************************************************************/
void RPG::CreationSwitch(int user_opt)
{
	switch (user_opt)
	{
	case 1:
		m_player.SaveCharacter();
		break;
	case 2:
		CharacterCreateMenu();
		break;
	}
}

/**********************************************************************
*																	  *
**********************************************************************/
int RPG::CharactersMenu()
{
	SaveLoad temp_io;
	m_characters = temp_io.LoadCharacters();

	int num = -1;
	LinkedList<PlayerCharacter> temp_list = m_characters;

	for (int i = 0; i < m_characters.GetNumNodes(); ++i)
	{
		cout << "\t(" << i << ")" << endl;
		temp_list.PopFront().Display();
		cout << endl;
	}
	cout << "ENTER NUMBER TO CHOOSE: ";
	cin >> num;

	return num;
}

/**********************************************************************
*																	  *
**********************************************************************/
void RPG::CharacterSelect()
{
	int link_num = 0;
	link_num = CharactersMenu();

	m_player = m_characters.GetIthElement(link_num);
}

/**********************************************************************
*																	  *
**********************************************************************/
int RPG::BattleMenu()
{
	int user_opt = 0;

	m_monsters.Front()->BattleDisplay();
	cout << endl;
	m_player.BattleDisplay();
	cout << "__________________________________________________"
			<< "________________________" << endl;
	
	cout << "\t|<1>ATTACK" << "|" << "<2>BLOCK" << "|" << "<3>BERSERK" 
		<< "|" << "<4>SHOP" << "|" << "<5>CHECK BACKPACK" << "|"<< endl;
	
	cout << "_________________________________________________"
		<< "________________________" << endl;

	cin >> user_opt;

	return user_opt;
}

int RPG::ShopMenu()
{
	int user_opt = 0;

	system("cls");

	PlaySound(TEXT("Shop.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	do {
	cout << "<1> 30 min - Block Training |+1 Armor (10 gold)|\n" << endl;
	cout << "<2> 30 min - Attack Training |+1 Attack (10 gold)|\n" << endl;
	cout << "<3> 60 min - Block Training |+3 Armor (20 gold)|\n" << endl;
	cout << "<4> 60 min - Attack Training |+3 Attack (20 gold)|\n\n" << endl;
	cout << "<5> Enter the Potion Cellar?\n\n" << endl;
	cout << "<6> EXIT\n\n" << endl;
	cout << "WALLET: " << m_player.GetGold() << " gold\n" << endl;

	cin >> user_opt;

	system("cls");

		switch (user_opt)
		{
		case 1:
			if (m_player.GetGold() >= 10)
			{
				m_player.AddArmor(1);
				m_player.Buy(10);
			}
			else
				cout << "You do not have enought gold." << endl;
			break;
		case 2:
			if (m_player.GetGold() >= 10)
			{
				m_player.AddAttack(1);
				m_player.Buy(10);

			}
			else
				cout << "You do not have enought gold." << endl;
			break;
		case 3:
			if (m_player.GetGold() >= 20)
			{
				m_player.AddArmor(3);
				m_player.Buy(20);

			}
			else
				cout << "You do not have enought gold." << endl;
			break;
		case 4:
			if (m_player.GetGold() >= 20)
			{
				m_player.AddAttack(3);
				m_player.Buy(20);

			}
			else
				cout << "You do not have enought gold." << endl;
			break;
		case 5:
			shop.PotionsMenu(m_player);
			break;
		case 6:
			PlaySound(NULL, 0, 0);
			break;
			system("pause");
		}

		
	} while (user_opt != 6);

	return 0;
}

/**********************************************************************
*																	  *
**********************************************************************/
void RPG::BattlePhase()
{
	Battle battle;
	int user_opt = 0;
	
	data_file.SaveRound(m_monsters, m_player);
	
	m_monsters.Front()->BattleSound();

	while (m_player.m_hit_points > 0 && m_monsters.Front()->m_hit_points > 0)
	{

		user_opt = BattleMenu();

		switch (user_opt)
		{
		case 1:
			battle.AttackSequence(m_monsters.Front(), m_player);
			system("pause");
			break;
		case 2:
			battle.BlockSequence(m_monsters.Front(), m_player);
			system("pause");
			break;
		case 3:
			battle.BerserkSequence(m_monsters.Front(), m_player);
			system("pause");
			break;
		case 4:
			ShopMenu();
			break;
		case 5:
			m_player.BackpackMenu(m_player);
			break;
		}
		system("cls");
	}

	m_game_over = IsKilled();

}

/**********************************************************************
*																	  *
**********************************************************************/
bool RPG::IsKilled()
{
	char _continue = '\0';


	if (m_player.m_hit_points > 0)
	{
		cout << "You have killed a " << m_monsters.Front()->m_name << endl;
		m_player.AddGold(m_monsters.Front()->GoldDrop());
		m_player.AddExperience(m_monsters.Front()->ExperienceDrop());
		m_monsters.PopFront();
		cout << "You must kill " << m_monsters.GetNumNodes() << " more monsters to win!\n" << endl;
		if (m_player.GetXP() > 100)
		{
			m_player.LevelUp();
		}
		system("pause");
	}
	else
	{
		system("cls");
		KilledArt();
		cout << "You have been killed by a " << m_monsters.Front()->m_name << endl;
		cout << "Would you like to reload from last the checkpoint?(y/n)" << endl;

		cin >> _continue;

		if (_continue == 'y')
		{
			m_monsters = data_file.LoadRound(m_monsters, m_player);
		}
		else if (_continue == 'n')
		{
			cout << "Goodbye!" << endl;
			system("pause");
			Credits();
			system("pause");
			m_game_over = true;
		}
	}

	return m_game_over;
}

/**********************************************************************
*																	  *
**********************************************************************/
void RPG::TransferMonsterList()
{
	m_monsters = data_file.GenerateCreatureList();
}

/**********************************************************************
*																	  *
**********************************************************************/
void RPG::BeginGame()
{
	m_game_over = false;
	// Character Selection.
	WelcomeMenu();
	StartSwitch();

	system("cls");

	// Creates a unique monster list to battle against.
	TransferMonsterList();
	// Begin Battleing

	while (m_monsters.GetNumNodes() > 0 && m_game_over == false)
	{
		BattlePhase();
		system("cls");
	}
	if (m_monsters.GetNumNodes() <= 0)
	{
		WinArt();
	}
}

/**********************************************************************
*																	  *
**********************************************************************/
void RPG::ShowAllBattleDisplay()
{
	TransferMonsterList();

	for (int i = 0; i < m_monsters.GetNumNodes();++i)
		m_monsters.GetIthElement(i)->BattleDisplay();
}

/**********************************************************************
*																	  *
**********************************************************************/
void RPG::KilledArt()
{
	PlaySound(TEXT("Avril_14th.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

		cout << "                    .--. .-,       .-..-.__" << endl;
		cout << "                  .'(`.-` \_.-'-./`  |\_( \__ "<< endl;
		cout << "            __.>\ ';  _;---,._|   / __/`'--)" << endl;
		cout << "           /.--.  : |/' _.--.<|  /  | |" << endl;
		cout << "      _..-'    `\     /' /`  /_/ _/_/" << endl;
		cout << "        >_.-``-. `Y  /' _;---.`|/)))) " << endl;
		cout << "        '` .-''. \|:  \.'   __, .-'`" << endl;
		cout << "           .'--._ `-:  \/:  /'  '.\             _|_" << endl;
		cout << "              /.'`\ :;   /'      `-           `-|-`" << endl;
		cout << "            -`    |     |                      |" << endl;
		cout << "                  :.; : |                  .-'~^~`-." << endl;
		cout << "                  |:    |                .' _     _ `." << endl;
		cout << "                  |:.   |                | |_) | |_) |" << endl;
		cout << "                  :. :  |                | | \\ | |   |" << endl;
		cout << "                      : ;                |           |" << endl;
		cout << "	 -. - / \\\ / :::.    `\.-._'. - _\\-|           |///. - "<< endl;
		cout << "             - .-.\\ - .//.- .`-._\\-.. - \\`=......... = `/ / -. " << endl;
}

/**********************************************************************
*																	  *
**********************************************************************/
void RPG::Credits()
{
	cout << "\nASCII art by Joan Stark of Westlake, Ohio." << endl;
	cout << "\n		Music" << endl;
	cout << "\tAvril 14th by Aphex Twin" << endl;
	cout << "\tAll sound effects found on YouTube.com\n" << endl;
}

/**********************************************************************
*																	  *
**********************************************************************/
void RPG::WinArt()
{
	PlaySound(TEXT("End.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

		cout << "Y88b   d88P .d88888b. 888     888   888       888 .d88888b. 888b    888" << endl;
		cout << " Y88b d88P d88P   Y88b888     888   888   o   888d88P   Y88b8888b   888" << endl;
		cout << "  Y88o88P  888     888888     888   888  d8b  888888     88888888b  888" << endl;
		cout << "   Y888P   888     888888     888   888 d888b 888888     888888Y88b 888" << endl;
		cout << "    888    888     888888     888   888d88888b888888     888888 Y88b888" << endl;
		cout << "    888    888     888888     888   88888P Y88888888     888888  Y88888" << endl;
		cout << "    888    Y88b. .d88PY88b. .d88P   8888P   Y8888Y88b. .d88P888   Y8888" << endl;
		cout << "    888      Y88888P    Y88888P     888P     Y888  Y88888P  888    Y888" << endl;
		Credits();
		system("pause");
}
