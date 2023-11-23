#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node
{
    int x, y, visited, val;
    Node(int xx = 0, int yy = 0)
    {
        x = xx, y = yy, visited = 0, val = 0;
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        Node maze[n][n];
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                maze[i][j].x = i, maze[i][j].y = j;
                cin >> maze[i][j].val;
            }
        }
        stack<Node> path;
        path.push(Node(0,0));
        int succeed = 0;
        if(maze[0][0].val == 0)
        {
            
        
        while(!path.empty())
        {
            Node curr = path.top();
            if(curr.x == n-1 && curr.y == n-1)
            {
                succeed = 1;
                break;
            }
            maze[curr.x][curr.y].visited = 1;
            int next_x = curr.x + 1;
            int next_y = curr.y + 1;
            if(next_y < n)   //东
            {
                if(!maze[curr.x][next_y].val && !maze[curr.x][next_y].visited)
                {
                    // maze[curr.x][next_y].visited = 1;
                    path.push(Node(curr.x, next_y));
                    continue;
                }
            }
            if(next_x < n)   //南
            {
                if(!maze[next_x][curr.y].val && !maze[next_x][curr.y].visited)
                {
                    // maze[next_x][curr.y].visited = 1;
                    path.push(Node(next_x, curr.y));
                    continue;
                }
            }
            if(curr.y - 1 >= 0)   //西
            {
                if(!maze[curr.x][curr.y-1].val && !maze[curr.x][curr.y-1].visited)
                {
                    // maze[curr.x][curr.y-1].visited = 1;
                    path.push(Node(curr.x, curr.y-1));
                    continue;
                }
            }
            if(curr.x - 1 >= 0)   //北
            {
                if(!maze[curr.x-1][curr.y].val && !maze[curr.x-1][curr.y].visited)
                {
                    // maze[curr.x-1][curr.y].visited = 1;
                    path.push(Node(curr.x-1, curr.y));
                    continue;
                }
            }
            path.pop();
        }

        }
        if(!succeed)
        {
            cout << "no path" << endl;
        }
        else
        {
            stack<Node> path1;
            while(!path.empty())
            {
                Node temp = path.top();
                path1.push(temp);
                path.pop();
            }
            int i=0;  //以下是输出路径的代码
            while (!path1.empty())
            {   
                Node cpos = path1.top();
                if ( (++i)%4 == 0 ) 
                    cout<<'['<<cpos.x<<','<<cpos.y<<']'<<"--"<<endl;
                else
                    cout<<'['<<cpos.x<<','<<cpos.y<<']'<<"--";
                path1.pop();
            }
            cout<<"END"<<endl;
        }
    }
    return 0;
}