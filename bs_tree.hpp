#include "bs_tree.h"

template <typename T>
BSTree<T>::BSTree()
{
    root = nullptr;
    count = 0;
}

template <typename T>
BSTree<T>::~BSTree()
{
    clear();
}

template <typename T>
void BSTree<T>::insert(const T &data)
{
    // TODO: Implement this function
}

template <typename T>
void BSTree<T>::remove(const std::string &key)
{
    // TODO: Implement this function
}

template <typename T>
bool BSTree<T>::contains(const std::string &key) const
{
    // TODO: Implement this function
}

template <typename T>
void BSTree<T>::clear()
{
    // TODO: Implement this function
}

template <typename T>
T *BSTree<T>::find(const std::string &key) const
{
    // TODO: Implement this function
}

template <typename T>
T &BSTree<T>::find_min() const
{
    // TODO: Implement this function
}

template <typename T>
T &BSTree<T>::find_max() const
{
    // TODO: Implement this function
}

template <typename T>
bool BSTree<T>::empty() const { return count == 0; }

template <typename T>
int BSTree<T>::size() const { return count; }

template <typename T>
void BSTree<T>::print_inorder(std::ostream &out) const
{
    // TODO: Implement this function
}

template <typename T>
void BSTree<T>::print_preorder(std::ostream &out) const
{
    // TODO: Implement this function
}

template <typename T>
void BSTree<T>::print_postorder(std::ostream &out) const
{
    // TODO: Implement this function
}

///////////////////////////// Private Functions ////////////////////////////////

template <typename T>
void BSTree<T>::clear(BTNode<T> *root)
{
    // TODO: Implement this function
}

template <typename T>
BTNode<T> *BSTree<T>::insert(const T &data, BTNode<T> *node)
{
    // TODO: Implement this function
}

template <typename T>
BTNode<T> *BSTree<T>::remove(const std::string &key, BTNode<T> *node)
{
    // TODO: Implement this function
}

template <typename T>
bool BSTree<T>::contains(const std::string &key, BTNode<T> *node) const
{
    // TODO: Implement this function
}

template <typename T>
BTNode<T> *BSTree<T>::find(const std::string &key, BTNode<T> *node) const
{
    // TODO: Implement this function
}

template <typename T>
BTNode<T> *BSTree<T>::find_min(BTNode<T> *node) const
{
    // TODO: Implement this function
}

template <typename T>
BTNode<T> *BSTree<T>::find_max(BTNode<T> *node) const
{
    // TODO: Implement this function
}

template <typename T>
void BSTree<T>::print_inorder(std::ostream &out, BTNode<T> *node) const
{
    // TODO: Implement this function
}

template <typename T>
void BSTree<T>::print_preorder(std::ostream &out, BTNode<T> *node) const
{
    // TODO: Implement this function
}

template <typename T>
void BSTree<T>::print_postorder(std::ostream &out, BTNode<T> *node) const
{
    // TODO: Implement this function
}

///////////////////////////// Helper Functions ////////////////////////////////

template <typename T>
std::ostream &operator<<(std::ostream &out, const BSTree<T> &tree)
{
    // TODO: Implement this function
}