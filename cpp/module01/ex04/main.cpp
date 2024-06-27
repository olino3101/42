#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

void replace(std::string line, std::string s1, std::string s2, std::ofstream &outfile)
{
    std::string newline;
    int pos;
    int index;
    do
    {
        pos = line.find(s1);
        newline.append(line, 0, pos);
        line.erase(0, pos + s1.size());
        newline += s2;
    } while (line.find(s1) != std::string::npos);
    newline += line;
    outfile << newline << std::endl;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "wrong number of arguments" << std::endl;
        return 0;
    }
    std::string newline;
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream file(argv[1]);
    if (!file)
    {
        std::cout << "file not found" << std::endl;
        return 0;
    }
    std::ofstream  outfile("output.txt");
    int i = 0;
    while (getline(file, newline) )
    {
        if (newline.find(s1) != std::string::npos)
            replace(newline, s1, s2, outfile);
        else
            outfile << newline << std::endl;
        i++;
    }
    std::cout << i << std::endl;
    outfile.close();
    file.close();
}