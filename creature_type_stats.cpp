#include "creature_type_stats.h"

#pragma region Constructor
CreatureTypeStats::CreatureTypeStats()
{
	type = "";
	count = 0;
	total_power = 0;
}

CreatureTypeStats::CreatureTypeStats(const std::string& new_type)
{
	type = new_type;
	count = 0;
	total_power = 0;
}

CreatureTypeStats::~CreatureTypeStats()
{
	type = "";
	count = 0;
	total_power = 0;
}
#pragma endregion

#pragma region Accessors
const std::string& CreatureTypeStats::get_key() const
{
	return (type);
}

int CreatureTypeStats::get_count() const
{
	return (count);
}

int CreatureTypeStats::get_total_power() const
{
	return (total_power);
}

#pragma endregion

#pragma region Mutators
void CreatureTypeStats::increment_count()
{
	count++;
}

void CreatureTypeStats::decrement_count()
{
	count--;
}

void CreatureTypeStats::add_power(int power)
{
	total_power += power;
}

void CreatureTypeStats::subtract_power(int power)
{
	total_power -= power;
}

#pragma endregion

#pragma region Operator Overloads

std::ostream& operator<<(std::ostream& os, const CreatureTypeStats& c)
{
	os << "(" << c.get_key() << ", " << c.get_count() << ", " << c.get_total_power() << ")";
	return (os);
}

bool operator==(const CreatureTypeStats& c1, const CreatureTypeStats& c2)
{

	return (c1.get_key() == c2.get_key());
}

bool operator<(const CreatureTypeStats& c1, const CreatureTypeStats& c2)
{
	return (c1.get_key() < c2.get_key());
}

bool operator>(const CreatureTypeStats& c1, const CreatureTypeStats& c2)
{
	return (c1.get_key() > c2.get_key());
}

#pragma endregion