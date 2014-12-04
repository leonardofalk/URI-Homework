/* by Elosilva */

#include <iostream>
#include <algorithm>

using namespace std;

struct camp {
	int id = -1, p = 0, g = 0, e = 0;
	double ca = 0;
};

bool comp (camp a, camp b) {
    if (a.p == b.p) {
        if (a.ca != b.ca) {
            return a.ca > b.ca;
        } else {
            if (a.p != b.p) {
                return a.g > b.g;
            } else {
                return a.id > b.id;
            }
        }
    }
    
    return a.p > b.p;
}

int main() {
    int n, m, a, b, x, y, cont = 1;

    while (cin >> n) {
        if (n==0) {break;}
        
        camp time[n];
        
        m = n * (n - 1) / 2;
        
        for (int i = 0 ; i < m ; i++ ){
            cin >> a >> x >> b >> y;
            
            time[a-1].id = a; time[b-1].id = b;
            time[a-1].g += x; time[a-1].e += y;
            time[b-1].g += y; time[b-1].e += x;
            
            if (x < y) {time[a-1].p += 1; time[b-1].p += 2;}
            if (x > y) {time[a-1].p += 2; time[b-1].p += 1;}
        }
        
        for (int i = 0; i < n; i++) {
            if (time[i].e == 0) {
                time[i].ca = time[i].p;
            } else {
                time[i].ca = double(time[i].g) / double(time[i].e);
            }
        }
        
        sort(time, time + n, comp);
        
        if (cont > 1) {cout << "\n";}
        
        cout << "Instancia " << cont++ <<endl;
        
        for (int i = 0; i < n; i++) {
            cout << ((i > 0) ? " " : "") << time[i].id;
        }
        
        cout << "\n";
    }
    return 0;
}
