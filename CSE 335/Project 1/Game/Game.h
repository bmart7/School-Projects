/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: bmart
 *
 * Created on February 25, 2019, 5:42 AM
 */

#ifndef GAME_H
#define GAME_H

#include "Character.h"
#include <string>
#include <vector>

using namespace std;

const string stars = "************ ";
const string middle_head = "**************** ";
const string head = "Printing Sisters ";
const string headRace = "Printing Sister: Order by Race ";
const string headHair = "Printing Sister: Order by Hair ";
const string headSpeed = "Printing Sister: Order by Speed ";
const string footer = "************ **************** ************\n";

class Game {
public:
    Game(string filename);
    void getCharacters();
    void getCharactersByRace();
    void getCharactersBySpeed();
    void getCharactersByHair();
    void populateCharacters(string filename);
    void print(vector<Character*> list);
private:
    vector<Character*> characterList;

};

#endif /* GAME_H */

