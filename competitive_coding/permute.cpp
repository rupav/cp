#include<iostream>

using namespace std;

void permute(string s, int si, int ei, string out){
    if(si == ei){
        cout<<out;
    }

}

int main(){
    string s;
    cin>>s;
    string out;

    out = 'rup';
    cout<<out[0];
    // permute(s, 0, s.size()-1, out);
    return 0;
}
