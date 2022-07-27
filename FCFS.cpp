#include<bits/stdc++.h>
#define Mx 5001
using namespace std;
int AT[Mx];
int BT[Mx];
int RT[Mx];
int CT[Mx];
int WT[Mx];
int TAT[Mx];
int PID[Mx];
double sum1 = 0, sum2 = 0, AVG_TAT, AVG_WT;
int main()
{
     freopen("p.txt","r",stdin);

        int numberOfprocess = 5000;
        int pid, bt, a;
        for(int i=0;i<5000;i++)
        {

            string str;

            cin>>str;
            for(int j=0;j<str.size();j++)if(str[j]==',')str[j]=' ';
            stringstream ss;

            ss<<str;

            ss>>pid;
            ss>>a;
            ss>>bt;
            PID[i] = pid;
            BT[i] = bt;
            AT[i] = a;


          cout<<pid<<" " <<a <<" " <<bt<<endl;
        }
    /*for(int i=1; i<=numberOfprocess; i++)
    {
        scanf("%d%d",&AT[i],&BT[i]);
    }*/

    for(int i=1; i<=numberOfprocess; i++)
    {
        RT[i] = max(CT[i-1],AT[i] );
        CT[i] = RT[i] + BT[i];
        WT[i] = CT[i] - AT[i] - BT[i];
        TAT[i] = CT[i] - AT[i];
        sum1 = sum1 + WT[i];
        sum2 = sum2 + TAT[i];
    }

    for(int i=1; i<=numberOfprocess; i++)
    {
        cout<<setw(4)<<"Process #"<<i<<": ";
        cout<<setw(4)<<" AT = "<<AT[i];
        cout<<setw(4)<<" BT = "<<BT[i];
        cout<<setw(4)<<" RT = "<<RT[i];
        cout<<setw(4)<<" CT = "<<CT[i];
        cout<<setw(4)<<" WT = "<<WT[i];
        cout<<setw(4)<<" TAT = "<<TAT[i]<<endl;
    }
    AVG_WT = sum1/numberOfprocess;
    cout<< "Average WT = " << AVG_WT <<endl;
    AVG_TAT = sum2/numberOfprocess;
    cout<< "Average TAT = " << AVG_TAT <<endl;
}
/*
    4
    0 8
    1 4
    2 9
    3 5

    */

