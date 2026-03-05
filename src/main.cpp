#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace std;

int search(string digits, string target) {

    for (int i = 0; i <=digits.length() - target.length(); i++){
        if (digits.substr(i, target.length()) == target){
            return i;
        }
    }
    return -1;
}

string loadDigits(string filename){
    ifstream file(filename);
    string digits, line;

    if (!file) {
        cout << "Error opening file.\n";
        return "";
    }
    while (getline(file, line)) {
        digits += line;
    }

    file.close();
    return digits;
}

int main(){

    string digits = loadDigits(".../data/digits.txt");

    string query;

    cout << "Enter your birthday: ";
    cin >> query;

    int index = search(digits, query);

    if (index != -1)
        cout << "Sequence found at index: " << index << endl;
    else
        cout << "Sequence not found within the first million digits of e.\n";

    return 0;
}