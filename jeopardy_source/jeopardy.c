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


// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4
#define MAX_LENGTH 20


// Put global environment variables here
char *name;

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens){
// Tokenize the input string based on spaces
    char *token = strtok(input, " ");
    int index = 0;

    // Iterate through the tokens
    while (token != NULL) {
        tokens[index++] = token;
        token = strtok(NULL, " ");
    }

    // Null-terminate the tokens array
    tokens[index] = NULL;

}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players){
printf("\n===== Final Results =====\n");
printf("%-20s %s\n", "Player Name", "Score");
printf("============================\n");
for (int i = 0; i < num_players - 1; i++) {
        for (int j = i + 1; j < num_players; j++) {
            if (players[i].score < players[j].score) {
                // Swap players[i] and players[j]
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
return 0;

}

int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    printf("This is JEOPARDY!!)
    initialize_game();
    
	// Prompt for players' names
	// initialize each of the players in the array
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Please enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0; // Initialize player score
    }   
  
    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Call functions from the questions and players source files
	display_catagories ();
	display_question();
	already_answered();
	player_exists();
	update_score();
        // Display the final results and exit
        show_results(players, NUM_PLAYERS);
        
    }
    return EXIT_SUCCESS;
}  

 










    // An array of 4 players, may need to be a pointer if you want it set dynamically
 
