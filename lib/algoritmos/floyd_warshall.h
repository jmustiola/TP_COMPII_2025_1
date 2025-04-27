#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H

#include <vector>
using namespace std;

namespace alg {

    template <class T>
    void floydWarshall(vector<vector<T>>& costs)
    {
        size_t size = costs.size();
        for (int k = 0; k < size; k++) {
            
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {

                    if (costs[i][j] > costs[i][k] + costs[k][j]) {
                        costs[i][j] = costs[i][k] + costs[k][j];
                    };
                }
            }
        }
    }
}

#endif // FLOYD_WARSHALL_H