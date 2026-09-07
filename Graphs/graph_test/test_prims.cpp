#include <iostream>
#include <vector>
#include "primsAlgo.cpp"
using namespace std;


int main(){
    int V = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};

    PrimsAlgo prims;
    int ans = prims.primsMST(edges, V);
    cout << ans;
}