#include <iostream>
#include <string.h>

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
        return 10;
    }
    return length;
}

string setFilePath(string path) {
    if(path.empty())    {
        return "wordlist.txt";
    }
    return path;
}



int main(int argc, char **argv) {
    int lines = 10;
    int length = 10;
    string path = "wordlist.txt";



    for (int i; i < argc; i++)  {
        if (strcmp(argv[i], "-n") == 0 | strcmp(argv[i], "-lines") == 0)    {
            lines = setLines(argv[i++]);
        }

        if (strcmp(argv[i], "-l") == 0 | strcmp(argv[i], "-length") == 0)
        {
            length = 
        }

        if (strcmp(argv[i], "-d") == 0 | strcmp(argv[i], "-dict") == 0)
        {
            cout << "Test3" << endl;
        }

        if (strcmp(argv[i], "-o") == 0 | strcmp(argv[i], "-output") == 0)
        {
            cout << "Test4" << endl;
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

    return -1;
}
