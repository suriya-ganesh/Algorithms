#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<vector>
#include<cstdio>
#include<string>
#include<cassert>
#include<cstring>
#include<numeric>
#include<sstream>
#include<iterator>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
#define MM(a,x) memset(a, x, sizeof(a))
#define P(x) cout<<#x<<" = "<<x<<endl;
#define P2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl;
#define PV(a,n) for(int i=0;i<n;i++) cout<<#a<<"[" << i <<"] = "<<a[i]<<endl;
#define TM(a,b) cout<<#a<<"->"<<#b<<": "<<1.*(b-a)/CLOCKS_PER_SEC<<"s\n";

string S;
int d[10010];
int n;
int c[26], w[26];

int main() {
    cin >> S;
    reverse(S.begin(), S.end());
    n = S.length();
    assert(n <= 10000);

    /*
    s => string of letters
        len(s) => string length
    d => number position derived by s[i] - a . So the values from a-z would be translated to 0-25
        len(d) => string length
    c => letter count for every letter of the alphabet
        len(c) => 26
    */
    for(int i = 0; i < n+10; i++) d[i] = S[i] - 'a';
    for(int i=0; i<n; i++) cout<< d[i]<<' ';
    cout<<'\n';
    for(int i=0; i<n; i++) cout<< S[i]<<' ';
    cout<<'\n';
        for(int i=0; i<26; i++) cout<< c[i]<<' ';
    cout<<'\n';
    for(int i = 0; i < n; i++) c[d[i]]++;
    cout<<'\n';for(int i=0; i<26; i++) cout<< c[i]<<' ';


//    assertion to make sure that there are no odd number of elements thereby making the code invalid
    for(int i = 0; i < 26; i++) assert(c[i] % 2 == 0);
    cout<<'\n'<<'w'<<'\n';
        for(int i=0; i<26; i++) cout<< w[i]<<' ';
        cout<<'\n';
    for(int i = 0; i < 26; i++) w[i] = c[i] / 2;
            for(int i=0; i<26; i++) cout<< w[i]<<' ';
        cout<<'\n';
    vector<int> ret(n / 2);
    for(int i = 0; 2 * i < n; i++) {
        for(int c = 0; c < 26; c++) {
            ret[i] = c;
            int p = 0;
            int l = 0;
            for(int j = 0; j < n; j++) {
                if(ret[p] == d[j]) {
                    p++;
                    l = j;
                    if(p > i) break;
                }
                            cout<<ret[p]<<' '<<p<<'\n';


            }
            cout<<'-';
            if(p <= i) continue;
            int want[26] = {};
            for(int j = 0; j < 26; j++) want[j] = w[j];
            for(int j = 0; j <= i; j++) want[ret[j]]--;
            int have[26] = {};
            for(int j = l + 1; j < n; j++) have[d[j]]++;
            int ok = 1;
            for(int j = 0; j < 26; j++) if(want[j] < 0 || want[j] > have[j]) ok = 0;
            if(ok) break;
        }
    }
    string r;
    for(int i = 0; 2 * i < n; i++) r += char(ret[i] + 'a');
    cout << r << endl;
    return 0;
}