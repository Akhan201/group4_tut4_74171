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
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void){
    // Define the set of questions, each category has different questions and values
    question temp_questions[NUM_QUESTIONS] = {
        {"programming", "What is the keyword to define a function in C?", "what is void", 100, false},
        {"programming", "Which programming language is known as the mother of all languages?", "what is c", 200, false},
        {"programming", "Which symbol is used for single-line comments in C?", "what is //", 300, false},
        {"programming", "What is the extension of a C header file?", "what is .h", 400, false},
        
        {"algorithms", "Which algorithm is used for sorting with an average time complexity of O(n log n)?", "what is quicksort", 100, false},
        {"algorithms", "Which algorithm is used to find the shortest path in a graph?", "what is dijkstra", 200, false},
        {"algorithms", "Which search algorithm repeatedly divides the array in half?", "what is binary search", 300, false},
        {"algorithms", "Which algorithm is used for traversing trees in depth-first order?", "what is dfs", 400, false},
        
        {"databases", "Which SQL command is used to retrieve data from a database?", "what is select", 100, false},
        {"databases", "What type of database structure organizes data in tables?", "what is relational", 200, false},
        {"databases", "Which database language is used to manipulate and retrieve data?", "what is sql", 300, false},
        {"databases", "Which normalization form ensures no transitive dependencies?", "what is third normal form", 400, false}
    };
    
    // Copy temporary questions to the global questions array
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        questions[i] = temp_questions[i];
    }
}

// Displays each of the remaining categories and questions dollar values that have not been answered
void display_categories(void) {
    printf("\nCategories and available questions:\n");
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        printf("%s: ", categories[i]);
        for (int j = 0; j < NUM_QUESTIONS; j++) {
            if (strcmp(questions[j].category, categories[i]) == 0 && !questions[j].answered) {
                printf("$%d ", questions[j].value);
            }
        }
        printf("\n");
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value && !questions[i].answered) {
            printf("Question: %s\n", questions[i].question);
            return;
        }
    }
    printf("Question not found or already answered.\n");
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer){
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            if (strcasecmp(questions[i].answer, answer) == 0) { // Case-insensitive comparison
                questions[i].answered = true; // Mark question as answered
                return true;
            }
        }
    }
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value){
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return questions[i].answered;
        }
    }
    return false;
}
