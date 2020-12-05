#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string line;
    ifstream myfile("test_copy_1.txt");
    vector<string> vec;
    string findWord = "court";
    string inputWord = "AAAAAA";
    if (myfile.is_open())
    {
        getline(myfile, line);
        myfile.close();

        vector<char> file_read(line.begin(), line.end());
        file_read.push_back('\0');
        char* ptr = &file_read[0];
        char* words = strtok(ptr," ");
        //cout << words <<endl;
        int count = 0;
        while (words != NULL) {
            if (!strcmp(words, findWord.c_str()) ) {
                cout << "같자나아아아아ㅏ아앙아아ㅏ앙아" << endl;
                vec.push_back(inputWord.c_str());
            }
            else {
            vec.push_back(words);
            }
            cout << vec[count++] <<"/"<< endl;
            words = strtok(NULL, " ");
        } 
    }
    else {
        cout << "Unable to open file";
    }
    ofstream ofile;
    ofile.open("test_copy_1.txt");
    for (int i = 0; i < vec.size(); i++) {
        ofile << vec[i] + " ";
    }
    ofile.close();
    return 0;
}