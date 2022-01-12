#include <bits/stdc++.h>
using namespace std;
#define maxN 200006
#define ll long long int
#define MOD (ll)1000000007
#define in long long int
#define mod (ll)1000000007

void Solve()
{
    // Read the Question Once Again
    // check brute force with time complexity
    //  A and B do no think of algorithm.
    // Do not give up
    /*


    */
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        pq.push(temp);
        if(pq.size()==11)
        {
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();

    }
    cout<<endl;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // fun();
    ll test;
    cin >> test;
    while (test--)
        Solve();
}
