#ifndef payload_h
#define payload_h

using namespace std;
#include <string>

class payload{
    public:
    payload(string n, string s, float g, int i);
    payload(string n, int i);

    string GetName();
    string GetStatus();
    float GetGPA();
    int GetID();

    void SetName(string n);
    void SetStatus(string s);
    void SetGPA(float g);
    void SetID(int i);

    private:
    string name;
    string status;
    float gpa;
    int id;
};

#endif