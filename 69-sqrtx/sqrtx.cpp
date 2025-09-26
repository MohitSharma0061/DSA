class Solution {
public:
long long int binarysearch(int x){
    int s=0;
    int e=x;
    long long int ans=0;
    while(s<=e){
        int mid=s+(e-s)/2;
       long long  int square=1LL*mid*mid;
        if(square==x){
            return mid;
        }
        else if(square<x){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}
    int mySqrt(int x) {
       return  binarysearch(x);

        
    }
};