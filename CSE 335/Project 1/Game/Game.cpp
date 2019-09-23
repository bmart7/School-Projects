/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: bmart
 * 
 * Created on February 25, 2019, 5:42 AM
 */

#include "Game.h"
#include "LargeCharacterFactory.h"
#include "LargeCharacter.h"
#include "MedCharacterFactory.h"
#include "MedCharacter.h"
#include "SmallCharacterFactory.h"
#include "SmallCharacter.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>

Game::Game(string filename) {
    populateCharacters(filename);
}

void Game::populateCharacters(string filename){
    ifstream infile(filename);
    if (infile){
        string line;
        while (getline(infile,line)){
            istringstream iss(line);
            vector<string> tokens;
            copy(istream_iterator<string>(iss),
                    istream_iterator<string>(),
                    back_inserter(tokens));
            if (tokens[1].compare("big") == 0){
                LargeCharacterFactory lcf;
                Character* newChar = lcf.createCharacter(tokens);
                characterList.push_back(newChar);
            }else if (tokens[1].compare("med") == 0){
                MedCharacterFactory mcf;
                Character* newChar = mcf.createCharacter(tokens);
                characterList.push_back(newChar);
            }else{
                SmallCharacterFactory scf;
                Character* newChar = scf.createCharacter(tokens);
                characterList.push_back(newChar);
            }
        }
    }
}

void Game::getCharactersBySpeed(){
    cout<<endl<<stars<<headSpeed<<stars<<endl;
    vector<Character*> temp = characterList;
    for (int i=1; i<temp.size();i++){
        Character* min = temp[i];
        int j = i-1;
        while (j > -1 && temp[j]->getSpeed() > min->getSpeed()){
            temp[j+1] = temp[j];
            j--;
        }
        temp[j+1] = min;
    }
    print(temp);
}

void Game::getCharactersByHair(){
    cout<<endl<<stars<<headHair<<stars<<endl;
    vector<Character*> temp = characterList;
    for (int i=1; i<temp.size();i++){
        Character* min = temp[i];
        int j = i-1;
        while (j > -1 && temp[j]->getHair() > min->getHair()){
            temp[j+1] = temp[j];
            j--;
        }
        temp[j+1] = min;
    }
    print(temp);
}

void Game::getCharacters(){
    cout<<endl<<stars<<head<<stars<<endl;
    print(characterList);
}

void Game::getCharactersByRace(){
    cout<<endl<<stars<<headRace<<stars<<endl;
    vector<Character*> temp = characterList;
    for (int i=1; i<temp.size();i++){
        Character* min = temp[i];
        int j = i-1;
        while (j > -1 && temp[j]->getRace() > min->getRace()){
            temp[j+1] = temp[j];
            j--;
        }
        temp[j+1] = min;
    }
    print(temp);
}

void Game::print(vector<Character*> list){
        for(int i = 0; i < list.size(); i++){
            list[i]->print();
        }
        cout<<footer<<endl;
}