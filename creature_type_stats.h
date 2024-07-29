/*
* creature_type_stats.h
* Written by : SENG1120 Staff (c1234567)
* Modified : 16/05/2024
*
* This class represents a stats object for a type of creature.
* This file should be used in conjunction with Assignment 3 for SENG1120.
*/

#ifndef SENG1120_CREATURE_TYPE_STATS_H
#define SENG1120_CREATURE_TYPE_STATS_H

#include <string>
#include <iostream>

class CreatureTypeStats
{
public:
	/*
    * Precondition:    None
    * Postcondition:   A CreatureTypeStats object is created with an empty string for the type, 
    * and 0 for the count and total power.
    */
    CreatureTypeStats();

    /*
    * Precondition:    None
    * Postcondition:   A CreatureTypeStats object is created with the supplied type, 
    * and 0 for the count and total power.
    */
    CreatureTypeStats(const std::string& type);

    /*
    * Precondition:    None
    * Postcondition:   The CreatureTypeStats is destroyed and all associated memory is freed.
    */
    ~CreatureTypeStats();

    /*
    * Return a reference to the underlying type as the key for the CreatureTypeStats object.
    *
    * Precondition:    The CreatureTypeStats has been initialised.
    * Postcondition:   A reference to the CreatureTypeStats' type is returned.
    */
    const std::string& get_key() const;

    /*
    * Return a count of the number of creatures with this type.
    *
    * Precondition:    The CreatureTypeStats has been initialised.
    * Postcondition:   The number of creatures with this type is returned.
    */
    int get_count() const;

    /*
    * Return the total power of creatures with this type.
    *
    * Precondition:    The CreatureTypeStats has been initialised.
    * Postcondition:   The total power of the creatures with this type is returned.
    */
    int get_total_power() const;

    /*
    * Increment the count by 1.
    *
    * Precondition:    The CreatureTypeStats has been initialised.
    * Postcondition:   The count is increased by 1.
    */
    void increment_count();
    
    /*
    * Decrement the count by 1.
    *
    * Precondition:    The CreatureTypeStats has been initialised.
    * Postcondition:   The count is decreased by 1.
    */
    void decrement_count();

    /*
    * Add the supplied power amount to the total power.
    *
    * Precondition:    The CreatureTypeStats has been initialised.
    * Postcondition:   The total power is increased by the supplied amount.
    */
    void add_power(int amount);
    
    /*
    * Subtract the supplied power amount from the total power.
    *
    * Precondition:    The CreatureTypeStats has been initialised.
    * Postcondition:   The total power is decreased by the supplied amount.
    */
    void subtract_power(int amount);

private:
    std::string type;     // The type.
    int count;            // The total power.
    int total_power;      // The power rating.
};

/*
* The value of the CreatureTypeStats is appended to the stream.
*
* The expected format is (<type>, <count>, <total power>), including the brackets.
*
* Precondition:    The supplied CreatureTypeStats and ostream are valid.
* Postcondition:   The stream is updated with the CreatureTypeStats appended.
*/
std::ostream& operator << (std::ostream& os, const CreatureTypeStats& c);

/*
* Determine if two CreatureTypeStats are equal. Two CreatureTypeStats are considered equal if they have the same type.
*
* Precondition:    The supplied CreatureTypeStats are initialised.
* Postcondition:   None.
*/
bool operator == (const CreatureTypeStats& c1, const CreatureTypeStats& c2);

/*
* Determine if the first CreatureTypeStats is ordered before the second CreatureTypeStats, alphabetically by type. 
*
* Precondition:    The supplied CreatureTypeStats are initialised.
* Postcondition:   None.
*/
bool operator < (const CreatureTypeStats& c1, const CreatureTypeStats& c2);

/*
* Determine if the first CreatureTypeStats is ordered after the second CreatureTypeStats, aplhabetically by type. 
*
* Precondition:    The supplied Creatures are initialised.
* Postcondition:   None.
*/
bool operator > (const CreatureTypeStats& c1, const CreatureTypeStats& c2);

#endif