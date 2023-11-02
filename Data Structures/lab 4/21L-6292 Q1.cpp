#include <iostream>
using namespace std;



class Singly {


    class node {
        int data;

        node* next;

        friend class Singly;

    };

    node* head;

public:

    Singly() {
        head = nullptr;
    }

    template <class A>
    void insertSorted(A const x) {

        node* temp = new node;
        temp->data = x;
        temp->next = head;
        head = temp;

        temp = head;
        while (temp->next != 0) {
            if (temp->data > temp->next->data) {
                int hold;
                hold = temp->next->data;
                temp->next->data = temp->data;
                temp->data = hold;
            }
            temp = temp->next;
        }

    }

    void display() {
        node* curr = head;

        while (curr != 0) {

            cout << curr->data << "-";

            curr = curr->next;

        }
    }

    void printNth(int index) {

        node* curr = head;

        int count = 0;
        while (curr->next != 0) {
            if (count == index) {
                cout << "The " << index << "th term is: " << curr->data << endl;
            }
            count += 1;



            curr = curr->next;


        }
    }

    void DeleteAtStart() {

        if (head == 0) {
            cout << "List Already Empty \n";

        }
        else {
            node* temp = head;


            head = temp->next;

            delete temp;
            temp = NULL;
            cout << "Deleted From start succesfully "<<endl;

        }
    }

    void DeleteAtEnd() {


        if (head == 0) {
            cout << "Already Empty!!!!\n";
        }
        else {
            node* curr = head;

            node* prev = 0;
            
            
            while (curr->next != 0) {
                prev = curr;
            
                curr = curr->next;
            }
            curr
                = prev->next;
            prev->next = nullptr;

            delete curr;
            curr = NULL;

            cout << "Deleted Succesfully  " << endl;;

        }



    }



};



int main() {

    Singly a;


    a.insertSorted(3);

    a.insertSorted(7);

    a.insertSorted(9);

    a.insertSorted(1);
    a.printNth(3);

    a.display();
    cout << endl;

    a.DeleteAtStart();
    a.DeleteAtEnd();


    a.display();


    system("pause");
    return 0;




}