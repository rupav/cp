#include<iostream>
#include<windows.h>
#include<mysql..h>

using namespace std;

int main() {
    string id, name, roll;
    cout<< "Enter Student id"<<endl;
    cin>>id;
    cout<< "Enter student name"<<endl;
    cin>>name;
    cout<< "Enter roll number"<<endl;
    cin>>roll;
    return 0;

    string query = INSERT INTO student(id, name, roll) VALUE("+id+", "+name+", "+roll+");
    const char* q = query.c_str();
    cout<<"query is "<<q>>endl;
    int qstate;
    qstate = mysql_query(conn.q);
    if(!qstate){
        cout<< "record inserted successfully "<<endl;
    } else {
    cout<<"query problem !!!"<<endl;

    mysql_conn(close);
    return 0;
}
