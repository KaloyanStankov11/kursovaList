#include <iostream>
#include <cstdlib>
#include "Detail.cpp"

using namespace std;

struct element{
    Detail* detail;
    struct element* next;
};

class List{
private:
    element* begin;
    element* current;
public:

    //Constructor
    List(){
        begin = NULL;
        current = NULL;
    };

    //Destructor that frees the allocated memory
    ~List(){
        element* curr = begin;
        element* temp;
        while(curr){
            temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    int addElement(Detail* newDetail){  //Function to add new element to the list. Returns 0(fault) or 1(success)
        if(newDetail->getID() <= 0){
            cout<<"Incorrect ID! ID must be greater than 0!"<<endl;
            return 0;
        }
        if(newDetail->getValue() <= 0){
            cout<<"Incorrect value! The value must be greater than 0!"<<endl;
            return 0;
        }
        element* temp = begin;
        while(temp != NULL){
            if(temp->detail->getID() == newDetail->getID()){
                cout<<"Incorrect ID! There is another detail with ID="<<newDetail->getID()<<" yet!"<<endl;
                return 0;
            }
            temp = temp->next;
        }
        if(begin == NULL){
            begin = (element*)malloc(sizeof(element));
            begin->detail = newDetail;
            begin->next = NULL;
            current = begin;
            current->next = NULL;
        }else{
            current->next = (element*)malloc(sizeof(element));
            current = current->next;
            current->detail = newDetail;
            current->next = NULL;
        }
        return 1;
    }

    void findElement(int id){ //Function to find element by ID
        if(begin == NULL){cout<<"Empty list!"<<endl; return;}
        element* curr = begin;
        while(curr != NULL){
            if(curr->detail->getID() == id){
                cout<<"ID: "<<curr->detail->getID();
                cout<<" | Name: "<<curr->detail->getName();
                cout<<" | Unit: "<<curr->detail->getUnit();
                cout<<" | Value: "<<curr->detail->getValue()<<endl;
                return;
            }
            curr = curr->next;
        }
        cout<<"Could not find element with such id"<<endl;
    }

    void printList(){ //Function to show all elements in the list
        if(begin == NULL){cout<<"Empty list!"<<endl; return;}
        element* curr = begin;
        while(curr != NULL){
            cout<<"ID: "<<curr->detail->getID();
            cout<<" | Name: "<<curr->detail->getName();
            cout<<" | Unit: "<<curr->detail->getUnit();
            cout<<" | Value: "<<curr->detail->getValue()<<endl;
            cout<<"---------------------------------------------------------"<<endl;
            curr = curr->next;
        }
    }

    int deleteElement(int id){ //Function to delete element by ID. Returns 0(fault) or 1(success)
        if(begin == NULL){cout<<"Empty list!"<<endl; return 0;}
        if(begin->detail->getID() == id){
            element* temp = begin;
            begin = begin->next;
            free(temp);
            return 1;
        }
        element* curr = begin->next;
        element* prev = begin;
        while(curr != NULL){
            if(curr->detail->getID() == id){
                element* temp = curr;
                prev->next = curr->next;
                free(temp);
                return 1;
            }
            curr = curr->next;
            prev = prev->next;
        }
        cout<<"No element found with such id"<<endl;
        return 0;
    }
};
