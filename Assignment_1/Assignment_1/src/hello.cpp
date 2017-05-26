#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include "hello.h"
using namespace std;

int main() {
    /* #1
    string result;
    string str="Stanford University";
    CensorString1(str,"nt");

    cout << str << endl;

    CensorString2(str,"nt");
    cout << str << endl;
    */

    /* #2
    stat result;
    string filename = "readme.txt";
    result = GetScoresAndStat(filename);
    cout << result.min << endl;
    cout << result.max << endl;
    cout << result.average << endl;
    */

    string filename = "readme.txt";
    CountLetters(filename);

    return 0;
}
