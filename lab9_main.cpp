#include <iostream>
#include <fstream> 
#include <string> 
using namespace std;

void task1_45(); 
int compare(const char* source, int pos, int len, const char* s); 

void task2_string13(); 
int processString(string input_string); 
bool satisfiesConditions(string input_string, int threshold); 

int main() { // menu
    cout << " " << endl; 
    int task_num; // diclaration
    do {
        cout << " Task number (0 - exit):  ";
        cin >> task_num; 
        if (!cin) { 
            cout << " Ups!" << endl;  // error notification
            continue; 
        }
        switch (task_num) { 
            case 1 : task1_45(); break; // task 1
            case 2 : task2_string13(); break; // task 2
            case 0 : cout << " The program is over!" << endl; break; 
            default : cout << " Wrong task number!" << endl; 
            // output for incorrect numbers
        }
    } while (task_num != 0); // end the program
    return 0; 
}
// task 1
void task1_45() { 
    cout << " ### Task 1 - 45 ### " << endl; 
    string str1 ("wonderful day"); // creating string str1
    const char * str2 = "wonderful day"; // creating a pointer to the string str2
    int comp_res; 
    // comparing part of the string str1 with a given string
    comp_res = str1.compare(10, 4, "day"); 
    if (comp_res == 0) 
        cout << " We need " << str1 << " every day!" << endl; 
        // display a message about string equality
    else
        cout << " Not equal: " << comp_res << endl; 
        // display a message about string inequality
    // comparing part of the string str2 with a given string
    comp_res = compare(str2, 10, 4, "day"); 
    if (comp_res == 0) 
        cout << " We need " << str2 << " every day!" << endl; 
        // display a message about string equality
    else
        cout << " Not equal: " << comp_res << endl;
        // display a message about string inequality

    return; 
}
// function for comparing parts of strings
int compare(const char* source, int pos, int len, const char* s) { 
    for (int i = 0; i < len; i++) { // loop through characters in part of a string
        if (source[pos + i] != s[i]) 
            return source[pos + i] - s[i]; 
            // return the difference between character codes
    }
    return 0; 
}
// task 2
void task2_string13() { 
    cout << " ### Task 2 String13 ### " << endl; 
    
    int threshold; // declaration of a variable for the threshold value
    cout << " Enter the threshold value: "; 
    cin >> threshold; 

    ifstream input_file("input_file.txt"); // opening a file for reading
    ofstream output_file("output_file.txt"); // opening a file for writing

    if (!input_file) { 
        cout << " Could not open input file." << endl; 
        // display an error message
        return; 
    }
    if (!output_file) { 
        cout << " Could not open output file." << endl; 
        // display an error message
        return; 
    }
    // declaration of a variable for a file line
    string line; 
    while (getline(input_file, line)) { 
        if (satisfiesConditions(line, threshold)) { 
            output_file << " Line '" << line << "' satisfies the conditions." << endl; 
            // recording a satisfaction message
        } else {
            output_file << " Line '" << line << "' doesn't satisfy the conditions." << endl; 
            // recording a message about non-fulfillment of conditions
        }
    }

    input_file.close(); // close the file for reading
    output_file.close();// close the file for writing
    cout << " Answer is in the 'output_file.txt' " << endl; 
    // displaying a message about the location of the result
    return; 
}

// function to process a string and count digits
int processString(string input_string) { 
    int digit_count = 0; // declaration of a variable to count digits
    for (char c : input_string) { 
        if (isdigit(c)) { 
            digit_count++; // increasing digit counter
        }
    }
    return digit_count; // return number of digits
}
// function to check a string to see if it meets the conditions
bool satisfiesConditions(string input_string, int threshold) { 
    int digit_count = processString(input_string); // counting the number of digits in a string
    return (digit_count >= threshold); 
    // returning the result of checking for compliance with the threshold value
}
