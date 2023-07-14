#include<bits/stdc++.h>
#define infinity 102040
using namespace std;

// Array to marh whether an edge is knowned or not
bool known[infinity];

int j=1;
// Depth First Search Algorithm Implmentation
void DFS(int n, list<int>adj[], int arr[], int num)
{
    j++;
    list<int>::iterator itr;
    for(itr=adj[n].begin();itr!=adj[n].end();itr++)
	{
		if(!known[*itr])
		{
    		known[*itr]=true;
    		DFS(*itr,adj,arr,num);
		}
        if(known[*itr])
		{
            j++;
        }
      
    }
    arr[n]=j;
}


void hashsearch(list<int>T[], int k,int num,bool found[])
{
    list <int> :: iterator it;
    for(int p =0; p<num;p++)
	{
	    for(it = T[p].begin(); it != T[p].end(); ++it)
		{
	        if(*it==k)
			{
	            cout<<p<<endl;
	            found[k]=true;
	            break;
	        }
	       
	    }
    }
    if(!found[k])
	{
        cout<<k<<endl;
    }
}


void dfs2(int n, list<int>t[], list<int>last[], int in)
{
    list<int>::iterator it;
    for(it = t[n].begin();it!=t[n].end();it++)
	{
        if (!known[*it])
		{
        	last[in].push_back(n);
            known[*it]=true;
            dfs2(*it,t,last,in);
        }
      
    }    
}

// Function to insert a vertice at a given edge in adjacency matrix
void insert(int vericies, int edge, list<int>adjMat[])
{
    adjMat[edge].push_back(vericies);
}


void printtable(int num, list<int>adj[])
{
    list <int> :: iterator it;
    for(int i = 0; i<num;i++)
	{
        cout<<i<<":";
        for(it = adj[i].begin(); it != adj[i].end(); ++it)
		{
            cout<<*it<<"->";
		}
        cout<<";"<<endl;
    }
}


void transpose(list<int>T[],list<int>adjMat[],int num)
{
	// Given a adjacency matrix adj this method is finding its transpose and storing it in T
    list <int> :: iterator itr;
    for(int i=0;i<num;i++)
	{
        for(itr=adjMat[i].begin();itr!=adjMat[i].end();++itr)
		{
            T[*itr].push_back(i);
        }
    }
}


void Scc(list<int>T[],int nums, int arr[],list<int>last[])
{
    for(int i =0; i<nums;i++)
	{
        if(!known[i])
		{
        	dfs2(arr[i], T, last,arr[i]);
        }
    }
    
}

void order(int arr[], int num, int order[])
{
    int o =0;
    for (int i =0; i <num;i++)
	{
        o = distance(arr, max_element(arr, arr + num));
        order[i]=o;
        arr[o]=0;
    }   
}
    


int main(int argc, const char * argv[]) 
{
    int loop=0 , numOfNodes;
    
    cin>>numOfNodes;
    cin>>loop;
    
    int arr[numOfNodes] , S[numOfNodes] , verticies , edges;
    
    // Adjacency Matrix to store the Graph represetation
    list<int>adjMat[numOfNodes];
    list<int>t[numOfNodes];
    list<int>last[numOfNodes];
    
    // Loop to get the vertices and edges and insert in the adjacency matrix
    for(int l=0; l<loop;l++)
	{
	    cin>>verticies>>edges;
	    insert(edges, verticies, adjMat);
    }
    
    // Transposing the Adjacency Matrix
    transpose(t,adjMat,numOfNodes);

	// Performing Depth First Search and storing in arr
    DFS(0,adjMat,arr,numOfNodes);

    for (int v=0;v<numOfNodes;v++)
	{
        if(!known[v])
		{
            arr[v]=j+2;
        }
        known[v]=NULL;
    }
    

    int o =0;
    for (int i =0; i <numOfNodes;i++)
	{
       	o = distance(arr, max_element(arr, arr + numOfNodes));
        S[i]=o;
        arr[o]=0;
    }   
	


    Scc(t, numOfNodes, S, last);
  
    for (int v=0;v<numOfNodes;v++)
	{
        if(!known[v])
		{
            last[v].push_back(v);
        }
    }
    
    bool foud[numOfNodes];
    
    // knownng each nod and finding to which strongly connected component hash do they belong to
    for(int p=0;p<numOfNodes;p++)
	{
       hashsearch(last, p, numOfNodes,foud);
    }
}

