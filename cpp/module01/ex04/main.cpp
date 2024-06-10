#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

void replace(string line, string s1, string s2, ofstream &outfile)
{
    string newline;
    int pos = line.find(s1);
    int i;
    for (i = 0; i < pos; i++)
        newline += line[i];
    i += s1.size();
    newline += s2;
    for (i; line[i + 1] != '\0'; i++)
        newline += line[i];
        
    outfile << newline << endl;
    cout << newline << endl;
}

int main(int argc, char **argv)
{
    string newline;
    string s1 = argv[2];
    string s2 = argv[3];
    if (argc != 4)
    {
        cout << "wrong number of arguments" << endl;
        return 0;
    }
    ifstream file(argv[1]);
    if (!file)
    {
        cout << "file not found" << endl;
        return 0;
    }
    ofstream  outfile("output.txt");
    int i = 0;
    while (getline(file, newline) )
    {
        if (newline.find(s1) != string::npos)
            replace(newline, s1, s2, outfile);
        else
            outfile << newline << endl;
        i++;
    }
    cout << i << endl;
    outfile.close();
    file.close();

}