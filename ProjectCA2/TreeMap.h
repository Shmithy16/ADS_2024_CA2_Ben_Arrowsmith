#pragma once
#include <iostream>
#include "BinaryTree.h"
#include "BSTNode.h"
#include "TreeMapNode.h"

template <class K, class V>
class TreeMap {
	void addKey(BSTNode<TreeMapNode<K, V>>* node, BinaryTree<K>& keys);

public:
	//TreeMap();  constructor
	BinaryTree<TreeMapNode<K, V>> tree;
	void clear();
	bool containsKey(K key);
	void put(K key, V value);
	int size();
	void display();
	V& get(K key);
	BinaryTree<K> keySet();
	bool removeKey(K key);
	V& operator[](K key);
	friend std::ostream& operator<<(std::ostream& out, TreeMap& other)
	{
		return out << other.tree;
	}
	



	//~TreeMap();

};

template<class K,class V>
void TreeMap<K, V>::display()
{
	tree.printInOrder();
}

template<class K, class V>
inline void TreeMap<K, V>::addKey(BSTNode<TreeMapNode<K, V>>* node, BinaryTree<K>& keys)
{
	/*if (left child)
	* run addKey(child)
	* add to tree
	* if(right child)
	* run addKey(child)
	*/

	if (node->getLeft() != nullptr)
		addKey(node->getLeft(), keys);
	keys.add(node->getItem().key);
	if (node->getRight() != nullptr)
		addKey(node->getRight(), keys);
}

template <class K, class V>
void TreeMap<K, V>::clear()
{
	tree.clear();
}

template <class K, class V>
bool TreeMap<K, V>::containsKey(K key)
{
	bool found = false;
	BSTNode<TreeMapNode<K, V>>* node = tree.root;
	while (!found)
	{
		if (node == nullptr)
			return false;
		else if (node->getItem().key == key)
		{
			return true;
		}
		else if (node->getItem().key > key)
			node = node->getLeft();
		else 
			node = node->getRight();
	}
}

template <class K, class V>
void TreeMap<K, V>::put(K key,V value)
{
	TreeMapNode<K,V> newItem(key,value);
	tree.add(newItem);
}

template <class K, class V>
int TreeMap<K, V>::size()
{
	return tree.count();
}

template<class K, class V>
inline V& TreeMap<K, V>::get(K key)
{
	TreeMapNode<K, V> itemGet(key);
	return tree.get(itemGet).value;
}

template<class K, class V>
inline BinaryTree<K> TreeMap<K, V>::keySet()
{
	BinaryTree<K> keys;

	addKey(tree.root, keys);

	return keys;
}



template<class K, class V>
inline bool TreeMap<K, V>::removeKey(K key)
{
	TreeMapNode<K, V> itemRemove(key);
	return tree.remove(itemRemove);
}

template<class K, class V>
inline V& TreeMap<K, V>::operator[](K key)
{
	return get(key);
}

//template <class K, class V>
//TreeMap<K, V>::TreeMap()
//{
//	tree();
//}
//
//template <class K, class V>
//TreeMap<K, V>::~TreeMap()
//{
//	delete tree();
//}
