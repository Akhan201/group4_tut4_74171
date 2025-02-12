/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <Nuha Tahnia Haq (100867378), Laiba Asif (100872058), 
 * Arzika Khan (100753164), Ubong Offiong (100866634)>
 *
 * All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>
#include "players.h"

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player %d name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
}

int isValidPlayer(Player players[], int numPlayers, const char* playerName) {
    for (int i = 0; i < numPlayers; i++) {
        if (strcmp(players[i].name, playerName) == 0) {
            return 1;
        }
    }
    return 0;
}

void updateScore(Player players[], int numPlayers, const char* playerName, int dollarAmount) {
    for (int i = 0; i < numPlayers; i++) {
        if (strcmp(players[i].name, playerName) == 0) {
            players[i].score += dollarAmount;
        }
    }
}

void displayFinalScores(Player players[], int numPlayers) {
printf("\033[48;5;89mWe have a WINNER!🥳🥳\033[0m\n");
 printf("\nFinal Scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: $%d\n", players[i].name, players[i].score);
    }
}
