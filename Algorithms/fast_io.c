/*

**********
 FAST I/O
**********

*/

void take(unsigned long long int *a)
{
    register int c;
    c=getchar_unlocked();
    *a=0;
    for(;(c>47&&c<58);c=getchar_unlocked())
        *a=(*a)*10+c-48;
}
 
void print(unsigned long long int a)
{
    char num[11];
    sprintf(num,"%llu",a);
    register int i=0;
    while(num[i]!='\0'){
        putchar(num[i]);
        i++;
    }
    putchar('\n');
}
