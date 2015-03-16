#include <iostream>
#include <cmath>

using namespace std;

struct rac {int num, div;};

int main() {
    int times;

    cin >> times;

    for (int i = 1; i <= times; i++) {
        rac a, b, res; char _, op;

        cin >> a.num >> _ >> a.div >> op >> b.num >> _ >> b.div;

        switch(op) {
            case ('+'):
                res.num = (a.num * b.div) + (b.num * a.div), res.div = (b.div * a.div);
            break;

            case ('-'):
                res.num = (a.num * b.div) - (b.num * a.div), res.div = (b.div * a.div);
            break;

            case ('*'):
                res.num = (a.num * b.num), res.div = (a.div * b.div);
            break;

            case ('/'):
                res.num = (a.num * b.div), res.div = (b.num * a.div);
            break;
        }

        cout << res.num << "/" << res.div << " = ";

        int div = 2;

        while (div <= fabs(res.num) and div <= fabs(res.div)) {
            if (res.num % div == 0 and res.div % div == 0) {
                res.num /= div;
                res.div /= div;
            } else {
                div++;
            }
        }

        cout << res.num << "/" << res.div << endl;
    }
}
