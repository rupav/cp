#include<bits/stdc++.h>
using namespace std;

namespace special_math_fun
{
    int ReturnFive(){
        cout<<"Returning Five: ";
        return 5;
    }
}

class Fun{
public:
    static int obj_count_;  /// class data memebers should have trailing underscore.

    Fun(){
        cout<<"Constructor Called!"<<endl;
        obj_count_++;
    }

    int A(){
        cout<<special_math_fun::ReturnFive()<<endl;
    }

    /// access function. - naming convention like normal variables.
    static int get_object_count(){
        return obj_count_;
    }

};

int Fun::obj_count_ = 0;  /// initialization

int main(){
    Fun obj1, obj2;
    obj1.A();
    cout<<Fun::get_object_count();
    return 0;
}
