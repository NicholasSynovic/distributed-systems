#include "decoder.h"
#include "encoder.h"

// Erik attempt (unfinished)
// Feel free to comment out
int main(int argc, char **argv) {
  // std::cout << "Hello Universe" << std::endl;
  std::unordered_set<std::string> dictionary =
      makeDictionary("/home/runner/Caesar-Cipher-1-comp-339-439-ds-8/include/"
                     "10000mostCommonEnglishWords.txt");
  std::queue<std::string> decodedQ =
      decodeLinesFromFile("/home/runner/Caesar-Cipher-1-comp-339-439-ds-8/"
                          "include/encodedTestFile.txt",
                          dictionary);

  while (!decodedQ.empty()) {
    std::cout << decodedQ.front() << std::endl;
    decodedQ.pop();
  }
}