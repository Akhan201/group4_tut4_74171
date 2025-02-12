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
#include <string.h>
#include "questions.h"

#define MAX_QUESTIONS 12  // Increase this to 12 to accommodate all questions from three categories

typedef struct {
    char category[50];
    int dollarAmount;
    char question[200];
    char correctAnswer[100];
    int answered;
} Question;

// Question Bank - 3 Categories, 4 Questions EACH
Question questionBank[MAX_QUESTIONS] = {
    // Algorithms category
    {"Algorithms", 200, "This algorithm is used to find the shortest path in a graph.", "Dijkstra", 0},
    {"Algorithms", 400, "This sorting algorithm has an average time complexity of O(n log n) and follows a divide-and-conquer approach.", "Merge Sort", 0},
    {"Algorithms", 600, "This algorithm is used for searching in a Balanced Binary Search Tree (BST).", "Binary Search", 0},
    {"Algorithms", 800, "This algorithm uses a priority queue, LIFO.", "BFS", 0},

    // Database category
    {"Database", 200, "Structured collection of data that allows users to store, manage, and retrieve information.", "database", 0},
    {"Database", 400, "A popular NoSQL database that stores data as JSON-like documents.", "MongoDB", 0},
    {"Database", 600, "The company that first played around with databases.", "IBM", 0},
    {"Database", 800, "Who co-founded Microsoft and oversaw the creation of SQL Server?", "Bill Gates", 0},

    // Programming Category
    {"Programming", 200, "This language is known for its use in system programming.", "What is C?", 0},
    {"Programming", 400, "This keyword is used to define a function in Python.", "What is def?", 0},
    {"Programming", 600, "This language is used for Android app dev.", "What is Java?", 0},
    {"Programming", 800, "The Father of AI", "Who is Alan Turing?", 0}
};

void displayCategoriesAndQuestions() {
    printf("\nCategories and Questions:\n");
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        if (questionBank[i].answered == 0) {
            printf("%s %d\n", questionBank[i].category, questionBank[i].dollarAmount);
        }
    }
}

int isQuestionAnswered(const char* category, int dollarAmount) {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        if (strcmp(questionBank[i].category, category) == 0 && questionBank[i].dollarAmount == dollarAmount) {
            return questionBank[i].answered;
        }
    }
    return 0;
}

void getQuestion(const char* category, int dollarAmount) {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        if (strcmp(questionBank[i].category, category) == 0 && questionBank[i].dollarAmount == dollarAmount) {
            printf("%s\n", questionBank[i].question);
            return;
        }
    }
}

int checkAnswer(const char* answer, const char* category, int dollarAmount) {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        if (strcmp(questionBank[i].category, category) == 0 && questionBank[i].dollarAmount == dollarAmount) {
            if (strstr(answer, questionBank[i].correctAnswer) != NULL) {
                return 1;
            }
        }
    }
    return 0;
}

void displayCorrectAnswer(const char* category, int dollarAmount) {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        if (strcmp(questionBank[i].category, category) == 0 && questionBank[i].dollarAmount == dollarAmount) {
            printf("%s\n", questionBank[i].correctAnswer);
        }
    }
}

void markQuestionAsAnswered(const char* category, int dollarAmount) {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        if (strcmp(questionBank[i].category, category) == 0 && questionBank[i].dollarAmount == dollarAmount) {
            questionBank[i].answered = 1;
        }
    }
}

int allQuestionsAnswered() {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        if (questionBank[i].answered == 0) {
            return 0;
        }
    }
    return 1;
}
