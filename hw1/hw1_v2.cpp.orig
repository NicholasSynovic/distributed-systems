#include <iostream>
#include <fstream>
#include <string.h>
#include <set>
#include <algorithm>

using namespace std;

int setLines(char* charLines) {
    int lines = stoi((string)charLines);

    if(lines <= 0)  {
        return 10;
    }
    return lines;
}

int setLength(char* charLength)
{
    int length = stoi((string)charLength);
    if (length <= 0)
    {
        return 3;
    }
    return length;
}

string setFilePath(string path)
{
    if(path.empty())    {
        return "wordlist.txt";
    }
    return path;
}

string setOutputPath(string path)
{
    if (path.empty())
    {
        return "stdout";
    }
    return path;
}

set<string> loadFile(string path, int wordLength)   {
    // https://cplusplus.com/doc/tutorial/files/
    set<string> data;
    string line;
    ifstream myFile;
    myFile.open(path);

    if(myFile.is_open())    {
        while(getline(myFile, line))    {
            if(line.length() >= wordLength & line.find_first_not_of("abcdefghijklmnop") == 0)   {
                // https://www.geeksforgeeks.org/conversion-whole-string-uppercase-lowercase-using-stl-c/
                transform(line.begin(), line.end(), line.begin(), ::toupper);
                data.insert(line);
            }
        }
    }

    myFile.close();
    return data;
}

int main(int argc, char **argv) {
    int lines = 10;
    int length = 3;
    string dictPath = "wordlist.txt";
    string outputPath = "stdout";

    for (int i; i < argc; i++)  {
        if (strcmp(argv[i], "-n") == 0 | strcmp(argv[i], "-lines") == 0)    {
            lines = setLines(argv[i + 1]);
            continue;
        }

        if (strcmp(argv[i], "-l") == 0 | strcmp(argv[i], "-length") == 0)
        {
            length = setLength(argv[i + 1]);
            continue;
        }

        if (strcmp(argv[i], "-d") == 0 | strcmp(argv[i], "-dict") == 0)
        {
            dictPath = setFilePath(argv[i + 1]);
            continue;
        }

        if (strcmp(argv[i], "-o") == 0 | strcmp(argv[i], "-output") == 0)
        {
            outputPath = setOutputPath(argv[i + 1]);
            continue;
        }
        if (strcmp(argv[i], "-h") == 0 | strcmp(argv[i], "-help") == 0)
        {
            cout << "COMP 439 HW 1: Ceasar Cipher Encoder" << endl;
            cout << " -n | -lines       Number of lines to generate (default = 10)" << endl;
            cout << " -l | -length      Minimum word length (default = 3)" << endl;
            cout << " -d | -dict        Location of dictionary containing the word list (default = wordlist.txt)" << endl;
            cout << " -o | -output      Output filename. No input defaults to $STDOUT" << endl;
            cout << " -h | -help        Display this message" << endl;
            return 1;
        }
    }
    set<string> data = loadFile(dictPath, length);
}
