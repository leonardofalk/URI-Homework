#include <iostream>
#include <algorithm>

using namespace std;

/* binary search with a simple/retarded backtracking way */

int binsearch(int vet[], int low, int high, int val) {
    if (high < low) {
        return -1;
	}

    int mid = low + ((high - low) / 2);

    if (vet[mid] > val) {
        return binsearch(vet, low, mid-1, val);
    }

    if (vet[mid] < val) {
        return binsearch(vet, mid+1, high, val);
    }

    if (vet[mid] == val) {
    	/* search for previous values in array */

    	for (int i = mid; i >= 0; i--) {
    		if (vet[i] == val) {
    			mid = i;
    		} else {
    			break;
    		}
    	}
    }

    return mid;
}

int main() {
    int tableSize, searchNum, testCase = 1, toFind, valueFound;

    while (cin >> tableSize >> searchNum) {
        if (tableSize == 0 and searchNum == 0) {
            break;
        }

        cout << "CASE# " << testCase++ << ":" << endl;

        int vet[tableSize];

        for (int i = 0; i < tableSize; i++) {
            cin >> vet[i];
        }

        sort(vet, vet+tableSize);

        for (int i = 0; i < searchNum; i++) {
            cin >> toFind;

            valueFound = binsearch(vet, 0, tableSize, toFind);

            if (valueFound == -1) {
                cout << toFind << " not found\n";
            } else {
                cout << toFind << " found at " << valueFound + 1 << endl;
            }
        }
    }

    return 0;
}
