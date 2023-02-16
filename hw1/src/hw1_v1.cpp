#include <iostream>
#include <string>

using namespace std;

int shiftLetter(char letter, int shift)
{
    if (letter == 32)
    {
        return letter + 0;
    }
    return letter + shift;
}

int main()
{
    int shift;
    string message;

    cout << "What is your shift (ints only)? ";
    cin >> shift;

    cout << "What is your message? ";
    cin.ignore();
    getline(cin, message);

    for (int i; i < message.length(); i++)
    {
        char encryptedLetter = char(shiftLetter(message[i], shift));
        cout << encryptedLetter;
    }

    return 0;
}
