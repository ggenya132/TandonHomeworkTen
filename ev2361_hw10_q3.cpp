#include <iostream>
#include <vector>
using namespace std;

// Version 1: Without using `vector`
void main1() {
    cout << "Please enter a sequence of positive integers, each in a separate "
            "line.\n";
    cout << "End your input by typing -1.\n";

    int *sequence = new int[1000];  // Start with an initial capacity of 1000
    int capacity = 1000;
    int count = 0;
    int num;

    // Collect the sequence of numbers
    while (true) {
        cin >> num;
        if (num == -1) break;

        if (count == capacity) {
            // Resize the array when the capacity is reached
            capacity *= 2;
            int *newSequence = new int[capacity];
            for (int i = 0; i < count; i++) {
                newSequence[i] = sequence[i];
            }
            delete[] sequence;
            sequence = newSequence;
        }

        sequence[count++] = num;  // Store the number in the array
    }

    cout << "Please enter a number you want to search.\n";
    int searchNum;
    cin >> searchNum;

    // Search the sequence
    bool found = false;
    cout << searchNum << " shows in lines";

    for (int i = 0; i < count; i++) {
        if (sequence[i] == searchNum) {
            if (!found) {
                found = true;
            }
            cout << " " << i + 1 << ",";
        }
    }

    if (found) {
        cout << "\b." << endl;  // Remove trailing comma and add period.
    } else {
        cout << searchNum << " does not show at all in the sequence." << endl;
    }

    // Free the dynamically allocated memory
    delete[] sequence;
}

// Version 2: Using `vector`
void main2() {
    cout << "Please enter a sequence of positive integers, each in a separate "
            "line.\n";
    cout << "End your input by typing -1.\n";

    vector<int> numbers;  // Vector to dynamically store the sequence
    int num;

    // Collect the sequence of numbers
    while (true) {
        cin >> num;
        if (num == -1) break;
        numbers.push_back(num);  // Append each number to the vector
    }

    cout << "Please enter a number you want to search.\n";
    int searchNum;
    cin >> searchNum;

    // Search the sequence
    bool found = false;
    cout << searchNum << " shows in lines";

    for (size_t i = 0; i < numbers.size(); i++) {
        if (numbers[i] == searchNum) {
            cout << " " << i + 1 << ",";
            found = true;
        }
    }

    if (found) {
        cout << "\b." << endl;  // Remove trailing comma and add period.
    } else {
        cout << searchNum << " does not show at all in the sequence." << endl;
    }
}

int main() {
    cout << "Running main1():" << endl;
    main1();

    cout << "\nRunning main2():" << endl;
    main2();

    return 0;
}
