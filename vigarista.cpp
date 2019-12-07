#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vi;
typedef vector<vi> Adj_List;

void show_Graph(Adj_List graph){

	int i;

	for (i = 0; i < graph.size(); i++)
	{
		cout << '[' << i << ']';
		vi :: iterator it = graph[i].begin();

		while(it != graph[i].end()){
			cout << (*it).first << "->";

			it = it + 1;
		}

		cout << endl;
	}
}
void Dijkstra(int source, Adj_List graph, int* visited, int* distance){

	priority_queue<ii, vi, greater<ii>> Queue;
	distance[source] = 0;

	Queue.push(ii(source,distance[source]));

	while(!Queue.empty())
	{
		int current = Queue.top().first, i;
		Queue.pop();

		if(visited[current]) continue;
		visited[current] = 1;

		for (i = 0; i < graph[current].size(); i++)
		{
			vi :: iterator it = graph[current].begin();

			while(it != graph[current].end())
			{
				if(distance[current] + (*it).second < distance[(*it).first]){
					distance[(*it).first] = distance[current] + (*it).second;
					Queue.push(ii((*it).first,distance[(*it).first]));
				}
				it = it + 1;
			}
		}
		
	}
}
int main()
{
	Adj_List Graph;
	int i, n, m, v1, v2, width;
	scanf("%d%d", &n,&m);

	int visited[n];
	int distance[n];

	for (i = 0; i < n; i++)
	{
		visited[i] = 0;
		distance[i] = INT_MAX;
	}
	
	Graph.resize(n);

	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &v1, &v2, &width);
		v1--;
		v2--;

		Graph[v1].push_back(ii(v2,width));
		Graph[v2].push_back(ii(v1,width));
	}

	show_Graph(Graph);
	printf("\n\n");
	Dijkstra(0,Graph,visited,distance);

	for (i = 0; i < n; i++)
	{
		printf("%d ", distance[i]);
	}
	
	return 0;
}
