#pragma once
#include "Setup.h"
#include "character.h" 
#include "enemy.h"
#include <vector>
#include <string>
using namespace std;

class Setup;

int chat(Setup& setup);

enum NodeType {
	NORMAL,
	START_BATTLE,
	OPEN_SHOP,
	BEGGAR_DROP
};

class dialogueNode {
public:
	string npcDialogue;
	string playerChoice;
	vector<int> nextDialogue;
	NodeType type;
	dialogueNode();
	dialogueNode(string npcLines, string playerOptions, vector<int> nextList, NodeType nType);
};

class talkingNPC : public character {
protected:
	vector<dialogueNode> dialogueTree;
public:
	talkingNPC(int size, string name);
	void printLines(int currentLine, Setup& setup);

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

class Farmer : public talkingNPC {
public:
	Farmer();
};

class Knight : public talkingNPC {
public:
	Knight();
};

class KnightEnemy : public enemy {
public:
	KnightEnemy();
};

void refreshNPC();