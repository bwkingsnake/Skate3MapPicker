#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <random>
#include <Windows.h> 

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

#define log(x) std::cout << x << std::endl

const vector<string> logo = {

	   "  __  __               _____ _      _             ",
	   " |  \\/  |             |  __ (_)    | |            ",
	   " | \\  / | __ _ _ __   | |__) |  ___| | _____ _ __ ",
	   " | |\\/| |/ _` | '_ \\  |  ___/ |/ __| |/ / _ \\ '__|",
	   " | |  | | (_| | |_) | | |   | | (__|   <  __/ |   ",
	   " |_|  |_|\\__,_| .__/  |_|   |_|\\___|_|\\_\\___|_|   ",
	   "              | |                                 ",
	   "              |_|                                 "
};

const vector<string> oneUpMaps = {

	"Battle of Haystings",
	"Chan Center",
	"Library",
	"Observe This",
	"Park N Play",
	"Quarry Cacciatore",
	"Sanaitori",
	"To The Streets",
	"Tresoutta",
	"Spillage"
};

const vector<string> SpotMaps = { 

	"Magic Rails",
	"Memorial Drop",
	"Naval Assault",
	"Bricklynn Bank Sesh",
	"Givers Fest",
	"Carvatron",
	"The Ditch",
	"Raffatran",
	"Haystrings Battle",
	"Kube Bowl",
	"Streets of Marraffa",
	"Super Ultra Mega Park" 
};

vector<string> oneUpMapsStack = {};
vector<string> SpotMapsStack = {};
vector<string> oneUpAndSpotMapStack{};

//Random Number Function
int getRandomNumber(int x) {
	static std::random_device rd;
	static std::mt19937 gen(rd());

	std::uniform_int_distribution<> distrib(0, x);
	return distrib(gen);
}

//Pick Random SpotBattle Map
string pickRandomSpotMap() {
	
	int x = SpotMaps.size();
	int randomMapNum = getRandomNumber(x - 1);
	string randomMap = SpotMaps[randomMapNum];
	return randomMap;
}

//Pick Random 1up Map

string pickRandom1upMap() {
	int x = oneUpMaps.size();
	int randomMapNum = getRandomNumber(x - 1);
	string randomMap = oneUpMaps[randomMapNum];
	return randomMap;
}

void trueRandom(bool spotMapsEnabled, bool oneUpMapsEnabled, bool trueRandomEnabled) {
	while (true) {

		//Displays the settings at the top
		if (spotMapsEnabled == true) {
			SetConsoleTextAttribute(hConsole, 2);
			log("SpotMapsEnabled = (True)");
		}
		else {
			SetConsoleTextAttribute(hConsole, 4);
			log("SpotMapsEnabled = (False)");
		}

		if (oneUpMapsEnabled == true) {
			SetConsoleTextAttribute(hConsole, 2);
			log("OneUpMapsEnabled = (True)");
		}
		else {
			SetConsoleTextAttribute(hConsole, 4);
			log("OneUpMapsEnabled = (False)");
		}

		if (trueRandomEnabled == true) {
			SetConsoleTextAttribute(hConsole, 2);
			log("TrueRandomEnabled = (True)");
		}
		else {
			SetConsoleTextAttribute(hConsole, 4);
			log("TrueRandomEnabled = (False)");
		}

		SetConsoleTextAttribute(hConsole, 14);
		log("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");

		//Prints The Logo
		SetConsoleTextAttribute(hConsole, 9);
		for (size_t i = 0; i < logo.size(); ++i) {
			std::cout << logo[i] << std::endl;
		}
		SetConsoleTextAttribute(hConsole, 14);
		log("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		SetConsoleTextAttribute(hConsole, 2);
		if (trueRandomEnabled == true) {
			if (spotMapsEnabled == true && oneUpMapsEnabled == true) {
				int randNum = getRandomNumber(1);

				if (randNum == 0) {
					string spotBattleMap = pickRandomSpotMap();
					log("Spot Battle : " + spotBattleMap);
				}
				else {
					string oneUpMap = pickRandom1upMap();
					log("1-UP : " + oneUpMap);
				}
			}
			else if (spotMapsEnabled == true) {
				string spotBattleMap = pickRandomSpotMap();
				log("Spot Battle : " + spotBattleMap);
			}
			else {
				string oneUpMap = pickRandom1upMap();
				log("1-UP : " + oneUpMap);
			}
		}
		else { 
			if (spotMapsEnabled == true && oneUpMapsEnabled == true) {
				int randNum = getRandomNumber(1);
				if (randNum == 0) {
					string spotBattleMap = pickRandomSpotMap();
					for (int i = 0; i < SpotMapsStack.size(); ++i) {
						while (SpotMapsStack[i] == spotBattleMap) {
							spotBattleMap = pickRandomSpotMap();
							i = 0;
						}
						if (SpotMaps.size() == SpotMapsStack.size()) {
							SpotMapsStack.clear();
						}
					}
					SpotMapsStack.insert(SpotMapsStack.begin(), spotBattleMap);
					log("Spot Battle : " + spotBattleMap);
				}
				else {
					string oneUpMap = pickRandom1upMap();
					for (int i = 0; i < oneUpMapsStack.size(); ++i) {
						while (oneUpMapsStack[i] == oneUpMap) {
							oneUpMap = pickRandom1upMap();
							i = 0;
						}
						if (oneUpMaps.size() == oneUpMapsStack.size()) {
							oneUpMapsStack.clear();
						}
					}
					oneUpMapsStack.insert(oneUpMapsStack.begin(), oneUpMap);
					log("1-UP : " + oneUpMap);
				}
			}
			else if (spotMapsEnabled == true) {
				string spotBattleMap = pickRandomSpotMap();
				for (int i = 0; i < oneUpAndSpotMapStack.size(); ++i) {
					while (oneUpAndSpotMapStack[i] == spotBattleMap) {
						spotBattleMap = pickRandomSpotMap();
						i = 0;
					}
					if (SpotMaps.size() == oneUpAndSpotMapStack.size()) {
						oneUpAndSpotMapStack.clear();
					}
				}
				oneUpAndSpotMapStack.insert(oneUpAndSpotMapStack.begin(), spotBattleMap);
				log("Spot Battle : " + spotBattleMap);
			}
			else {
				string oneUpMap = pickRandom1upMap();
				for (int i = 0; i < oneUpAndSpotMapStack.size(); ++i) {
					while (oneUpAndSpotMapStack[i] == oneUpMap) {
						oneUpMap = pickRandom1upMap();
						i = 0;
					}
					if (oneUpMaps.size() == oneUpAndSpotMapStack.size()) {
						oneUpAndSpotMapStack.clear();
					}
				}
				oneUpAndSpotMapStack.insert(oneUpAndSpotMapStack.begin(), oneUpMap);
				log("1-UP : " + oneUpMap);
			}
		}
		SetConsoleTextAttribute(hConsole, 14);
		log("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		for (size_t i = 0; i < oneUpAndSpotMapStack.size(); ++i) {
			std::cout << oneUpAndSpotMapStack[i] << std::endl;
		}
		cin.get();
		system("cls");
	}
}

bool getSpotMapsSetting() {
	SetConsoleTextAttribute(hConsole, 14);
	int x;
	cout << ("type 1 if you want spotbattle map and 0 if you dont want spot battle maps : ");
	cin >> x;
	system("cls");
	if (x != 1 && x != 0) {
		SetConsoleTextAttribute(hConsole, 4);
		log("you did not enter in a valid input");
		getSpotMapsSetting();
	}
	if (x == 1) {
		return true;
	}
	else
		return false;
}

bool getOneUpMapsSetting() {
	SetConsoleTextAttribute(hConsole, 14);
	int x;
	cout << ("type 1 if you want One-UP maps and 0 if you dont want one up maps : ");
	cin >> x;
	system("cls");
	if (x != 1 && x != 0){
		SetConsoleTextAttribute(hConsole, 4);
		log("you did not enter in a valid input");
		getOneUpMapsSetting();
	}
	if (x == 1) {
		return true;
	}
	else
		return false;
}

bool getTrueRandomSetting() {
	SetConsoleTextAttribute(hConsole, 14);
	int x;
	cout << ("type 1 if you want TrueRandom maps and 0 if you dont want true random : ");
	cin >> x;
	system("cls");
	if (x != 1 && x != 0) {
		SetConsoleTextAttribute(hConsole, 4);
		log("you did not enter in a valid input");
		getTrueRandomSetting();
	}
	if (x == 1) {
		return true;
	}
	else
		return false;
}