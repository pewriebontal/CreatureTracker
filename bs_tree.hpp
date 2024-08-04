/*
* bs_tree.h
* Written by : Min Thu Khaing (c3489993)
* Modified : 01/08/2024
*
* This class represents a templated binary search tree.
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
#ifndef BS_TREE_H
#define BS_TREE_H
#include "bs_tree.h"

#pragma region Constructor

/**
 * @brief Construct a new BSTree<T>::BSTree object
 * 
 * Initializes an empty binary search tree with a null root and a count of zero.
 * 
 * @tparam T The data type stored in the tree
 */
template <typename T>
BSTree<T>::BSTree()
{
	root = nullptr;
	count = 0;
}

/**
 * @brief Destroy the BSTree<T>::BSTree object
 * 
 * Deletes all nodes in the binary search tree and sets the root to null.
 * 
 * @tparam T The data type stored in the tree
 */
template <typename T>
BSTree<T>::~BSTree()
{
	// clear alr set root to nullptr
	// so so i will not set it here.
	clear();
}

#pragma endregion

#pragma region Functions Public

/**
 * @brief Insert a new element into the binary search tree
 * 
 * Public interface for inserting an element. Calls the private insert function.
 * 
 * @tparam T The data type stored in the tree
 * @param data The data to insert into the tree
 */
template <typename T>
void BSTree<T>::insert(const T& data)
{
	root = insert(data, root);
}

/**
 * @brief Remove an element from the binary search tree
 * 
 * Public interface for removing an element. Calls the private remove function.
 * 
 * @tparam T The data type stored in the tree
 * @param key The key of the element to remove
 */
template <typename T>
void BSTree<T>::remove(const std::string& key)
{
	root = remove(key, root);
}

/**
 * @brief Check if the tree contains an element with the specified key
 * 
 * Determines whether the tree contains a node with the given key.
 * 
 * @tparam T The data type stored in the tree
 * @param key The key to search for in the tree
 * @return true if the key is found in the tree, false otherwise
 */
template <typename T>
bool BSTree<T>::contains(const std::string& key) const
{
	return (contains(key, root));
}

/**
 * @brief Clear all elements from the binary search tree
 * 
 * Deletes all nodes in the tree and resets the root to null and count to zero.
 * 
 * @tparam T The data type stored in the tree
 */
template <typename T>
void BSTree<T>::clear()
{
	clear(root);
	root = nullptr;
	count = 0;
}

/**
 * @brief Find a node with the specified key and return its data
 * 
 * Searches the tree for a node with the given key and returns a pointer to its data.
 * 
 * @tparam T The data type stored in the tree
 * @param key The key to search for in the tree
 * @return T* A pointer to the data of the found node, or nullptr if not found
 */
template <typename T>
T* BSTree<T>::find(const std::string& key) const
{
	BTNode<T>* node;
	node = find(key, root);
	if(node)
		return (&node->get_data());
	else
		return (nullptr);
}

/**
 * @brief Find and return the minimum value in the tree
 * 
 * Finds the node with the smallest key in the tree and returns its data.
 * 
 * @tparam T The data type stored in the tree
 * @return T& The data of the node with the minimum key
 * @throws empty_collection_exception if the tree is empty
 */
template <typename T>
T& BSTree<T>::find_min() const
{
	if(empty())
		throw empty_collection_exception();
	return (find_min(root)->get_data());
}

/**
 * @brief Find and return the maximum value in the tree
 * 
 * Finds the node with the largest key in the tree and returns its data.
 * 
 * @tparam T The data type stored in the tree
 * @return T& The data of the node with the maximum key
 * @throws empty_collection_exception if the tree is empty
 */
template <typename T>
T& BSTree<T>::find_max() const
{
	if(empty())
		throw empty_collection_exception();
	return (find_max(root)->get_data());
}

/**
 * @brief Check if the binary search tree is empty
 * 
 * Determines if the tree contains any nodes.
 * 
 * @tparam T The data type stored in the tree
 * @return true if the tree is empty, false otherwise
 */
template <typename T>
bool BSTree<T>::empty() const
{
	return (count == 0);
}

/**
 * @brief Get the number of elements in the binary search tree
 * 
 * Returns the number of nodes currently in the tree.
 * 
 * @tparam T The data type stored in the tree
 * @return int The number of elements in the tree
 */
template <typename T>
int BSTree<T>::size() const
{
	return (count);
}

/**
 * @brief Print the elements of the tree in inorder traversal
 * 
 * Outputs the elements of the tree to the supplied stream in sorted order.
 * 
 * @tparam T The data type stored in the tree
 * @param out The stream to which the elements will be printed
 */
template <typename T>
void BSTree<T>::print_inorder(std::ostream& out) const
{
	print_inorder(out, root);
}

/**
 * @brief Print the elements of the tree in preorder traversal
 * 
 * Outputs the elements of the tree to the supplied stream in preorder.
 * 
 * @tparam T The data type stored in the tree
 * @param out The stream to which the elements will be printed
 */
template <typename T>
void BSTree<T>::print_preorder(std::ostream& out) const
{
	print_preorder(out, root);
}

/**
 * @brief Print the elements of the tree in postorder traversal
 * 
 * Outputs the elements of the tree to the supplied stream in postorder.
 * 
 * @tparam T The data type stored in the tree
 * @param out The stream to which the elements will be printed
 */
template <typename T>
void BSTree<T>::print_postorder(std::ostream& out) const
{
	print_postorder(out, root);
}

#pragma endregion

#pragma region Functions Private

/**
 * @brief Clear all nodes in the subtree rooted at the given node
 * 
 * Recursively deletes all nodes in the subtree rooted at the specified node.
 * 
 * @tparam T The data type stored in the tree
 * @param root The root of the subtree to clear
 */
template <typename T>
void BSTree<T>::clear(BTNode<T>* root)
{
	if(root)
	{
		clear(root->get_left());
		clear(root->get_right());
		delete root;
		// root = nullptr; // i think this is not necessary
	}
}

/**
 * @brief Insert a new node into the subtree rooted at the given node
 * 
 * Recursively inserts a new node with the given data into the appropriate location in the subtree.
 * 
 * @tparam T The data type stored in the tree
 * @param data The data to insert
 * @param node The root of the subtree where the data should be inserted
 * @return BTNode<T>* The new root of the subtree after insertion
 */
template <typename T>
BTNode<T>* BSTree<T>::insert(const T& data, BTNode<T>* node)
{
	if(!node)
	{
		node = new BTNode<T>(data);
		count++;
	}
	else if(data < node->get_data())
		node->set_left(insert(data, node->get_left()));
	else if(data > node->get_data())
		node->set_right(insert(data, node->get_right()));
	return (node);
}

/**
 * @brief Remove a node with the specified key from the subtree
 * 
 * Recursively removes a node with the given key from the subtree rooted at the specified node.
 * 
 * @tparam T The data type stored in the tree
 * @param key The key of the node to remove
 * @param node The root of the subtree from which to remove the node
 * @return BTNode<T>* The new root of the subtree after removal
 */
template <typename T>
BTNode<T>* BSTree<T>::remove(const std::string& key, BTNode<T>* node)
{
	if(!node)
		return (nullptr);

	if(key < node->get_data().get_key())
		node->set_left(remove(key, node->get_left()));
	else if(key > node->get_data().get_key())
		node->set_right(remove(key, node->get_right()));
	else
	{
		if(!node->get_left())
		{
			BTNode<T>* right_child = node->get_right();
			delete node;
			--count;
			return (right_child);
		}
		else if(!node->get_right())
		{
			BTNode<T>* left_child = node->get_left();
			delete node;
			--count;
			return (left_child);
		}
		else
		{
			BTNode<T>* successor = find_min(node->get_right());
			node->set_data(successor->get_data());
			node->set_right(remove(successor->get_data().get_key(), node->get_right()));
		}
	}
	return (node);
}

/**
 * @brief Check if a node with the specified key exists in the subtree
 * 
 * Recursively checks if a node with the given key is present in the subtree rooted at the specified node.
 * 
 * @tparam T The data type stored in the tree
 * @param key The key to search for
 * @param node The root of the subtree to search in
 * @return true if the key is found, false otherwise
 */
template <typename T>
bool BSTree<T>::contains(const std::string& key, BTNode<T>* node) const
{
	if(!node)
		return (false);
	if(key < node->get_data().get_key())
		return (contains(key, node->get_left()));
	if(key > node->get_data().get_key())
		return (contains(key, node->get_right()));
	return (true);
}

/**
 * @brief Find a node with the specified key in the subtree
 * 
 * Recursively searches for a node with the given key in the subtree rooted at the specified node.
 * 
 * @tparam T The data type stored in the tree
 * @param key The key to search for
 * @param node The root of the subtree to search in
 * @return BTNode<T>* A pointer to the found node, or nullptr if not found
 */
template <typename T>
BTNode<T>* BSTree<T>::find(const std::string& key, BTNode<T>* node) const
{
	if(!node)
		return (nullptr);
	if(key < node->get_data().get_key())
		return (find(key, node->get_left()));
	if(key > node->get_data().get_key())
		return (find(key, node->get_right()));
	return (node);
}

/**
 * @brief Find the minimum node in the subtree
 * 
 * Traverses the subtree rooted at the given node to find the node with the smallest key.
 * 
 * @tparam T The data type stored in the tree
 * @param node The root of the subtree to search in
 * @return BTNode<T>* A pointer to the node with the minimum key
 */
template <typename T>
BTNode<T>* BSTree<T>::find_min(BTNode<T>* node) const
{
	while(node->get_left() != nullptr)
		node = node->get_left();
	return (node);
}

/**
 * @brief Find the maximum node in the subtree
 * 
 * Traverses the subtree rooted at the given node to find the node with the largest key.
 * 
 * @tparam T The data type stored in the tree
 * @param node The root of the subtree to search in
 * @return BTNode<T>* A pointer to the node with the maximum key
 */
template <typename T>
BTNode<T>* BSTree<T>::find_max(BTNode<T>* node) const
{
	while(node->get_right() != nullptr)
		node = node->get_right();
	return (node);
}

/**
 * @brief Print the elements of the subtree in inorder traversal
 * 
 * Recursively prints the elements of the subtree rooted at the given node in inorder traversal to the supplied stream.
 * 
 * @tparam T The data type stored in the tree
 * @param out The stream to which the elements will be printed
 * @param node The root of the subtree to print
 */
template <typename T>
void BSTree<T>::print_inorder(std::ostream& out, BTNode<T>* node) const
{
	if(node != nullptr)
	{
		print_inorder(out, node->get_left());
		out << node->get_data() << " ";
		print_inorder(out, node->get_right());
	}
}

/**
 * @brief Print the elements of the subtree in preorder traversal
 * 
 * Recursively prints the elements of the subtree rooted at the given node in preorder traversal to the supplied stream.
 * 
 * @tparam T The data type stored in the tree
 * @param out The stream to which the elements will be printed
 * @param node The root of the subtree to print
 */
template <typename T>
void BSTree<T>::print_preorder(std::ostream& out, BTNode<T>* node) const
{
	if(node != nullptr)
	{
		out << node->get_data() << " ";
		print_preorder(out, node->get_left());
		print_preorder(out, node->get_right());
	}
}

/**
 * @brief Print the elements of the subtree in postorder traversal
 * 
 * Recursively prints the elements of the subtree rooted at the given node in postorder traversal to the supplied stream.
 * 
 * @tparam T The data type stored in the tree
 * @param out The stream to which the elements will be printed
 * @param node The root of the subtree to print
 */
template <typename T>
void BSTree<T>::print_postorder(std::ostream& out, BTNode<T>* node) const
{
	if(node != nullptr)
	{
		print_postorder(out, node->get_left());
		print_postorder(out, node->get_right());
		out << node->data << " ";
	}
}

#pragma endregion

#pragma region Operator Overloading

/**
 * @brief Append the value of each node in the sub-tree rooted at the supplied node, to the supplied stream. 
 * By default, the tree should be printed according to an inorder traversal.
 * 
 * @tparam T The data type stored in the tree
 * @param out The stream to which the elements will be appended
 * @param tree The binary search tree to print
 * @return std::ostream& The stream with appended tree elements
 */
template <typename T>
std::ostream& operator<<(std::ostream& out, const BSTree<T>& tree)
{
	tree.print_inorder(out);
	return (out);
}

#pragma endregion
#endif // BS_TREE_H