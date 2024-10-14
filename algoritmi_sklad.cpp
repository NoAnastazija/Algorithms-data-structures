#include <iostream>
#include <stack>

using namespace std;

// Sklad izbira
struct Stack{
    // array for storing values <- we put our values in here
    int *S;
    // top of the stack
    int top;
    // size of array
    int MAX;

    void push(){
        cout<<"push()";
    }
};

// Krožna izbira
struct Q{
    // array for storing values <- we put our values in here
    int *S;
    // head -> najstarejsi podaek
    // ob branju povecujemo glavo
    int head;
    // tail kaze na mesto, kamor bomo vstavili novi element -> najnovejsi podatek
    // ob vpisovannju povecujemo rep
    int tail;
    // size of array
    int MAX;
};

void menu() {
    cout << "============================" << endl;
    cout << "=========== MENU ===========" << endl;
    cout << "============================" << endl;
    cout << "1....INPUT VALUE" << endl;
    cout << "2....READ VALUES AND OUTPUT THEM " << endl;
    cout << "3....GET ENTIRE CONTENT" << endl;

    cout << "4....INPUT VALUE" << endl;
    cout << "5....READ VALUE AND OUTPUT" << endl;
    cout << "6....GET ARRAY Q (VALUES) " << endl;
    cout << "7....GET ALL FROM HEAD TO TAIL INCLUDED " << endl;
    cout << "0 " << endl;
    cout << "============================" << endl;
    cout << "Select: ";
}

int main(){
    Stack s;
    s.push();

    int sklad_size;
    s.MAX = sklad_size;

    cout<<"Input the MAX size of the array: ";
    cin>>s.MAX;
    cout<<endl;

    // Memory is dynamically stored -> for array S dtorage
    s.S = new int[s.MAX];
    // Top of the stack, so tail?? -> incrementation
    s.top = -1;

    int x;

    // Krozna vrsta
    Q circ;
   int circ_size;
   circ.MAX = circ_size;

   cout<<"Input the MAX size of the array: ";
   cin>>circ.MAX;
   cout<<endl;

   circ.S = new int[circ.MAX];

   // For empty default values
   circ.head = -1;
   circ.tail = -1;

   int y;

   int new_tail;

    bool running = true;
    int selection;
    do{
    menu();
    cin >> selection;
    switch (selection) {
        // Vnos podatka
        case 1:
            cout << "Input the value: ";
            cin >> x;
            // if exceeds
            if (s.top == s.MAX - 1) {
                cout << "The array is full" << endl;
            } else {
                s.top++;
                s.S[s.top] = x;
            }

            //s.S.push(s, x);
            break;
            // Branje podatka in izpis
        case 2:
            cout << "Input value: ";
            cin >> x;
            /*while(!myStackk.empty()){
                cout<<myStackk.top();
                myStackk.pop();
            }
            myStackk.push(s, x);
            */
            if (s.top == s.MAX - 1) {
                cout << "The array is full" << endl;
            } else {
                s.top++;
                s.S[s.top] = x;
            }
            // Output the current number
            cout << "Izpis" << endl;
            cout << s.S[s.top] << endl;
            break;

            // Izpis vesbine sklada
        case 3:
            // Output only what we have
            for (int i = 0; i <= s.top; i++) {
                cout << s.S[i] << endl;
            }


            cout << "Ignore this" << endl;
            // For output everything even the values we dont have
            for (int i = 0; i <= s.MAX - 1; i++) {
                /* if (s.top == 0) {
                     cout << "Empty" << endl;
                 } else {*/
                //s.top--;
                cout << s.S[i] << endl;
                //  }
            }
            /*
             * if(s.top ==
             */

            break;

            // Vnos podatka
        case 4:
            cout << "Input the value";
            cin >> y;
            cout << endl;
            // new_tail -> where next element will be inserted
            // % - in case of max index
            new_tail = (circ.tail + 1)  % circ.MAX;
            if (new_tail > circ.MAX) {
                new_tail = 1;
            }

            if(circ.tail == circ.MAX - 1) {
        cout << "The array is full" << endl;
         } else {

                if (circ.head == new_tail) {
                    cout << "It is full" << endl;
                } else {
                    circ.S[circ.tail] = y;
                    circ.tail = new_tail;
                }
            }
            break;

            // Branje podatka in izpis
        case 5:
            cout << "Input the value";
            cin >> y;
            cout << endl;

            // Position handling
            // used so when it reaches the end it makes circual
            // if max 5, tail index 3-> 3+1 = 4 % 5 = 4 since 4 < 5, 4 is assign value
            new_tail = (circ.tail + 1) % circ.MAX;
            if (new_tail > circ.MAX) {
                new_tail = 1;
            }

            if(circ.tail == circ.MAX - 1) {
                cout << "The array is full" << endl;
            } else {

                if (new_tail == circ.head) {
                    // circ.tail = new_tail;
                    cout << "It is full" << endl;
                } else {
                    circ.S[circ.tail] = y;
                    circ.tail = new_tail;
                    cout << y << endl;
                }
            }
            break;
            // Izpis polja
        case 6:
    // from 0 ro max we have
    for(int i = 0; i< circ.MAX; i++) {
        cout << circ.S[i] << endl;
    }
            break;
        // Izpis vrste od glave do repa
        case 7:
            if (circ.head == circ.tail) {
                cout << "it is empty" << endl;
            } else {
                cout << "Outpput" << endl;
                cout << circ.S[circ.head] << endl;
                // Increment so the head moves to next value it will store data to
                circ.head = circ.head + 1;


                //s.S[s.top] = x;
                //y = circ.S[circ.head];
                //circ.head = circ.head + 1;
                if (circ.head > circ.MAX) {
                    // for wrapping to the beginning
                    // nect elements can be accessed
                    circ.head = 1;
                }
            }
            break;
        case 0:
            break;
        default:
            cout << "Wrong selection " << endl;
            break;
    }
    cout << endl;
    } while (running);



    delete[] s.S;
    delete[] circ.S;

    return 0;
}
