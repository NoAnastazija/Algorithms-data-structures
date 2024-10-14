#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>     // For measuring execution time

using namespace std;

// Function to display the menu options
void menu() {
    cout << "============================" << endl;
    cout << "=========== MENU ===========" << endl;
    cout << "============================" << endl;
    cout << "1....GENERIRAJ NAKLJUCNO ZAPOREDJE" << endl;
    cout << "2....GENERIRAJ NARASCAJOCE ZAPOREDJE" << endl;
    cout << "3....GENERIRAJ PADAJOCE ZAPOREDJE" << endl;
    cout << "4....IZPIS ZAPOREDJA" << endl;
    cout << "5....PREVERI ALI JE ZAPOREDJE UREJENO" << endl;
    cout << "6....UREDI S HITRIM ALGORITMOM BREZ MEDIANE" << endl;
    cout << "7....UREDI S HITRIM ALGORITMOM Z MEDIANO" << endl;
    cout << "8....UREDI Z DRUGIM ALGORITMOM" << endl;
    cout << "0....KONEC" << endl;
    cout << "============================" << endl;
    cout << "Select: ";
}

// Function to generate a random sequence of given length
void generateRandomSequence(vector<int>& seq, int length) {
    seq.resize(length);
    for (int& x : seq) {
        x = rand() % 1000001; // Random number between 0 and 1000000
    }
}

// Function to generate an ascending sequence of given length
void generateAscendingSequence(vector<int>& seq, int length) {
    seq.resize(length);
    for (int i = 0; i < length; ++i) {
        seq[i] = i + 1;
    }
}

// Function to generate a descending sequence of given length
void generateDescendingSequence(vector<int>& seq, int length) {
    seq.resize(length);
    for (int i = 0; i < length; ++i) {
        seq[i] = length - i;
    }
}

// Function to print the sequence
void printSequence(const vector<int>& seq) {
    for (int x : seq) {
        cout << x << " ";
    }
    cout << endl;
}

// Function to check if the sequence is sorted in non-decreasing order
bool isSorted(const vector<int>& seq) {
    for (size_t i = 1; i < seq.size(); ++i) {
        if (seq[i] < seq[i - 1]) return false;
    }
    return true;
}

// Partition function for QuickSort
int partition(vector<int>& seq, int low, int high) {
    int pivot = seq[low];
    int left = low + 1;
    int right = high;

    while (true) {
        // Move left pointer to the right until it finds an element greater than pivot
        while (left <= right && seq[left] <= pivot) left++;
        // Move right pointer to the left until it finds an element smaller than pivot
        while (left <= right && seq[right] >= pivot) right--;

        // If left and right pointers cross, break the loop
        if (left > right) break;

        // Swap elements at left and right pointers
        swap(seq[left], seq[right]);
    }

    // Swap pivot with the element at the right pointer
    swap(seq[low], seq[right]);

    // Return the partitioning index
    return right;
}

// Recursive function to perform QuickSort
void quickSort(vector<int>& seq, int low, int high) {
    if (low < high) {
        int pi = partition(seq, low, high);
        quickSort(seq, low, pi - 1);
        quickSort(seq, pi + 1, high);
    }
}

// QuickSort function with median pivot
void quickSortWithMedian(vector<int>& seq, int low, int high) {
    if (low < high) {
        int median = low + (high - low) / 2;
        swap(seq[low], seq[median]); // Swap median element with the first element
        int pi = partition(seq, low, high);
        quickSortWithMedian(seq, low, pi - 1);
        quickSortWithMedian(seq, pi + 1, high);
    }
}

// Selection sort algorithm
void selectionSort(vector<int>& seq) {
    for (size_t i = 0; i < seq.size() - 1; ++i) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < seq.size(); ++j) {
            if (seq[j] < seq[minIdx]) {
                minIdx = j;
            }
        }
        swap(seq[i], seq[minIdx]);
    }
}

// Main function
int main() {
    srand(time(0)); // Seed for random number generation

    vector<int> sequence; // Vector to store the sequence of numbers
    int choice;           // Variable to store user's choice
    int length;           // Variable to store sequence length

    while (true) {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Vnesi dolzino zaporedja: ";
                cin >> length;
                generateRandomSequence(sequence, length);
                break;
            case 2:
                cout << "Vnesi dolzino zaporedja: ";
                cin >> length;
                generateAscendingSequence(sequence, length);
                break;
            case 3:
                cout << "Vnesi dolzino zaporedja: ";
                cin >> length;
                generateDescendingSequence(sequence, length);
                break;
            case 4:
                printSequence(sequence);
                break;
            case 5:
                if (isSorted(sequence)) {
                    cout << "Zaporedje je urejeno." << endl;
                } else {
                    cout << "Zaporedje ni urejeno." << endl;
                }
                break;
            case 6: {
                auto start = chrono::high_resolution_clock::now(); // Start time measurement
                quickSort(sequence, 0, sequence.size() - 1);      // Sort using QuickSort
                auto end = chrono::high_resolution_clock::now();   // End time measurement
                cout << "Cas izvajanja hitrega urejanja brez mediane: "
                     << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mikrosekund" << endl;
                break;
            }
            case 7: {
                auto start = chrono::high_resolution_clock::now(); // Start time measurement
                quickSortWithMedian(sequence, 0, sequence.size() - 1); // Sort using QuickSort with median pivot
                auto end = chrono::high_resolution_clock::now();   // End time measurement
                cout << "Cas izvajanja hitrega urejanja z mediano: "
                     << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mikrosekund" << endl;
                break;
            }
            case 8: {
                auto start = chrono::high_resolution_clock::now(); // Start time measurement
                selectionSort(sequence); // Sort using Selection Sort
                auto end = chrono::high_resolution_clock::now();   // End time measurement
                cout << "Cas izvajanja ureditve z izbiranjem: "
                     << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mikrosekund" << endl;
                break;
            }
            case 0:
                return 0; // Exit the program
            default:
                cout << "Napacna izbira!" << endl; // Invalid choice
                break;
        }
    }

    return 0;
}
