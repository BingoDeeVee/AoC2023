#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
    int sum = 0;
    string line;
    ifstream input ("part1_input.txt");

    while(getline(input, line)) 
    {
        char first = '\0';
        char last = '\0';
        string numberAsString;
        int number;

        for(int i = 0; i < line.length(); i++)
        {
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

        numberAsString += first;
        numberAsString += last;
        number = stoi(numberAsString);
        sum += number;
        first = '\0';
        last = '\0';
    }
    cout << sum << '\n';
    return 0;
}