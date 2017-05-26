#include "hello.h"
using namespace std;

int main()
{

    //CountTokens();

    /*
    Vector<int> numbers = MakeRandomVector(5);
    PrintVector(numbers);
    */

    string filename = "readme.txt";

    ifstream infile;
    infile.open(filename.data());
    /*
    while (true)
    {
        cout << "Enter name: ";
        string s;
        cin >> s;
        in.open(s.c_str());
        if (!in.fail()) break;
        cout << "Couldn't open file, try again!" << endl;
        in.clear();
    }
    */
    cout << "Num lines = " << CountLines(infile) << endl;

    return 0;
}
