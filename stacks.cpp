#include <iostream>
#include <stack>
using namespace std;


void menu() {
    cout << "============================" << endl;
    cout << "=========== MENU ===========" << endl;
    cout << "============================" << endl;
    cout << "2....MOVE ELEMENT FROM 1 TO 2" << endl;
    cout << "3....MOVE ELEMENT FROM 1 TO 3" << endl;
    cout << "4....MOVE ELEMENT FROM 2 TO 1" << endl;
    cout << "5....MOVE ELEMENT FROM 2 TO 3" << endl;
    cout << "6....MOVE ELEMENT FROM 3 TO 1" << endl;
    cout << "7....MOVE ELEMENT FROM 3 TO 2" << endl;
    cout << "0....EXIT" << endl;
    cout << "============================" << endl;
    cout << "Select: ";
}

void printStacks(int velikost, stack<int>& s1, stack<int>& s2, stack<int>& s3) {
    /// Before :)))))
    // // Output from bottom to top
    //    cout<<"Stack 1: ";
    //    while(!temp.empty()){
    //        cout << temp.top() << " ";
    //        temp.pop();
    //    }
    //    cout<<endl;
    //
    //    cout<<"Stack 2: ";
    //    while(!temp2.empty()){
    //        cout << temp2.top() << " ";
    //        temp2.pop();
    //    }
    //    cout<<endl;
    //
    //    cout<<"Stack 3: ";
    //    while(!temp3.empty()){
    //        cout << temp3.top() << " ";
    //        temp3.pop();
    //    }
    //    cout<<endl;

    stack<int> temp1 = s1;
    stack<int> temp2 = s2;
    stack<int> temp3 = s3;


    // So it outputs from bottom to top
    // 1. need copy -> write in
    // 2. output
    cout << "Stack 1: ";
    stack<int> reversedStack1;
    while (!temp1.empty()) {
        reversedStack1.push(temp1.top());
        temp1.pop();
    }
    while (!reversedStack1.empty()) {
        cout << reversedStack1.top() << " ";
        reversedStack1.pop();
    }
    cout << endl;


    cout << "Stack 2: ";
    stack<int> reversedStack2;
    while (!temp2.empty()) {
        reversedStack2.push(temp2.top());
        temp2.pop();
    }
    while (!reversedStack2.empty()) {
        cout << reversedStack2.top() << " ";
        reversedStack2.pop();
    }
    cout << endl;


    cout << "Stack 3: ";
    stack<int> reversedStack3;
    while (!temp3.empty()) {
        reversedStack3.push(temp3.top());
        temp3.pop();
    }
    while (!reversedStack3.empty()) {
        cout << reversedStack3.top() << " ";
        reversedStack3.pop();
    }
    cout << endl;
}


void moveElement(stack<int>& source, stack<int>& destination) {
    /// Modified from this code made previously
    //  // Check if stack we are getting element from is not empty
    //    if (!s1.empty()) {
    //        // Compare stacks
    //        if (s2.empty() || s1.top() < s2.top()) {
    //            // Moving the top
    //            s2.push(s1.top());
    //            s1.pop();
    //        } else {
    //            cout << "Ni mozno nastavljati iz vecje na manjso vrednost" << endl;
    //
    //        }
    //    } else {
    //        cout << "Stack 1 je prazen" << endl;
    //
    //    }
    if (!source.empty() && (destination.empty() || source.top() < destination.top())) {
        destination.push(source.top());
        source.pop();
    } else {
        cout << "Cant move on smaller element" << endl;
    }
}

void move1to2(int& velikost, stack<int>& s1, stack<int>& s2, stack<int>& s3) {
    moveElement(s1, s2);
}

void move1to3(int& velikost, stack<int>& s1, stack<int>& s2, stack<int>& s3) {
    moveElement(s1, s3);
}

void move2to1(int& velikost, stack<int>& s1, stack<int>& s2, stack<int>& s3) {
    moveElement(s2, s1);
}

void move2to3(int& velikost, stack<int>& s1, stack<int>& s2, stack<int>& s3) {
    moveElement(s2, s3);
}

void move3to1(int& velikost, stack<int>& s1, stack<int>& s2, stack<int>& s3) {
    moveElement(s3, s1);
}

void move3to2(int& velikost, stack<int>& s1, stack<int>& s2, stack<int>& s3) {
    moveElement(s3, s2);
}

bool isSolved(stack<int>& s2, stack<int>& s3, int velikost) {
    /// Before i killed my entire program :)))
    // // Check if the game is solved or not
    //    stack<int> tempStack1= s1;
    //    stack<int> tempStack3 = s3;
    //
    //    // Checking for for loop
    //    bool solved = true;
    //
    //        for (int i = 1; i <= velikost; ++i) {
    //            if (tempStack3.empty() || i != tempStack3.top()) {
    //                solved = false;
    //                break;
    //            }
    //            // if it matches
    //            tempStack3.pop();
    //        }
    //
    //
    //    if (solved == true) {
    //        cout << "Cestitke!!" << endl;
    //        // so our menu stops as well
    //        podatek = 1;
    //    }
    stack<int> tempStack2 = s2;
    stack<int> tempStack3 = s3;

    // Stack2
    bool solvedStack2 = true;
    for (int i = 1; i <= velikost; ++i) {
        if (tempStack2.empty() || i != tempStack2.top()) {
            solvedStack2 = false;
            break;
        }
        tempStack2.pop();
    }

    // Stack3
    bool solvedStack3 = true;
    for (int i = 1; i <= velikost; ++i) {
        if (tempStack3.empty() || i != tempStack3.top()) {
            solvedStack3 = false;
            break;
        }
        tempStack3.pop();
    }

    // Return true if stack2 or stack3 is solved
    return solvedStack2 || solvedStack3;
}

int main() {
    int value = 0;
    int size;
    stack<int> s1;
    stack<int> s2;
    stack<int> s3;

    cout << "Enter the number of elements: ";
    cin >> size;
    cout << endl;

    for (int i = size; i > 0; i--) {
        s1.push(i);
    }

    printStacks(size, s1, s2, s3);

    bool running = true;
    int selection;
    do {
        menu();
        cin >> selection;

        switch (selection) {
            case 2:
                move1to2(size, s1, s2, s3);
                break;
            case 3:
                move1to3(size, s1, s2, s3);
                break;
            case 4:
                move2to1(size, s1, s2, s3);
                break;
            case 5:
                move2to3(size, s1, s2, s3);
                break;
            case 6:
                move3to1(size, s1, s2, s3);
                break;
            case 7:
                move3to2(size, s1, s2, s3);
                break;
            case 0:
                cout << "Exiting" << endl;
                break;
            default:
                cout << "That is not a valid option" << endl;
                break;
        }

        printStacks(size, s1, s2, s3);

        // if(podatek == 1 || selection == 0){
        //            running = false;
        //        }
        //        cout << endl;
        if (isSolved(s2, s3, size)) {
            cout << "Congratulations!!" << endl;
            running = false;
        }

        cout << endl;
    } while (running);

    return 0;
}