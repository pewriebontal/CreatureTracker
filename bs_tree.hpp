#include "bs_tree.h"

#pragma region Constructor

template <typename T>
BSTree<T>::BSTree()
{
	root = nullptr;
	count = 0;
}

template <typename T>
BSTree<T>::~BSTree()
{
	// clear alr set root to nullptr
	// so so..
	clear(root);
}

#pragma endregion

#pragma region Functions Public

template <typename T>
void BSTree<T>::insert(const T& data)
{
	root = insert(data, root);
}

template <typename T>
void BSTree<T>::remove(const std::string& key)
{
	root = remove(key, root);
}

template <typename T>
bool BSTree<T>::contains(const std::string& key) const
{
	return (contains(key, root));
}

template <typename T>
void BSTree<T>::clear()
{
	clear(root);
	root = nullptr;
	count = 0;
}

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

template <typename T>
T& BSTree<T>::find_min() const
{
	if(empty())
		throw empty_collection_exception();
	return (find_min(root)->get_data());
}

template <typename T>
T& BSTree<T>::find_max() const
{
	if(empty())
		throw empty_collection_exception();
	return (find_max(root)->get_data());
}

template <typename T>
bool BSTree<T>::empty() const
{
	return (count == 0);
}

template <typename T>
int BSTree<T>::size() const
{
	return (count);
}

template <typename T>
void BSTree<T>::print_inorder(std::ostream& out) const
{
	print_inorder(out, root);
}

template <typename T>
void BSTree<T>::print_preorder(std::ostream& out) const
{
	print_preorder(out, root);
}

template <typename T>
void BSTree<T>::print_postorder(std::ostream& out) const
{
	print_postorder(out, root);
}

#pragma endregion

#pragma region Functions Private

template <typename T>
void BSTree<T>::clear(BTNode<T>* root)
{
	if(root)
	{
		clear(root->get_left());
		clear(root->get_right());
		delete root;
	}
}

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

template <typename T>
BTNode<T>* BSTree<T>::find_min(BTNode<T>* node) const
{
	while(node->get_left() != nullptr)
		node = node->get_left();
	return (node);
}

template <typename T>
BTNode<T>* BSTree<T>::find_max(BTNode<T>* node) const
{
	while(node->get_right() != nullptr)
		node = node->get_right();
	return (node);
}

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

template <typename T>
void BSTree<T>::print_postorder(std::ostream& out, BTNode<T>* node) const
{
	if(node != nullptr)
	{
		print_postorder(out, node->get_left);
		print_postorder(out, node->get_right);
		out << node->data << " ";
	}
}

#pragma endregion

#pragma region Operator Overloading

template <typename T>
std::ostream& operator<<(std::ostream& out, const BSTree<T>& tree)
{
	tree.print_inorder(out);
	return (out);
}

#pragma endregion