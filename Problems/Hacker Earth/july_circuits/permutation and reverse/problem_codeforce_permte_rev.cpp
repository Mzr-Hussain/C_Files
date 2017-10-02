#include<iostream>
#include<algorithm>
using namespace std;
long long n,k,j,i,p;//,a[1002],b[1002],c[1002][5],a1[10002];
int main(){
	while(1){
		cin>>n;
		long long a[n],b[n],c[n][5],a1[n];
		for(i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i];
		}
		for(i=1;i<=n;i++){
			cin>>a1[i];
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++)
		{
			if(a[i]!=b[i])
			{
				k++;
				for(j=i+1;j<=n;j++)
				{
					if(b[j]==a[i])
					{
						c[k][1]=i-1;
						c[k][2]=j-1;
						p=b[i];
						b[i]=b[j];
						b[j]=p;
						break;
					}
				}
			}
		}
		cout<<k<<endl;
		for(i=1;i<=k;i++)
			cout<<c[i][1]<<" "<<c[i][2]<<endl;
	}		
	return 0;
}