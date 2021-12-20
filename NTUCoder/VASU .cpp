#include<iostream>
#include<vector>
#pragma GCC optimize("O3")
using namespace std;

int maxid(vector<long long> a) {
    long long max = a.at(0);
    int maxid = 0;
    for (int i=1;i<a.size();++i) {
        if (a.at(i)>max) {
            max = a.at(i);
            maxid = i;
        }
    }
    return maxid;
}
int slt(vector<long long> vec) {
    long long res = 0;
    if (vec.size()>0) {
        res += vec.at(maxid(vec));
        vec.erase(vec.begin()+ maxid(vec));
        for (int i=0;i<vec.size();++i) {
            vec.at(i) -= 1;
        }
        for (int i=0;i<vec.size();++i) {
            if (vec.at(i) == 0) {
                vec.erase(vec.begin() + i);
                --i;
            }
        }
        res += slt(vec);
    }
    return res;
}
int main() {
    long n,k;
    cin >> n;
    vector<long long> vec;
    for (int i=0;i<n;++i) {
        cin >> k;
        vec.push_back(k);
    }
    cout << slt(vec);
}


