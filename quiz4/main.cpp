#include <iostream>

using namespace std;

typedef int seg;


seg intToSeg(int i){
    
    switch (i){
        case 0:
            return 0b1111110; 
            break;
        case 1:
            return 0b0000110;
            break;
        case 2:
            return 0b1011011;
            break;
        case 3:
            return 0b1001111;
            break;
        case 4:
            return 0b0100111;
            break;
        case 5:
            return 0b1101101;
            break;
        case 6:
            return 0b1111101;
            break;
        case 7:
            return 0b1000110;
            break;
        case 8:
            return 0b1111111;
            break;
        case 9:
            return 0b1101111;
            break;
        default:
            cout << "ERROR: UNDEFINED INPUT" << endl;
            return 0;
            break;
    }

    return 0;
}

int dist(seg i, int num){

    /*
        i = seg: 0 to 127
        j = int: 0 to 9
    */
   
    seg j = intToSeg(num);
    seg t = i^j;

    int s = 0;

    
    for (int k = 0; k < 7; k++){
        s += t%2;
        t /= 2;
    }

    //cout << i << ", " << num << ", " << s << endl;

    return s;
}

int main(){

    int T;
    int diff;
    seg temp;
    seg x1, x2, x3, x4;
    
    cin >> T;

    for (int testNum = 1; testNum <= T; testNum++){
        x1 = 0;
        x2 = 0;
        x3 = 0;
        x4 = 0;

        
        for (int i = 0; i < 7; i++){
            cin >> temp;
            x1 = 2*x1 + temp;
        }

        for (int i = 0; i < 7; i++){
            cin >> temp;
            x2 = 2*x2 + temp;
        }

        for (int i = 0; i < 7; i++){
            cin >> temp;
            x3 = 2*x3 + temp;
        }

        for (int i = 0; i < 7; i++){
            cin >> temp;
            x4 = 2*x4 + temp;
        }

        //cout << (int)x1 << " " << (int)x2 << " " << (int)x3 << " " << (int)x4 << endl;

        int t1, t2, t3, t4;
        int i1, i2, i3, i4;
        bool flag = true;
        diff = 0;


        i1 = 0;
        do{
            t1 = dist(x1, i1);
            diff += t1;

            if (diff <= 2){
                i2 = 0;
                do{
                    t2 = dist(x2, i2);
                    diff += t2;
                    if (diff <= 2){
                        i3 = 0;
                        do{
                            t3 = dist(x3, i3);
                            diff += t3;
                            if (diff <= 2){
                                i4 = 0;
                                do{
                                    t4 = dist(x4, i4);
                                    diff += t4;
                                    if (diff <= 2){
                                        flag = false;
                                    }
                                    diff -= t4;
                                    i4++;
                                }while(flag && i4 <= 9);
                            }
                            diff -= t3;
                            i3++;
                        }while(flag && i3 <= 5);
                    }

                    diff -= t2;
                    i2++;
                } while (flag && ((i1 < 2 && i2 <= 9) || (i1 == 2 && i2 <= 3)));
            }

            diff = 0;


            i1++;
        } while (flag && i1 <= 2);

        
        i1--;
        i2--;
        i3--;
        i4--;

        cout << "#" << testNum << " " << 10*i1 + i2 << " " << 10*i3 + i4 << endl;
    }

    return 0;
}

