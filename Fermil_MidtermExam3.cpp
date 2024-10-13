/*
    Stephanie Fermil | BCS32
    Tower of Hanoi is a mathematical puzzle
    involving moving blocks to a target tower.

    Rules:
    - Only one disk at a time can be moved.
    - The bigger disk CANNOT be placed above a smaller one.
    
    Explanation:
    - n: number of disks/packages present.
    - fro: source tower/starting point.
    - to: target tower/end point.
    - aux: auxiliary/temporary point.
    - moves: move count.
*/

#include <iostream>
using namespace std;

// tower of hanoi function
void Tower_of_Hanoi(int n, char fro, char to, char aux, int& moves) {
    if (n == 1) {
        cout << "Moving Package [ 1 ] from " << fro << " to " << to << endl;
        moves++;
        return; 
    }

    // recursive algorithm: Use the auxiliary tower as the temporary tower
    // to temporarily place n - 1 packages into it
    Tower_of_Hanoi(n - 1, fro, aux, to, moves);

    cout << "Moving Package [ " << n << " ] from " << fro << " to " << to << endl;
    moves++;

    Tower_of_Hanoi(n - 1, aux, to, fro, moves);
}

// main program
int main() {
    int packages; 
    int moves = 0;

    cout << "Enter the number of packages to be moved: ";
    cin >> packages;

    // symbolized by three towers: 'B' (source), 'C' (destination), 'A' (auxiliary)
    Tower_of_Hanoi(packages, 'B', 'C', 'A', moves);

    // counter output
    cout << "Total number of moves used: " << moves << endl;

    return 0;
}

/*

Tower of Hanoi is a puzzle wherein only the topmost disk can be moved,
and only one disk can be moved per time. The essence of this shows how 
the recursive algorithm is called to successfully bring all packages to
the target destination. The algorithm also considers the number
of towers present (or in this case, points since we're moving packages)
and counts the number of moves used to move all packages to the target.



*/