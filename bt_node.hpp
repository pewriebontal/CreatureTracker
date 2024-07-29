#include "bt_node.h"

template <typename T>
BTNode<T>::BTNode()
{
    data = T();
    left = nullptr;
    right = nullptr;
}

template <typename T>
BTNode<T>::BTNode(const T &new_data)
{
    data = new_data;
    left = nullptr;
    right = nullptr;
}

template <typename T>
BTNode<T>::~BTNode()
{
    data = nullptr;
    left = nullptr;
    right = nullptr;
}

template <typename T>
void BTNode<T>::set_data(const T &new_data)
{
    data = new_data;
}

template <typename T>
void BTNode<T>::set_left(BTNode<T> *new_left)
{
    left = new_left;
}

template <typename T>
void BTNode<T>::set_right(BTNode<T> *new_right)
{
    right = new_right;
}

template <typename T>
T &BTNode<T>::get_data()
{
    return data;
}

template <typename T>
BTNode<T> *BTNode<T>::get_left() const
{
    return left;
}

template <typename T>
BTNode<T> *BTNode<T>::get_right() const
{
    return right;
}

//////////////////////////////overloaded operator///////////////////////////////
template <typename T>
std::ostream &operator<<(std::ostream &out, const BTNode<T> &node)
{
    // TODO: Implement this function
}