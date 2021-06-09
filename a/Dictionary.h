#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//https://www.geeksforgeeks.org/trie-insert-and-search/ 
struct Node {
	struct Node *letters[26] = {}; //later, characters are being stored in this, which probably does not work
	bool isWord;
};

class Dictionary
{
public:
	Dictionary();
	Dictionary(string file);
	void addWord(string word);
	bool isPrefix(string word);
	bool isWord(string word);
	int wordCount(); // this is not used

private:
	Node* root;
	int numWords; //this is also not used
	// Any private methods you need/want
};

//establishes an empty node
Dictionary::Dictionary()
{
	Node* tmp = root;
	//this for loop maaaay be unnecessary, but, it ensures that root's pointers are null
	for (int i = 0; i < 25; i++)
	{
		root->letters[i] = nullptr;
	}

	isWord = false;
}

//takes  in a string file and reads line by line, using addWord to add words to dictionary
Dictionary::Dictionary(string file)
{
	ifstream inFile;
	string word;

	inFile.open(file);


	//http://www.cplusplus.com/forum/lounge/52458/
	if (inFile.is_open())
	{
		while (inFile.good())
		{
			getline(inFile, word);
			addWord(word);
		}
		myfile.close();
	}

	else cout << "Unable to open file";	
}

//adds an inputted word to the dictionary
//currently is only the given psuedocode
void addWord(string word)
{
	Node* currNode = root;


	for (char const &c: word) //for (each character c of the word) https://www.techiedelight.com/iterate-over-characters-string-cpp/
	{
		cInt = (int)c - (int)'a'; //this is needed for accessing character specific indexes
		if (currNode->letters[cInt] == nullptr) //if  (the branch for character c is NULL)  
		{
			currNode->letters[cInt] = c; //set the branch of character c = new Node
			currNode->isWord = false; //set flag of this new Node to false 
		}
		currNode = currNode->letters[cInt]; //currNode = the pointer index of character c 
	}
	currNode->isWord = true; // Set the flag at the currNode to true 
}

//returns true if a word exists within the dictionary
//very similiar to addWord, minus the adding bit
//returns false if it runs into a null, if gets through whole loop with no null, returns true
bool isPrefix(string word)
{
	Node* currNode = root;

	for (char const &c : word) 
	{
		cInt = (int)c - (int)'a';
		if (currNode->letters[cInt] == nullptr)
		{
			return false;
		}
		currNode = currNode->letters[cInt];
	}
	return true;
}

//similiar to both of above functions, therefore requires both done first
//returns flag found at end of path
bool isWord(string word)
{
	Node* currNode = root;
	string tempWord = ""; //the purpose of this will become clear soon


	for (char const &c : word)
	{
		cInt = (int)c - (int)'a';
		tempWord += c;//this is needed for the if statement
		if (tempWord == word)
		{
			currNode = currNode->letters[cInt];
			return currNode->isWord;
		}
		currNode = currNode->letters[cInt];
	}
	return currNode->isWord;
}