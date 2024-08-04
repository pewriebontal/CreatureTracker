/*
 * bt_node.hpp
 * Written by : Min Thu Khaing (c3489993)
 * Modified : 01/08/2023
 *
 * This class represents a templated binary tree node.
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
#ifndef BT_NODE_HPP
#define BT_NODE_HPP
#include "bt_node.h"

#pragma region Constructor

/**
 * @brief Construct a new BTNode<T>::BTNode object
 *

	* Default constructor that initializes a binary tree node with default data and null children.
 *
 * @tparam T The data type stored in the node
 */
template <typename T>
BTNode<T>::BTNode()
{
	data = T();
	left = nullptr;
	right = nullptr;
}

/**
 * @brief Construct a new BTNode<T>::BTNode object
 *

	* Constructor that initializes a binary tree node with specified data and null children.
 *
 * @tparam T The data type stored in the node
 * @param new_data The data to initialize in the node
 */
template <typename T>
BTNode<T>::BTNode(const T& new_data)
{
	data = new_data;
	left = nullptr;
	right = nullptr;
}

/**
 * @brief Destroy the BTNode<T>::BTNode object
 *

	* Destructor that clears the data and nullifies the children pointers of the node.
 *
 * @tparam T The data type stored in the node
 */
template <typename T>
BTNode<T>::~BTNode()
{
	data = T();
	left = nullptr;
	right = nullptr;
}

#pragma endregion

#pragma region Accessors and Mutators

/**
 * @brief Set the data in the node
 *
 * Updates the data stored in the node.
 *
 * @tparam T The data type stored in the node
 * @param new_data The new data to store in the node
 */
template <typename T>
void BTNode<T>::set_data(const T& new_data)
{
	data = new_data;
}

/**
 * @brief Set the left child of the node
 *
 * Updates the left child pointer of the node.
 *
 * @tparam T The data type stored in the node
 * @param new_left Pointer to the new left child node
 */
template <typename T>
void BTNode<T>::set_left(BTNode<T>* new_left)
{
	left = new_left;
}

/**
 * @brief Set the right child of the node
 *
 * Updates the right child pointer of the node.
 *
 * @tparam T The data type stored in the node
 * @param new_right Pointer to the new right child node
 */
template <typename T>
void BTNode<T>::set_right(BTNode<T>* new_right)
{
	right = new_right;
}

/**
 * @brief Get the data stored in the node
 *
 * Provides access to the data stored in the node.
 *
 * @tparam T The data type stored in the node
 * @return T& A reference to the data stored in the node
 */
template <typename T>
T& BTNode<T>::get_data()
{
	return (data);
}

/**
 * @brief Get the left child of the node
 *
 * Provides access to the left child node.
 *
 * @tparam T The data type stored in the node
 * @return BTNode<T>* A pointer to the left child node
 */
template <typename T>
BTNode<T>* BTNode<T>::get_left() const
{
	return (left);
}

/**
 * @brief Get the right child of the node
 *
 * Provides access to the right child node.
 *
 * @tparam T The data type stored in the node
 * @return BTNode<T>* A pointer to the right child node
 */
template <typename T>
BTNode<T>* BTNode<T>::get_right() const
{
	return (right);
}

#pragma endregion
#pragma region Operator Overloads

/**
 * @brief Append the value of the node's data to the stream
 *

	* Overloads the << operator to append the node's data value to the output stream.
 *
 * @tparam T The data type stored in the node
 * @param out The output stream to append to
 * @param node The node whose data will be appended to the stream
 * @return std::ostream& The output stream with the node's data appended
 */
template <typename T>
std::ostream& operator<<(std::ostream& out, const BTNode<T>& node)
{
	out << node.get_data();
	return (out);
}

#pragma endregion
#endif // BT_NODE_HPP