#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <algorithm>
#include <tuple>

using namespace std;

int main()
{
    std::cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    int cnt[500][500][26] = {};
    int max_n[500][500] = {};
    for(int i=0; i<500; i++)
      for(int j=0; j<500; j++)
        max_n[i][j]='A';
    for(int i=0; i<n; i++)
    {
        string s;
        cin >> s;
        
        for(int j=0; j<m; j++)
        {
            cnt[i%k][j%k][s[j]-'A']++;
            if(cnt[i%k][j%k][max_n[i%k][j%k]-'A'] < cnt[i%k][j%k][s[j]-'A']) max_n[i%k][j%k] = s[j];
        }
    }
    
    int sum = 0;
    
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<k; j++) 
          sum += n * m / k / k - cnt[i][j][max_n[i][j]-'A'];
    }
    
    cout << sum << "\n";
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++) cout << static_cast<char>(max_n[i%k][j%k]);
        cout << "\n";
    }
    
    return 0;
}