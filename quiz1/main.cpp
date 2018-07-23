#include <iostream>
#include <vector>
#include <queue>

#define MAXN 10002
#define BIGNUMBER 1000000000

using namespace std;

vector<int> path[MAXN];
int dist[MAXN];


int main(){

    /*
        T = # of test cases
        N = # of heritages
        M = # of maps
        K = # of remaining time
    */

    int T, N, M, K;

    cin >> T;


    for(int testNum = 1; testNum <= T; testNum++){
        cin >> N;
        cin >> M;
        cin >> K;

        for (int i = 1; i <= N; i++){
            path[i].clear();
            dist[i] = BIGNUMBER;
        }

        for (int i = 1; i <= M; i++){
            int p,q;
            cin >> p;
            cin >> q;
            path[p].push_back(q);
        }

        priority_queue <pair<int, int>> que;
        dist[1] = 0;
        que.push(make_pair(0,1));

        while (!que.empty()){
            int length = -que.top().first;
            int node = que.top().second;
            que.pop();

            if (dist[node] != length) continue;

            for (int i = ((int)(path[node]).size()); i--;){
                int r = path[node][i];
                if (dist[r] > dist[node] + 1){
                    dist[r] = dist[node] + 1;
                    que.push(make_pair(-dist[r], r));
                }
            }
        }

        cout << "#" << testNum << " ";

        if (dist[N] > K){
            cout << -1 << endl;
        } else {
            cout << dist[N] << endl;
        }
    }
    return 0;
}
