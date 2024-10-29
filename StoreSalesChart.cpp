#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    unsigned int StoreNum;
    long long int Sales_Value;
    string input_File;

    cout << "Please enter the input file name." << endl;
    cin >> input_File;

    ifstream input_file(input_File);
    ofstream output_file("saleschart.txt");

    if (!input_file) {
        cout << "\"" << input_File << "\" could not be opened." << endl;
        return 1;
    }
    
    if (!output_file) {
        cout << "Could not write to this file :(" << endl;
        input_file.close();
        return 1;
    }

    bool validData = false;

    while (input_file >> StoreNum >> Sales_Value) {
        if (StoreNum < 1 || StoreNum > 99) {
            cout << StoreNum << " is not in the range 1 through 99." << endl;
            continue;
        }

        if (Sales_Value < 0) {
            cout << "Skipped store #" << StoreNum << "." << endl;
            continue;
        }

        if (!validData) {
            output_file << "SALES BAR CHART\n";
            output_file << "(Each * equals 5,000 dollars)\n";
            validData = true;
        }

        long long stars = Sales_Value / 5000;

        output_file << "Store " << (StoreNum < 10 ? " " : "") << StoreNum << ": ";
        for (long long i = 0; i < stars; i++) {
            output_file << "*";
        }
        output_file << endl;
    }

    input_file.close();
    output_file.close();
    return 0;
}
