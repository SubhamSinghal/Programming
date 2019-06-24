//ref link: https://www.quora.com/Given-a-stream-of-n-integers-between-1-and-n-find-one-number-that-repeats-in-linear-time-using-less-than-O-n-space-and-traversing-the-stream-sequentially-O-1-times

#include <iostream>
#include <vector>
using namespace std;

int repeatedNumber(const vector<int> &A) {
   
   int slow, fast;
   slow = A[0];
   fast = A[A[0]];
   
   while(slow != fast)
   {
       slow = A[slow];
       fast = A[A[fast]];
   }
   
   slow = 0;
   while(slow != fast)
   {
       slow = A[slow];
       fast = A[fast];
   }
   
   return slow;
}

int main()
{
  vector<int> A = {3,4,1,4,1};
  cout << repeatedNumber(A);
}