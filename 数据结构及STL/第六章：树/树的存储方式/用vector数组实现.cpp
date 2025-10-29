#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;

int n;
vector<int> edges[N];//存储树 

int main()
{
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		//a 和 b 之间有一条边
		edges[a].push_back(b);
		edges[b].push_back(a); 
	}
	
	return 0;
 } 
