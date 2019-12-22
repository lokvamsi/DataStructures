#include <bits/stdc++.h>
#define INF 9999
using namespace std;

//Defining pair of integers representing vertice and weight for each edge.
typedef pair <int,int> myPair;

//Hard coding the size of the graph and adjacency matrix.
int V = 10;
vector<myPair> adjacent[10];


//Function to insert an edge into corresponding list index with weight.
void insertEdge(int a, int b, int w){
	adjacent[a].push_back(make_pair(b,w));
}

//Function to print initial Graph.
void printAdjacent(){

	cout<<"Printing Graph Vertices:\n";
	cout<<"Vertices: ";
	for(int i = 0; i<V; i++){
			cout<<i <<" ";
		}
	cout<<"\n";
	cout<<"\n";

	cout<<"Printing Graph Edges:\n";

	for(int i =0;i<20;i++){
		int a = i;
		vector<myPair>::iterator it;
		for(it = adjacent[a].begin(); it!=adjacent[a].end(); it++){
			cout<<a<<" -> "<<it->first<<" Weight = "<<it->second<<"\n";
		}
	}
	cout<<"\n";
}

//Function implementing Dijkstras Algorithm using MinHeap.
void dijkstras(int start){

	cout<<"Running Algorithm...\n";
	
	//Declaring Min Heap.
	//Defining each pair as <distance from start, node name>
	priority_queue <myPair, vector<myPair>, greater<myPair> > min_heap;

	//List for holding distance from start to node, all set to INF.
	vector <int> distance(V,INF);
	vector <int> parent(V,0);
	parent[start] = 0;
	distance[start] = 0;

	//Inserting start node into heap.
	min_heap.push(make_pair(0,start));

	while(!min_heap.empty()){

		//Extracting vertex with min distance so far.
		int a = min_heap.top().second;

		min_heap.pop();

		//Looking at adjacent nodes and update distances.
		vector<myPair>::iterator it;
		for(it = adjacent[a].begin(); it!=adjacent[a].end(); it++){
			
			//First holds the node name, second holds the weight.
			int b = it->first;
			int w = it->second;

			//Update if new distance is less than old.
			if(distance[b] > distance[a] + w){
				distance[b] = distance[a] + w;
				parent[b] = a;
				//Add this node to heap.
				min_heap.push(make_pair(distance[b],b));
			}
		}
	}

	cout<<"Algorithm Completed!\n";
	cout<<"\n";

	//Printing results.

	cout<<"Printing final shortest distances from start:\n";
	for(int i = 0; i<V; i++){
		cout<<"Vertex: "<< i << " Distance: " << distance[i] << "\n";
	}
	cout<<"\n";

	cout<<"Printing Final Graph Vertices:\n";
	cout<<"Vertices: ";
	for(int i = 0; i<V; i++){
			cout<<i <<" ";
		}

	cout<<"\n";
	cout<<"\n";

	cout<<"Printing Final Graph Edges:\n";
	for(int i = 0; i<V; i++){
		cout<<parent[i]<<" -> "<<i;
		cout<<" Weight = "<<distance[i]-distance[parent[i]]<< "\n";
	}
}

int main(){

	//Creating the graph.
	insertEdge(0, 4, 2); 
	insertEdge(0, 5, 2); 
	insertEdge(0, 1, 2); 
	insertEdge(0, 2, 2); 
	insertEdge(1, 7, 2); 
	insertEdge(1, 5, 2); 
	insertEdge(2, 9, 3); 
	insertEdge(2, 3, 2); 
	insertEdge(2, 4, 2); 
	insertEdge(3, 6, 2); 
	insertEdge(4, 5, 2); 
	insertEdge(5, 3, 2); 
	insertEdge(6, 1, 2); 
	insertEdge(7, 8, 2); 
	insertEdge(8, 9, 2); 
	insertEdge(8, 2, 3); 
	insertEdge(9, 6, 2); 

	//Printing initial Graph
	printAdjacent();

	//Running the algorithm and printing results.
	dijkstras(0);

	return 0;

}