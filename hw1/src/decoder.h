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

int do_nothing();

queue<string> splitString(string &toSplit);

string shiftString(string &toShift, int &shiftValue);

pair<int, string> decode(unordered_set<string> &dict, string &toDecode);

queue<pair<int, string>> decodeLinesFromInput(string &fileName, unordered_set<string> &dict);

unordered_set<string> makeDictionary(string &fileName);

string setDictionaryPath(string path);

string setInputPath(string path);

string setOutputPath(string path);

void writeToOutput(queue<pair<int, string>> decodedQ, string output);

#endif