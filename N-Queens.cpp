#include <iostream>
using namespace std;
const int N = 10;
int n;
char grid[N][N];
bool isValid(int r , int c)
{
    for(int r2 = r-1 , c2 = c-1; r2 >= 0 && c2 >= 0;r2-- , c2--)
    {
        if(grid[r2][c2]=='Q')
        {
            return false;
        }
    }
    for(int r2 = r-1 , c2 = c+1; r2 >= 0 && c2 < n;r2-- , c2++)
    {
        if(grid[r2][c2]=='Q')
        {
            return false;
        }
    }
    for(int r2 = r-1; r2 >= 0;r2--)
    {
        if(grid[r2][c]=='Q')
        {
            return false;
        }
    }
    return true;
}
void solve(int r) //takes the row I am in
{
    if(r==n)
    {
        //Base-case
        for(int i=0;i<n;i++)
        {
            cout<<grid[i]<<endl;
        }
        cout<<"--------------------------"<<endl;
        return;
    }
    for(int c=0; c<n; c++)//my options on every row
    {
        //is valid
        if(isValid(r , c))
        {
            //DO
            grid[r][c]='Q';
            //Recurse
            solve(r+1);
            //undo
            grid[r][c]='.';
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        fill(grid[i] , grid[i]+n , '.');
    }
    solve(0);
}
