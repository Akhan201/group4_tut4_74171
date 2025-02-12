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
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

#define BUFFER_LEN 256
#define NUM_PLAYERS 4
#define MAX_LENGTH 20

// Function declarations
void display_answer(char *category, int value);
bool all_questions_answered(void);

// Function to show results
void show_results(player *players, int num_players) {
    printf("\n===== Final Results =====\n");
    printf("%-20s %s\n", "Player Name", "Score");
    printf("============================\n");
    
    // Sorting players based on their scores (descending order)
    for (int i = 0; i < num_players - 1; i++) {
        for (int j = i + 1; j < num_players; j++) {
            if (players[i].score < players[j].score) {
                player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    // Display sorted player names and scores
    for (int i = 0; i < num_players; i++) {
        printf("%-20s %d\n", players[i].name, players[i].score);
    }
}

// Main game loop
int main(int argc, char *argv[]) {
    player players[NUM_PLAYERS];
    char buffer[BUFFER_LEN] = { 0 };
    char name[MAX_LENGTH];
    int chosen_value;
    char chosen_category[MAX_LENGTH];

    // Display introduction
    printf("Welcome to JEOPARDY!\n");
    initialize_game();

    // Get player names
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Please enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0; // Initialize player score
    }

    while (1) {
        // Display remaining categories and their values
        display_categories();

        // Get player selection
        printf("\nEnter the name of the player who will pick the next category: ");
        scanf("%s", name);
        
        // Validate that player exists
        if (!player_exists(players, NUM_PLAYERS, name)) {
            printf("Invalid player name. Please try again.\n");
            continue;
        }

        // Player selects a category and value
        printf("\n%s, enter the category and dollar amount (e.g., programming 100): ", name);
        scanf("%s %d", chosen_category, &chosen_value);

        // Check if the selected category and value have already been answered
        if (already_answered(chosen_category, chosen_value)) {
            printf("This question has already been answered.\n");
            continue;
        }

        // Display the question for the selected category and value
        display_question(chosen_category, chosen_value);

        // Get the player's answer
        printf("Your answer: ");
        fgets(buffer, BUFFER_LEN, stdin);  // to capture any extra newline
        fgets(buffer, BUFFER_LEN, stdin);  // Get the answer

        // Tokenize and check if answer is valid
        if (valid_answer(chosen_category, chosen_value, buffer)) {
            printf("Correct!\n");
            update_score(players, NUM_PLAYERS, name, chosen_value);
        } else {
            printf("Incorrect! The correct answer was: ");
            display_answer(chosen_category, chosen_value);
        }

        // Show results at the end of the game
        if (all_questions_answered()) {
            show_results(players, NUM_PLAYERS);
            break;
        }
    }

    return EXIT_SUCCESS;
}
