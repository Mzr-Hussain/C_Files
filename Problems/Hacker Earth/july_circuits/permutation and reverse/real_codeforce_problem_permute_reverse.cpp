#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <sstream>
#include <tuple>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;

#define sc second 
#define fr first
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define plli pair<ll,int>
#define vpii vector<pii>
#define tiii tuple<int,int,int>
#define tiiii tuple<int,int,int,int> 

#define mt(a,b,c) make_tuple(a,b,c)
#define get(arr,i) get<i>(arr)

int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};

int main() 
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<pii> vec;
    for(int i=0;i<n;i++)
    {
        int mins=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[mins]>arr[j])
                mins=j;
        }
        if(i!=mins)
            vec.push_back({i,mins});
        swap(arr[mins],arr[i]);
    }
    cout<<vec.size()<<"\n";
    for(auto t:vec)
        cout<<t.fr<<" "<<t.sc<<"\n";
}
