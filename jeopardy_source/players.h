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

#define PLAYER_COUNT 4

typedef struct {
    char name[50];
    int score;
} Player;

void initialize_players(Player players[PLAYER_COUNT]);
void display_scores(const Player players[PLAYER_COUNT]);
#endif
