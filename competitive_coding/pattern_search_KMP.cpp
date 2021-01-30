
#include<iostream>
using namespace std;

void lps_generate(char *pat,int *lps,int n) // longest prefix suffix
{
    int len = 0, i = 1;
    lps[0] = 0;
    while(i<n)
    {
        if(pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }

        }
    }
}

void KMP(char *txt, int n,char *pat, int m) /// KNUTH MORRIS PRATT's pattern search algo
{
    int i=0, j=0;               // 0<=j<=m
    int *lps = new int[m];
    lps_generate(pat, lps, m);
    int flag = 0;
    while(i<n)
    {
        if(txt[i] == pat[j])
        {
            j++;
            i++;
            if (j == m)
            {
                flag = 1;
                cout<<"Pattern matched at index "<<i-j<<endl;
                j = lps[j-1];
            }
            else
            {
                continue;
            }
        }
        else /// mismatch found, jump using lps array and don't increment i!
        {
            if(j!=0)
                j = lps[j-1];
            else
                i+=1;
        }
    }

    if(flag == 0)
    {
        cout<<"Not matched!"<<endl;

    }
    return ;
}

int main()
{
    int n,m;
    cout<<"enter size of text array"<<endl;
    cin>>n;
    char *txt = new char[n];
    cout<<"enter array elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>txt[i];
    }
    cout<<"enter size of pattern array"<<endl;
    cin>>m;
    cout<<"enter array elements: "<<endl;

    char *pat = new char[m];
    for(int i=0;i<m;i++)
    {
        cin>>pat[i];
    }

    KMP(txt, n, pat, m);
    return 0;
}
/*

// C++ program for implementation of KMP pattern searching
// algorithm
#include<bits/stdc++.h>

void computeLPSArray(char *pat, int M, int *lps);

// Prints occurrences of txt[] in pat[]
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            printf("Found pattern at index %d n", i-j);
            j = lps[j-1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char *pat, int M, int *lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len-1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Driver program to test above function
int main()
{
    char *txt = "ABABDABACDABABCABAB";
    char *pat = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}
*/
