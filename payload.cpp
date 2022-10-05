#include "payload.h"
using namespace std;

payload::payload(string n, string s, float g, int i){
    name = n;
    status = s;
    gpa = g;
    id = i;
}

payload::payload(string n, int i){
    name = n;
    status = "Freshman";
    gpa = 0;
    id = i;
}

string payload::GetName() { return name; }
string payload::GetStatus() { return status; }
float payload::GetGPA() { return gpa; }
int payload::GetID() { return id; }

void payload::SetName(string n) { name = n; }
void payload::SetStatus(string s) { status = s; }
void payload::SetGPA(float g) { gpa = g; }
void payload::SetID(int i) { id = i; }