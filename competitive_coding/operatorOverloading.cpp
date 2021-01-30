#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i, st, en) for(int i=st; i<=en; i++)
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;

class Complex{
private:
    int real, imag;
public:
    Complex(int r=0, int i=0){
        real = r;
        imag = i;
    }
    friend Complex operator + (Complex const&, Complex const&);
    void print();
};

/// friend function is not a member-function, so don't needs to be scoped.
Complex operator + (Complex const &c1, Complex const &c2){
    return Complex(c1.real+c2.real, c1.imag+c2.imag);
}

/// member function, so has to be scoped for function definition.
void Complex::print(){
    cout<<this->real<<" + i"<<this->imag<<endl;
}

int main(){
    int r1, r2, i1, i2;
    cin>>r1>>i1>>r2>>i2;
    Complex c1(r1, i1);
    cout<<"c1: ";
    c1.print();
    Complex c2(r2, i2);
    cout<<"c2: ";
    c2.print();
    cout<<"c1 + c2 = ";
    Complex c3 = c1+c2;
    c3.print();
    return 0;
}
