#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct lnode
{
    int l;
    int t;
};

typedef struct lnode node;

bool compareLnode(node n1, node n2)
{
    return(n1.l < n2.l);
}

void print(vector<node> arr, int N)
{
    cout << endl;
    for(int i = 0 ; i < N; i++)
    {
        cout << arr[i].l << "\t" << arr[i].t << endl;
    }
    cout << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, K;
    cin >> N >> K;
    vector<node> arr(N);
    for(int i = 0; i < N ; i++)
    {
        cin >> arr[i].l >> arr[i].t;
    }
    
    sort(arr.begin(), arr.end(), compareLnode);
    
    //print(arr, N);
    
    int subtract = 0;
    int count = 0;
    int imp = 0;
    for(int i = 0; i < N; i++)
    {
        if(1 == arr[i].t)
            imp++;
    }
    int impWin = 0;
    
    if((imp - K) > 0)
    {
        impWin = imp - K;
    }
    else
    {
        impWin = 0;
    }
    for(int i = 0; i < N; i++)
    {
        if( 0 < impWin )
        {
            if(1 == arr[i].t)
            {
                subtract += arr[i].l;
                impWin--;
            }   
        }      
    }

    int add = 0;
    for(int i = 0 ; i < N; i++)
    {
        add += arr[i].l;
    }
    cout << add - (2 * subtract);
    
    return 0;
}
