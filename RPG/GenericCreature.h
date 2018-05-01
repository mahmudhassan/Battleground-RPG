#pragma once

#include "String.h"

class GenericCreature
{
	public:
		GenericCreature();
		virtual ~GenericCreature();
		virtual void Display() const = 0;

		String m_name;
		int m_hit_points;
		int m_damage_range;
		int m_armor;
};