#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

#define INF 100000000

using namespace std;

int main(void)
{
    ifstream pfin("input.txt");
    ofstream pfout("output.txt");
    int N,d,minim=INF;
    vector<int> physics;
    pfin >> N;
    int n = N;
    for(int i=0; i<N; i++) {
        pfin >> d;
        physics.push_back(d);
    }
    sort(physics.begin(),physics.end());
    for(int i=0; i<N; i++) {
        int z = physics[i]*2;
        int temp = upper_bound(physics.begin(), physics.end(), z) - physics.begin();
        minim = min(minim, n-temp + i);
    }
    pfout << minim << endl;
    return 0;
}
