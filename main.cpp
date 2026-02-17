#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void printGrid(int array[], int n) {
    for (int i = 0; i < n; i++) {
        // i = the row we are at
        for (int j = 0; j < n; j++) {
            //the columns
            cout << "0 ";
        }
        cout << endl;
    }
}

int main() {
    //initialize the forest
    int n;
    cout << "Enter size of grid: " << endl;
    cin >> n;

    int forest_grid[n][n];
    printGrid(*forest_grid, n);

}