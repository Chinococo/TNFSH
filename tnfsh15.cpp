#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define int long long
#define vec vector<int>
#define vecs vector<string>

#define x first
#define y second
#define maxlen 8
#define over 1e8
#define t tuple<string,string,int>
using namespace std;
map<string,int> c;
bool bin(string a,string b)
{
    if(a.compare(b)<0)
        return true;
    return false;
}
bool cmp(t a, t b) {
    if(get<1>(a)==get<1>(b))
    {
        if(get<2>(a)==get<2>(b))
            return bin(get<0>(a),get<0>(b));
        if(c[get<1>(a)]==5)
            return get<2>(a) < get<2>(b);
        return get<2>(a)  > get<2>(b);
    }else
        return c[get<1>(a)]  < c[get<1>(b)];//小

}

signed main() {IOS;
    c["elder"]=1;
    c["nursy"]=2;
    c["kit"]=3;
    c["warrior"]=4;
    c["appentice"]=5;
    c["medicent"]=6;
    c["deputy"]=7;
    c["leader"]=8;
    int n, m;
    while(cin >> n >> m)
    {
        t data[n];
        string name, cancer;
        int age;
        for (int i = 0; i < n; i++) {
            cin >> name >> cancer >> age;
            data[i] = make_tuple(name, cancer, age);
        }
        stable_sort(data, data + n, cmp);
        for (int i = 0; i < min(n,m); i++)
            cout << get<0>(data[i]) << endl;
    }


}
