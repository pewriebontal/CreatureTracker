/*
* creature.h
* Written by : SENG1120 Staff (c1234567)
* Modified : 09/05/2024
*
* This class represents a simple creature object that contains a name, a type, and a power rating.
* This file should be used in conjunction with Assignment 3 for SENG1120.
*/

#ifndef SENG1120_CREATURE_H
#define SENG1120_CREATURE_H

#include <string>
#include <iostream>

class Creature
{
public:
	/*
    * Precondition:    None
    * Postcondition:   A new Creature is created with an empty string for the name and type, and 0 for the power.
    */
    Creature();

    /*
    * Precondition:    None
    * Postcondition:   A new Creature is created with the specified name, type, and power.
    */
    Creature(const std::string& name, const std::string& type, int power);

    /*
    * Precondition:    None
    * Postcondition:   The Creature is destroyed and all associated memory is freed.
    */
    ~Creature();

    /*
    * Return a reference to the underlying name as the key for the Creature object.
    *
    * Precondition:    The Creature has been initialised.
    * Postcondition:   A reference to the Creature's name is returned.
    */
    const std::string& get_key() const;

    /*
    * Return a reference to the type of the Creature object.
    *
    * Precondition:    The Creature has been initialised.
    * Postcondition:   A reference to the Creature's type is returned.
    */
    const std::string& get_type() const;

    /*
    * Return the power rating of the Creature object.
    *
    * Precondition:    The Creature has been initialised.
    * Postcondition:   The Creature's power rating is returned.
    */
    int get_power() const;

private:
    std::string name;     // The creature name.
    std::string type;     // The type.
    int power;            // The power rating.
};

/*
* The value of the Creature is appended to the stream, without any spaces.
*
* Precondition:    The supplied Creature and ostream are valid.
* Postcondition:   The stream is updated with the Creature appended.
*/
std::ostream& operator << (std::ostream& os, const Creature& c);

/*
* Determine if two creatures are equal. Two creatures are considered equal if they have the same name.
*
* Precondition:    The supplied Creatures are initialised.
* Postcondition:   None.
*/
bool operator == (const Creature& c1, const Creature& c2);

/*
* Determine if the first Creature is ordered before the second Creature, alphabetically by name. 
*
* Precondition:    The supplied Creatures are initialised.
* Postcondition:   None.
*/
bool operator < (const Creature& c1, const Creature& c2);

/*
* Determine if the first Creature is ordered after the second Creature, aplhabetically by name. 
*
* Precondition:    The supplied Creatures are initialised.
* Postcondition:   None.
*/
bool operator > (const Creature& c1, const Creature& c2);

#endif