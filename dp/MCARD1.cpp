#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct card
{
	int color, value, cost;
};

int main()
{
	int c, n, totalCard, i;
	vector<card> v[100000];
	bool color[c + 1];
	cin >> c >> n;
	totalCard = c * n;
	card arr[totalCard];
	for(i = 0; i < totalCard; i++)
	{
		cin >> arr[i].color >> arr[i].value;
	}

	for(i = 0; i <= c; i++)
	{
		color[i] = false;
	}

	i = 1;
	v[0].push_back(arr[0]);
	v[0][0].cost = 0;
	color[arr[0].color] = true;

	int index = 1;
	while(i < c * n)
	{
		vector<card> prevCard = v[index - 1];
		card currentCard = arr[i];

		for(int j = 0; j < prevCard.size(); j++)
		{
			if(color[currentCard.color])
			{
				if(prevCard[j].color == currentCard.color)
				{
					if(prevCard[j].value + 1 == currentCard.value)
					{

						card temp ;
						temp.color = currentCard.color;
						temp.value = currentCard.value;
						temp.cost = prevCard[j].cost;
						v[index].push_back(temp);
					}
					else if(prevCard[j].value + 1 < currentCard.value)
					{
							//push current card to end of vector
						//cout << "Prev card vakue = " << prevCard[j].value << " current card value = " << currentCard.value << endl;
							card temp ;
							temp.color = prevCard[j].color;
							temp.value = prevCard[j].value;
							temp.cost = prevCard[j].cost + 1;
							v[index].push_back(temp);

							card temp1 ;
							temp1.color = prevCard[j].color;
							temp1.value = currentCard.value;
							temp1.cost = prevCard[j].cost;
							v[index].push_back(temp1);
					}
					else if(currentCard.value < prevCard[j].value)
					{
						//scout << "prev card value = "  << prevCard[j].value << endl;
						//increase the cost 
						card temp ;
						temp.color = prevCard[j].color;
						temp.value = prevCard[j].value;
						temp.cost = prevCard[j].cost + 1;
						v[index].push_back(temp);

						//put prevCard at proper place
						int k = i + 1;
						int swapPosition;
						
						temp.color = currentCard.color;
						temp.value = currentCard.value;
						temp.cost = prevCard[j].cost + 1;
						v[index].push_back(temp);
					}
					//cout << "Cost if color is same = " << temp.cost << endl;
				}
				//color of current card and prev held card does not match
				//so put current card somewhere in deck and just increase the cost 
				//so end color does not change
				else
				{
					//cout << "current card color = " << currentCard.color << " " << color[currentCard.color] <<  endl;
					card temp ;
					temp.color = prevCard[j].color;
					temp.value = prevCard[j].value;
					temp.cost = prevCard[j].cost + 1;
					v[index].push_back(temp);
					//cout << "cost if color is diff " << temp.cost << endl;
				}
			}
			//color of the current card does not exist in the held deck
			// either put current card at end and do not change cost or put it somewhere in deck and increase cost by 1
			else
			{
				//cout << "new card color = " << currentCard.color << "  ";
				//put card somewhere in deck
				card temp;
				temp.color = prevCard[j].color;
				temp.value = prevCard[j].value;
				temp.cost = prevCard[j].cost + 1;
				v[index].push_back(temp);
				//cout << "Cost to push in middle of deck = " << temp.cost << "  ";


				//put current card at end
				card temp1;
				temp1.color = currentCard.color;
				temp1.value = currentCard.value;
				temp1.cost = prevCard[j].cost;
				v[index].push_back(temp1);
				//cout << " to push end = " << temp1.cost << endl;
			}
		}
		color[currentCard.color] = true;
		i++;
		index++;

	}

	int minCost = 9999999;
	for(i = 0; i < v[index - 1].size(); i++)
	{
		if(v[index - 1][i].cost < minCost)
		{
			minCost = v[index - 1][i].cost;
		}
	}

	cout << minCost << endl;
	return 0;
}