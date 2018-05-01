/**********************************************************************
* Author:			Alexander Ott
* Filename:			Lab08
* Date Created:		02/28/2016
**********************************************************************/

#include "Dice.h"

/**********************************************************************
*																	  *
**********************************************************************/
Dice::Dice() : m_sides(0)
{ }

/**********************************************************************
*																	  *
**********************************************************************/
int Dice::Roll(int num_sides)
{
	return GetRandomNum(1, num_sides);
}

/**********************************************************************
* Purpose: Make and return a random integer.
*
* Precondition:
*		There is no precondition.
*
* Postcondition:
*		Returns the value of m_random_num.
*
************************************************************************/
int Dice::GetRandomNum(int min, int max)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(min, max);

	int random_integer = uni(rng);

	return random_integer;
}