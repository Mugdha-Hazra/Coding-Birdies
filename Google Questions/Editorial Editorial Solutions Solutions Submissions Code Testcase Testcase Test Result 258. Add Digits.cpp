class Solution {
public:
int nsum(int n)
{
    int p=0;
        while(n>0)
        {
            p+=n%10;
            n/=10;
        }
        return p;
}
    int addDigits(int n) {
        while(n/10>0)
        {
           n=nsum(n);
        }
        return n;
    }
};
