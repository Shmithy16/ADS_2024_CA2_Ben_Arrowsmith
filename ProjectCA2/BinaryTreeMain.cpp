#pragma once
#include <iostream>
#include "BinaryTree.h"
#include "BSTNode.h"
#include "TreeMapNode.h"
#include "TreeMap.h"

using namespace std;

int main() {

	TreeMap<string, int> test;
	test.put("a", 1);
	test.put("a", 2);
	test.put("b", 3);

	cout << test["b"] << endl;

	return 0;
}