/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <Nuha Tahnia Haq (100867378), Laiba Asif (100872058), 
 * Arzika Khan (100753164), Ubong Offiong (100866634)>
 *
 * All rights reserved.
 *
 */

#ifndef PLAYERS_H
#define PLAYERS_H

typedef struct {
    char name[50];
    int score;
} Player;

void initializePlayers(Player players[], int numPlayers);
int isValidPlayer(Player players[], int numPlayers, const char* playerName);
void updateScore(Player players[], int numPlayers, const char* playerName, int dollarAmount);
void displayFinalScores(Player players[], int numPlayers);

#endif
