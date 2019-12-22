#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//Graph without cycle
int V = 11;

//Graph with cycle
//int V = 12;

list<int> *adjacent = new list<int>[V];

vector<int> in_degree(V, 0);

void addEdge(int a, int b){
	adjacent[a].push_back(b);
	in_degree[b]++;
	cout<< a <<"->"<<b<<"\n";
}

void topoSort(){
	
	queue<int> q;

	for(int i = 0; i<V; i++){
		if(in_degree[i] == 0){
			q.push(i);
		}
	}

	vector<int> result;
	int vertexCount = 0;

	while(!q.empty()){

		int a = q.front();
		q.pop();

		result.push_back(a);

		list<int>::iterator it;
		for(it = adjacent[a].begin(); it != adjacent[a].end(); it++){
			in_degree[*it]--;
			if(in_degree[*it] == 0){
				q.push(*it);
			}
		}

		vertexCount++;
	}

	if(vertexCount != V){
		cout<< "Cycle Detected!\nOrder so far: ";
		for(int i = 0; i<result.size(); i++){
		cout<<result[i]<<" ";
	}
		return;
	}

	cout<<"No cycle detected!\nTopological Order: ";
	for(int i = 0; i<result.size(); i++){
		cout<<result[i]<<" ";
	}
	return;
}

int main(){

	cout<<"Printing Graph\n";

	//Graph without cycle
	addEdge(0,1);
	addEdge(0,5);
	addEdge(1,5);
	addEdge(1,2);
	addEdge(2,4);
	addEdge(4,3);
	addEdge(1,3);
	addEdge(5,6);
	addEdge(6,8);
	addEdge(7,3);
	addEdge(7,8);
	addEdge(8,10);
	addEdge(9,10);
	addEdge(9,4);
	addEdge(9,7);

	//Graph with cycle
	// addEdge(0,2);
	// addEdge(0,4);
	// addEdge(0,3);
	// addEdge(4,3);
	// addEdge(2,1);
	// addEdge(2,5);
	// addEdge(3,5);
	// addEdge(5,10);
	// addEdge(5,11);
	// addEdge(7,6);
	// addEdge(6,3);
	// addEdge(6,11);
	// addEdge(8,6);
	// addEdge(8,9);
	// addEdge(9,6);
	// addEdge(10,11);
	// addEdge(10,9);

	cout<<"Running Algorithm\n";

	topoSort();

	return 0;
}