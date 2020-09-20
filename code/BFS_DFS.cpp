#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph
{
public:
	Graph(int n) : dot_num(n)
	{
		color.resize(dot_num);
		distance.resize(dot_num);
		predecessor.resize(dot_num);
		discover.resize(dot_num);
		finish.resize(dot_num);
	};
	vector<vector<int>> vertex;

	void BFS(int start);

	void DFS(int start);
	void DFSvisit(int start, int &time);

	void Topo_logical_Sort(int start);
private:
	int dot_num;
	vector<int> color;			// 0: withe (not found), 1:gray (be found), 2:black (remove from queue)
	vector<int> predecessor;	// find vertex's ancestor
	// for BFS
	vector<int> distance;		// record vertex distance fron Start
	// for DFS
	vector<int> discover;
	vector<int> finish;
};
void Graph::BFS(int start)
{
	for (int i = 0; i < dot_num; i++) // initialize
	{
		color[i] = 0;				// 0: withe
		distance[i] = dot_num + 1;	// number of dot_num
		predecessor[i] = -1;		// -1: no predecessor
	}

	queue<int> q;
	int i = start;
	for (int n = 0; n < dot_num; n++)	// n will find all vertex
	{
		if (color[i] == 0)
		{
			color[i] = 1;
			distance[i] = 0;
			predecessor[i] = -1;	// root
			q.push(i);
			
			while (!q.empty())
			{
				int now = q.front();	// now is new_start
				for (int j = 0; j < vertex[now].size(); j++)
				{
					int next = vertex[now][j];
					if (color[next] == 0)
					{
						color[next] = 1;
						distance[next] = distance[now] + 1;
						predecessor[next] = now;
						q.push(next);
					}
				}
				q.pop();
				color[now] = 2;
			}
		}
		// if for_loop do not traversal all dot, represent this graph has many connected components.
		// set new Start.
		i = n;
	}
}
void Graph::DFS(int start)
{
	for (int i = 0; i < dot_num; i++)	// initialize
	{
		color[i] = 0;
		predecessor[i] = -1;
		discover[i] = 0;
		finish[i] = 0;
	}
	int time = 1;	// timestamp
	
	for (int n = 0; n < dot_num; n++)
	{
		if (color[start] == 0)
			DFSvisit(start, time);
		else
			start = n;
	}
}
void Graph::DFSvisit(int now, int &time)
{
	color[now] = 1;
	discover[now] = time++;
	for (int i = 0; i < vertex[now].size(); i++)
	{
		int next = vertex[now][i];
		if (color[next] == 0)
		{
			predecessor[next] = now;
			DFSvisit(next, time);	// recursion
		}
	}
	color[now] = 2;
	finish[now] = time++;
}
void Graph::Topo_logical_Sort(int start)
{
	DFS(start);
	vector<int>finish_BigtoSmall;
	finish_BigtoSmall.resize(dot_num);
	for (int i = 0; i < dot_num; i++)
		finish_BigtoSmall[i] = i;

	for (int i = 0; i < dot_num; i++)
	{
		for (int j = i + 1; j < dot_num; j++)
		{
			if (finish[i] < finish[j])
			{
				swap(finish[i], finish[j]);
				swap(finish_BigtoSmall[i], finish_BigtoSmall[j]);
			}
		}
	}

	cout << "Topological Sort\n";
	for (int i = 0; i < dot_num; i++)
		cout << finish_BigtoSmall[i] << " ";
	cout << "\n";
}
int main()
{
	int vertex_num, edge_num;
	while (cin >> vertex_num >> edge_num)
	{
		Graph graph(vertex_num);
		graph.vertex.resize(vertex_num);
		// input
		for (int i = 0; i < edge_num; i++)
		{
			int start, end;
			cin >> start >> end;
			graph.vertex[start].push_back(end);
		}

		graph.BFS(0);
		// graph.DFS(0);
		// graph.Topo_logical_Sort(4);
	}
	return 0;
}
/*
6 6
0 1
0 2
1 3
2 4
3 4
4 5
*/
/*
15 15
0 2
1 2
2 6
2 7
3 4
4 5
5 6
5 14
6 8
6 9
6 11
6 12
7 8
9 10
12 13
*/
/*
9 9
0 1
1 2
0 3
3 2
6 3
5 6
5 7
6 7
8 7
*/