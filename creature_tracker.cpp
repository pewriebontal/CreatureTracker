#include "creature_tracker.h"

#pragma region Constructor
CreatureTracker::CreatureTracker()
	: tree_creatures()
	, ht_stats(101)
{ }

CreatureTracker::~CreatureTracker()
{
	clear();
}

#pragma endregion

#pragma region Functions

void CreatureTracker::add_creature(const std::string& name, const std::string& type, int power)
{
	Creature new_creature(name, type, power);
	tree_creatures.insert(new_creature);

	CreatureTypeStats* existing_stats = ht_stats.get(type);
	if(existing_stats)
	{
		existing_stats->increment_count();
		existing_stats->add_power(power);
		ht_stats.insert(*existing_stats);
	}
	else
	{
		CreatureTypeStats new_stats(type);
		new_stats.increment_count();
		new_stats.add_power(power);
		ht_stats.insert(new_stats);
	}
}

void CreatureTracker::remove_creature(const std::string& name)
{
	Creature* to_remove = tree_creatures.find(name);
	if(to_remove)
	{
		Creature found_creature = *to_remove;
		tree_creatures.remove(name);

		CreatureTypeStats stats(found_creature.get_type());
		if(ht_stats.contains(found_creature.get_type()))
		{
			stats = *ht_stats.get(found_creature.get_type());
			stats.decrement_count();
			stats.subtract_power(found_creature.get_power());
			if(stats.get_count() > 0)
				ht_stats.insert(stats);
			else
				ht_stats.remove(found_creature.get_type());
		}
	}
}

bool CreatureTracker::creature_exists(const std::string& name)
{
	return (tree_creatures.contains(name));
}

Creature* CreatureTracker::get_creature(const std::string& name)
{
	return (tree_creatures.find(name));
}

int CreatureTracker::type_count(const std::string& type)
{
	if(ht_stats.contains(type))
		return (ht_stats.get(type)->get_count());
	return (0);
}

int CreatureTracker::type_power(const std::string& type)
{
	if(ht_stats.contains(type))
		return (ht_stats.get(type)->get_total_power());
	return (0);
}

CreatureTypeStats* CreatureTracker::get_stats(const std::string& type)
{
	return (ht_stats.get(type));
}

void CreatureTracker::clear()
{
	tree_creatures.clear();
	ht_stats.clear();
}

void CreatureTracker::print(std::ostream& os) const
{
	os << "Creatures: " << tree_creatures << std::endl;
	os << "Type stats:" << std::endl;
	ht_stats.print(os);
}

#pragma endregion

#pragma region Operator Overloads

std::ostream& operator<<(std::ostream& out, const CreatureTracker& tracker)
{
	tracker.print(out);
	return (out);
}

#pragma endregion