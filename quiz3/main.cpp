#include <iostream>
#include <queue>

using namespace std;

int main(){

    int T, N;
    long long int temp;
    long long int p,q;
    long long int s;

    cin >> T;

    
    for(int testNum = 1; testNum <= T; testNum++){

        priority_queue<long long int> que;
        cin >> N;
        s = 0;

        for (int i = 0; i < N; i++){
            cin >> temp;
            que.push(-temp);
        }

        while (que.size() > 1){
            p = -que.top();
            que.pop();
            q = -que.top();
            que.pop();

            s += p + q;
            que.push(-p-q);
        }


        cout << "#" << testNum << " " << s << endl;;
    }
    

    return 0;
}

