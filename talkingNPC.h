#pragma once
#include "character.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void chat();

class dialogueNode {
public:
	string npcDialogue;
	string playerChoice;
	vector<int> nextDialogue;
	dialogueNode();
	dialogueNode(string npcLines, string playerOptions, vector<int> nextList);
};

class talkingNPC :public character
{
protected:
	vector<dialogueNode> dialogueTree;
public:
	talkingNPC(int size, string name);
	void printLines(int currentLine);

};

class ShopKeeper : public talkingNPC {
public:
	ShopKeeper();
};

class Banker : public talkingNPC {
public:
	Banker();
};

class Blacksmith : public talkingNPC {
public:
	Blacksmith();
};

class Beggar : public talkingNPC {
public:
	Beggar();
};

class Townsfolk : public talkingNPC {
public:
	Townsfolk();
};

class Knight : public talkingNPC {
public:
	Knight();
};

class Farmer : public talkingNPC {
public:
	Farmer();
};

