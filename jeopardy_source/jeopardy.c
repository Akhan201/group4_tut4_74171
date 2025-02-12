/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <Nuha Tahnia Haq (100867378), Laiba Asif (100872058), 
 * Arzika Khan (100753164), Ubong Offiong (100866634)>
 *
 * All rights reserved.
 *
 */

#include "jeopardy.h"
#include <stdio.h>
#include <string.h>

void play_game(Player players[PLAYER_COUNT], Question questions[CATEGORY_COUNT][QUESTIONS_PER_CATEGORY]) {
    char selected_category[50];
    int selected_value;
    char answer[100];
    printf("\033[43mJeopardy!\033[0m\n");
    while (1) {
        display_questions(questions);
        display_scores(players);
        
        printf("Enter player's name to select a question: ");
        char player_name[50];
        scanf("%s", player_name);
        
        printf("Enter category and value (e.g., Algorithms 200): ");
        scanf("%s %d", selected_category, &selected_value);
        
        if (!validate_question(questions, selected_category, selected_value)) {
            printf("Invalid question selection. Try again.\n");
            continue;
        }
        
        for (int i = 0; i < CATEGORY_COUNT; i++) {
            for (int j = 0; j < QUESTIONS_PER_CATEGORY; j++) {
                if (strcmp(questions[i][j].category, selected_category) == 0 && questions[i][j].value == selected_value) {
                    printf("Question: %s\n", questions[i][j].question);
                    printf("Your answer: ");
                    getchar();
                    fgets(answer, sizeof(answer), stdin);
                    answer[strcspn(answer, "\n")] = 0;
                    
                    if (check_answer(&questions[i][j], answer)) {
                        for (int k = 0; k < PLAYER_COUNT; k++) {
                            if (strcmp(players[k].name, player_name) == 0) {
                                players[k].score += selected_value;
                            }
                        }
                        printf("Correct!\n");
                    } else {
                        printf("Incorrect! The correct answer was: %s\n", questions[i][j].answer);
                    }
                    break;
                }
            }
        }
        
        int all_answered = 1;
        for (int i = 0; i < CATEGORY_COUNT; i++) {
            for (int j = 0; j < QUESTIONS_PER_CATEGORY; j++) {
                if (!questions[i][j].answered) {
                    all_answered = 0;
                    break;
                }
            }
        }
        if (all_answered) break;
    }
printf("\033[43mGame Over! - We Have a Winner ^-^\033[0m\n");
    display_scores(players);
}

int main() {
    Player players[PLAYER_COUNT];
    Question questions[CATEGORY_COUNT][QUESTIONS_PER_CATEGORY];
    
    initialize_players(players);
    initialize_questions(questions);
    play_game(players, questions);
    
    return 0;
}
