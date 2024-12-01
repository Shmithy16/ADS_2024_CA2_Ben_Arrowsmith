#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "BinaryTree.h"
#include "BSTNode.h"
#include "TreeMap.h"
#include <string>


using namespace std;

struct pokemon
{
	string name,type;
	int gen, dex;
	bool evolves;
	pokemon(string name,string type,int gen, int dex, bool evolves)
	{
		this->dex = dex;
		this->type = type;
		this->gen = gen;
		this->evolves = evolves;
		this->name = name;
	}

	bool operator<(pokemon& other)
	{
		return this->name < other.name;
	}

	bool operator>(pokemon& other)
	{
		return this->name > other.name;
	}

	bool operator==(pokemon& other)
	{
		return this->name == other.name;
	}

	friend std::ostream& operator<<(std::ostream& out, pokemon& other)
	{
		return out << other.name << " " << other.type << " " << other.gen << " " << other.evolves << " " << other.dex;
	}

	pokemon()
	{}

};

int main() {

	TreeMap<string, int> test;
	test.put("a", 1);
	test.put("a", 2);
	test.put("b", 3);

	test.removeKey("a");

	TreeMap<char, BinaryTree<string>> tMap;

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
				if (!tMap.containsKey(word[0]))
				{
					BinaryTree<string> tree;
					tree.add(word);
					tMap.put(word[0],tree);
				}
				else
				{
					tMap.get(word[0]).add(word);
				}
				
			}
		}
		std::cout << tMap << endl;
		fin.close();
	}
	else
	{
		std::cout << "Error opening file" << endl;
	}
	TreeMap<string, pokemon> tMap2;
	ifstream xl("ADSDataPage.csv");
	string bad = "";
	getline(xl, bad, '\n');
	if (xl)
	{
		string name,type,gen,evolve,dex = "";

		while (!xl.eof())
		{

			while (getline(xl, name, ',')) //https://stackoverflow.com/questions/16446665/c-read-from-csv-file
			{
				std::cout << "Name: " << name << " ";
				getline(xl, type, ',');
				std::cout << "Type: " << type << " ";
				getline(xl, gen, ',');
				int genI = stoi(gen);
				std::cout << "Gen: " << genI << " ";
				getline(xl, evolve, ',');
				std::cout << "Evolves: " << evolve << " ";
				getline(xl, dex);
				int dexI = stoi(dex);
				std::cout << "Dex: " << dexI << endl;
				pokemon lilGuy(name, type, genI, dexI,evolve == "TRUE");
				tMap2.put(name, lilGuy);
			}
		}

		
		string in;
		std::cout << "Input Name: " << endl;
		std::cin >> in;
		xl.close();
		cout << tMap2.get(in) << endl;;


	}
	else
	{
		std::cout << "Error opening file" << endl;
	}

	string m;
	std::cout << "Input Letter: " << endl;
	std::cin >> m;
	while (!tMap.containsKey(m[0])) 
	{
		std::cout << "Not valid letter" << endl;
		std::cout << "Input Letter: " << endl;
		std::cin >> m;
	}
	std::cout << tMap.get(m[0]) << endl;
	return 0;
}