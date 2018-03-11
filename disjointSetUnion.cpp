// fundamental code for Disjoint set union 

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,m;
vector <ll> arr;
vector <ll> size;

void initialize() {
    arr.push_back(0);
    size.push_back(0);
    for(ll i=1; i<=n; i++) {
        arr.push_back(i);
        size.push_back(1);
    }
}

// to calculate the root.
ll root(ll i) {
    while(arr[i] != i) {
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}

// the heart of my code
void weighted_union(ll a, ll b) {
    ll root_a = root(a);
    ll root_b = root(b);
    if(root_a == root_b){
        return;
    }
    if(size[root_a] < size[root_b]) {
        arr[root_a] = arr[root_b];
        size[root_b] += size[root_a];
        size[root_a] = 0;
    }
    else {
        arr[root_b] = arr[root_a];
        size[root_a] += size[root_b];
        size[root_b] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    initialize(); // where things begin
    ll x,y;
    ll t = m;
    while(t--) {
        cin>>x>>y;
        weighted_union(x, y);
        vector <ll> op = size;
        sort(op.begin(),op.end());
        
        for( ll i=1; i<op.size(); i++) {
            if(op[i] != 0)
              cout<<op[i]<<" ";
        }
        cout<<'\n';
    }
}
