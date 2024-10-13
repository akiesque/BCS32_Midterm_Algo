/*

 STEPHANIE FERMIL | BCS32
 Mathematical Functions

 To improve delivery route calculations,
 you need to compute the total distance between
 multiple points efficiently. This is through 
 using the formula sqrt[(x2 - x1) ** 2 + (y2-y1) ** 2]
 include for math

*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// define the main formula by:
double determinant(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

int main() {
    vector<vector<double>> points;
    int n;
    double total = 0.0;

    // enter the range of points
    cout << "Enter the total number of delivery points: ";
    cin >> n;

    // main coordinate collector
    for (int i = 0; i < n; i++) {
        double x, y;
        cout << "\nPOINT " << i + 1 << " COORDINATES:\n";
        cout << "Enter x and y coordinates, separated by a space: ";
        cin >> x >> y;
        points.push_back({x, y});
    }

    // Calculating the total distance
    for (int b = 1; b < n; b++) {
        total += determinant(points[b-1][0], points[b-1][1], points[b][0], points[b][1]);
    }

    int sum_of_natural = n * (n + 1) / 2;

    // show result
    cout << "\n---------------- OUTPUT ------------------\n";
    cout << "Total distance: " << total << endl;
    cout << "Sum of first two natural (n): " << sum_of_natural << endl;

    return 0;
}
