

#include <bits/stdc++.h>
using namespace std;


#define GREY 1
#define WHITE 0
#define BLACK 2


int color1[100005];
vector <int> adj[100005];
stack<int>st,st2;
int counter;
map<char, int> m1;
map<int, char> m2;



void DFS1(int u,vector<int>greyList)
{
    color1[u] = GREY;

    greyList.push_back(u);

    int s = adj[u].size();

    for(int i = 0; i < s; i++)
    {
        int v = adj[u][i];

        vector<int>::iterator it;
        it = find (greyList.begin(), greyList.end(), v);

        if(color1[v] == WHITE)
        {
                DFS1(v,greyList);
        }

        else if(color1[v]==GREY)
        {
            counter++;
            cout << m2[v] << " ";
            cout << "Cycle found " << endl;

            vector<int>::iterator it1;

            for(it1=it ;it1!=greyList.end();it1++)
            {
                cout << m2[*it1] << " ";
            }
            cout << endl;
            adj[u].erase(find(adj[u].begin(),adj[u].end(),v));
        }
    }

    color1[u] = BLACK;
}

int main()
{
    int n;

    cout << "Enter the number of nodes : ";
    cin >> n;

    cout << "Node Names : ";

    char s;

    for(int i =0;i<n;i++)
    {
        cin >> s;
        m1[s] = i;
        m2[i] = s;
    }

    getchar();

    map <char, int> :: iterator it;
    int x;
    cout << "Enter the number of edges : " << endl;
    cin >> x;
    getchar();

    string s1;
    cout << "Edges : " << endl;

    while(getline(cin , s1) && x--)
    {
        adj[m1[s1[0]]].push_back(m1[s1[2]]);
    }

    for(int i =0;i<n;i++)
    {
        cout << i << " : ";

        for(int j=0;j<adj[i].size();j++)
        {
            cout << adj[i][j] << " ";
        }

        cout << endl;
    }

    vector<int>greyList;

    for(int i =0; i<n;i++)
    {
        if(color1[i]==0)
        {
            greyList.clear();
            DFS1(i,greyList);
        }
    }

    for(int i =0;i<n;i++)
    {
        color1[i]= 0;
    }

    counter = 0;

    for(int i =0; i<n;i++)
    {
        if(color1[i]==0)
        {
            greyList.clear();
            DFS1(i,greyList);
        }
    }


    if(counter==0)
        cout << "No deadlock found " << endl;


    for(int i =0;i<n;i++)
    {
        cout << i << " : ";

        for(int j=0;j<adj[i].size();j++)
        {
            cout << adj[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}

/*
13
R A S C F W D B T E V G U
13
R A
A S
C S
W F
F S
D S
D T
B T
T E
E V
V G
G U
U D
*/
