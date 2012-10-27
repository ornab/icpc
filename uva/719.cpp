//719
//Glass Beads
//Misc;String Matching;Suffix Array;Circular
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#define MAX 10050
using namespace std;

int RA[MAX], tempRA[MAX];
int SA[MAX], tempSA[MAX];
int C[MAX];                

void suffix_sort(int n, int k) {
    memset(C, 0, sizeof C);        

    for (int i = 0; i < n; i++)        
        C[RA[(i + k)%n]]++;
        
    int sum = 0;
    for (int i = 0; i < max(256, n); i++) {                     
        int t = C[i]; 
        C[i] = sum; 
        sum += t;
    }

    for (int i = 0; i < n; i++)        
        tempSA[C[RA[(SA[i] + k)%n]]++] = SA[i];

    for (int i = 0; i < n; i++)        
        SA[i] = tempSA[i];
}

void suffix_array(string s) {             
    int n = s.size();
    
    for (int i = 0; i < n; i++) 
        RA[i] = s[i];              

    for (int i = 0; i < n; i++) 
        SA[i] = i;

    for (int k = 1; k < n; k *= 2) {     
        suffix_sort(s.size(), k);
        suffix_sort(s.size(), 0);
        int r = tempRA[SA[0]] = 0;
        for (int i = 1; i < s.size(); i++)
            tempRA[SA[i]] =     
                (RA[SA[i]] == RA[SA[i-1]] && RA[(SA[i]+k)%n] == RA[(SA[i-1]+k)%n]) ? r : ++r;
        for (int i = 0; i < s.size(); i++)
            RA[i] = tempRA[i];
    } 
}

int main() {
    int tt; cin >> tt;
    while(tt--) {
        string s; cin >> s;
        suffix_array(s);
        cout << SA[0]+1 << endl;
   }
}