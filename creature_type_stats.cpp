/*
* creature_type_stats.cpp
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
#include "creature_type_stats.h"

#pragma region Constructor

/**
 * @brief Construct a new CreatureTypeStats object
 * 
 * Default constructor that initializes a CreatureTypeStats object with default values.
 * Sets the type to an empty string, and both count and total power to zero.
 */
CreatureTypeStats::CreatureTypeStats()
{
	type = "";
	count = 0;
	total_power = 0;
}

/**
 * @brief Construct a new CreatureTypeStats object with a specified type
 * 
 * Initializes a CreatureTypeStats object with a given type, setting count and total power to zero.
 * 
 * @param new_type The type of the creature
 */
CreatureTypeStats::CreatureTypeStats(const std::string& new_type)
{
	type = new_type;
	count = 0;
	total_power = 0;
}

/**
 * @brief Destroy the CreatureTypeStats object
 * 
 * Destructor that resets the type to an empty string and both count and total power to zero.
 */
CreatureTypeStats::~CreatureTypeStats()
{
	type = "";
	count = 0;
	total_power = 0;
}
#pragma endregion

#pragma region Accessors

/**
 * @brief Get the key (type) of the creature
 * 
 * Returns the type of the creature, which serves as the key for the stats.
 * 
 * @return const std::string& A reference to the creature type
 */
const std::string& CreatureTypeStats::get_key() const
{
	return (type);
}

/**
 * @brief Get the count of creatures of this type
 * 
 * Provides the number of creatures of this type tracked by the stats.
 * 
 * @return int The count of creatures of this type
 */
int CreatureTypeStats::get_count() const
{
	return (count);
}

/**
 * @brief Get the total power of creatures of this type
 * 
 * Provides the total power of all creatures of this type.
 * 
 * @return int The total power of creatures of this type
 */
int CreatureTypeStats::get_total_power() const
{
	return (total_power);
}

#pragma endregion

#pragma region Mutators

/**
 * @brief Increment the count of creatures of this type
 * 
 * Increases the count of creatures of this type by one.
 */
void CreatureTypeStats::increment_count()
{
	count++;
}

/**
 * @brief Decrement the count of creatures of this type
 * 
 * Decreases the count of creatures of this type by one.
 */
void CreatureTypeStats::decrement_count()
{
	count--;
}

/**
 * @brief Add power to the total power of this creature type
 * 
 * Increases the total power of creatures of this type by the specified amount.
 * 
 * @param power The amount of power to add
 */
void CreatureTypeStats::add_power(int power)
{
	total_power += power;
}

/**
 * @brief Subtract power from the total power of this creature type
 * 
 * Decreases the total power of creatures of this type by the specified amount.
 * 
 * @param power The amount of power to subtract
 */
void CreatureTypeStats::subtract_power(int power)
{
	total_power -= power;
}

#pragma endregion

#pragma region Operator Overloads

/**
 * @brief Append the CreatureTypeStats to the stream
 *
 * Overloads the << operator to append the creature type stats in the format 
 * (<type>, <count>, <total power>) to the output stream.
 * 
 * @param os The output stream to append to
 * @param c The CreatureTypeStats object to append
 * @return std::ostream& The output stream with the appended CreatureTypeStats
 */
std::ostream& operator<<(std::ostream& os, const CreatureTypeStats& c)
{
	os << "(" << c.get_key() << ", " << c.get_count() << ", " << c.get_total_power() << ")";
	return (os);
}

/**
 * @brief Determine if two CreatureTypeStats are equal
 * 
 * Compares two CreatureTypeStats objects for equality based on their type.
 * 
 * @param c1 The first CreatureTypeStats object to compare
 * @param c2 The second CreatureTypeStats object to compare
 * @return true if both CreatureTypeStats have the same type, false otherwise
 */
bool operator==(const CreatureTypeStats& c1, const CreatureTypeStats& c2)
{
	return (c1.get_key() == c2.get_key());
}

/**
 * @brief Determine if one CreatureTypeStats is ordered before another
 * 
 * Compares two CreatureTypeStats objects alphabetically by type to determine order.
 * 
 * @param c1 The first CreatureTypeStats object to compare
 * @param c2 The second CreatureTypeStats object to compare
 * @return true if the first CreatureTypeStats is ordered before the second, false otherwise
 */
bool operator<(const CreatureTypeStats& c1, const CreatureTypeStats& c2)
{
	return (c1.get_key() < c2.get_key());
}

/**
 * @brief Determine if one CreatureTypeStats is ordered after another
 * 
 * Compares two CreatureTypeStats objects alphabetically by type to determine order.
 * 
 * @param c1 The first CreatureTypeStats object to compare
 * @param c2 The second CreatureTypeStats object to compare
 * @return true if the first CreatureTypeStats is ordered after the second, false otherwise
 */
bool operator>(const CreatureTypeStats& c1, const CreatureTypeStats& c2)
{
	return (c1.get_key() > c2.get_key());
}

#pragma endregion