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
		while (!fin.eof())
		{
			getline(fin, text, ' ');
			stringstream  nextLine(text);
			string word = "";
			while (getline(nextLine, word, '\n')) {	
				if (!part2.containsKey(word[0]))
				{
					BinaryTree<string> tree;
					tree.add(word);
					part2.put(word[0],tree);
				}
				else
				{
					part2.get(word[0]).add(word);
				}
				
			}
		}
		cout << part2 << endl;
		fin.close();
	}
	else
	{
		cout << "Error opening file" << endl;
	}

	string m;
	cout << "Input Letter: " << endl;
	cin >> m;
	cout << part2.get(m[0]) << endl;
	return 0;
}