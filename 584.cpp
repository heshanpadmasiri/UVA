#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <sstream>
#include "competitions.h"

int strike(vector<string>& vector, int i);

int sparse(vector<string>& vector, int i);

using namespace std;

int bounusAddition(vector<string>& tokens, int i, int num){
    int score, last;
    score = last = 0;
    for (int j = i; j < i+num; ++j) {
        if (tokens[j] == "X"){
            score += 10;
        } else if(tokens[j] == "/"){
            score += (10-last);
        } else {
            last = stoi(tokens[j]);
            score += last;
        }
    }
    return score;
}

int getScore(string& line){
    vector<string> tokens = split_string(line,' ');
    int i, count, score;
    i = count = score = 0;
    while (count < 10){
        if (tokens[i] == "X"){
            score += 10 + strike(tokens,i);
        } else if(tokens[i+1] == "/"){
            i++;
            score += 10 + sparse(tokens,i);
        } else {
            score += stoi(tokens[i]) + stoi(tokens[i+1]);
            i++;
        }
        i++;count++;
    }
    return score;
}

int sparse(vector<string>& vector, int i) {
    return bounusAddition(vector,i+1,1);
}

int strike(vector<string>& vector, int i) {
    return bounusAddition(vector,i+1,2);
}

int main() {
    char input[100];
    gets(input);
    while (strcmp(input,"Game Over")){
        string line = input;
        int score = getScore(line);
        printf("%d\n",score);
        gets(input);
    }
    return 0;
}

