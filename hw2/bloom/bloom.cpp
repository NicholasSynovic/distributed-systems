#include <CLI/CLI.hpp>
#include <cmath>
#include <iostream>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <string>
#include <vector>

using namespace std;

class Bloom_Filter {
public:
  // Constructor
  Bloom_Filter(int num_bits, int num_hash_funcs)
      : // intializer list allows custom setting of vector<bool> data
        num_bits(num_bits), num_hash_funcs(num_hash_funcs), num_inserts(0),
        data(num_bits) {}

  // method to insert an element into the bloom filter
  void insert(string element) {
    if (num_hash_funcs == 1) {
      int hash1 = hash_f_1(element) % num_bits;
      data[hash1] = true;
    } else if (num_hash_funcs == 2) {
      int hash1 = hash_f_1(element) % num_bits;
      int hash2 = hash_f_2(element) % num_bits;
      data[hash1] = true;
      data[hash2] = true;
    }
    num_inserts++;
  }

  // method to search for an element in the bloom filter
  double search(string element) {
    if (num_hash_funcs == 1) {
      int hash1 = hash_f_1(element) % num_bits;
      if (!data[hash1]) {
        return -1.0;
      }
    } else if (num_hash_funcs == 2) {
      int hash1 = hash_f_1(element) % num_bits;
      int hash2 = hash_f_2(element) % num_bits;
      if (!data[hash1] || !data[hash2]) {
        return -1.0;
      }
    }
    double prob =
        pow(1.0 - pow(1.0 - 1.0 / num_bits, num_hash_funcs * num_inserts),
            num_hash_funcs);
    return prob;
  }

  // method to return bloom filter's data as a string
  string get_data() {
    string data_str = "[";
    for (int i = 0; i < num_bits; i++) {
      data_str += to_string(data[i]);
      if (i != num_bits - 1) {
        data_str += ", ";
      } else {
        data_str += "]";
      }
    }
    return data_str;
  }

private:
  int num_bits;
  int num_hash_funcs;
  vector<bool> data;
  int num_inserts;

  int hash_f_1(string word) {
    unsigned char md[MD5_DIGEST_LENGTH];
    MD5((unsigned char *)word.c_str(), word.size(), md);
    hash<string> str_hash;
    string str_md(reinterpret_cast<const char *>(md), MD5_DIGEST_LENGTH);
    return str_hash(str_md.substr(0, 6)) % 10;
  }

  int hash_f_2(string word) {
    unsigned char md[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)word.c_str(), word.size(), md);
    hash<string> str_hash;
    string str_md(reinterpret_cast<const char *>(md), SHA256_DIGEST_LENGTH);
    return str_hash(str_md.substr(0, 6)) % 10;
  }
};

int main(int argc, char **argv) {

  int numberOfBits = 10;
  int numberOfHashFunctions = 1;
  string dictionaryPath = "wordlist.txt";

  CLI::App app{"Bloom Filter Implementation"};
  app.option_defaults()->always_capture_default(true);

  app.add_option("-b,--number-of-bits", numberOfBits,
                 "Number of bits to allocate to the bit vector")
      ->check(CLI::PositiveNumber.description(" >0"));

  app.add_option("-f,--number-of-hash-functions", numberOfHashFunctions,
                 "Number of functions to hash the data")
      ->check(CLI::PositiveNumber.description(" >0"));
  app.add_option("-d,--dict", dictionaryPath,
                 "Path to dictionary (default = wordlist.txt)");
  CLI11_PARSE(app, argc, argv);

  Bloom_Filter bf1(numberOfBits, numberOfHashFunctions);
  bf1.insert("Hello");
  cout << bf1.get_data() << endl;
  cout << bf1.search("Hello") << endl;
  cout << bf1.search("No Way") << endl;
  cout << bf1.search("ge") << endl;

  return 0;
}