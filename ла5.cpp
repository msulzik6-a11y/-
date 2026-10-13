#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

int main() {
  

    string input_path, output_path_1, output_path_2;

    cout << "Enter the path to the input file: ";
    getline(cin, input_path);

    cout << "Enter the path to the first output file (for round brackets): ";
    getline(cin, output_path_1);

    cout << "Enter the path to the second output file (for square brackets): ";
    getline(cin, output_path_2);

    
    ifstream f_in(input_path);
    if (!f_in.is_open()) {
        cerr << "Error: Failed to open the input file!" << endl;
        return 1;
    }


    regex pattern_round(R"(\([^()]*\S[^()]*\))");
    regex pattern_square(R"(\[[^\[\]]*\S[^\[\]]*\])");

    vector<string> lines_round;
    vector<string> lines_square;
    string line;

    
    while (getline(f_in, line)) {
        if (regex_search(line, pattern_round)) {
            lines_round.push_back(line);
        }
        if (regex_search(line, pattern_square)) {
            lines_square.push_back(line);
        }
    }
    f_in.close();

    ofstream f_out1(output_path_1);
    if (!f_out1.is_open()) {
        cerr << "Error: Failed to create the first output file!" << endl;
        return 1;
    }
    for (const auto& l : lines_round) {
        f_out1 << l << endl;
    }
    f_out1.close();

    ofstream f_out2(output_path_2);
    if (!f_out2.is_open()) {
        cerr << "Error: Failed to create the second output file!" << endl;
        return 1;
    }
    for (const auto& l : lines_square) {
        f_out2 << l << endl;
    }
    f_out2.close();

    cout << "Processing completed successfully!" << endl;
    return 0;
}