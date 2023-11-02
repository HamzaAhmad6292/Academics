#include <iostream>
using namespace std;

class Singly;
class node
{
    friend class Singly;
    int data;
    node* next;
    friend class Singly;

};


class Singly {


    node* head;

public:
    Singly() {
        head = nullptr;
    }
    bool top(Singly& obj, int val) {
        node* curr = head;
        node* temp = new node;
        if (obj.isempty()) {
            temp->data = val;
            temp->next = curr;
            head = temp;
            return 0;
        }
        else {
            temp->data = val;
            temp->next = curr;
            head = temp;
            return 1;
        }
    }


    void Print() {
        node* curr = head;

        while (curr != NULL)
        {

            cout << curr->data << ",";
            curr = curr->next;

        }
        cout << endl;
    }

    bool isempty()
    {

        if (head == 0)
            return 1;

        else
            return 0;
    }

    void size() {
        node* curr = head;



        int count = 0;

        while (curr != 0) {


            curr = curr->next;
            count = count + 1;
        }
        cout << "The Size Of Stack Is :" << count << endl;
    }
    void pop()
    {

        if (head == 0)

        {
            cout << "List is Empty" << endl;;
        }
        else {
            node* temp_holder = head;

            head = temp_holder->next;

            delete temp_holder;

            temp_holder = 0;

            cout << "Deleted From start " << endl;

        }
    }
    bool delmidval()
    {

        node* fast = head;

        node* slow = head;

        node* prev = nullptr;
        if (isempty())
        {
            return 0;
        }
        while (fast->next != nullptr) {

            prev = slow;

            slow = slow->next;


            fast = fast->next->next;
        }
        prev->next = slow->next;

        delete slow;

        slow = 0;

        return 1;
    }
    void sort()
    {
        int x = 0;
        node* curr = head;

        node* ncurr = curr;

        while (curr->next != nullptr)
        {
            while (ncurr->next != nullptr)
            {

                if (ncurr->next->data < ncurr->data)

                {
                    x = ncurr->data;

                    ncurr->data = ncurr->next->data;

                    ncurr->next->data = x;

                }
                ncurr = ncurr->next;

            }
            curr = curr->next;

            ncurr = head;

        }
        return;
    }
    bool findsum(int x)
    {
        node* curr = head->next;
        node* next = head;
        while (head != nullptr)
        {
            while (curr != nullptr)
            {


                if (head->data + curr->data == x)

                {

                    cout << "Elements Exists" << endl;
                }
                curr = curr->next;
            }
            head = head->next;

        }
        return false;
    }
    bool ispalindrom() {
        node* slow = head;


        node* fast = head;

        while (fast != nullptr) {
            slow = slow->next;

            fast = fast->next;


        }
        node* prev = nullptr;
        node* next;


        node* curr = slow;
        while (curr != nullptr) {

            next = curr->next;

            curr->next = prev;
            prev = curr;

            curr = next;
        }
        fast = head;

        while (prev != nullptr) {
            if (fast->data != prev->data) {
                return 0;
            }
            fast = fast->next;
            prev = prev->next;
        }
        cout << "Palindrom" << endl;


        return true;
    }

};


int main() {

    Singly obj;
    obj.top(obj, 9);

    obj.top(obj, 10);

    obj.top(obj, 7);

    obj.top(obj, 5);

    obj.top(obj, 6);

    obj.Print();

    obj.delmidval();

    obj.Print();

    obj.findsum(11);



    Singly obj2;

    obj2.top(obj2, 3);

    obj2.top(obj2, 2);

    obj2.top(obj2, 1);

    obj2.top(obj2, 2);
    obj2.top(obj2, 3);


    obj.Print();
    obj2.ispalindrom();

    system("pause");
    return 0;

}