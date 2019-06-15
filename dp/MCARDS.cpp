#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
using namespace std;

struct Card
{
	int color, value;
};

int bsearch(vector<int> v, int low, int high, int value)
{
	int result = -1;
	while(low <= high)
	{
		int mid = (low + high) / 2;
		if(v[mid] < value)
		{
			result = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	return result;
}

int findLis(vector<int> lis, int totalCards)
{
	vector<int> v;
	v.push_back(lis[0]);

	for(int i = 1; i < totalCards; i++)
	{
		int index = bsearch(v, 0, v.size() - 1, lis[i]);
			
		if(index + 1 == v.size())
		{
			v.push_back(lis[i]);
		}
		v[index + 1] = lis[i];	
	}

	return v.size();
}

int main()
{
	int c, n, totalCards, i, maxLength;
	vector<int> per;

	cin >> c >> n;
	totalCards = c * n;
	Card arr[totalCards];
	vector<int> lis;

	for(i = 0; i < totalCards; i++)
	{
		cin >> arr[i].color >> arr[i].value;
	}

	for(i = 0; i < c; i++)
	{
		per.push_back(i);
	}

	result = 0;

	do {
		int a[c][n];
		int cnt = 1;

		for(i = 0; i < c; i++){
			for(int j = 0; j < n; j++){
				a[per[i]][j]=cnt++;
			}
		}

		lis.clear();
		for(i = 0; i < totalCards; i++){
			lis.push_back(a[arr[i].color - 1][arr[i].value - 1]);
		}

		int length = findLis(lis, totalCards);
		maxLength = max(maxLength, length);

        
    } while(next_permutation(per.begin(), per.end()));

    cout << totalCards - maxLength << endl;

	return 0;
}