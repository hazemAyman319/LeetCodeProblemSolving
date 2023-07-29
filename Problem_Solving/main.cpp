#include <iostream>
using namespace std;
const int N = 10;

int n , m;
char grid[N][N];
string path;
void solve(int r , int c)
{
    if(r == n-1 && c == m-1) //BaseCase Cheese Found
    {
        cout<<path.c_str()<<endl;
        return;
    }
    if(c+1 < m && grid[r][c+1] != '#')//Option Right
    {
        path.push_back('R');
        solve(r , c+1);
        path.pop_back();
    }
    if(r+1 < n && grid[r+1][c] != '#')//Option Down
    {
        path.push_back('D');
        solve(r+1 , c);
        path.pop_back();
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>grid[i];
    }
    solve(0,0);
    return 0;
}
