// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files

#include <string>
#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include "tokenscanner.h"
#include <fstream>
#include "random.h"

using namespace std;

void CountTokens()
{
    string str;
    ifstream infile;
    TokenScanner scanner;

    cout << "Please enter a sentence: ";
    cin >> str;
    scanner.setInput(str);

    int count = 0;
    while (scanner.hasMoreTokens()) {
        scanner.nextToken();
        count++;
    }
    cout << "You entered " << count << " tokens." << endl;
}

Vector<int> MakeRandomVector(int sz)
{
    Vector<int> numbers;
    for (int i = 0; i < sz; i++)
    numbers.add(randomInteger(1, 100));
    return numbers;
}

void PrintVector(Vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
}

int CountLines(ifstream &in)
{
    int count = 0;
    while (true)
    {
        string line;
        getline(in, line);
        if (in.fail()) break;
        count++;
    }
    return count;
}

