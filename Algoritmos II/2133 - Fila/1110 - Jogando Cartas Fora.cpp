#include <iostream>
#include <queue>
 
using namespace std;
 
int main(){
    queue <int> q;
    int n;
    while((cin >> n) and n!=0){
        for(int i=1; i<=n; i++){
            q.push(i);
        }
        cout << "Discarded cards: ";
        while (q.size()>2){
            cout << q.front() << ", ";
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();
        cout << endl << "Remaining card: " << q.front() << endl;
        while(!q.empty()){
            q.pop();
        }
    }
    return 0;
}
