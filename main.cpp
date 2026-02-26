#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/** initializeForest
 * this function sets up each cell of our created grid given it's size (n)
 * and the probability a tree cell starts off on fire (pFireCell)
 * @param array grid (forest)
 * @param n grid (forest) size
 * @param pFireCell fire cell probability int
 */
void initializeForest(int array[], int n, int pFireCell) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (rand() % 100 < 80) {
                array[i*n + j] = 1; //Tree Cell
            }
            else {
                array[i*n + j] = 0; //Empty Cell
            }

            if (rand() % 100 < pFireCell && array[i*n + j] == 1) {
                array[i*n+j] = 2; //Tree Cell -> fire cell instead
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
    //dashes
    for (int x = 0; x < 3*n+2; x++) {
        cout << "-";
    }
    cout << endl;
    //loop through array
    for (int i = 0; i < n; i++) {
        //beginning of row place a bar
        cout << "|";
        for (int j = 0; j < n; j++) {
            //choose the index's corresponding visual
            switch (array[i*n + j]) {
                case 0:
                    cout << "   ";
                    break;
                case 1:
                    cout << " T ";
                    break;
                case 2:
                    cout << " ~ ";
                    break;
                case 3:
                    cout << " # ";
                    break;
            }
        }
        //end of row place a bar
        cout << "|" << endl;
    }
    //dashes
    for (int x = 0; x < 3*n+2; x++) {
        cout << "-";
    }
    cout << endl;
}

/** spreadFire
 * this function simulates the spreading of the forest fire at each fire cell for every iteration.
 * @param array
 * @param n
 * @param pfireSpread
 */
void spreadFire(int*& array, int n, int pfireSpread) {
    int* updatedForest = new int[n*n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (array[i*n + j] == 0) {
                //Empty remains empty
                updatedForest[i*n + j] = 0;
            }
            else if(array[i*n + j] == 1) {
                //before we check just assign it back to a tree
                updatedForest[i*n + j] = 1;
                //Tree Cell to check for neighboring fire cells
                for (int row = -1; row <= 1; row++) {
                    for (int col = -1; col <= 1; col++) {
                        //this is the original cell anyways
                        if (row == 0 && col == 0) continue;
                        //border if the i+row or j+col is 0 or the size of n
                        if (i+row >= 0 && i+row < n && j+col >= 0 && j+col < n) {
                            //if cell is fire
                            if (array[(i+row)*n + (j+col)] == 2) {
                                //update it
                                updatedForest[i*n + j] = 2;
                                break;
                            }
                        }
                    }
                }
            } else if (array[i*n + j] == 2) {
                // Fire cell to become Ash cell
                updatedForest[i*n + j] = 3;
            } else {
                // Ash cell to empty cell
                updatedForest[i*n + j] = 0;
            }

        }
    }

    delete[] array;
    array = updatedForest;
}

/** continueSimulation
 * this function returns a boolean on whether or not the passed array contains index 2 or 3 (fire or ash) and if so
 * returns true.
 * @param array forestGrid
 * @param n size of grid
 * @return
 */
bool continueSimulation(const int* array, int n) {
    bool isProblem = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i*n + j] == 2 || array[i*n + j] == 3) {
                isProblem = true;
            }
        }
    }
    return isProblem;
}


int main() {
    //initialize the forest (─‿‿─)
    //-----------------------------------------------------------------------------------
    int n;
    cout << "Enter size of grid (an integer in range [10,30]: " << endl;
    cin >> n;

    int fireProb;
    cout << "Enter probability of fire (an integer in range [10,90]: " << endl;
    cin >> fireProb;

    int spreadProb;
    cout << "Enter probability of fire spread (an integer in range [25,100]: " << endl;
    cin >> spreadProb;
    //-----------------------------------------------------------------------------------

    int* forestGrid = new int[n*n];

    initializeForest(forestGrid,n,fireProb);
    printForest(forestGrid,n);

    do {
        spreadFire(forestGrid,n,spreadProb);
        printForest(forestGrid,n);
    }
    while (continueSimulation(forestGrid,n));




    delete[] forestGrid; // no leakage (─‿‿─)
}