#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sentence = "HI THIS IS BRAIN";
    string *stringPTR = &sentence;
    string &stringREF = sentence;

    cout << "string: " << &sentence << endl;
    cout << "stringPTR: " << stringPTR << endl;
    cout << "stringREF: " << &stringREF << endl;

    cout << "string: " << sentence << endl;
    cout << "stringPTR: " << *stringPTR << endl;
    cout << "stringREF: " << stringREF << endl;
}