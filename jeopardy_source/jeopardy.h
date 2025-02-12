/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <Nuha Tahnia Haq (100867378), Laiba Asif (100872058), 
 * Arzika Khan (100753164), Ubong Offiong (100866634)>
 *
 * All rights reserved.
 *
 */

#ifndef JEOPARDY_H
#define JEOPARDY_H

#include "players.h"

// Display categories and their available question values
void displayCategoriesAndQuestions();

// Check if the selected question has already been answered
int isQuestionAnswered(const char* category, int dollarAmount);

// Get the question from the bank based on category and dollar amount
void getQuestion(const char* category, int dollarAmount);

// Check if the player's answer is correct
int checkAnswer(const char* answer, const char* category, int dollarAmount);

// Update the player's score
void updateScore(Player players[], int numPlayers, const char* playerName, int dollarAmount);

// Display the correct answer if the player was wrong
void displayCorrectAnswer(const char* category, int dollarAmount);

// Mark the selected question as answered
void markQuestionAsAnswered(const char* category, int dollarAmount);

// Check if all questions have been answered
int allQuestionsAnswered();

// Display the final scores of all players
void displayFinalScores(Player players[], int numPlayers);

#endif
