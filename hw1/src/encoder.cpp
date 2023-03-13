#include "encoder.h"
#include <CLI/CLI.hpp>

using namespace std;

// int setNumberOfSentences(char *charLines) {
//   int lines = stoi((string)charLines);

//   if (lines <= 0) {
//     return 10;
//   }
//   return lines;
// }

// int setMinimumWordLength(char *charLength) {
//   int length = stoi((string)charLength);
//   if (length <= 0) {
//     return 3;
//   }
//   return length;
// }

// string setDictionaryPath(string path) {
//   if (path.empty()) {
//     return "wordlist.txt";
//   }
//   return path;
// }

// string setOutputPath(string path) {
//   if (path.empty()) {
//     return "stdout";
//   }
//   return path;
// }

set<string> loadDictionary(string dictionaryPath, int minimumWordLength) {
  // https://cplusplus.com/doc/tutorial/files/
  set<string> data;
  string line;
  ifstream myFile;

  myFile.open(dictionaryPath);

  if (myFile.is_open()) {
    while (getline(myFile, line)) {
      // https://www.geeksforgeeks.org/conversion-whole-string-uppercase-lowercase-using-stl-c/
      transform(line.begin(), line.end(), line.begin(), ::toupper);
      if (line.length() >= minimumWordLength &
          line.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == -1) {
        data.insert(line);
      }
    }
  }

  myFile.close();
  return data;
}

string generateSentence(set<string> dictionary, int shift) {
  random_device rd;
  mt19937 gen(rd());

  uniform_int_distribution<> distr(0, dictionary.size());
  int wordCount = 0;
  int maxWordCount = 10;

  string sentence = "";

  while (wordCount < maxWordCount) {
    int letterIndexer = 0;
    string word = *next(dictionary.begin(), distr(gen));

    while (letterIndexer < word.size()) {
      word[letterIndexer] = word[letterIndexer] + shift;
      if (word[letterIndexer] > 90) {
        int diff = word[letterIndexer] - 26;
        word[letterIndexer] = diff;
      }
      letterIndexer++;
    }
    sentence = sentence + word + " ";
    wordCount++;
  }

  return sentence;
}

void writeToOutput(vector<string> data, string output) {
  if (output == "stdout") {
    for (int i = 0; i < data.size(); i++) {
      cout << data[i] << endl;
    }
  } else {
    ofstream outputFile;
    outputFile.open(output);
    for (string line : data) {
      outputFile << line << endl;
    }
    outputFile.close();
  }
}

int main(int argc, char **argv) {
  srand(time(NULL));

  vector<string> sentences;

  int numberOfSentences = 10;
  int minimumWordLength = 3;
  string dictionaryPath = "wordlist.txt";
  string outputPath = "stdout";

  CLI::App app{"Caesar Cipher Encoder"};

  app.option_defaults()->always_capture_default(true);

  app.add_option("-n,--lines", numberOfSentences,
                 "Number of sentences to generate (default = 10)")
      ->check(CLI::PositiveNumber.description(" >= 10"));

  app.add_option("-l,--length", minimumWordLength,
                 "Minimum word length (default = 3)")
      ->check(CLI::PositiveNumber.description(" >= 3"));

  app.add_option("-d,--dict", dictionaryPath,
                 "Path to dictionary (default = wordlist.txt)");

  app.add_flag("-o,--output", outputPath, "Output path (default = $STDOUT)");

  CLI11_PARSE(app, argc, argv);

  set<string> dictionary = loadDictionary(dictionaryPath, minimumWordLength);

  for (int i; i < numberOfSentences; i++) {
    int shift = rand() % 26;
    sentences.push_back(generateSentence(dictionary, shift));
  }

  writeToOutput(sentences, outputPath);
}
