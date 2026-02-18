#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void initializeForest(int array[], int n, int pFireCell) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (rand() % 100 < 80) {
                array[i*n + j] = 1;
            }
            else {
                array[i*n + j] = 0;
            }
        }

    }

}

/** printForest
 * this function takes the nested loop function that prints out the grid and simply makes it easier to repeat.
 * @param array an int array, the grid
 * @param n an int that represents the grid size
 */
void printForest(int array[], int n) {

    for (int i = 0; i < n; i++) {
        cout << "|";
        for (int j = 0; j < n; j++) {
            cout << array[i] << " ";
        }
        cout << "|" << endl;
    }
}

int main() {
    //initialize the forest
    int n;
    cout << "Enter size of grid (an integer in range [10,30]: " << endl;
    cin >> n;

    int fireProb;
    cout << "Enter probability of fire (an integer in range [10,90]: " << endl;
    cin >> fireProb;

    /*int spreadProb;
    cout << "Enter probability of fire spread (an integer in range [25,100]: " << endl;
    cin >> spreadProb;*/

    int* forestGrid = new int[n*n];

    initializeForest(forestGrid,n,fireProb);
    printForest(forestGrid,n);



    delete[] forestGrid; // no leakage
}