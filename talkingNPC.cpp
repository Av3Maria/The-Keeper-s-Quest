#include "Setup.h"
#include "talkingNPC.h"
#include "character.h"
#include "enemy.h" 
#include "BattleSequence.h"
#include "Shop.h"
#include "Inventory.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int chat(Setup& setup) {

	ShopKeeper ShopKeepernpc;
	Blacksmith Blacksmithnpc;
	Banker Bankernpc;
	Beggar Beggarnpc;
	Townsfolk Townsfolknpc;
	Farmer Farmernpc;
	Knight Knightnpc;
	

	vector < talkingNPC*> NPCs = {
		&ShopKeepernpc, &Blacksmithnpc, &Bankernpc ,&Beggarnpc ,&Townsfolknpc ,&Farmernpc ,&Knightnpc
	};

	int index = randomNum(0, NPCs.size() - 1);
	cout << "As you are walking you run into " << NPCs[index]->getName() << "." << endl;
	NPCs[index]->printLines(0, setup);
	return 0;
}

talkingNPC::talkingNPC(int size, string name)
	: character(name), dialogueTree(size) {
	dialogueTree.resize(size);
}
void talkingNPC::printLines(int currentLine, Setup& setup) {
	dialogueNode& node = dialogueTree[currentLine];
	cout << endl;
	cout << getName() << ": " << node.npcDialogue << endl;

	if (node.type == START_BATTLE) {
		enterBattle(setup, new KnightEnemy());
		return;
	}
	if (node.type == OPEN_SHOP) {
		int nextNode = displayShopMenu(setup);

		if (nextNode != -1) {
			printLines(nextNode, setup);
		}
		return;
	}
	if (node.type == BEGGAR_DROP) {
		addToInventory(setup, 17);
		return;
	}

	if (node.playerChoice.empty()) {
		return;
	}
	cout << node.playerChoice << endl;
	int choice;
	cin >> choice;

	if (choice < 0 || choice >= node.nextDialogue.size()) {
		return;
	}
	int nextSpot = node.nextDialogue[choice];
	printLines(nextSpot, setup);
}

dialogueNode::dialogueNode() {
	npcDialogue = "";
	playerChoice = "";
	nextDialogue = {};
	type = NORMAL;
}

dialogueNode::dialogueNode(string npcLines, string playerOptions, vector<int> nextList, NodeType nType) {
	npcDialogue = npcLines;
	playerChoice = playerOptions;
	nextDialogue = nextList;
	type = nType;
}

ShopKeeper::ShopKeeper()
	: talkingNPC(6, "ShopKeeper")
{
	dialogueTree[0] = dialogueNode(
		"Welcome to my shop! Looking for something?\n",
		"0) Show me your wares\n1) Thanks but I'm good\n",
		{ 1,5 }, 
		NORMAL
	);

	dialogueTree[1] = dialogueNode(
		"Here's what I have for sale!\n",
		"",
		{}, 
		OPEN_SHOP
	);

	dialogueTree[2] = dialogueNode(
		"Take your time looking around.\n",
		"",
		{ 3 },
		NORMAL
	);

	dialogueTree[3] = dialogueNode(
		"Have you decided yet?\n",
		"0) Show me your wares\n2) Thanks but I'm good",
		{ 1, 2, 5},
		NORMAL
	);

	dialogueTree[4] = dialogueNode(
		"Pleasure doing business with you! Feel free to keep looking!\n",
		"",
		{},
		NORMAL
	);

	dialogueTree[5] = dialogueNode(
		"Come back anytime!\n",
		"",
		{},
		NORMAL
	);
}

Banker::Banker()
	: talkingNPC(5, "Banker")
{
	dialogueTree[0] = dialogueNode(
		"Hello traveler!! How are you doing on this fine day, any questions?\n",
		"0) I'm great, any advice for me?\n1) Just going for a walk, how are you?\n2) Sorry Im busy, goodbye!\n",
		{ 1,2,4 },
		NORMAL
	);

	dialogueTree[1] = dialogueNode(
		"Well, I would advise being wary of the other folk out there. I have seen quite odd individuals who seem like they'd steal a few coins off any they come across.\n",
		"0) Oh wow, what do these people look like?\n1) Yikes, I'll be sure to keep an eye out then. Thank you!\n",
		{ 3,4 },
		NORMAL
	);

	dialogueTree[2] = dialogueNode(
		"Oh I am quite alright, bank hasn't been to busy lately so I too am out for a stroll myself.\n",
		"Great day for it, have a nice day!\n",
		{ 4 },
		NORMAL
	);

	dialogueTree[3] = dialogueNode(
		"Well a little something like you actually! A bit worn down and unkempt. Although, they look like they would be able to fight.\n",
		"Oh...uh, I think I'll be going now\n",
		{ 4 },
		NORMAL
	);

	dialogueTree[4] = dialogueNode(
		"Alright then, I will be seeing you around.\n",
		"",
		{},
		NORMAL
	);
}

Blacksmith::Blacksmith()
	: talkingNPC(6, "Blacksmith")
{
	dialogueTree[0] = dialogueNode(
		"Do you need something?\n",
		"0) Wow, what a way to start a conversation.\n1) Yeah I wanted to ask about your opinion on some armor.\n2) No sorry.\n",
		{ 1,2,4 },
		NORMAL
	);

	dialogueTree[1] = dialogueNode(
		"Oh! Why didn't you start with that, what did you want to ask about? I have knowledge on many different types of armor and gear.\n",
		"0) What is the best type of armor to use?\n1) Well I always wanted to know what I should use for a weapon.\n2) Actually nevermind, I know a good amount on my own.\n",
		{ 2,3,4 },
		NORMAL
	);

	dialogueTree[2] = dialogueNode(
		"Well that depends. If you want something that is great for protection, metal armor is great, but it will slow you down. If you are a runner, you'll want to go for something more lightweight like leahter.\n",
		"0) Oh that makes sense. Thank you!\n1) Well I could have told you that.\n",
		{ 4,5 },
		NORMAL
	);

	dialogueTree[3] = dialogueNode(
		"My favorite type of weapon is a nice sharp blade. Swords are the most effective weapon you can have here, and a good one will keep you out of trouble if used correctly.\n",
		"0) I do like my sword, thanks.\n1) Oh, well I think I'll stick with my bow.\n",
		{ 4,5 },
		NORMAL
	);

	dialogueTree[4] = dialogueNode(
		"Alright then, need help with anything else just come ask.\n",
		"",
		{},
		NORMAL
	);

	dialogueTree[5] = dialogueNode(
		"Well suit yourself, I'll be one my way.\n",
		"",
		{},
		NORMAL
	);
}

Beggar::Beggar()
	: talkingNPC(8, "Beggar")
{
	dialogueTree[0] = dialogueNode(
		"Hey..Any chance you have money to spare?\n",
		"0) Oh uh no I don't sorry\n1) I might, I can look for you\n2) Yeah but I don't want to give it to you\n3) No sorry, goodbye.\n",
		{ 1,2,4,4 },
		NORMAL
	);

	dialogueTree[1] = dialogueNode(
		"Please I need it! I have no money left...\n",
		"0) Mind telling me why you have no money?\n1) I told you I don't have anything! Sorry but I am busy, goodbye.\n",
		{ 5,4 },
		NORMAL
	);

	dialogueTree[2] = dialogueNode(
		"Oh thank you so much...I just need one coin\n",
		"0) Here, I will give you one.\n1) Sorry to tell you this, but I don't actually have anything for you...\n",
		{ 3,1 },
		NORMAL
	);

	dialogueTree[3] = dialogueNode(
		"Oh thank you kind soul! You were so nice to me...here take this thing I found...\n",
		"0) Oh, thank you!\n1) Where did you get that? No thanks\n",
		{ 7, 4 }, 
		NORMAL
	);

	dialogueTree[4] = dialogueNode(
		"Oh...\n",
		"",
		{}, 
		NORMAL
	);

	dialogueTree[5] = dialogueNode(
		"Oh...uh. Well you see...I had a lot of money before, but I had spent it on some games. I almost won too!! I just need a little more and I am sure I'll get it all back.\n",
		"0) Wow no I am not giving you anything.\n1) Oh um ok, here is a coin.\n",
		{ 4,6 },
		NORMAL 
	);

	dialogueTree[6] = dialogueNode(
		"Thank you so much kind soul! This is going to good use, trust me.\n",
		"",
		{}, 
		NORMAL 
	);

	dialogueTree[7] = dialogueNode(
		"Hope it helps...\n",
		"",
		{},
		BEGGAR_DROP
	);
}

Townsfolk::Townsfolk()
	: talkingNPC(6, "Townsfolk")
{
	dialogueTree[0] = dialogueNode(
		"Hello! Staying safe out there?\n",
		"0) Yeah, I'm trying my best. \n1) What do you mean?\n2) Sorry I don't have time to talk\n",
		{ 1,2,4 },
		NORMAL 
	);

	dialogueTree[1] = dialogueNode(
		"That is all you can do sometimes, with the amount of monsters out there I'm surprised people like you are brave enough to travel through the woods alone.\n",
		"0) At first it was difficult, but I am getting the hang of it now\n1) Oh I know. Sometimes I don't even want to go out there.\n2)Haha...yeah. Speaking of the woods, I have to go. See ya!\n",
		{ 3,5,4 },
		NORMAL 
	);

	dialogueTree[2] = dialogueNode(
		"Well with all the monsters around I worry for those like you who seem to follow the danger. I was just wondering if you are doing alright out there!\n",
		"0) Oh, sorry. Yeah I am doing alright, thank you for asking!\n 1) If I am being honest, these enemies are horrible!\n",
		{ 4,3 },
		NORMAL 
	);

	dialogueTree[3] = dialogueNode(
		"That's great! Could never be me, I hate monsters...Anyway I wish you good luck on your travels!!\n",
		"",
		{},
		NORMAL 
	);

	dialogueTree[4] = dialogueNode(
		"That's ok!! Good luck out there.\n",
		"",
		{},
		NORMAL 
	);

	dialogueTree[5] = dialogueNode(
		"Haha yeah Good luck out there!\n",
		"",
		{},
		NORMAL 
	);
}

Farmer::Farmer()
	: talkingNPC(6, "Farmer")
{
	dialogueTree[0] = dialogueNode(
		"The crops around here haven't been doing well lately..\n",
		"0) Oh no, what's wrong?\n1) Anything I can help with?\n2) Yikes, that's gotte be rough. Good luck with that!\n",
		{ 1,2,4 },
		NORMAL 
	);

	dialogueTree[1] = dialogueNode(
		"Well it looks like some creature is coming in and eating off the produce. I have found slimy trails all around, and it is killing my plants!.\n",
		"0) Sounds like you have got a bug infestation.\n1) That is horrible! I'm sorry about that.\n",
		{ 3,4 },
		NORMAL 
	);

	dialogueTree[2] = dialogueNode(
		"Well...What do you think this creature like? I can't figure out what it is...\n",
		"0) Well It seems like a type of bug that is going through your crops.\n1)Uhhh I have no clue, maybe a bird??\n",
		{ 3,5 },
		NORMAL 
	);

	dialogueTree[3] = dialogueNode(
		"I haven't thought about that...I'll look into some repellent, thank you traveler.\n",
		"",
		{}, 
		NORMAL 
	);

	dialogueTree[4] = dialogueNode(
		"Yeah...I'll see you around\n",
		"",
		{},
		NORMAL
	);

	dialogueTree[5] = dialogueNode(
		"A bird? We don't have many of those around here. Even then, that makes no sense...but I'll look into it I guess. Thanks.\n",
		"",
		{},
		NORMAL
	);
}

Knight::Knight()
	: talkingNPC(6, "Knight")
{
	dialogueTree[0] = dialogueNode(
		"Hello traveler, can I help you? I am busy at the moment.\n",
		"0) Are you? There are so many monsters around I couldn't tell.\n1) Just walking around, see anything interesting lately?\n2) No, sorry to bother.\n",
		{ 1,2,4 },
		NORMAL 
	);

	dialogueTree[1] = dialogueNode(
		"I'll have you know I am one of the BEST knights we have around here. There would be a lot more without me, so you should be thankng me. You seem like one who would not be able to survive the things I have fought.\n",
		"0) Oh yeah? With the look you've got going now it seems like you would run away at the sight of a butterfly.\n1) No need to get defensive, I was just making a joke\n2) I am not dealing with this, I hope you have the day you deserve.\n",
		{ 3,3,4 },
		NORMAL
	);

	dialogueTree[2] = dialogueNode(
		"Nothing that scares me. All the enemies around here are weak, I wonder if there is anything that could be a challenge for me.\n",
		"0) Oh uh.. right. Makes sense that this is your job then.\n1) Someone's full of themself huh? If they are so easy why aren't you doing your job then?\n",
		{ 4,3 }, 
		NORMAL
	);

	dialogueTree[3] = dialogueNode(
		"How rude. Leave this instance, I do not have time to deal with someone like you.\n",
		"0) I'll make you regret speaking to me like that. (fight the knight)\n1) Fine...\n",
		{ 5, 4 },
		NORMAL 
	);

	dialogueTree[4] = dialogueNode(
		"Alright then.\n",
		"",
		{},
		NORMAL 
	);

	dialogueTree[5] = dialogueNode(
		"You will never beat me!\n", 
		"",
		{},
		START_BATTLE
	);
}

KnightEnemy::KnightEnemy() 
	: enemy(50, 30, 30) {

	name = "Knight";

	attacks = {
		{ "Sword Slash", 12, { "The knight lands a hit on you with his sword. 'Aha! You clearly need more practice with a sword!'" } },
		{ "Shield Bash", 10, { "The knight catches you off guard and smashes you to the ground with his shield. 'You are the slowest person I have ever fought!'" } },
		{ "Piercing Lance", 8, { "You back away but the knight throws his lance and it hits you in the leg." } },
		{ "Mailed Fist Punch", 6, { "Took a few bruises there!" } }
	};

	runLines = {
		"'Perhaps...you are not as weak as you first seemed. I yield.'",
		"'The sun is in my eyes! This is not a fair fight.'",
		"The knight, overwhelmed by your strength, mounts his horse and flees.",
		"The knight runs away, crying, 'You were right, I do run away from butterflies.'"
	};

	healLines = {
		"The knight backs off and quickly downs a healing potion.",
		"While you are down from his last attack, the knight heals himself",
		"'Ha ha ha! You are just as weak as I thought!' The knight drinks a potion to heal his wounds",
		"'My armor is too strong for you to do much damage!' The knight heals the few cuts you gave him."
	};

	dieLines = {
		"'You have fought honorably...' You have won this battle, Player.",
		"'You are cruel and a murderer...I hope a wizard curses you...' The knight collapses at your feet, vanquished, but at what cost...",
		"The knight yields to you, saying, 'That was an good fight, I could learn a lot from you!'",
		"'I suppose I'll overlook the rude comments from earlier...' Defeated the knight mounts his horse and finds a safer place to fight his enemies in peace."
	};
}
