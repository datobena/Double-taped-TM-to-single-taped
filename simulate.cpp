#include <bits/stdc++.h>
using namespace std;


int n;
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
void simulateOn(node nodes[], vector<char>& tape){
    int i = 0;
    int curNode = 0;
    while(true){
        if(i == tape.size()) tape.push_back('_');
        if(curNode == n - 1) break;
        char read = tape[i];
        if(nodes[curNode].edges.find(read) == nodes[curNode].edges.end()){
            cout << -1 << endl;
            return;
        }
        edge curEdge = nodes[curNode].edges[read];
        tape[i] = curEdge.push;
        curNode = curEdge.to;
        cout << curNode << endl;
        if(curEdge.dir == 'L') i--;
        else i++;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    node nodes[n];
    for(int i = 0; i < n - 1; i++){
        nodes[i].idx = i;
        int times;
        cin >> times;
        while(times--){
            int to;
            char read, write, c;
            cin >> read >> to >> write >> c;
            edge cur = edge(read, to, write, c);
            nodes[i].edges[read] = cur;
        }
    }
    nodes[n - 1] = node(n - 1);
    int num;   
    vector<char> tape;
    string st;
    cin >> st;
    for(char c : st)
        tape.push_back(c);
    simulateOn(nodes, tape);

    return 0;
}