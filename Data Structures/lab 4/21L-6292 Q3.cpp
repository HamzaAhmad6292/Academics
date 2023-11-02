#include <iostream>
using namespace std;



class doubly {


    class node {
        int data;
        node* next;
        node*prev;

        friend class doubly;

    };

    node* head;

public:

    doubly() {
        head = nullptr;
    }


    void display() {
        node* curr = head;

        while (curr->next != head ) {

            cout << curr->data << "-";

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
            
            
            while (curr != 0) {
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
    template <class A>
    void InsertAtStart(A val)
    {
        node* temp = new node;
        temp->prev = nullptr;
        temp->next = head;
        temp->data = val;
        if (head != nullptr)
        {
            head->prev = temp;
        }

        head = temp;

        node* curr = head;
        node* previous = NULL;
        
        return ;

    }

    template<class T>
    void InsertAtEnd(T val)
    {
        node* temp = new node;
       
        temp->data = val;
     
        node* curr = head;
        node* previous = NULL;



        while (curr != NULL)
        {




            previous = curr;
            curr = curr->next;
            if (curr == NULL)
            {
                temp->prev = previous;
                previous->next = temp;

            }
            temp->next = head;

        }
        return;

    }



};



int main() {

    doubly a;


    a.InsertAtStart(1);


    a.InsertAtStart(5);
    a.InsertAtStart(7);
    a.InsertAtEnd(4);
    a.InsertAtStart(1);


    

    a.display();
    cout << endl;

   //a.DeleteAtStart();
   // a.DeleteAtEnd();
    


    a.display();


    system("pause");
    return 0;




}