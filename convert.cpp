#include <bits/stdc++.h>
using namespace std;
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
struct node{
    int idx;
    map<char, edge> edges;
    node(int i = -1){
        idx = i;
    }
};
int main(){

    return 0;
}