#include<iostream>
#include<unordered_map>
using namespace std;


int main()
 {
        int t, k;
        cin>>t;
        char *str = new char[100000];
        while(t--)
        {
            cin>>str;
            cin>>k;
            unordered_map<char, int> myMap;
            int count = 0;
            int flag = 0;
            int i =0;
            while(str[i] != '\0'){
                if(myMap.count(str[0]) == 0){
                    myMap[str[i]] = 1;
                } else{
                    myMap[str[i]] ++;
                }
                i++;
            }

            if(i<25){
                cout<<0<<endl;
                break;
            }

            for(int i=0; i<26; i++){
                if(myMap.count(i + 'a') == 0){
                    k--;
                }
                else{
                    k += myMap.count(i + 'a') - 1;
                }
            }
            if(k >= 0)
                cout<<1<<endl;
            else
                cout<<0<<endl;

        }
	return 0;
}
