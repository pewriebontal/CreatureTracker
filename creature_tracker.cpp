/*
* creature_tracker.cpp
* Written by : Min Thu Khaing (c3489993)
* Modified : 01/08/2024
*
* This class represents a simple creature tracker to maintain information about creatures.
* This file should be used in conjunction with Assignment 3 for SENG1120.
*/
/*
 *                       _oo0oo_
 *                      o8888888o
 *                      88" . "88
 *                      (| -_- |)
 *                      0\  =  /0
 *                    ___/`---'\___
 *                  .' \\|     |// '.
 *                 / \\|||  :  |||// \
 *                / _||||| -:- |||||- \
 *               |   | \\\  -  /// |   |
 *               | \_|  ''\---/''  |_/ |
 *               \  .-\__  '-'  ___/-. /
 *             ___'. .'  /--.--\  `. .'___
 *          ."" '<  `.___\_<|>_/___.' >' "".
 *         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *         \  \ `_.   \_ __\ /__ _/   .-` /  /
 *     =====`-.____`.___ \_____/___.-`___.-'=====
 *                       `=---='
 *
 *
 *     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *               佛祖保佑         永无BUG
 */
#include "creature_tracker.h"

#pragma region Constructor

/**
 * @brief Construct a new CreatureTracker object
 * 
 * Initializes the creature tracker with an empty binary search tree for creatures
 * and a hash table for creature type statistics with a capacity of 101.
 */
CreatureTracker::CreatureTracker()
	: tree_creatures()
	, ht_stats(101)
{ }

/**
 * @brief Destroy the CreatureTracker object
 * 
 * Clears all data from the tracker by removing all creatures and resetting statistics.
 */
CreatureTracker::~CreatureTracker()
{
	clear();
}

#pragma endregion

#pragma region Functions

/**
 * @brief Add a new creature to the tracker
 * 
 * Inserts a new creature into the binary search tree and updates the hash table
 * with the creature's type statistics. If the type already exists, updates its
 * count and total power.
 * 
 * @param name The name of the creature
 * @param type The type of the creature
 * @param power The power level of the creature
 */
void CreatureTracker::add_creature(const std::string& name, const std::string& type, int power)
{
	CreatureTypeStats* existing_stats;

	Creature new_creature(name, type, power);
	tree_creatures.insert(new_creature);
	existing_stats = ht_stats.get(type);
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

/**
 * @brief Remove a creature from the tracker
 * 
 * Removes the creature with the specified name from the binary search tree.
 * Updates the hash table by decrementing the type's count and subtracting the
 * creature's power. Removes the type from the hash table if its count reaches zero.
 * 
 * @param name The name of the creature to remove
 */
void CreatureTracker::remove_creature(const std::string& name)
{
	Creature* to_remove;
	Creature found_creature;

	to_remove = tree_creatures.find(name);
	if(to_remove)
	{
		found_creature = *to_remove;
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

/**
 * @brief Check if a creature exists in the tracker
 * 
 * Determines if a creature with the specified name exists in the binary search tree.
 * 
 * @param name The name of the creature to check
 * @return true if the creature exists, false otherwise
 */
bool CreatureTracker::creature_exists(const std::string& name)
{
	return (tree_creatures.contains(name));
}

/**
 * @brief Retrieve a creature from the tracker
 * 
 * Searches for and returns a pointer to the creature with the specified name.
 * 
 * @param name The name of the creature to retrieve
 * @return Creature* A pointer to the creature, or nullptr if not found
 */
Creature* CreatureTracker::get_creature(const std::string& name)
{
	return (tree_creatures.find(name));
}

/**
 * @brief Get the count of creatures of a specific type
 * 
 * Returns the number of creatures of the specified type in the hash table.
 * 
 * @param type The type of creatures to count
 * @return int The count of creatures of the specified type
 */
int CreatureTracker::type_count(const std::string& type)
{
	if(ht_stats.contains(type))
		return (ht_stats.get(type)->get_count());
	return (0);
}

/**
 * @brief Get the total power of creatures of a specific type
 * 
 * Returns the combined power of all creatures of the specified type in the hash table.
 * 
 * @param type The type of creatures to calculate total power for
 * @return int The total power of creatures of the specified type
 */
int CreatureTracker::type_power(const std::string& type)
{
	if(ht_stats.contains(type))
		return (ht_stats.get(type)->get_total_power());
	return (0);
}

/**
 * @brief Retrieve statistics for a specific creature type
 * 
 * Returns a pointer to the CreatureTypeStats for the specified type, or nullptr if not found.
 * 
 * @param type The type of creatures to retrieve statistics for
 * @return CreatureTypeStats* A pointer to the statistics, or nullptr if not found
 */
CreatureTypeStats* CreatureTracker::get_stats(const std::string& type)
{
	return (ht_stats.get(type));
}

/**
 * @brief Clear all data from the tracker
 * 
 * Removes all creatures from the binary search tree and clears the hash table,
 * effectively resetting the tracker.
 */
void CreatureTracker::clear()
{
	tree_creatures.clear();
	ht_stats.clear();
}

/**
 * @brief Print the contents of the tracker
 * 
 * Outputs all creatures and their statistics to the provided stream.
 * 
 * @param os The output stream to print to
 */
void CreatureTracker::print(std::ostream& os) const
{
	os << "Creatures: " << tree_creatures << std::endl;
	os << "Type stats:" << std::endl;
	ht_stats.print(os);
}

#pragma endregion

#pragma region Operator Overloads

/**
 * @brief Output the tracker to a stream
 * 
 * Overloads the << operator to output the contents of the creature tracker.
 * 
 * @param out The output stream to append to
 * @param tracker The CreatureTracker object to print
 * @return std::ostream& The output stream with the appended tracker information
 */
std::ostream& operator<<(std::ostream& out, const CreatureTracker& tracker)
{
	tracker.print(out);
	return (out);
}

#pragma endregion