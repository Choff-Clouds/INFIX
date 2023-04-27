#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[i) {
    ifstream inFile(argv[1]);
    ofstream outFile(argv[1]);

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
        line = line.substr(0, line.size() - 1); // remove the end period
        line = line.substr(line.find(" ") + 1); // remove the line number
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}

