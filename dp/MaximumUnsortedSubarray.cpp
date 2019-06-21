#include<iostream>
#include<vector>
using namespace std;

vector<int> subUnsort(vector<int> &A) {
   int minVal, maxVal, minIndex, maxIndex, n;
   vector<int> result;
    n = A.size() - 1;
    minVal = A[0];
    maxVal = A[n];
    minIndex = 0;
    maxIndex = n;
    
    for(int i = 1; i <= n; i++)
    {
        if(A[i] >= minVal)
        {
            minIndex++;
            minVal = max(minVal, A[i]);
        }
        else
            break;
    }
    
    for(int j = n - 1; j >= 0; j--)
    {
        if(A[j] <= maxVal)
        {
            maxIndex--; 
            maxVal = min(maxVal, A[j]);
        }
        else
            break;
    }
    
    //find min and max value from i and j
    for(int i = minIndex; i <= maxIndex; i++)
    {
        if(A[i] < minVal)
            minVal = A[i];
        
        if(A[i] > maxVal)
            maxVal = A[i];
    }
    
    int index = minIndex;
    // decrease minIndex till minValue is less than array value
    for(int i = index; i >= 0; i--)
    {
        if(minVal < A[i])
        {
            minIndex = i;
        }
    }
    
    index = maxIndex;
    //increase maxIndex if maxValue is greater
    for(int i = index; i <= n; i++)
    {
        if(maxVal > A[i])
        {
            maxIndex = i;
        }
    }
     
    if(minIndex == n && maxIndex == 0)
    {
       result.push_back(-1);
    }
    else
    {
        result.push_back(minIndex);
        result.push_back(maxIndex);
    }
    
    return result;
}

int main()
{
    vector<int> A = {1, 3, 5, 2};
    subUnsort(A);
}
