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

void displayCategoriesAndQuestions();
int isQuestionAnswered(const char* category, int dollarAmount);
void getQuestion(const char* category, int dollarAmount);
int checkAnswer(const char* answer, const char* category, int dollarAmount);
void displayCorrectAnswer(const char* category, int dollarAmount);
void markQuestionAsAnswered(const char* category, int dollarAmount);
int allQuestionsAnswered();

#endifar *category, int value);
bool check_answer(Question *q, const char *player_answer);
#endif
