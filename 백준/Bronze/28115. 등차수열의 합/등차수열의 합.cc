#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    if(n==1){
    cout<<"YES\n"<<v[0]<<' '<<0;
        return 0;
    }
    long long temp = v[1]-v[0];
    for(int i=0; i<n-1; i++){
    if(temp!=v[i+1]-v[i]) {
    cout<<"NO";
        return 0;
    }
    }
    cout<<"YES\n";
    for(int i=0; i<n; i++) cout<<v[i]<<' ';
    cout<<'\n';
    for(int i=0; i<n; i++) cout<<"0 ";
}