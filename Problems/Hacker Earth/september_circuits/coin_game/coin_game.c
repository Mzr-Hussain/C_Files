#include <stdio.h>

int main()
{
    int t,n;
    long a;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        long sum=0;
        for(int i=0; i<n;i++){
            scanf("%ld",&a);
            while( a%2==0 ){
                sum++;
				a/=2;
            }
        }
        if(sum&1)   printf("Charlie\n");
        else        printf("Alan\n");
    }
    return 0;
}
