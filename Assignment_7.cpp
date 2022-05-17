/*Represent a given graph using adjacency matrix/list to perform DFS and using adjacency list to perform BFS. 
Use the map of the area around the college as the graph. Identify the prominent land marks as nodes and perform DFS and BFS on that.*/

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

void DFS(int a[10][10],int n)
{
    int v[100];
    int v1;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
    }
    cout<<"Enter Vertex to start DFS from: "<<endl;
    cin>>v1;
    //v1=0;
    s.push(v1);
    while (!s.empty())
    {
        v1 = s.top();
        s.pop();
        if (v[v1] == 0)
        {
            cout << v1 << " ";
            v[v1] = 1;
            for (int v2 = 0; v2 <= n; v2++)
            {
                if (a[v1][v2] == 1)
                {
                    s.push(v2);
                }
            }
        }
    }
}

void BFS(int a[10][10], int n)
{
    int v[100];
    int v1;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
    }
    cout<<"Enter Vertex to start BFS from: "<<endl;
    cin>>v1;
    q.push(v1);
    v[v1] = 1;
    while (!q.empty())
    {
        v1 = q.front();
        q.pop();
        cout << v1 << " ";
        for (int v2 = 0; v2 < n; v2++)
        {
            if (a[v1][v2] == 1 && v[v2] == 0)
            {
                q.push(v2);
                v[v2] = 1;
            }
        }
    }
}

int main()
{
    int cost[10][10];
    int m, n, i, j, k;
    cout << "Enter number of vertices : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> m;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cost[i][j]=0;        
            }
       
    }
    cout << "\nEDGES :\n";
    for (k = 1; k <= m; k++)
    {
        cin >> i >> j;
        cost[i][j] = 1;
        cost[j][i] = 1;
    }
    // display function
    cout << "The adjacency matrix of the graph is : " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }
    cout << "DFS is: " << endl;
    DFS(cost,n);
    cout<<"\nBFS is: "<<endl;
    BFS(cost,n);

    return 0;
}
