#include <iostream>

using namespace std;


int *list;


int partition(int left, int right){
    int pivot = list[left];
    int index = left;
    int temp;

    for (int i = left + 1; i <= right; i++){
        if (pivot > list[i]){
            index++;
            temp = list[index];
            list[index] = list[i];
            list[i] = temp;
        }
    }

    temp = list[left];
    list[left] = list[index];
    list[index] = temp;
    
    return index;
}



int main(){

    int T, N, P, M;
    cin >> T;

    for (int testNum = 1; testNum <= T; testNum++){
        cin >> N;
        cin >> P;
        cin >> M;

        list = NULL;
        list = new int[N];
        
        int temp;
        int UP = N-1;
        int DOWN = 1;
    

        for (int i = 0; i < N; i++){
            cin >> temp;
            list[i] = temp;
        }
        

        while (UP > DOWN){

           temp = partition(DOWN, UP);

           if (temp == M) break; 

           if (temp < M){
               DOWN = temp + 1;
           } else{
               UP = temp - 1;
           }

        }

        long long int s = list[0];
        
        for (int j = 1; j <= M; j++) s -= list[j];
        for (int j = M + 1; j < N; j++) s += list[j];


        cout << "#" << testNum << " " << s << endl;
        
    }
    
    return 0;
}

