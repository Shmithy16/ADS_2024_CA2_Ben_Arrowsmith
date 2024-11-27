#pragma once
#include <iostream>
#include <fstream>
#include "BinaryTree.h"
#include "BSTNode.h"
#include "TreeMapNode.h"
#include "TreeMap.h"
#include <string>

using namespace std;

int main() {

	TreeMap<string, int> test;
	test.put("a", 1);
	test.put("a", 2);
	test.put("b", 3);

	test.removeKey("a");

	TreeMap<char, string> part2;

	ifstream fin("Part2Text.txt");
	if (fin)
	{
		string text;
		while (!fin.eof())
		{
			getline(fin, text);
			cout << text << endl;
			//part2.put(text[0], text);
			cout << text[0] << endl;;
		}
		fin.close();
	}
	else
	{
		cout << "Error opening file" << endl;
	}

	
	return 0;
}