/*


 STEPHANIE FERMIL | BCS32
 Algorithmic Complexity

 The logistics company wants to categorize routes by
 efficiency. Thus, Bubble Sort and Merge Sort
 will be used to sort the list of delivery times
 in ascending order.

 In addition, a comparison will be done
 to see which of the two sorting methods
 are much efficient.


*/

/*
====================== ANALYSIS ======================

Based on the time taken using the two sorting algorithms, 
the following were discovered:
    - Both algorithms can effectively sort numbers into ascending order.
    - However, it turns out that Merge Sort is generally quicker in
    handling larger data, compared to Bubble Sort.
    - Bubble Sort excels better with smaller data, (i.e: 5 deliverances.) and
    is observed to be quicker in sorting a smaller range of elements compared
    to Merge Sort.
    - This pace and speed of processing is due to their time complexities, 
    to elaborate:
        > Bubble Sort has a time complexity of O(n^2), which is efficient in handling
        smaller input data, hence it is quicker in sorting a smaller range of numbers. 
        It is also why it is slower than Merge Sort as the time complexity O(n^2) is slower
        than of Merge Sort's time complexity.
        > Merge Sort is quicker because its time complexity is O(n log n), hence it is faster in
        processing larger input data, but is slower in smaller input data, thus it takes longer
        for smaller input sizes when Merge Sort is  used.
    - Both algorithms are good in sorting the given deliverances, but it is recommended for a big
    company (that possibly has more than 5 delivery routes) to use Merge Sorting Algorithm because
    it is quicker and efficient, as well as it is suitable for the quantity of data it handles.

*/

// imports

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

// bubble sort function 
void b_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// merge sort function
void m_sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // sort first and second half (left, right)
        m_sort(arr, left, mid);
        m_sort(arr, mid + 1, right);

        // merge two sorted arrays
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++) {
            L[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            R[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}



// array function to print arr
void print_array(const vector<int>& arr) {
    for (int time : arr) {
        cout << time << " ";
    }
    cout << endl;
}

// show analysis of both bubble & merge sort
void show(const vector<int>& deliver_rec) {
    // bubble sort
    vector<int> b_sorted_deliverance = deliver_rec;
    auto start_bubble = high_resolution_clock::now();
    b_sort(b_sorted_deliverance);
    auto end_bubble = high_resolution_clock::now();
    auto b_time = duration_cast<duration<double>>(end_bubble - start_bubble);

    // merge sort
    vector<int> m_sorted_deliverance = deliver_rec;
    auto start_merge = high_resolution_clock::now();
    m_sort(m_sorted_deliverance, 0, m_sorted_deliverance.size() - 1);
    auto end_merge = high_resolution_clock::now();
    auto m_time = duration_cast<duration<double>>(end_merge - start_merge);

    // show/print the analysis of the bubble/merge sort
    cout << "======= BUBBLE SORT ===========" << endl;
    cout << "Sorted delivery times: ";
    print_array(b_sorted_deliverance);
    cout << "Time taken: " << b_time.count() << " seconds" << endl;
    cout << "Time Complexity: O(n^2)\n";

    cout << "\n========== MERGE SORT ==========" << endl;
    cout << "Sorted delivery times: ";
    print_array(m_sorted_deliverance);
    cout << "Time taken: " << m_time.count() << " seconds" << endl;
    cout << "Time Complexity: O(n log n)\n";
}

// main program
int main() {
    int N;

    // main range of deliverances
    cout << "Enter the number of deliveries: ";
    cin >> N;

    // ensures N is only a positive integer.
    while (N <= 0) {
        cout << "Please enter a positive number for the number of deliveries: ";
        cin >> N;
    }

    // input the number of deliverances
    vector<int> deliver_rec(N);
    cout << "Enter the delivery times (in minutes)." << endl;
    for (int i = 0; i < N; i++) {
        cout << "Delivery Time (" << i + 1 << "): ";
        cin >> deliver_rec[i];
    }

    // show the analysis of both sorts
    show(deliver_rec);

    return 0;
}
