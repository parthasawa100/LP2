#include <bits/stdc++.h>
using namespace std;

class state
{
    public:
    int st[3][3];
    int f=INT_MAX,g=0,h=INT_MAX;
    int x,y;
    bool flag=0;
};
vector<state> possible_moves;
state start,goal;

int H(state s)
{
    int h=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(s.st[i][j]!=goal.st[i][j])
            h++;
        }
    }
    return h;
}

void print(state s)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<s.st[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"F = "<<s.f<<" G = "<<s.g<<" H = "<<s.h<<endl;
}
void moves(state s, int g)
{
    cout<<"\nThe possible moves are"<<endl;
    if(s.x>0)
    {
        state n=s;
        swap(n.st[n.x][n.y],n.st[n.x-1][n.y]);
        n.x--;n.flag=0;
        n.h=H(n);
        n.f=n.h+g;
        n.g=g;
        possible_moves.push_back(n);
        print(n);
    }
    if(s.x<2)
    {
        state n=s;
        swap(n.st[n.x][n.y],n.st[n.x+1][n.y]);
        n.x++;
        n.h=H(n);n.flag=0;
        n.f=n.h+g;
        n.g=g;
        possible_moves.push_back(n);
        print(n);
    }
    if(s.y<2)
    {
        state n=s;
        swap(n.st[n.x][n.y],n.st[n.x][n.y+1]);
        n.y++;
        n.h=H(n);
        n.f=n.h+g;n.flag=0;
        n.g=g;
        possible_moves.push_back(n);
        print(n);
    }
    if(s.y>0)
    {
        state n=s;
        swap(n.st[n.x][n.y],n.st[n.x][n.y-1]);
        n.y--;
        n.h=H(n);n.flag=0;
        n.f=n.h+g;
        n.g=g;
        possible_moves.push_back(n);
        print(n);
    }

}

int main()
{
    cout<<"Enter start state and use 0 for blank"<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>start.st[i][j];
            if(start.st[i][j]==0)
            {
                start.x=i;start.y=j;
            }
        }
    }

    cout<<"Enter goal state and use 0 for blank"<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>goal.st[i][j];
            if(goal.st[i][j]==0)
            {
                goal.x=i;goal.y=j;
            }
        }
    }

    start.f=H(start),start.h=H(start);
    possible_moves.push_back(start);
    int g=0;int c=0;int z=0;

    while(!possible_moves.empty())
    {
        g++;
        int min_f=INT_MAX;

        for (int i=0;i<possible_moves.size();i++)
        {
            //cout<<possible_moves[i].flag<<endl;
            if(possible_moves[i].f<min_f && possible_moves[i].flag!=1)
            {
                min_f=possible_moves[i].f;
                z=i;
            }
            if(possible_moves[i].h==0)
            {
                cout<<"The goal state has reached :"<<endl;
                print(possible_moves[i]);
                c=1;
                break;
            }
        }

        if(c==1)
        break;
        cout<<"The selected state is :"<<endl;
        possible_moves[z].flag=1;
        print(possible_moves[z]);
        moves(possible_moves[z],g);
    }
    return 0;

}