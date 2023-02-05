#include <iostream>
#include <string>

using namespace std;

int main()  {
    int shift;
    string message;

    cout << "What is your shift (ints only)? ";
    cin >> shift;

    cout << "What is your message? ";
    cin.ignore();
    getline(cin, message);

    for (int i; i < message.length(); i++)  {
        char letter = message[i];
        if (letter == 32)   {
            cout << letter;
            continue;
        }

        cout << char(letter + shift);
    }

        return 0;
}
