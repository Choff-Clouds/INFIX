#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void removeEndline(string& line) {
    if (!line.empty() && line[line.length() - 1] == '\r') {
        line.erase(line.length() - 1);
    }
}

int main(int argc, char *argv[i]) {
    ifstream inFile(arg[1]);
    ofstream outFile(arg[2]);

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
        removeEndline(line);
        line = line.substr(0, line.size() - 1); // remove the end period
        line = line.substr(line.find(" ") + 1); // remove the line number
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();

    inFile.open("answersFromBot.txt");
    outFile.open("answersFromBot_clean.txt");

    if (!inFile) {
        cerr << "Unable to open input file";
        return 1;
    }

    if (!outFile) {
        cerr << "Unable to open output file";
        return 1;
    }

    while (getline(inFile, line)) {
        removeEndline(line);
        line = line.substr(0, line.size() - 1); // remove the end period
        line = line.substr(line.find(" ") + 1); // remove the line number
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}
