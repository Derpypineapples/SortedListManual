#include <iostream>
#include <fstream>

#include "payload.cpp"
#include "payloadList.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    payloadList list;

    ifstream inFile;
    ofstream outFile;
    string command;

    inFile.open("test.txt");
    outFile.open("out.txt");

    inFile >> command;
    for (int count = 1; command != "Quit"; count++){
        //Commands

        //Build List
        if (command == "push") {
            int size;
            inFile >> size;
            for (int i = 0; i < size; i++) {
                string format;
                string name;
                string status;
                float gpa;
                int id;
                payload* p;

                inFile >> format;
                if (format == "full") {
                    inFile >> name >> status >> gpa >> id;
                    p = new payload (name, status, gpa, id);
                }
                else if (format == "part") {
                    inFile >> name >> id;
                    p = new payload (name, id);
                }

                if (list.hasNext() && (&list, id)) {
                    outFile << "Push Failed, ID \"" << id << "\" Already Exists" << endl;
                }
                else {
                    list.push(p);
                    outFile << "Pushing \"" << name << ":" << id << "\" to list" << endl;
                }
            }
        }

        //Delete Element
        else if (command == "delete") {
            int id;
            inFile >> id;
            outFile << "Deleting \"" << id << "\"" << endl;
            list.del(id);
        }

        //Print list
        else if (command == "print") {
            outFile << "Built List: [";
            for (payloadList* ptr = list.GetHead(); ptr != NULL; ptr = ptr->GetNext()) {
                outFile << ptr->GetContent()->GetName() << ":" << ptr->GetContent()->GetID();
                if (ptr->hasNext()) outFile << ", ";
            }
            outFile << "]" << endl;
        }

        //Search for element in list
        else if (command == "search") {
            int srch;
            inFile >> srch;
            //if (srch != NULL && search(&list, srch)) outFile << "Search Succ essful, \"" << srch << "\" found" << endl;
            if (list.search(srch)) outFile << "Search Successful, \"" << srch << "\" found" << endl;
            else outFile << "Search Unsuccessful, \"" << srch << "\" not found" << endl;
        }

        else if (command == "sort") {
            list.sort();
            outFile << "List is Sorted" << endl;
        }
        
        else if (command == "") { /*Do nothing*/ }
        else outFile << "Command " << command << " does not exist" << endl;

        cout << "Test " << count << " Completed" << " : " << command  << endl;
        inFile >> command;
    }
    
    cout << "All Tests Completed" << endl;

    inFile.close();
    outFile.close();

    return 0;
}
