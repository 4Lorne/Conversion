#include <iostream>
#include <regex>

#include "../inc/main.h"

using namespace std;

int main() {

    //Variables
    string line;
    string filepath;

    regex findLeft("[<]");
    regex validPathHTML(".?:(\\\\[a-zA-Z 0-9()]*)*.[a-zA-Z]*.(html)"); // https://stackoverflow.com/a/15710561
    regex validPathCPP(".?:(\\\\[a-zA-Z 0-9()]*)*.[a-zA-Z]*.(cpp)");

    ifstream inputFile;
    ofstream outputFile;

    cout << "File paths must have no spaces & conform to Windows file path rules. (ie C:\\Desktop\\input.cpp)" << endl;

    cout << "Enter the desired path of the CPP input file:";
    do { // Validates empty entry and blank space entry
        getline(cin,filepath);
        if (filepath.length() == 0){
            cout << "Enter the desired path of the CPP input file:";
        }
    } while (filepath.empty());

    try {
        setInputFile(inputFile,filepath,validPathCPP);
    } catch(CustomException& e) {
        e.what(); // Programmer defined exception
    }


    cout << "Enter the desired path of the HTML output file:";
    do {
        getline(cin,filepath);
        if (filepath.length() == 0){
            cout << "Enter the desired path of the HTML output file:";
        }
    } while (filepath.empty());

    try {
        setOutputFile(outputFile,filepath,validPathHTML);
    } catch(exception& e){
        e.what(); // Default exception
    }


    try {
        writeFile(inputFile, outputFile, line, findLeft); //Writes from the CPP file to the HTML file
    } catch (bad_exception& e){
        cerr << "Error. Please try again" << e.what() << "\n"; //Library exception
    }


    cout << "Finished writing " << filepath << ".";

    //Closes the two files
    try {
        inputFile.close();
        outputFile.close();
    } catch(exception& e){
        e.what();
    }


    return 0;
}

int setInputFile(ifstream& inputFile, string& filepath, regex &validPathCPP) {
    //Checks if the filepath is a valid Windows file path for input.
    if (!regex_match(filepath, validPathCPP)) {
        cerr << "Enter a valid Windows file path. \nFiles must end in .cpp \n(ie C:\\Desktop\\input.cpp)";
        exit(1);
    }

    //Checks if the CPP file can be located.
    inputFile.open(filepath);
    if (inputFile.fail()) {
        cerr << "Error locating the input file. Please try again.\n(ie C:\\Desktop\\input.cpp)";
        exit(1);
    }

    return 0;
}

int setOutputFile(ofstream& outputFile, string& filepath, regex& validPathHTML){
    //Checks if the filepath is a valid Windows file path for output.
    if (!regex_match(filepath, validPathHTML)) {
        cerr << "Enter a valid Windows file path. \nFiles must end in .html \n(ie C:\\Desktop\\output.html)";
        exit(1);
    }
    //Checks if the HTML file can be written to
    outputFile.open(filepath);
    if (outputFile.fail()) {
        cerr << "Error writing the file. Please try again with a valid Windows file path. \n(ie C:\\Desktop\\output.html)";
        exit(1);
    }

    return 0;
}

int writeFile(ifstream& inputFile, ofstream& outputFile, string line, regex& findLeft){
    outputFile << "<pre>"; // Adds the html tag pre to the beginning of the file
    while (inputFile.peek() != EOF) {     //Reads the file line by line, checks for occurrences of <
        while (std::getline(inputFile, line)) {
            string temp;
            regex_replace(back_inserter(temp), line.begin(), line.end(), findLeft, "&lt");
            outputFile << temp << endl;
        }
    }
    outputFile << "</pre>"; // Closes the html tag pre at the end of the file.

    return 0;
}