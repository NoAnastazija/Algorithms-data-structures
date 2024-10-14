#include <iostream>
#include <stack>

using namespace std;


void menu() {
    cout << "============================" << endl;
    cout << "=========== MENU ===========" << endl;
    cout << "============================" << endl;
   // cout << "1....NASTAVI VELIKOST" << endl;
    cout << "2....PRESTAVI IZ PALICE 1 NA 2" << endl;
    cout << "3....PRESTAVI IZ PALICE 1 NA 3" << endl;
    cout << "4....PRESTAVI IZ PALICE 2 NA 1" << endl;
    cout << "5....PRESTAVI IZ PALICE 2 NA 3" << endl;
    cout << "6....PRESTAVI IZ PALICE 3 NA 1" << endl;
    cout << "7....PRESTAVI IZ PALICE 3 NA 2" << endl;
    cout << "0....IZHOD" << endl;
    cout << "============================" << endl;
    cout << "Select: ";
}

void zacetnoStanje(int& velikost, stack<int>& s1, stack<int>& s2, stack<int>& s3, int& podatek){
    for(int i=velikost; i>0; i--){
        s1.push(i);
    }

    cout<<"Stolp 1: ";
    for(int i=velikost; i>0; i--){
        //s1.top();
        cout<<i<<" ";
    }

    cout<<endl;

    /*for(int i=velikost; i>0; i--){
        s2.push(i);
    }*/

    cout<<"Stolp 2: ";
    //s1.top();
    cout<<0<<" ";

    cout<<endl;

    /*for(int i=velikost; i>0; i--){
        s3.push(i);
    }

     */
    cout<<"Stolp 3: ";
    //s1.top();
    cout<<0<<" ";

    cout<<endl;
}


// Popravi, kopijo se uporabi pri izpisovanju ig
void prestavi1na2(int& velikost, stack<int>& s1, stack<int>& s2, stack<int>& s3, int& podatek){
   // infinitive loop while(!s1.empty()) {

    stack<int> temp = s1;
    stack<int> temp2 = s2;
    stack<int> temp3 = s3;

    // Check if stack we are getting element from is not empty
    if (!s1.empty()) {
        // Compare stacks
        if (s2.empty() || s1.top() < s2.top()) {
            // Moving the top
            s2.push(s1.top());
            s1.pop();
        } else {
            cout << "Ni mozno nastavljati iz vecje na manjso vrednost" << endl;

        }
    } else {
        cout << "Stack 1 je prazen" << endl;

    }


    // Output using copies
    // Since we are returnign from bottom to top we do not want to change our order
    // to avoid changing our order we make copy so our original stacks dont get modified
    // We do same for each

    // Copy to temporary stack
    // we commented this out because we would empty s1 in the process that is why i had trouble later on while calling
    // this cfunction because it kept saaying the stack was emptty even tho it was not
    // instead i used this approach stack<int> temp = s1;
   /* while(!s1.empty()){
        temp.push(s1.top());
        s1.pop();
    }*/


    // Output from bottom to top
    cout<<"Stack 1: ";
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout<<endl;


    /*while(!s2.empty()){
        temp2.push(s2.top());
        s2.pop();
    }*/
    cout<<"Stack 2: ";
    while(!temp2.empty()){
        cout << temp2.top() << " ";
        temp2.pop();
    }
    cout<<endl;

    /*
    while(!s3.empty()){
        temp3.push(s3.top());
        s3.pop();
    }*/

    cout<<"Stack 3: ";
    while(!temp3.empty()){
        cout << temp3.top() << " ";
        temp3.pop();
    }
    cout<<endl;


    //Here i tried to combine the moving the elements and checking if the game has been solved
/*
    bool solved = false;
    if(!temp.empty()) {
        if (temp.top() != temp2.top()) {
            if (s1.top() < s2.top()) {
                s2.push(s1.top());
                s1.pop();
            } else if (s1.top() > s2.top()) {
                cout << "Ni mozno prestaviti iz vecjega na manjsega" << endl;
            }
        } else if (temp.top() == temp2.top()) {
            for (int i = 1; i < velikost; i++) {
                if (temp.top() == temp2.top()) {
                    temp.pop();
                    temp2.pop();
                    solved = true;
                }
                else if(temp.top() != temp2.top()){
                    solved = false;
                }
            }

        }
        else{
            cout<<"Stack 1 je prazen"<<endl;
        }*/

    // Check if the game is solved or not
    stack<int> tempStack1= s1;
    stack<int> tempStack2 = s2;

    // Checking for for loop
    bool solved = true;


        for (int i = 1; i <= velikost; ++i) {
            if (tempStack2.empty() || i != tempStack2.top()) {
                solved = false;
                break;
            }
            // if it matches
            tempStack2.pop();
        }


    if (solved == true) {
        cout << "Cestitke!!" << endl;
        // so our menu stops as well
        podatek = 1;
    }

    // Here i tried different approach to checing comparissin but menu woulndt display no more
   // bool solved = false;
  /* int solved = 0;

    for(int i=1; i<=velikost;){
        if(tempStack2.empty() || i == tempStack2.top()){
            i++;
            tempStack2.pop();
            solved = 1;
        }
        else if(i != tempStack2.top()){
            solved = 0;
        }
    }

    if(solved == 1){
        cout<<"Cestitke!!"<<endl;
        podatek = 1;
    }*/

}

void prestavi1na3(int& velikost, stack<int>& s1, stack<int>& s2, stack<int>& s3, int& podatek){
    stack<int> temp = s1;
    stack<int> temp2 = s2;
    stack<int> temp3 = s3;

    // Check if stack we are getting element from is not empty
    if (!s1.empty()) {
        // Compare stacks
        if (s3.empty() || s1.top() < s3.top()) {
            // Moving the top
            s3.push(s1.top());
            s1.pop();
        } else {
            cout << "Ni mozno nastavljati iz vecje na manjso vrednost" << endl;

        }
    } else {
        cout << "Stack 1 je prazen" << endl;

    }

    // Output from bottom to top
    cout<<"Stack 1: ";
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout<<endl;

    cout<<"Stack 2: ";
    while(!temp2.empty()){
        cout << temp2.top() << " ";
        temp2.pop();
    }
    cout<<endl;

    cout<<"Stack 3: ";
    while(!temp3.empty()){
        cout << temp3.top() << " ";
        temp3.pop();
    }
    cout<<endl;

    // Check if the game is solved or not
    stack<int> tempStack1= s1;
    stack<int> tempStack3 = s3;

    // Checking for for loop
    bool solved = true;

        for (int i = 1; i <= velikost; ++i) {
            if (tempStack3.empty() || i != tempStack3.top()) {
                solved = false;
                break;
            }
            // if it matches
            tempStack3.pop();
        }


    if (solved == true) {
        cout << "Cestitke!!" << endl;
        // so our menu stops as well
        podatek = 1;
    }

}
void prestavi2na1(int& velikost, stack<int>& s1, stack<int>& s2, stack<int>& s3, int& podatek){
    stack<int> temp = s1;
    stack<int> temp2 = s2;
    stack<int> temp3 = s3;

    // Check if stack we are getting element from is not empty
    if (!s2.empty()) {
        // Compare stacks
        if (s1.empty() || s2.top() < s1.top()) {
            // Moving the top
            s1.push(s2.top());
            s2.pop();
        } else {
            cout << "Ni mozno nastavljati iz vecje na manjso vrednost" << endl;

        }
    } else {
        cout << "Stack 2 je prazen" << endl;

    }

    // Output from bottom to top
    cout<<"Stack 1: ";
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout<<endl;

    cout<<"Stack 2: ";
    while(!temp2.empty()){
        cout << temp2.top() << " ";
        temp2.pop();
    }
    cout<<endl;

    cout<<"Stack 3: ";
    while(!temp3.empty()){
        cout << temp3.top() << " ";
        temp3.pop();
    }
    cout<<endl;

    // Check if the game is solved or not
    stack<int> tempStack1= s1;
    stack<int> tempStack2 = s2;

    // Checking for for loop
    bool solved = true;


        for (int i = 1; i <= velikost; ++i) {
            if (tempStack1.empty() || i != tempStack1.top()) {
                solved = false;
                break;
            }
            // if it matches
            tempStack1.pop();
        }


    if (solved == true) {
        cout << "Cestitke!!" << endl;
        // so our menu stops as well
        podatek = 1;
    }

}
void prestavi2na3(int& velikost, stack<int>& s1, stack<int>& s2, stack<int>& s3, int& podatek){
    stack<int> temp = s1;
    stack<int> temp2 = s2;
    stack<int> temp3 = s3;

    // Check if stack we are getting element from is not empty
    if (!s2.empty()) {
        // Compare stacks
        if (s3.empty() || s2.top() < s3.top()) {
            // Moving the top
            s3.push(s2.top());
            s2.pop();
        } else {
            cout << "Ni mozno nastavljati iz vecje na manjso vrednost" << endl;

        }
    } else {
        cout << "Stack 2 je prazen" << endl;

    }

    // Output from bottom to top
    cout<<"Stack 1: ";
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout<<endl;

    cout<<"Stack 2: ";
    while(!temp2.empty()){
        cout << temp2.top() << " ";
        temp2.pop();
    }
    cout<<endl;

    cout<<"Stack 3: ";
    while(!temp3.empty()){
        cout << temp3.top() << " ";
        temp3.pop();
    }
    cout<<endl;

    // Check if the game is solved or not
    stack<int> tempStack2= s2;
    stack<int> tempStack3 = s3;
    stack<int> tempStack1 = s1;

    // Checking for for loop
    bool solved = true;


        for (int i = 1; i <= velikost; ++i) {
            if (tempStack3.empty() || i != tempStack3.top()) {
                solved = false;
                break;
            }
            // if it matches
            tempStack3.pop();
        }


    if (solved == true) {
        cout << "Cestitke!!" << endl;
        // so our menu stops as well
        podatek = 1;
    }

}
void prestavi3na1(int& velikost, stack<int>& s1, stack<int>& s2, stack<int>& s3, int& podatek){
    stack<int> temp = s1;
    stack<int> temp2 = s2;
    stack<int> temp3 = s3;

    // Check if stack we are getting element from is not empty
    if (!s3.empty()) {
        // Compare stacks
        if (s1.empty() || s3.top() < s1.top()) {
            // Moving the top
            s1.push(s3.top());
            s3.pop();
        } else {
            cout << "Ni mozno nastavljati iz vecje na manjso vrednost" << endl;

        }
    } else {
        cout << "Stack 3 je prazen" << endl;

    }

    // Output from bottom to top
    cout<<"Stack 1: ";
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout<<endl;

    cout<<"Stack 2: ";
    while(!temp2.empty()){
        cout << temp2.top() << " ";
        temp2.pop();
    }
    cout<<endl;

    cout<<"Stack 3: ";
    while(!temp3.empty()){
        cout << temp3.top() << " ";
        temp3.pop();
    }
    cout<<endl;

    // Check if the game is solved or not
    stack<int> tempStack1= s1;
    stack<int> tempStack3 = s3;

    // Checking for for loop
    bool solved = true;


        for (int i = 1; i <= velikost; ++i) {
            if (tempStack1.empty() || i != tempStack1.top()) {
                solved = false;
                break;
            }
            // if it matches
            tempStack1.pop();
        }


    if (solved == true) {
        cout << "Cestitke!!" << endl;
        // so our menu stops as well
        podatek = 1;
    }

}
void prestavi3na2(int& velikost, stack<int>& s1, stack<int>& s2, stack<int>& s3, int& podatek){
    stack<int> temp = s1;
    stack<int> temp2 = s2;
    stack<int> temp3 = s3;

    // Check if stack we are getting element from is not empty
    if (!s3.empty()) {
        // Compare stacks
        if (s2.empty() || s3.top() < s2.top()) {
            // Moving the top
            s2.push(s3.top());
            s3.pop();
        } else {
            cout << "Ni mozno nastavljati iz vecje na manjso vrednost" << endl;

        }
    } else {
        cout << "Stack 3 je prazen" << endl;

    }

    // Output from bottom to top
    cout<<"Stack 1: ";
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout<<endl;

    cout<<"Stack 2: ";
    while(!temp2.empty()){
        cout << temp2.top() << " ";
        temp2.pop();
    }
    cout<<endl;

    cout<<"Stack 3: ";
    while(!temp3.empty()){
        cout << temp3.top() << " ";
        temp3.pop();
    }
    cout<<endl;

    // Check if the game is solved or not
    stack<int> tempStack1= s1;
    stack<int> tempStack2 = s2;
    stack <int> tempStack3 = s3;

    // Checking for for loop
    bool solved = true;


        for (int i = 1; i <= velikost; ++i) {
            if (tempStack2.empty() || i != tempStack2.top()) {
                solved = false;
                break;
            }
            // if it matches
            tempStack2.pop();
        }


    if (solved == true) {
        cout << "Cestitke!!" << endl;
        // so our menu stops as well
        podatek = 1;
    }

}
void izpis(int& velikost, stack<int>& s1, stack<int>& s2, stack<int>& s3, int& podatek) {
    /* stack<int> kopija = s1;
    stack<int> kopija2 = s2;
    stack<int> kopija3 = s3;


    while(s1.empty()) {
        int pod1 = s1.top();
        s1.pop();
    }
     */

   /* stack<int> kopija = s1;
    while(kopija.empty()){
        int pod = s1.top();
        s1.pop();
        cout<<s1.top()<<" ";

    }

    stack<int> kopija2 = s2;
    while(kopija2.empty()){
        int pod2 = s2.top();
        cout<<s2.top()<<" ";
        s2.pop();

    }

    stack<int> kopija3 = s3;
    while(kopija3.empty()){
        int pod3 = s3.top();
        cout<<s3.top()<<" ";
        s3.pop();

    }*/
}


int main(){

    int podatek = 0;
    int velikost;
    stack<int> s1;
    stack<int> s2;
    stack<int> s3;

    cout<<"Vnesi velikost: "<<endl;
    cin>> velikost;
    cout<<endl;

    zacetnoStanje(velikost, s1, s2, s3, podatek);

    bool running = true;
    int selection;
    do{
        menu();
        cin >> selection;
        switch (selection) {
           /* case 1:
                cout<<"Vnesi velikost: "<<endl;
                cin>>selection;

                break;*/
            case 2:
                prestavi1na2(velikost, s1, s2,s3, podatek);
                break;
            case 3:
                prestavi1na3(velikost, s1, s2,s3, podatek);
                break;
            case 4:
                prestavi2na1(velikost, s1, s2,s3, podatek);
                break;
            case 5:
                prestavi2na3(velikost, s1, s2,s3, podatek);
                break;
            case 6:
                prestavi3na1(velikost, s1, s2,s3, podatek);
                break;
            case 7:
                prestavi3na2(velikost, s1, s2,s3, podatek);
                break;
            case 0:
                cout<<"Izbrali ste exit"<<endl;
                break;
            default:
                cout << "Wrong selection " << endl;
                break;
        }

        if(podatek == 1 || selection == 0){
            running = false;
        }
        cout << endl;
    } while (running);




    return 0;
}
