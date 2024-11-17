#pragma once
#include <iostream>

template <class K, class V>
struct TreeMapNode {
	K key;
	V value;

	TreeMapNode( K key, V value)
	{
		this->key = key;
		this->value = value;
	}
	TreeMapNode(K key)
	{
		this->key = key;
	}
	TreeMapNode()
	{
	}

	bool operator<(TreeMapNode& other)
	{
		return this->key < other.key;
	}

	bool operator>(TreeMapNode& other)
	{
		return this->key > other.key;
	}

	bool operator==(TreeMapNode& other)
	{
		return this->key == other.key;
	}

};
