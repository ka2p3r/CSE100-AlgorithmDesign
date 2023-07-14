#include <iostream>
#include <limits.h>
using namespace std;

void bellmanFordAlgo(int n, int c){
	
    int **myGraph;
	myGraph = new int *[3];
	int s=0, d=0, w=0;
	bool var = true;
    int dist[n];

    for(int i = 0; i < n; i++){
		dist[i] = INT_MAX;

        myGraph[i] = new int[c];
		for(int j = 0; j < n; j++){
			myGraph[i][j] = 0;
		}
	}

	for(int i = 0; i < c; i++){
		cin>>myGraph[0][i]>>myGraph[1][i]>>myGraph[2][i];
	}

    dist[0] = 0;

	for(int i = 1; i <= n - 1; i++){
		for(int j = 0; j < c; j++){

			int x = myGraph[0][j], y = myGraph[1][j], w = myGraph[2][j];

			if(dist[x] != INT_MAX && dist[x] + w < dist[y]){
				dist[y] = dist[x] + w;
			}
		}
	}

	for(int i = 0; i < c; i++){
	
		int x = myGraph[0][i], y = myGraph[1][i], w = myGraph[2][i];

		if(dist[x] != INT_MAX && dist[x] + w < dist[y]){
            //case-2
			var=false;
            break;
		}

	}

	if(var){
        //case1
		cout << "TRUE" << endl;
		for(int i = 0; i < n; i++){
			if(dist[i] == INT_MAX){
				cout << "INFINITY" << endl;
			}
            else{
				cout << dist[i] << endl;
			}
		}
	}else{
        cout << "FALSE" << endl;
    }
}

int main(){

	int n, c;
	cin>>n>>c;

	bellmanFordAlgo(n,c);
}