/*
* hash_table.hpp
* Written by : Min Thu Khaing (c3489993)
* Modified : 01/08/2024
*
* This class represents a templated hash table that uses a linked list for chaining.
* It is assumed that data items contain the method get_key, which returns a string.
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

#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP
#include "hash_table.h"

#pragma region Constructor

/**
 * @brief Construct a new HashTable<T> object
 * 
 * Initializes a hash table with the specified capacity.
 * 
 * @tparam T The data type stored in the hash table
 * @param table_capacity The initial capacity of the hash table
 */
template <typename T>
HashTable<T>::HashTable(int table_capacity)
	: capacity(table_capacity)
{
	table.resize(capacity);
}

/**
 * @brief Destroy the HashTable<T> object
 * 
 * Destructor that clears the hash table and resets its capacity and count.
 * 
 * @tparam T The data type stored in the hash table
 */
template <typename T>
HashTable<T>::~HashTable()
{
	clear();
	capacity = 0;
	count = 0;
}

#pragma endregion

#pragma region Functions

/**
 * @brief Insert data into the hash table
 * 
 * The supplied data is inserted into the hash table. If a collision occurs, the data is inserted
 * at the end of the list in the corresponding bucket.
 * 
 * @tparam T The data type stored in the hash table
 * @param data The data to insert
 */
template <typename T>
void HashTable<T>::insert(const T& data)
{
	int index;

	index = hash_function(data.get_key());
	std::list<T>& cell = table[index]; // i dont know can use auto keyword anot
	for(T& item : cell)
	{
		if(item.get_key() == data.get_key())
		{
			item = data;
			return;
		}
	}
	cell.push_back(data);
	++count;
}

/**
 * @brief Remove an item from the hash table
 *
 * Removes the item with the specified key from the hash table, if it exists.
 *
 * This function may use the list_remove implementation provided in hash_table.h.
 * 
 * @tparam T The data type stored in the hash table
 * @param key The key of the item to remove
 */
template <typename T>
void HashTable<T>::remove(const std::string& key)
{
	int index;

	index = hash_function(key);
	if(list_remove(table[index], key))
		count--;
}

/**
 * @brief Retrieve an item from the hash table
 * 
 * Returns a pointer to the item with the specified key, if it exists. If no such item exists, nullptr is returned.
 * 
 * This function may use the list_find implementation provided in hash_table.h.
 * 
 * @tparam T The data type stored in the hash table
 * @param key The key of the item to retrieve
 * @return T* A pointer to the item, or nullptr if not found
 */
template <typename T>
T* HashTable<T>::get(const std::string& key)
{
	int index;

	index = hash_function(key);
	return (list_find(table[index], key));
}

/**
 * @brief Check if an item exists in the hash table
 * 
 * Determines if an item with the specified key exists in the hash table.
 * 
 * This function may use the list_contains implementation provided in hash_table.h.
 * 
 * @tparam T The data type stored in the hash table
 * @param key The key to search for
 * @return true if the item exists, false otherwise
 */
template <typename T>
bool HashTable<T>::contains(const std::string& key)
{
	int index;

	index = hash_function(key);
	return (list_contains(table[index], key));
}

/**
 * @brief Clear all items from the hash table
 * 
 * Removes all items from the hash table, effectively resetting it.
 * 
 * @tparam T The data type stored in the hash table
 */
template <typename T>
void HashTable<T>::clear()
{
	for(std::list<T>& lst : table)
		lst.clear();
	count = 0;
}

/**
 * @brief Check if the hash table is empty
 * 
 * Determines if the hash table contains any items.
 * 
 * @tparam T The data type stored in the hash table
 * @return true if the hash table is empty, false otherwise
 */
template <typename T>
bool HashTable<T>::empty() const
{
	return (count == 0);
}

/**
 * @brief Get the number of items in the hash table
 * 
 * Returns the total number of items currently stored in the hash table.
 * 
 * @tparam T The data type stored in the hash table
 * @return int The number of items in the hash table
 */
template <typename T>
int HashTable<T>::size() const
{
	return (count);
}

/**
 * @brief Print the contents of the hash table
 * 
 * Appends the value of each cell in the hash table to the supplied stream. 
 * Each cell is printed on its own line in the format "index: <list>".
 *
 * To print the list, the list_print function implementation provided in hash_table.h may be used.
 * 
 * @tparam T The data type stored in the hash table
 * @param os The output stream to append to
 */
template <typename T>
void HashTable<T>::print(std::ostream& os) const
{
	for(size_t i = 0; i < table.size(); ++i)
	{
		os << i << ": ";
		list_print(os, table[i]);
		os << std::endl;
	}
}

#pragma endregion

#pragma region Operator Overloads

/**
 * @brief Output the hash table to a stream
 * 
 * Overloads the << operator to output the hash table's contents to the supplied stream.
 * This function internally calls the print method.
 * 
 * @tparam T The data type stored in the hash table
 * @param out The output stream to append to
 * @param table The hash table to output
 * @return std::ostream& The output stream with the appended hash table contents
 */
template <typename T>
std::ostream& operator<<(std::ostream& out, const HashTable<T>& table)
{
	table.print(out);
	return (out);
}

#pragma endregion
#endif // HASH_TABLE_HPP