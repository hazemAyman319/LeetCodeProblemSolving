#include <iostream>
using namespace std;
const int N = 10;
int n , target;
int A[N];
int sum;
vector<int>path;
void solve(int i)
{
    if(i==n)
    {
        if(sum==target)
        {
            for(int i=0; i<path.size(); i++)
            {
                cout<<path[i]<<endl;
                cout<<[i+1 == path.size()];
            }
        }
        return;
    }
    //Option 1 -> pick
    if(sum+A[i] <= target)
    {
        sum += A[i];          //Do
        path.push_back(A[i]);
        solve(i+1]);        //Recurse
        sum -= A[i];          //Undo
        path.pop_back();
    }
    //Option 2 -> Leave
    solve(i+1);
}
int main()
{
    cin>>n>>target;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    solve(0);
    return 0;
}
