/// Strongly Connected Components - SCC.
/// SCC can be found by other algorithms in linear time like tarjan algorithm (articulation finding algorithm)
/// Here I will implement Kosaraju's algorithm.
/// Time Complexity O(V+E) ,linear time.

/*
If a graph has a cycle, and one particular city in this cycle is such that every other city is reachable from this node, 
then the same is true for all nodes in that cycle. 
This is a good hint that we should find all the strongly connected components and get an acyclic graph.
Now give the id number such as scc_number to each block's nodes.
Now,main idea is we have to find that scc which is reachable from other scc and their nodes.But there should not be  no edge to go from this scc.
If such scc with outer degree (zero),are more than one then it is impossible.

From which scc we can reach to our wanted scc,mark them as auxiliary scc.
Then find that scc which is stated real scc,which is reachable from other scc.
*/

/// Time-1290ms

#include<bits/stdc++.h>

using namespace std;

const int mx=100001;

bool visited[mx]={false};
bool nwvisited[mx]={false};
/// above two arrays used for finding scc 

/// this states that which scc block is auxiliary 
bool auxiliary_scc[mx]={false};
/// this state that each node's scc block number 
int scc_number[mx];
/// by this ,we count scc block.
int scc_cnt;

stack<int>st;
vector<int>adj[mx];
vector<int>rev[mx];

void dfs1(int u)
{
    visited[u]=true;
    vector<int>::iterator it;
    for(it=adj[u].begin();it!=adj[u].end();it++)
    {
        int v=(*it);
        if(!visited[v])
        {
            dfs1(v);
        }
    }
    st.push(u);
    ///it stores the nodes in the stack according to dfs time
}

void dfs2(int u)
{
    /// this node (u) is a part of the current cycle i.e. current scc block
    nwvisited[u]=true;
    /// giving the scc number to nodes in which block of scc the nodes are in
    scc_number[u]=scc_cnt;
    vector<int>::iterator it;
    for(it=rev[u].begin();it!=rev[u].end();it++)
    {
        int v=(*it);
        if(!nwvisited[v])
        {
            dfs2(v);
        }
    }
}

int main()
{
    /// directed graph
    int V,E,u,v;

    cin>>V>>E;

    while(E--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    for(int i=1;i<=V;i++)
    {
        if(!visited[i]) dfs1(i);
    }

    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(!nwvisited[node])
        {
///this function dfs2 will print the scc block including node
            dfs2(node);
            scc_cnt++;
        }
    }

    /// O(V+E) time complexity of two loops
    /// It will distinguish those scc from where we can come to our real scc whose all nodes may be candidate cities.
     for (int i=1; i<=V; i++)
    {
	for (int j=0; j<adj[i].size(); j++)
	{
	    if (scc_number[adj[i][j]]!=scc_number[i])
        {
		auxiliary_scc[scc_number[i]]=true;
	    }
	}
     }
     int scc_ans_number=-1;
     int real_scc=0;
    ///if real scc are two,then it is impossible.
    for(int j=0;j<scc_cnt;j++)
    {
        if(!auxiliary_scc[j])
        {
            scc_ans_number=j;
            real_scc++;
        }
    }

    if(real_scc>1) {cout<<"0"<<endl;return 0;}

    int number_of_nodes_of_real_scc=0;

    vector<int>vec;

    for(int j=1;j<=V;j++)
    {
        if(scc_number[j]==scc_ans_number)
        {
            number_of_nodes_of_real_scc++;
            vec.push_back(j);
        }
    }

    cout<<number_of_nodes_of_real_scc<<endl;
    for(int l=0;l<vec.size();l++)
    {
        cout<<vec[l]<<" ";
    }

    cout<<endl;

    return 0;
}
