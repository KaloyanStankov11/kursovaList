#include <iostream>
#include <cstdlib>
#include "List.cpp"
using namespace std;

void showMenu(){    //function to show the menu of the program
    cout<<"1. Add new detail"<<endl;
    cout<<"2. Remove detail"<<endl;
    cout<<"3. Find detail"<<endl;
    cout<<"4. Show all details"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Choose option: ";
}

int main()
{
    List list;
    int option; // variable to store the option selected by the user
    while(1){

        showMenu();
        cin>>option;
        if(option == 1){
            system("cls");
            int id;
            string name, unit;
            double value;
            cout<<"Enter id: "; cin>>id;
            cout<<"Enter name: "; cin>>name;
            cout<<"Enter unit: "; cin>>unit;
            cout<<"Enter value: "; cin>>value;
            system("cls");
            if(list.addElement(new Detail(id, name, unit, value)) == 1){
                cout<<"Added successfully!"<<endl;
                cout<<"======================================================="<<endl;
            }else{
                cout<<"======================================================="<<endl;
            }
        }else if(option == 2){
            system("cls");
            int id;
            cout<<"Enter the ID of the product you want to remove: "; cin>>id;
            system("cls");
            if(list.deleteElement(id) == 1){
                cout<<"Removed successfully"<<endl;
                cout<<"======================================================="<<endl;
            }else{
                cout<<"======================================================="<<endl;
            }
        }else if(option == 3){
            system("cls");
            int id;
            cout<<"Enter the ID of the product you want to search for: "; cin>>id;
            system("cls");
            list.findElement(id);
            cout<<"======================================================="<<endl;
        }else if(option == 4){
            system("cls");
            list.printList();
        }else if(option == 5){
            break;
        }else{
            cout<<"Invalid option!"<<endl;
            cout<<"======================================================="<<endl;
        }
    }
    return 0;
}
