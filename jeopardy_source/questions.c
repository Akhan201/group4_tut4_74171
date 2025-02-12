/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <Nuha Tahnia Haq (100867378), Laiba Asif (100872058), 
 * Arzika Khan (100753164), Ubong Offiong (100866634)>
 *
 * All rights reserved.
 *
 */

// questions.c
#include "questions.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>  // for isspace() function

// Function to trim leading and trailing spaces from a string
void trim_spaces(char *str) {
    int start = 0, end = strlen(str) - 1;
    
    // Trim leading spaces
    while (start <= end && isspace((unsigned char)str[start])) {
        start++;
    }
    
    // Trim trailing spaces
    while (end >= start && isspace((unsigned char)str[end])) {
        end--;
    }
    
    // Shift the string to the left and terminate it at the new end
    for (int i = start; i <= end; i++) {
        str[i - start] = str[i];
    }
    str[end - start + 1] = '\0';
}

void initialize_questions(Question questions[CATEGORY_COUNT][QUESTIONS_PER_CATEGORY]) {
    const char *categories[] = {"Programming", "Algorithms", "Databases"};
    int values[] = {200, 400, 600, 800};
    
    // Questions and answers for each category
    const char *questions_text[][4] = {
        {
            "This language is known for its use in system programming.",
            "This keyword is used to define a function in Python.",
            "This language is used for Android app dev.",
            "The Father of AI"
        },
        {
            "This algorithm is used to find the shortest path in a graph.",
            "This sorting algorithm has an average time complexity of O(n log n) and follows a divide-and-conquer approach.",
            "This algorithm is used for searching in a Balanced Binary Search Tree (BST).",
            "This algorithm uses a priority queue, LIFO."
        },
        {
            "Structured collection of data that allows users to store, manage, and retrieve information.",
            "A popular NoSQL database that stores data as JSON-like documents.",
            "The company that first played around with databases.",
            "Who co-founded Microsoft and oversaw the creation of SQL Server?"
        }
    };
    
    const char *answers_text[][4] = {
        {
            "What is C?",
            "What is def?",
            "What is Java?",
            "Who is Alan Turing?"
        },
        {
            "What is Dijkstra?",
            "What is Merge Sort?",
            "What is Binary Search?",
            "What is BFS?"
        },
        {
            "What is a database?",
            "What is MongoDB?",
            "Who is IBM?",
            "Who is Bill Gates?"
        }
    };
    
    for (int i = 0; i < CATEGORY_COUNT; i++) {
        for (int j = 0; j < QUESTIONS_PER_CATEGORY; j++) {
            // Assigning the new category, value, question, and answer
            strcpy(questions[i][j].category, categories[i]);
            questions[i][j].value = values[j];
            sprintf(questions[i][j].question, "%s", questions_text[i][j]);
            sprintf(questions[i][j].answer, "%s", answers_text[i][j]);
            questions[i][j].answered = false;
        }
    }
}

void display_questions(const Question questions[CATEGORY_COUNT][QUESTIONS_PER_CATEGORY]) {
    printf("Available Questions:\n");
    for (int i = 0; i < CATEGORY_COUNT; i++) {
        printf("%s: ", questions[i][0].category);
        for (int j = 0; j < QUESTIONS_PER_CATEGORY; j++) {
            if (!questions[i][j].answered) {
                printf("$%d ", questions[i][j].value);
            }
        }
        printf("\n");
    }
}

bool validate_question(const Question questions[CATEGORY_COUNT][QUESTIONS_PER_CATEGORY], const char *category, int value) {
    for (int i = 0; i < CATEGORY_COUNT; i++) {
        for (int j = 0; j < QUESTIONS_PER_CATEGORY; j++) {
            if (strcmp(questions[i][j].category, category) == 0 && questions[i][j].value == value && !questions[i][j].answered) {
                return true;
            }
        }
    }
    return false;
}

bool check_answer(Question *q, const char *player_answer) {
    char trimmed_answer[256];
    strcpy(trimmed_answer, player_answer);

    // Trim any leading/trailing spaces from the player's answer
    trim_spaces(trimmed_answer);

    // Check for "What is" or "Who is" prefix and adjust accordingly
    if (strncmp(trimmed_answer, "What is ", 8) == 0) {
        // Compare the rest of the answer (after the "What is ")
        if (strcasecmp(trimmed_answer + 8, q->answer) == 0) {
            q->answered = true;
            return true;
        }
    } else if (strncmp(trimmed_answer, "Who is ", 7) == 0) {
        // Compare the rest of the answer (after the "Who is ")
        if (strcasecmp(trimmed_answer + 7, q->answer) == 0) {
            q->answered = true;
            return true;
        }
    }

    // If the answer doesn't match, mark it as answered but incorrect
    q->answered = true;
    return false;
}
