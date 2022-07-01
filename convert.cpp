#include <bits/stdc++.h>
using namespace std;
#define pb push_back
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
    map<char, vector<pair<edge, edge>>> edges;
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
int n;
vector<node> TM;
map<int, int> indexMap;
char getChar(char c){
    if(c == '1') return 'I';
    if(c == '0') return 'O';
    if(c == '_') return 'E';
    if(c == '#') return '$';
    return 0;
}
int addGetToRight(int curi){
    int from = curi;
    TM[from].edges['E'] = edge('E', TM[from].idx, 'E', 'R');
    TM[from].edges['O'] = edge('O', TM[from].idx, 'O', 'R');
    TM[from].edges['I'] = edge('I', TM[from].idx, 'I', 'R');
    TM[from].edges['0'] = edge('0', TM[from].idx, '0', 'R');
    TM[from].edges['1'] = edge('1', TM[from].idx, '1', 'R');
    TM[from].edges['_'] = edge('_', TM[from].idx, '_', 'R');
    TM[from].edges['#'] = edge('#', TM.size(), '#', 'R');
    TM.pb(node(TM.size()));
    from = TM.size() - 1;
    TM[from].edges['0'] = edge('0', TM[from].idx, '0', 'R');
    TM[from].edges['1'] = edge('1', TM[from].idx, '1', 'R');
    TM[from].edges['_'] = edge('_', TM[from].idx, '_', 'R');
    TM[from].edges['E'] = edge('E', TM.size(), 'E', 'L');
    TM[from].edges['O'] = edge('O', TM.size(), 'O', 'L');
    TM[from].edges['I'] = edge('I', TM.size(), 'I', 'L');
    TM.pb(node(TM.size()));
    from = TM.size() - 1;
    TM[from].edges['0'] = edge('0', TM.size(), '0', 'R');
    TM[from].edges['1'] = edge('1', TM.size(), '1', 'R');
    TM[from].edges['_'] = edge('_', TM.size(), '_', 'R');
    TM[from].edges['#'] = edge('#', TM.size(), '#', 'R');
    TM.pb(node(TM.size()));
    return TM.size() - 1;
}
int addGetToLeft(int curi){
    int from = curi;
    TM[from].edges['E'] = edge('E', TM[from].idx, 'E', 'L');
    TM[from].edges['O'] = edge('O', TM[from].idx, 'O', 'L');
    TM[from].edges['I'] = edge('I', TM[from].idx, 'I', 'L');
    TM[from].edges['0'] = edge('0', TM[from].idx, '0', 'L');
    TM[from].edges['1'] = edge('1', TM[from].idx, '1', 'L');
    TM[from].edges['_'] = edge('_', TM[from].idx, '_', 'L');
    TM[from].edges['#'] = edge('#', TM.size(), '#', 'L');
    TM.pb(node(TM.size()));
    from = TM.size() - 1;
    TM[from].edges['0'] = edge('0', TM[from].idx, '0', 'L');
    TM[from].edges['1'] = edge('1', TM[from].idx, '1', 'L');
    TM[from].edges['_'] = edge('_', TM[from].idx, '_', 'L');
    TM[from].edges['E'] = edge('E', TM.size(), 'E', 'R');
    TM[from].edges['O'] = edge('O', TM.size(), 'O', 'R');
    TM[from].edges['I'] = edge('I', TM.size(), 'I', 'R');
    TM.pb(node(TM.size()));
    from = TM.size() - 1;
    TM[from].edges['0'] = edge('0', TM.size(), '0', 'L');
    TM[from].edges['1'] = edge('1', TM.size(), '1', 'L');
    TM[from].edges['_'] = edge('_', TM.size(), '_', 'L');
    TM[from].edges['#'] = edge('#', TM.size(), '#', 'L');
    TM.pb(node(TM.size()));
    int res= TM.size() - 1;
    return res;
}
int addConverterToOneTM(){
    TM.pb(node(TM.size()));
    int cur = TM.size() - 1;
    TM[cur].edges['1'] = edge('1', TM.size(), 'I', 'R');
    TM[cur].edges['0'] = edge('0', TM.size(), 'O', 'R');
    TM[cur].edges['_'] = edge('_', TM.size(), 'E', 'R');
    TM.pb(node(TM.size()));
    cur = TM.size() - 1;
    TM[cur].edges['1'] = edge('1', TM.size() - 1, '1', 'R');
    TM[cur].edges['0'] = edge('0', TM.size() - 1, '0', 'R');
    TM[cur].edges['_'] = edge('_', TM.size(), '#', 'R');
    TM.pb(node(TM.size()));
    cur = TM.size() - 1;
    TM[cur].edges['_'] = edge('_', TM.size(), 'E', 'R');
    TM.pb(node(TM.size()));
    cur = TM.size() - 1;
    TM[cur].edges['_'] = edge('_', TM.size(), '!', 'L');
    TM.pb(node(TM.size()));
    return addGetToLeft(TM.size() - 1);
}
void addIfEnd(int curNode){
    TM.pb(node(TM.size()));
    int hashtag = TM.size() - 1;
    TM.pb(node(TM.size()));
    int one = TM.size() - 1;
    TM.pb(node(TM.size()));
    int zero = TM.size() - 1;
    TM.pb(node(TM.size()));
    int capI = TM.size() - 1;
    TM.pb(node(TM.size()));
    int capO = TM.size() - 1;
    TM.pb(node(TM.size()));
    int empty = TM.size() - 1;
    TM.pb(node(TM.size()));
    int capE = TM.size() - 1;
    TM.pb(node(TM.size()));
    int last = TM.size() - 1;
    TM.pb(node(TM.size()));
    int goBack = TM.size() - 1;
    TM.pb(node(TM.size()));
    int end = TM.size() - 1;
    TM[curNode].edges['!'] = edge('!', TM[last].idx, '$', 'R');
    TM[curNode].edges['#'] = edge('#', TM[hashtag].idx, '$', 'R');
    //hashtag
    TM[hashtag].edges['1'] = edge('1', TM[one].idx, '#', 'R');
    TM[hashtag].edges['0'] = edge('0', TM[zero].idx, '#', 'R');
    TM[hashtag].edges['I'] = edge('I', TM[capI].idx, '#', 'R');
    TM[hashtag].edges['O'] = edge('O', TM[capO].idx, '#', 'R');
    TM[hashtag].edges['_'] = edge('_', TM[empty].idx, '#', 'R');
    TM[hashtag].edges['E'] = edge('E', TM[capE].idx, '#', 'R');
    TM[hashtag].edges['!'] = edge('!', TM[last].idx, '#', 'R');
    // zero
    TM[zero].edges['1'] = edge('1', TM[one].idx, '0', 'R');
    TM[zero].edges['0'] = edge('0', TM[zero].idx, '0', 'R');
    TM[zero].edges['I'] = edge('I', TM[capI].idx, '0', 'R');
    TM[zero].edges['O'] = edge('O', TM[capO].idx, '0', 'R');
    TM[zero].edges['_'] = edge('_', TM[empty].idx, '0', 'R');
    TM[zero].edges['E'] = edge('E', TM[capE].idx, '0', 'R');
    TM[zero].edges['!'] = edge('!', TM[last].idx, '0', 'R');
    //one
    TM[one].edges['1'] = edge('1', TM[one].idx, '1', 'R');
    TM[one].edges['0'] = edge('0', TM[zero].idx, '1', 'R');
    TM[one].edges['I'] = edge('I', TM[capI].idx, '1', 'R');
    TM[one].edges['O'] = edge('O', TM[capO].idx, '1', 'R');
    TM[one].edges['_'] = edge('_', TM[empty].idx, '1', 'R');
    TM[one].edges['E'] = edge('E', TM[capE].idx, '1', 'R');
    TM[one].edges['!'] = edge('!', TM[last].idx, '1', 'R');
    //capI
    TM[capI].edges['1'] = edge('1', TM[one].idx, 'I', 'R');
    TM[capI].edges['0'] = edge('0', TM[zero].idx, 'I', 'R');
    TM[capI].edges['I'] = edge('I', TM[capI].idx, 'I', 'R');
    TM[capI].edges['O'] = edge('O', TM[capO].idx, 'I', 'R');
    TM[capI].edges['_'] = edge('_', TM[empty].idx, 'I', 'R');
    TM[capI].edges['E'] = edge('E', TM[capE].idx, 'I', 'R');
    TM[capI].edges['!'] = edge('!', TM[last].idx, 'I', 'R');
    //capO
    TM[capO].edges['1'] = edge('1', TM[one].idx, 'O', 'R');
    TM[capO].edges['0'] = edge('0', TM[zero].idx, 'O', 'R');
    TM[capO].edges['I'] = edge('I', TM[capI].idx, 'O', 'R');
    TM[capO].edges['O'] = edge('O', TM[capO].idx, 'O', 'R');
    TM[capO].edges['_'] = edge('_', TM[empty].idx, 'O', 'R');
    TM[capO].edges['E'] = edge('E', TM[capE].idx, 'O', 'R');
    TM[capO].edges['!'] = edge('!', TM[last].idx, 'O', 'R');
    //empty
    TM[empty].edges['1'] = edge('1', TM[one].idx,   '_', 'R');
    TM[empty].edges['0'] = edge('0', TM[zero].idx,  '_', 'R');
    TM[empty].edges['I'] = edge('I', TM[capI].idx,  '_', 'R');
    TM[empty].edges['O'] = edge('O', TM[capO].idx,  '_', 'R');
    TM[empty].edges['_'] = edge('_', TM[empty].idx, '_', 'R');
    TM[empty].edges['E'] = edge('E', TM[capE].idx,  '_', 'R');
    TM[empty].edges['!'] = edge('!', TM[last].idx,  '_', 'R');
    //capE
    TM[capE].edges['1'] = edge('1', TM[one].idx,   'E', 'R');
    TM[capE].edges['0'] = edge('0', TM[zero].idx,  'E', 'R');
    TM[capE].edges['I'] = edge('I', TM[capI].idx,  'E', 'R');
    TM[capE].edges['O'] = edge('O', TM[capO].idx,  'E', 'R');
    TM[capE].edges['_'] = edge('_', TM[empty].idx, 'E', 'R');
    TM[capE].edges['E'] = edge('E', TM[capE].idx,  'E', 'R');
    TM[capE].edges['!'] = edge('!', TM[last].idx,  'E', 'R');

    
    TM[last].edges['_'] = edge('_', TM[goBack].idx, '!', 'L');
    TM[goBack].edges['1'] = edge('1', TM[goBack].idx,   '1', 'L');
    TM[goBack].edges['0'] = edge('0', TM[goBack].idx,  '0', 'L');
    TM[goBack].edges['I'] = edge('I', TM[goBack].idx,  'I', 'L');
    TM[goBack].edges['O'] = edge('O', TM[goBack].idx,  'O', 'L');
    TM[goBack].edges['_'] = edge('_', TM[goBack].idx, '_', 'L');
    TM[goBack].edges['E'] = edge('E', TM[goBack].idx,  'E', 'L');
    TM[goBack].edges['#'] = edge('#', TM[goBack].idx,  '#', 'L');
    

    TM[goBack].edges['$'] = edge('$', TM[end].idx,  '_', 'R');
    TM[end].edges['1'] = edge('1', TM[curNode].idx,   '1', 'L');
    TM[end].edges['0'] = edge('0', TM[curNode].idx,  '0', 'L');
    TM[end].edges['_'] = edge('_', TM[curNode].idx, '_', 'L');
    TM[end].edges['#'] = edge('#', TM[curNode].idx,  '#', 'L');
    TM[end].edges['!'] = edge('!', TM[curNode].idx,  '!', 'L');

    

}
void changeAndGo(char dir, int curi, int dest){
    int curNode = curi;
    dir = (dir == 'L' ? 'R' : 'L');
    if(dir != 'R')
        addIfEnd(curNode);
    else
        TM[curNode].edges['#'] = edge('#', TM.size(), '#', 'R');
    TM[curNode].edges['1'] = edge('1', TM.size(), 'I', dir);
    TM[curNode].edges['0'] = edge('0', TM.size(), 'O', dir);
    TM[curNode].edges['_'] = edge('_', TM.size(), 'E', dir);
    TM.pb(node(TM.size()));
    dest = (dest == -1 ? TM.size() : dest);
    curNode = TM.size() - 1;
    dir = (dir == 'L' ? 'R' : 'L');
    TM[curNode].edges['1'] = edge('1', dest, '1', dir);
    TM[curNode].edges['0'] = edge('0', dest, '0', dir);
    TM[curNode].edges['_'] = edge('_', dest, '_', dir);
    TM[curNode].edges['#'] = edge('#', dest, '#', dir);
    TM[curNode].edges['!'] = edge('!', dest, '!', dir);
    if(dest == TM.size())
        TM.pb(node(TM.size()));
}

void addPath(edge edge1, edge edge2, int idx, int &sameNodeIndex){
    int curNode;
    if(sameNodeIndex == -1){
        curNode = idx;
        TM[curNode].edges[edge1.pop] = edge(getChar(edge1.pop), TM.size(), getChar(edge1.pop), 'R');
        TM.pb(node(TM.size()));
        sameNodeIndex = addGetToRight(TM.size() - 1);
    }
    //Now on right coursor
    int curi = sameNodeIndex;
    curNode = curi;
    TM[curNode].edges[getChar(edge2.pop)] = edge(getChar(edge2.pop), TM.size(), edge2.push, edge2.dir);
    TM.pb(node(TM.size()));
    changeAndGo(edge2.dir, TM.size() - 1, -1);
    curi = addGetToLeft(TM.size() - 1);
    //Now on left coursor
    curNode = curi;
    TM[curNode].edges[getChar(edge1.pop)] = edge(getChar(edge1.pop), TM.size(), edge1.push, edge1.dir);
    TM.pb(node(TM.size()));
    int dest = (indexMap.find(edge1.to) != indexMap.end() ? indexMap[edge1.to] : -1);
    changeAndGo(edge1.dir, TM.size() - 1, dest);
    indexMap[edge1.to] = (dest == -1 ? TM.size() - 1 : dest);
}
void addNode(dnode& curNode, int curi){
    for(auto a : curNode.edges){
        int sameNodeIndex = -1;
        for(auto b: a.second){
            edge edge1 = b.first, edge2 = b.second;
            addPath(edge1, edge2, indexMap[curNode.idx], sameNodeIndex);
        }
    }
}
void convertTM(dnode nodes[]){
    int curi = addConverterToOneTM();
    indexMap[0] = curi;
    indexMap[n - 1] = -2;
    for(int i = 0; i < n - 1; i++){
        addNode(nodes[i], curi);
    }
}
void printTM(){
    cout << TM.size() + 1 << endl;
    for(int i = 0; i < TM.size(); i++){
        auto cur = TM[i];
        cout << cur.edges.size();
        for(auto pr : cur.edges)
            cout << " " << pr.second.pop << " " << (pr.second.to == -2 ? TM.size() : pr.second.to) 
            << " " << pr.second.push << " " << pr.second.dir;
        cout << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    dnode nodes[n - 1];
    for(int i = 0; i < n - 1; i++){
        nodes[i] = dnode(i);
        int count;
        cin >> count;
        for(int j = 0; j < count; j++){
            char pop1, push1, pop2, push2, dir1, dir2;
            int to;
            cin >> pop1 >> pop2 >> to >> push1 >> push2 >> dir1 >> dir2;
            auto newP = make_pair(edge(pop1, to, push1, dir1), edge(pop2, to, push2, dir2));
            nodes[i].edges[pop1].pb(newP);
        }
    }
    convertTM(nodes);
    printTM();
    return 0;
}