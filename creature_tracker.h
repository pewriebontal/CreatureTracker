/*
* creature_tracker.h
* Written by : SENG1120 Staff (c1234567)
* Modified : 09/05/2024
*
* This class represents a simple creature tracker to maintain information about creatures.
* This file should be used in conjunction with Assignment 3 for SENG1120.
*/

#ifndef SENG1120_CREATURE_TRACKER_H
#define SENG1120_CREATURE_TRACKER_H

#include <string>
#include <iostream>
#include "creature.h"
#include "creature_type_stats.h"
#include "hash_table.h"
#include "bs_tree.h"

class CreatureTracker
{
public:
	/*
    * Precondition:    None
    * Postcondition:   A new CreatureTracker is created - not much to do here!
    */
    CreatureTracker();

    /*
    * Precondition:    None
    * Postcondition:   The CreatureTracker is destroyed and all associated memory is freed.
    */
    ~CreatureTracker();

    /*
    * Add a new Creature with the supplied information to the CreatureTracker.
    *
    * Precondition:    The CreatureTracker has been initialised.
    * Postcondition:   Both the tree and hash table have been updated accordingly.
    */
    void add_creature(const std::string& name, const std::string& type, int power);
    
    /*
    * Remove the information for the Creature with the supplied name from the CreatureTracker.
    *
    * Precondition:    The CreatureTracker has been initialised.
    * Postcondition:   Both the tree and hash table have been updated accordingly.
    */
    void remove_creature(const std::string& name);

    /*
    * Check if a Creature with the supplied name exists.
    *
    * Precondition:    The CreatureTracker has been initialised.
    * Postcondition:   Return true if the creature is in the tree. Otherwise, return false.
    */
    bool creature_exists(const std::string& name);

    /*
    * Get a pointer to the Creature with the supplied name, or nullptr if it does not exist.
    *
    * Precondition:    The CreatureTracker has been initialised.
    * Postcondition:   A pointer to the creature with the supplied name, if it exists. Otherwise, returns nullptr.
    */
    Creature* get_creature(const std::string& name);
    
    /*
    * Return a count of the number of creatures with the supplied type.
    *
    * Precondition:    The CreatureTracker has been initialised.
    * Postcondition:   The number of creatures with the supplied type is returned.
    */
    int type_count(const std::string& type);

    /*
    * Return the total power of the creatures with the supplied type.
    *
    * Precondition:    The CreatureTracker has been initialised.
    * Postcondition:   The total power of creatures with the supplied type is returned.
    */
    int type_power(const std::string& type);

    /*
    * Get a pointer to the CreatureTypeStats with the supplied type, or nullptr if it does not exist.
    *
    * Precondition:    The CreatureTracker has been initialised.
    * Postcondition:   A pointer to the CreatureTypeStats with the supplied type, if it exists. Otherwise, returns nullptr.
    */
    CreatureTypeStats* get_stats(const std::string& type);

    /*
    * Clears all Creatures and CreatureTypeStats' from the CreatureTracker.
    *
    * Precondition:    None
    * Postcondition:   All nodes from the tree, and entries from the hash table, are removed and any associated memory is reclaimed. Pointers are set to nullptr.
    */
    void clear();

    /*
    * Append both the creature tree and the type stats hash table to the stream.
    * 
    * The expected format is given below.
    * 
    * Creatures: <tree>
    * 
    * Type stats:
    * <hash table>
    * 
    * Precondition:    The supplied ostream has been initialised.
    * Postcondition:   The creature tracker has not been modified and has been appended to the stream.
    */ 
    void print(std::ostream& os) const;

private:
    BSTree<Creature> tree_creatures;       //a binary search tree holding the Creatures
    HashTable<CreatureTypeStats> ht_stats; //a hash table holding the CreatureTypeStats
};

/*
* Append both the creature tree and the type stats hash table to the stream. You are expected to use the print function. See print for further details on the expected format.
*
* Precondition:    The supplied ostream has been initialised.
* Postcondition:   The creature tracker has not been modified and has been appended to the stream.
*/ 
std::ostream& operator<<(std::ostream& out, const CreatureTracker& tracker);

#endif