#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string a,b,c,d,e;
	int f=0;
	cin>>a;
	if(a.size()>f)
        f=a.size();
	cin>>b;
	if(b.size()>f)
        f=b.size();
	cin>>c;
	if(c.size()>f)
        f=c.size();
	cin>>d;
	if(d.size()>f)
        f=d.size();
	cin>>e;
	if(e.size()>f)
        f=e.size();
    for(int i=0; i<f; i++)
    {
        if(i<a.size())
            cout<<a[i];
        if(i<b.size())
            cout<<b[i];
        if(i<c.size())
            cout<<c[i];
        if(i<d.size())
            cout<<d[i];
        if(i<e.size())
            cout<<e[i];
    }
	return 0;
}
