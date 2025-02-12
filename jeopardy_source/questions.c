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
#include <strings.h>
#include <ctype.h>
#include "questions.h"

// Global array to hold Jeopardy questions
question questions[NUM_QUESTIONS];

void initialize_game(void){
    int i = 0;
    int double_jeopardy_index;  // Declare it
    double_jeopardy_index = rand() % NUM_QUESTIONS;

    // ---------- Programming Questions ----------
    strcpy(questions[i].category, "programming");
    strcpy(questions[i].question, "Which language is known for its use in system programming?");
    strcpy(questions[i].answer, "C");
    questions[i++].value = 100;

    strcpy(questions[i].category, "programming");
    strcpy(questions[i].question, "What is the keyword to define a function in Python?");
    strcpy(questions[i].answer, "def");
    questions[i++].value = 200;

    strcpy(questions[i].category, "programming");
    strcpy(questions[i].question, "Which language is mainly used for Android app development?");
    strcpy(questions[i].answer, "Java");
    questions[i++].value = 300;

    strcpy(questions[i].category, "programming");
    strcpy(questions[i].question, "Which does const mean in C language when used before a variable?");
    strcpy(questions[i].answer, "Immutable");
    questions[i++].value = 400;

    strcpy(questions[i].category, "programming");
    strcpy(questions[i].question, "Which language is commonly used for AI and machine learning?");
    strcpy(questions[i].answer, "Python");
    questions[i++].value = 500;

// **Bonus Question - 600 Points**
    strcpy(questions[i].category, "programming");
    strcpy(questions[i].question, "Which programming language is used to develop iOS applications?");
    strcpy(questions[i].answer, "Swift");
    questions[i++].value = 600;

    // ---------- Algorithms Questions ----------
    strcpy(questions[i].category, "algorithms");
    strcpy(questions[i].question, "Which algorithm is used to find the shortest path in a graph?");
    strcpy(questions[i].answer, "Dijkstra");
    questions[i++].value = 100;

    strcpy(questions[i].category, "algorithms");
    strcpy(questions[i].question, "Which sorting algorithm has an average time complexity of O(n log n)?");
    strcpy(questions[i].answer, "Merge Sort");
    questions[i++].value = 200;

    strcpy(questions[i].category, "algorithms");
    strcpy(questions[i].question, "Which algorithm is used for searching in a balanced BST?");
    strcpy(questions[i].answer, "Binary Search");
    questions[i++].value = 300;

    strcpy(questions[i].category, "algorithms");
    strcpy(questions[i].question, "Which algorithm uses a priority queue and is optimal for greedy selection?");
    strcpy(questions[i].answer, "Prim's");
    questions[i++].value = 400;

    strcpy(questions[i].category, "algorithms");
    strcpy(questions[i].question, "What is the best-case time complexity of QuickSort?");
    strcpy(questions[i].answer, "O(n log n)");
    questions[i++].value = 500;

    // ---------- Databases Questions ----------
    strcpy(questions[i].category, "databases");
    strcpy(questions[i].question, "Which database language is used to query relational databases?");
    strcpy(questions[i].answer, "SQL");
    questions[i++].value = 100;

    strcpy(questions[i].category, "databases");
    strcpy(questions[i].question, "Which type of database does MongoDB represent?");
    strcpy(questions[i].answer, "NoSQL");
    questions[i++].value = 200;

    strcpy(questions[i].category, "databases");
    strcpy(questions[i].question, "Which type of database model organizes data in parent-child relationships?");
    strcpy(questions[i].answer, "Hierarchical");
    questions[i++].value = 300;

    strcpy(questions[i].category, "databases");
    strcpy(questions[i].question, "What is the key feature of NoSQL databases that makes them different from SQL databases?");
    strcpy(questions[i].answer, "Schema-less");
    questions[i++].value = 400;

    strcpy(questions[i].category, "databases");
    strcpy(questions[i].question, "Which type of database is optimized for analytical queries?");
    strcpy(questions[i].answer, "OLAP");
    questions[i++].value = 500;

    // Mark all questions as unanswered initially
    for (int j = 0; j < NUM_QUESTIONS; j++) {
        questions[j].answered = false;
    }
}

/*
 * Prints out all available categories and their respective dollar values
 * for questions that have not been answered yet.
 */
void display_categories(void) {
    printf("\nAvailable Categories and Question Values:\n");
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (!questions[i].answered) {
            printf("%s - $%d\n", questions[i].category, questions[i].value);
        }
    }
}

/*
 * Displays the question for the given category and value.
 * If the question has already been answered, it notifies the user.
 */
void display_question(char *category, int value) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            if (!questions[i].answered) {
                printf("\nQuestion: %s\n", questions[i].question);
                return;
            }
            else {
                printf("This question has already been answered.\n");
                return;
            }
        }
    }
    printf("Invalid category or value.\n");
}

/*
 * Validates the player's answer by checking if it starts with "what is" or "who is"
 * and then compares the actual answer against the correct one.
 *
 * Returns:
 * - true: if the answer is correct and properly formatted
 * - false: if the answer is incorrect or not formatted properly
 */
bool valid_answer(char *category, int value, char *answer) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            if (!questions[i].answered) {
                // Tokenize answer to check required format
                char *token = strtok(answer, " ");
                if (token == NULL || (strcmp(token, "what") != 0 && strcmp(token, "who") != 0)) {
                    return false;
                }
                token = strtok(NULL, " ");
                if (token == NULL || strcmp(token, "is") != 0) {
                    return false;
                }
                token = strtok(NULL, " ");
                if (token != NULL && strcmp(token, questions[i].answer) == 0) {
                    questions[i].answered = true;
                    return true; // Correctly formatted and correct answer
                }
            }
        }
    }
    return false; // Either incorrect answer or formatting issue
}

/*
 * Checks if a question with the given category and value has already been answered.
 *
 * Returns:
 * - true: if the question has been answered
 * - false: if the question is still available
 */
bool already_answered(char *category, int value) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return questions[i].answered;
        }
    }
    return false;
}
