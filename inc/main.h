//
// Created by Lorne on 2023-01-23.
//

#include <string>
#include <iostream>
#include <regex>
#include <fstream>

#ifndef ASSIGNMENT_MAIN_H
#define ASSIGNMENT_MAIN_H

using namespace std;

struct CustomException : public exception {
public:
    string what()
    {
        return "Error. Please try again.";
    }
} ;

int setInputFile(ifstream& inputFile, string& filepath, regex& validPathCPP);

int setOutputFile(ofstream& outputFile, string& filepath, regex& validPathHTML);

int writeFile(ifstream& inputFile, ofstream& outputFile, string line, regex& findLeft);
#endif //ASSIGNMENT_MAIN_H
