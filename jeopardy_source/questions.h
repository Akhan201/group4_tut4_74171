/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <Nuha Tahnia Haq (100867378), Laiba Asif (100872058), 
 * Arzika Khan (100753164), Ubong Offiong (100866634)>
 *
 * All rights reserved.
 *
 */

#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <stdbool.h>

#define CATEGORY_COUNT 3
#define QUESTIONS_PER_CATEGORY 3

// Structure to store a Jeopardy question
typedef struct {
    char category[500];
    int value;
    char question[2560];
    char answer[500];
    bool answered;
} Question;

void initialize_questions(Question questions[CATEGORY_COUNT][QUESTIONS_PER_CATEGORY]);
void display_questions(const Question questions[CATEGORY_COUNT][QUESTIONS_PER_CATEGORY]);
bool validate_question(const Question questions[CATEGORY_COUNT][QUESTIONS_PER_CATEGORY], const char *category, int value);
bool check_answer(Question *q, const char *player_answer);
#endif
