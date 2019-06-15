#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct box
{
	int w, h;
};

bool customSort(box a, box b)
{
	if(a.w == b.w)
	{
		return a.h < b.h;
	}
	return a.w > b.w;
}

vector<box> v;
int bsearch(int w, int h, int low, int high)
{
	int mid;
	int ans = 100000;
	while(low <= high)
	{
		 mid = (low + high) / 2;
		int width = v[mid].w;
		int height = v[mid].h;

		if(height > h)
		{
			ans = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return ans;
}

int main()
{
	int t, m, w, h, n, i;
	
	cin >> t;
	while(t--)
	{
		cin >> m;
		box arr[m];
		n = 1;
		v.clear();

		for(i = 0; i < m; i++)
		{
			cin >> arr[i].w >> arr[i].h;
		}

		sort(arr, arr + m, customSort);
		
		i = 1;
		v.push_back(arr[0]);
		while(i < m)
		{
			int index = bsearch(arr[i].w, arr[i].h, 0, v.size() - 1);
			if(index <= m - 1)
			{
				v[index].w = arr[i].w;
				v[index].h = arr[i].h;
			}
			else
			{
				v.push_back(arr[i]);
			}
			i++;
		}

		cout << v.size() << endl;
	}
	return 0;
}