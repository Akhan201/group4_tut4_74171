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
#include <stdlib.h>
#include <string.h>
#include "jeopardy.h"
#include "players.h"
#include "questions.h"

int main() {
    Player players[4];
    int numPlayers = 4;
    char category[50];
    int dollarAmount;
	//Jeopardy title coloured terminal
	printf("\033[48;5;18mJeopardy Game!\033[0m\n");
    // Initialize players
    initializePlayers(players, numPlayers);
    // Start the game
    while (1) {
        displayCategoriesAndQuestions();
        char selectedPlayer[50];
        printf("\nEnter player name: ");
        scanf("%s", selectedPlayer);

        // Validate player
        if (!isValidPlayer(players, numPlayers, selectedPlayer)) {
            printf("Invalid player. Try again.\n");
            continue;
        }

        // Get category and dollar amount
        printf("Enter category and dollar amount (e.g., Algorithms 200): ");
        scanf("%s %d", category, &dollarAmount);

        // Validate question
        if (isQuestionAnswered(category, dollarAmount)) {
            printf("This question has already been answered. Choose another one.\n");
            continue;
        }

        // Ask the question
        char answer[100];
        printf("Question: ");
        getQuestion(category, dollarAmount);
        printf("Your answer (start with 'What is' or 'Who is'): ");
        getchar(); // to clear the buffer
        fgets(answer, sizeof(answer), stdin);
        
        // Check answer
        if (checkAnswer(answer, category, dollarAmount)) {
            printf("Correct!\n");
            updateScore(players, numPlayers, selectedPlayer, dollarAmount);
        } else {
            printf("Incorrect! The correct answer is: ");
            displayCorrectAnswer(category, dollarAmount);
        }

        // Mark question as answered
        markQuestionAsAnswered(category, dollarAmount);

        // End game if all questions are answered
        if (allQuestionsAnswered()) {
            break;
        }
    }

    // Display final scores
    displayFinalScores(players, numPlayers);
    return 0;
}
