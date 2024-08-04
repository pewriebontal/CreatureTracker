/*
* creature.cpp
* Written by : Min Thu Khaing (c3489993)
* Modified : 01/08/2024
*
* This class represents a simple creature object that contains a name, a type, and a power rating.
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
#include "creature.h"

#pragma region Constructors

/**
 * @brief Construct a new Creature object
 * 
 * Default constructor that initializes a Creature object with default values.
 * Sets the name and type to empty strings and power to zero.
 */
Creature::Creature()
{
	name = "";
	type = "";
	power = 0;
}

/**
 * @brief Construct a new Creature object with specified attributes
 * 
 * Initializes a Creature object with the given name, type, and power.
 * 
 * @param name The name of the creature
 * @param type The type of the creature
 * @param power The power level of the creature
 */
Creature::Creature(const std::string& name, const std::string& type, int power)
	: name(name)
	, type(type)
	, power(power)
{ }

/**
 * @brief Destroy the Creature object
 * 
 * Destructor that clears the name and type and sets power to zero.
 */
Creature::~Creature()
{
	name = "";
	type = "";
	power = 0;
}

#pragma endregion

#pragma region Accessors

/**
 * @brief Get the key (name) of the creature
 * 
 * Returns the name of the creature, which serves as the key for identification.
 * 
 * @return const std::string& A reference to the creature's name
 */
const std::string& Creature::get_key() const
{
	return (name);
}

/**
 * @brief Get the type of the creature
 * 
 * Returns the type of the creature.
 * 
 * @return const std::string& A reference to the creature's type
 */
const std::string& Creature::get_type() const
{
	return (type);
}

/**
 * @brief Get the power rating of the creature
 * 
 * Returns the power level of the creature.
 * 
 * @return int The power rating of the creature
 */
int Creature::get_power() const
{
	return (power);
}

#pragma endregion

#pragma region Operator Overloads

/**
 * @brief Append the Creature to the stream
 * 
 * Overloads the << operator to append the creature's information in the format 
 * (<name>, <type>, <power>) to the output stream.
 * 
 * @param os The output stream to append to
 * @param c The Creature object to append
 * @return std::ostream& The output stream with the appended Creature information
 */
std::ostream& operator<<(std::ostream& os, const Creature& c)
{
	os << "(" << c.get_key() << ", " << c.get_type() << ", " << c.get_power() << ")";
	return (os);
}

/**
 * @brief Determine if two creatures are equal
 * 
 * Compares two Creature objects for equality based on their name.
 * 
 * @param c1 The first Creature object to compare
 * @param c2 The second Creature object to compare
 * @return true if both creatures have the same name, false otherwise
 */
bool operator==(const Creature& c1, const Creature& c2)
{
	return (c1.get_key() == c2.get_key());
}

/**
 * @brief Determine if one creature is ordered before another
 * 
 * Compares two Creature objects alphabetically by name to determine order.
 * 
 * @param c1 The first Creature object to compare
 * @param c2 The second Creature object to compare
 * @return true if the first creature is ordered before the second, false otherwise
 */
bool operator<(const Creature& c1, const Creature& c2)
{
	return (c1.get_key() < c2.get_key());
}

/**
 * @brief Determine if one creature is ordered after another
 * 
 * Compares two Creature objects alphabetically by name to determine order.
 * 
 * @param c1 The first Creature object to compare
 * @param c2 The second Creature object to compare
 * @return true if the first creature is ordered after the second, false otherwise
 */
bool operator>(const Creature& c1, const Creature& c2)
{
	return (c1.get_key() > c2.get_key());
}

#pragma endregion