#pragma once

#include "String.h"
#include "Dice.h"

class Items
{
	public:
		Items();
		Items(const Items & copy);
		virtual ~Items();
		virtual Items & operator = (const Items & rhs);
		virtual void Display() const {};
		String GetName() const;
		int GetCost() const;
		virtual int UseItem();
		
		String m_name;
		int m_cost;
};