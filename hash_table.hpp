#include "hash_table.h"

#pragma region Constructor

template <typename T>
HashTable<T>::HashTable(int table_capacity)
	: capacity(table_capacity)
{
	table.resize(capacity);
}

template <typename T>
HashTable<T>::~HashTable()
{
	clear();
	capacity = 0;
	count = 0;
}

#pragma endregion

#pragma region Functions

template <typename T>
void HashTable<T>::insert(const T& data)
{
	int index = hash_function(data.get_key());
	std::list<T>& cell = table[index];

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

template <typename T>
void HashTable<T>::remove(const std::string& key)
{
	int index;
	index = hash_function(key);
	if(list_remove(table[index], key))
		count--;
}

template <typename T>
T* HashTable<T>::get(const std::string& key)
{
	int index;
	index = hash_function(key);
	return (list_find(table[index], key));
}

template <typename T>
bool HashTable<T>::contains(const std::string& key)
{
	int index;
	index = hash_function(key);
	return (list_contains(table[index], key));
}
template <typename T>
void HashTable<T>::clear()
{
	for(std::list<T>& lst : table)
		lst.clear();
	count = 0;
}

template <typename T>
bool HashTable<T>::empty() const
{
	return (count == 0);
}

template <typename T>
int HashTable<T>::size() const
{
	return (count);
}

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

template <typename T>
std::ostream& operator<<(std::ostream& out, const HashTable<T>& table)
{
	table.print(out);
	return (out);
}

#pragma endregion