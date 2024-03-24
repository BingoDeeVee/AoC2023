#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string numberWords[10] = 
{
    "zero",
    "one",
    "two",
    "three",
    "four", 
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};
int getFirstNumber(string line);
int getSecondNumber(string line);
int testSubString(string numberWord);

int main () 
{
    string line;
    ifstream input ("part2_input.txt");
    int sum = 0;

    while(getline(input, line)) {
        int firstNumber = getFirstNumber(line) * 10;
        int secondNumber = getSecondNumber(line);
        int combinedNumber = firstNumber + secondNumber;
        sum += combinedNumber;
    }
    cout << sum; 
    return 0;
}

int getFirstNumber(string line) {
    int number = 0;
    string unmatchedLetters = "\0";
    int foundNumber = 0;

    for (int i = 0; i < line.length(); i++) {
        if(line[i] > 48 && line[i] < 58 ) {
            return line[i] - 48;
        }

        unmatchedLetters += line[i];
        foundNumber = testSubString(unmatchedLetters);
        if (foundNumber)
        {
            break;
        }
        
    }
    return foundNumber;
}

int getSecondNumber(string line) {
    int number = 0;
    string unmatchedLetters = "\0";
    int foundNumber = 0;

    for (int i = line.length() - 1; i > -1; i--) {
        if(line[i] > 48 && line[i] < 58 ) {
            return line[i] - 48;
        }

        unmatchedLetters.insert(0, 1, line[i]);
        foundNumber = testSubString(unmatchedLetters);
        if (foundNumber)
        {
            break;
        }
        
    }
    return foundNumber;
}

int testSubString(string testString) {
    for(int i = 0; i < 10; i++){
        if (testString.find(numberWords[i]) != std::string::npos) {
           return i; 
        }
    }
    return 0;
}