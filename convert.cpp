#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n;
vector<node> TM;
struct edge{
    char push;
    char pop;
    int to;
    char dir;
    edge(){
        push = 0;
        pop = 0;
        to = -1;
        dir = 0;
    }
    edge(char po, int t, char pu, char c){
        push = pu;
        pop = po;
        to = t;
        dir = c;
    }
};
struct dnode{
    int idx;
    map<char, pair<edge, edge>> edges;
    dnode(int i = -1){
        idx = i;
    }
};
struct node{
    int idx;
    map<char, edge> edges;
    node(int i = -1){
        idx = i;
    }
};
void addGetToE(int curi){

}
void addGetToe(int curi){
    node from = TM[curi];

}
void addConverterTM(){
    node start = node(0);
    TM.pb(start);
    start.edges['1'] = edge('1', 1, 'e', 'R');
    start.edges['0'] = edge('0', 2, 'e', 'R');

    node cur = node(1);
    cur.edges['_'] = edge('_', 3, '1', 'R');
    cur.edges['0'] = edge('0', 2, '1', 'R');
    TM.pb(cur);

    cur = node(2);
    cur.edges['_'] = edge('_', 3, '0', 'R');
    cur.edges['1'] = edge('1', 1, '0', 'R');
    TM.pb(cur);

    cur = node(3);
    cur.edges['_'] = edge('_', 4, '#', 'R');
    TM.pb(cur);

    cur = node(4);
    cur.edges['_'] = edge('_', 5, 'E', 'R');
    TM.pb(cur);

    cur = node(5);
    cur.edges['_'] = edge('_', 6, '!', 'L');
    TM.pb(cur);
    cur = node(6);
    TM.pb(cur);
    addGetToe(6);
}
void convertTM(dnode nodes[]){
    addConverterTM();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    dnode nodes[n];
    for(int i = 0; i < n - 1; i++){
        nodes[i] = dnode(i);
        char pop1, push1, pop2, push2, dir1, dir2;
        int to;
        cin >> pop1 >> pop2 >> to >> push1 >> push2 >> dir1 >> dir2;
        auto newP = make_pair(edge(pop1, to, push1, dir1), edge(pop2, to, push2, dir2));
        nodes[i].edges[pop1] = newP;
    }
    convertTM(nodes);
    return 0;
}