/*
* hash_table.h
* Written by : SENG1120 Staff (c1234567)
* Modified : 23/05/2024
*
* This class represents a templated hash table that uses a linked list for chaining.
* It is assumed that data items contain the method get_key, which returns a string.
* This file should be used in conjunction with Assignment 3 for SENG1120.
*/

#ifndef SENG1120_HASH_TABLE_H
#define SENG1120_HASH_TABLE_H

#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

template <typename T>
class HashTable
{
public:
    /*
    * Initialise a hash table with the specified capacity.
    *
    * Precondition:    None
    * Postcondition:   A new HashTable is created, with variables initialised as appropriate.
    */
    HashTable(int table_capacity = 101);

	/*
    * Precondition:    None
    * Postcondition:   The HashTable is destroyed and all associated memory is freed. Pointers should be set to nullptr.
    */
    ~HashTable();

    /*
    * The supplied data is inserted into the hash table. If a collision occurs, the data should be inserted 
    * at the end of the list.
    * 
    * Precondition:    The supplied data is valid.
    * Postcondition:   The data is inserted into the correct cell in the hash table. The count is increased by 1.
    */
    void insert(const T& data);

    /*
    * Remove the item with the specified key from the hash table, if it exists.
    *
    * This function may use the list_remove implementation provided in hash_table.h
    * 
    * Precondition:    The hash table has been initialised.
    * Postcondition:   The item with the specified key has been removed, if it exists. The count is reduced by 1 if an item is removed.
    */
    void remove(const std::string& key);

    /*
    * Return a pointer to the item with the specified key, if it exists. If no such item exists, nullptr is returned.
    * 
    * This function may use the list_find implementation provided in hash_table.h
    * 
    * Precondition:    The hash table has been initialised.
    * Postcondition:   The hash table has not been modified. 
    */
    T* get(const std::string& key);

    /*
    * Determine if an item with the specified key exists.
    * 
    * This function may use the list_contains implementation provided in hash_table.h

    * Precondition:    The hash table has been initialised.
    * Postcondition:   The hash table has not been modified.
    */
    bool contains(const std::string& key);

    /*
    * Clears all items from the hash table.
    *
    * Precondition:    None
    * Postcondition:   All cells in the hash table are emptied and any associated memory is reclaimed. Pointers are set to nullptr.
    */
    void clear();

    /*
    * Return true if the hash table is empty, false otherwise.
    * 
    * Precondition:    The hash table has been initialised.
    * Postcondition:   The hash table has not been modified.
    */  
    bool empty() const;

    /*
    * Return the number of items in the hash table.
    * 
    * Precondition:    The hash table has been initialised.
    * Postcondition:   The hash table has not been modified.
    */  
    int size() const;

    /*
	* Append the value of each cell in the hash table to the supplied stream. 
	* Each cell should be printed on its own line, as "index: <list>".
	*
	* To print the list, you may use the list_print function implementation provided in hash_table.h.
    * 
    * Precondition:    The hash table and supplied ostream have been initialised.
    * Postcondition:   The hash table has not been modified and has been appended to the stream.
    */ 
    void print(std::ostream& os) const;

private:
    std::vector<std::list<T>> table;  // The vector of lists, representing the cells. 
    int capacity;                     // The number of cells in the hash table.
    int count;                        // The number of elements in the hash table.

    /*
    * Compute the hash function for the supplied string. This should use std::hash<std::string> 
    * and return a valid index within the hash table. See the assignment spec for the implementation.
    * 
    * Precondition:    The hash table has been initialised.
    * Postcondition:   The hash table has not been modified.
    */ 
    int hash_function(const std::string& key) const
    {
        std::hash<std::string> hf;
        return hf(key) % capacity;
    }

    /**
     * Helper function to search for an item in a std::list by key. You should not need to directly call this function.
     * 
     * Precondition:    None
     * Postcondition:   Returns an iterator pointing to the list item with the supplied key, if it exists. Otherwise, the iterator will point to list.end().
     */ 
    typename std::list<T>::iterator internal_find(std::list<T>& list, const std::string& key) const
    {
        auto key_equals = [&key](const T& c) { return c.get_key() == key; };
        return std::find_if(list.begin(), list.end(), key_equals);
    }

    /**
     * Helper function to determine if an item exists in a std::list by its key.
     * 
     * Precondition:    None
     * Postcondition:   Returns true if an item with the supplied key exists in the list, false otherwise.
     */ 
    bool list_contains(std::list<T>& list, const std::string& key) const
    {
        typename std::list<T>::iterator it = internal_find(list, key);

        return it != list.end();
    }

    /**
     * Helper function to return a pointer to an item if it exists in the std::list, otherwise returns nullptr.
     * 
     * Precondition:    None
     * Postcondition:   Returns a reference to item with the supplied key it exists in the list, and nullptr otherwise.
     */ 
    T* list_find(std::list<T>& list, const std::string& key) const
    {
        typename std::list<T>::iterator it = internal_find(list, key);
        if(it != list.end())
        {
            return &*it;  //take a pointer to the value within the iterator
        }
        else
        {
            return nullptr;
        }
    }

    /**
     * Helper function to remove item if it exists in the std::list.
     * 
     * Precondition:    None
     * Postcondition:   Returns true if an item with the supplied key was removed from the list, otherwise returns false.
     */ 
    bool list_remove(std::list<T>& list, const std::string& key)
    {
        typename std::list<T>::iterator it = internal_find(list, key);
        //only erase if found
        if(it != list.end())
        {
            list.erase(it);
            return true;
        }
        else
        {
            return false;    
        }
    }

    void list_print(std::ostream& out, const std::list<T>& list) const
    {
        for(const T& item : list)
        {
            out << item << " ";
        }
    }
    
};

/*
* Append the value of each cell in the hash table, to the supplied stream. 
* Each cell should be printed on its own line, as "index: <list>".
*
* To print the list, you may use the list_print function implementation provided in hash_table.h.
* 
* Precondition:    The hash table and supplied ostream have been initialised.
* Postcondition:   The hash table has not been modified and has been appended to the stream.
*/ 
template <typename T>
std::ostream& operator<<(std::ostream& out, const HashTable<T>& table);

#include "hash_table.hpp"
#endif