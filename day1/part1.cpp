#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int processLine(string line);

int main() {
    int sum = 0;
    string line;
    ifstream input ("part1_input.txt");

    while(getline(input, line)) {
        sum += processLine(line);
    }
    cout << sum << '\n';
    return 0;
}

int processLine(string line) {
    char first = '\0';
    char last = '\0';
    string numberAsString = "\0";
    int number = 0;

    for(int i = 0; i < line.length(); i++) {
        if(line[i] < 48 || line[i] > 57 )
        {
            continue;
        }
        if(!first)
        {
            first = line[i];
        }
        last = line[i];
    }

    numberAsString = first;
    numberAsString += last;
    number = stoi(numberAsString);
    return number;
}