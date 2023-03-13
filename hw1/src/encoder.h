#ifndef ENCODER_H
#define ENCODER_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <set>
#include <string.h>
#include <vector>

using namespace std;

// int setNumberOfSentences(char *charLines);

// int setMinimumWordLength(char *charLength);

// string setDictionaryPath(string path);

// string setOutputPath(string path);

set<string> loadDictionary(string dictionaryPath, int minimumWordLength);

string generateSentence(set<string> dictionary, int shift);

void writeToOutput(vector<string> data, string output);

#endif