#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream inFile(argv[1]);
    ofstream outFile("output.txt");

    if (!inFile) {
        cerr << "Unable to open input file";
        return 1;
    }

    if (!outFile) {
        cerr << "Unable to open output file";
        return 1;
    }

    string line;

    while (getline(inFile, line)) {
        size_t spacePos = line.find(' ');
        if(spacePos != string::npos)
        {
         line.erase(0, spacePos + 1);   
        }
        while(!line.empty() && line.back() == '.')
        {
         line.pop_back();   
        }
        cout << line << endl;
    }

    inFile.close();
    outFile.close();

    
    return 0;
}
