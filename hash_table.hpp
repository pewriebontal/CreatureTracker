#include "hash_table.h"

template <typename T>
HashTable<T>::HashTable(int table_capacity)
{
}

template <typename T>
HashTable<T>::~HashTable()
{
}

template <typename T>
void HashTable<T>::insert(const T &data)
{
}

template <typename T>
void HashTable<T>::remove(const std::string &key)
{
}

template <typename T>
T *HashTable<T>::get(const std::string &key)
{
}

template <typename T>
bool HashTable<T>::contains(const std::string &key)
{
}

template <typename T>
void HashTable<T>::clear()
{
}

template <typename T>
bool HashTable<T>::empty() const
{
}

template <typename T>
int HashTable<T>::size() const
{
}

template <typename T>
void HashTable<T>::print(std::ostream &os) const
{
}

///////////////////////////overloaded operators///////////////////////////

template <typename T>
std::ostream &operator<<(std::ostream &out, const HashTable<T> &table)
{
}