#include "decoder.h"
#include <algorithm>

using namespace std;

// Function to split a string into a queue of strings. Takes in a string to
// split. Returns a queue of strings.
queue<string> splitString(const string &toSplit) {
  stringstream ss(toSplit);
  string word;
  queue<string> words;

  while (ss >> word) {
    words.push(word);
  }
  return words;
}

// Function to attempt a given shift value. Takes in a string and shift value to
// shift. Returns string after shift applied
string shiftString(const string &toShift, const int &shiftValue) {
  string toReturn;
  for (char c : toShift) {
    // toReturn += (char)(((c + shiftValue - 'A') % 26) + 'A');
    char shiftedLetter = c + shiftValue;
    if (shiftedLetter > 90)  {
      shiftedLetter -= 26;
    }
    toReturn += shiftedLetter;
  }
  return toReturn;
}

// Function to decode a string. Takes in a dictionary and a string to decode.
// Returns the decoded string.
pair<int, string> decode(const unordered_set<string> &dict,
                         const string &toDecode) {
  pair<int, string> toReturnPair;
  string toReturnString;
  // string lower = toDecode;
  // transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
  queue<string> words = splitString(toDecode);
  int shiftValue;
  bool foundShiftValue = false;

  // while there are still words to decode
  while (!words.empty()) {
    string queueWord = words.front();
    words.pop();
    if (foundShiftValue) {
      toReturnString += shiftString(queueWord, shiftValue) + " ";
    } else {
      // try each shift value and store shift value for a given line if found
      for (int i = 0; i < 26; i++) {
        string tempWord = shiftString(queueWord, i);
        // cout << queueWord << endl;
        // cout << tempWord << endl;
        if (dict.find(tempWord) != dict.end()) {
          toReturnString += tempWord + " ";
          shiftValue = i;
          foundShiftValue = true;
          break;
        } else {
          continue;
        }
      }
    }
    // if toReturnString is empty, the correct shift value wasn't found for this
    // line
    if (toReturnString.empty()) {
      break;
    }
  }
  if (!foundShiftValue) {
    toReturnPair = make_pair(-1, "No shift value found");
  } else {
    toReturnPair = make_pair(shiftValue, toReturnString);
  }
  return toReturnPair;
}

// Function to decode a file. Takes in a file name and a dictionary.
// Returns a queue of decoded strings.
queue<pair<int, string>>
decodeLinesFromInput(const string &fileName,
                     const unordered_set<string> &dict) {
  istream *input = &cin;
  ifstream file;
  if (fileName != "stdin") {
    file.open(fileName);
    input = &file;
  }

  queue<pair<int, string>> decodedLines;
  string line;

  while (getline(*input, line)) {
    decodedLines.push(decode(dict, line));
  }
  return decodedLines;
}

// Function to make a dictionary from a file. Takes in a file name.
// Returns a dictionary as an unordered set of strings.
unordered_set<string> makeDictionary(const string &fileName) {
  ifstream file(fileName);
  unordered_set<string> dict;
  string line;
  while (getline(file, line)) {
    transform(line.begin(), line.end(), line.begin(), ::toupper);
    dict.insert(line);
  }
  return dict;
}

// Function to set dictionary path. Takes in path as string.
// Returns string based on presence of path.
string setDictionaryPath(const string path) {
  if (path.empty()) {
    return "wordlist.txt";
  }
  return path;
}

// Function to set input path. Takes in a path as string.
// Returns string based on presence of path.
string setInputPath(const string path) {
  if (path.empty()) {
    return "stdin";
  }
  return path;
}

// Function to set output path. Takes in path as string.
// Returns string based on presence of path.
string setOutputPath(const string path) {
  if (path.empty()) {
    return "stdout";
  }
  return path;
}

// Function to write the output of decoded string in queue. Takes in queue
// holding a decoded string and path of output as string.
void writeToOutput(queue<pair<int, string>> decodedQ, const string output) {
  // write to stdout
  if (output == "stdout") {
    while (!decodedQ.empty()) {
      pair<int, string> front = decodedQ.front();
      cout << front.first << "\t: " << front.second << endl;
      decodedQ.pop();
    }
  } else {
    // write output to file
    ofstream outputFile;
    outputFile.open(output);
    while (!decodedQ.empty()) {
      pair<int, string> front = decodedQ.front();
      outputFile << front.first << ": " << front.second << endl;
    }
    outputFile.close();
  }
}

int main(int argc, char **argv) {
  string dictionaryPath = "wordlist.txt";

  string inputPath = "stdin";
  string outputPath = "stdout";

  for (int i; i < argc; i++) {
    if (strcmp(argv[i], "-d") == 0 | strcmp(argv[i], "-dict") == 0) {
      dictionaryPath = setDictionaryPath(argv[i + 1]);
      continue;
    }
    if (strcmp(argv[i], "-i") == 0 | strcmp(argv[i], "-input") == 0) {
      inputPath = setInputPath(argv[i + 1]);
      continue;
    }
    if (strcmp(argv[i], "-o") == 0 | strcmp(argv[i], "-output") == 0) {
      outputPath = setOutputPath(argv[i + 1]);
      continue;
    }
    if (strcmp(argv[i], "-h") == 0 | strcmp(argv[i], "-help") == 0) {
      cout << "COMP 439 HW1: Caesar Cipher Decoder" << endl;
      cout << " -d | -dict        Location of dictionary containing word list "
              "(default = wordlist.txt)"
           << endl;
      cout << " -i | -input       Input filename. No input defaults to $STDIN"
           << endl;
      cout << " -o | -output      Output filename. No input defaults to $STDOUT"
           << endl;
      cout << " -h | -help        Display this message" << endl;
      return 1;
    }
  }

  // create dictionary
  unordered_set<string> dictionary = makeDictionary(dictionaryPath);

  // decode lines from input
  queue<pair<int, string>> decodedQ =
      decodeLinesFromInput(inputPath, dictionary);

  // output the decoded lines
  writeToOutput(decodedQ, outputPath);
}