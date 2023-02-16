#ifndef DECODER_H
#define DECODER_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string.h>
#include <unordered_set>
#include <utility>

using namespace std;

queue<string> splitString(const string &toSplit);

string shiftString(const string &toShift, const int &shiftValue);

pair<int, string> decode(const unordered_set<string> &dict, const string &toDecode);

queue<pair<int, string>> decodeLinesFromInput(const string &fileName, const unordered_set<string> &dict);

unordered_set<string> makeDictionary(const string &fileName);

string setDictionaryPath(const string path);

string setInputPath(const string path);

string setOutputPath(const string path);

void writeToOutput(queue<pair<int, string>> decodedQ, const string output);

#endif