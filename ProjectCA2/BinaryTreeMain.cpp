#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
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

	TreeMap<char, BinaryTree<string>> part2;

	ifstream fin("Part2Text.txt");
	if (fin)
	{
		string text = "";
		BinaryTree<string> tree;
		while (!fin.eof())
		{
			getline(fin, text, ' ');
			stringstream  nextLine(text);
			string word = "";
			while (getline(nextLine, word, '\n')) {
				tree.add(word);
				if (part2.containsKey(word[0]))
				{
					part2.get(word[0]).add(word);
				}
				else
				{
					part2.put(word[0], tree);
				}
				
			}
		}
		part2.display();
		part2.get('a');
		fin.close();
	}
	else
	{
		cout << "Error opening file" << endl;
	}
	return 0;
}