/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <Nuha Tahnia Haq (100867378), Laiba Asif (100872058), 
 * Arzika Khan (100753164), Ubong Offiong (100866634)>
 *
 * All rights reserved.
 *
 */

#include "players.h"
#include <stdio.h>
#include <string.h>

void initialize_players(Player players[PLAYER_COUNT]) {
    for (int i = 0; i < PLAYER_COUNT; i++) {
        printf("Enter name for Player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
}

void display_scores(const Player players[PLAYER_COUNT]) {
    printf("Current Scores:\n");
    for (int i = 0; i < PLAYER_COUNT; i++) {
        printf("%s: $%d\n", players[i].name, players[i].score);
    }
}
