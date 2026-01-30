#include <iostream>
#include <time.h>
#include <random>

using namespace std;


void bubbleSort(int* tab, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= 1; j--) {
            if (tab[j] < tab[j - 1]) {
                int bufor = tab[j-1];
                tab[j-1] = tab[j];
                tab[j] = bufor;
            }
        }
    }
}

void quicksort(int* tablica, int lewy, int prawy) {
    int v = tablica[(lewy + prawy) / 2];
    int i, j, x;
    i = lewy;
    j = prawy;

    do {
        while (tablica[i] < v) i++;
        while (tablica[j] > v) j--;
        if (i <= j) {
            x = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = x;
            i++;
            j--;
        }
    } while (i <= j);

    if (lewy < j) quicksort(tablica, lewy, j);
    if (i < prawy) quicksort(tablica, i, prawy);
}

// https://www.geeksforgeeks.org/dsa/cpp-program-for-heap-sort/
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int* arr, int n, int i)
{
    int largest = i; // Initialize largest as root Since we are using 0 based indexing
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int* arr, int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/
void selectionSort(int* &arr, int size) {
    int n = size;

    for (int i = 0; i < n - 1; ++i) {

        // Assume the current position holds
        // the minimum element
        int min_idx = i;

        // Iterate through the unsorted portion
        // to find the actual minimum
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {

                // Update min_idx if a smaller
                // element is found
                min_idx = j;
            }
        }

        // Move minimum element to its
        // correct position
        swap(arr[i], arr[min_idx]);
    }
}


void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}




int main() {
    // Generowanie tablicy losowych liczb https://stackoverflow.com/questions/55786909/how-do-i-generate-random-numbers-in-a-range
    random_device seed;
    mt19937 gen{seed()}; // seed the generator
    uniform_int_distribution<> dist{1, 100000}; // określamy zasięg;
    clock_t start, stop;
    double czas;
    cout << "Podaj wielkość tablicy: " << endl;
    int entries = 0;
    cin >> entries;
    start = clock();
    int* arrForQuicksort = new int[entries];
    int* arrForBubblesort = new int[entries];
    int* arrForHeapSort = new int[entries];
    int* arrForSelectionSort = new int[entries];
    bool showArrays = false;
    cout << "Czy wyświetlić tablice? (1 - tak, 0 - nie): ";
    cin >> showArrays;
    for (int i = 0; i < entries; i++) {
        int value = dist(gen); // zakres od 1 do 100 000
        arrForQuicksort[i] = value;
        arrForBubblesort[i] = value;
        arrForHeapSort[i] = value;
        arrForSelectionSort[i] = value;
    }
    if (showArrays) {
        cout << "Wygenerowane tablice: " << endl;
        printArray(arrForQuicksort, entries);
        printArray(arrForBubblesort, entries);
        printArray(arrForHeapSort, entries);
        printArray(arrForSelectionSort, entries);
    }

    stop = clock();
    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << endl << "----- Tablica n: " << entries << " czas generowania tablicy: " << czas << " s ----- " << endl;
    // Quicksort
    start = clock();
    quicksort(arrForQuicksort, 0, entries - 1);
    stop = clock();
    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << endl << "czas sortowania szybkiego: " << czas << " s" << endl;
    if (showArrays) {
        cout << "----------------------------------------" << endl;
        cout << "Tablice po quick sort" << endl;
        printArray(arrForQuicksort, entries);
        printArray(arrForBubblesort, entries);
        printArray(arrForHeapSort, entries);
        printArray(arrForSelectionSort, entries);
    }
    // Heap sort
    start = clock();
    // Zmiana na stos
    for(int i=entries/2 -1;i>=0;i--){
        heapify(arrForHeapSort,entries,i);
    }
    heapSort(arrForHeapSort, entries);
    stop = clock();
    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << endl << "czas sortowania przez kopcowanie: " << czas << " s" << endl;
    if (showArrays) {
        cout << "----------------------------------------" << endl;
        cout << "Tablice po heap sort" << endl;
        printArray(arrForQuicksort, entries);
        printArray(arrForBubblesort, entries);
        printArray(arrForHeapSort, entries);
        printArray(arrForSelectionSort, entries);
    }
    // Selection sort
    start = clock();
    selectionSort(arrForSelectionSort, entries);
    stop = clock();
    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << endl << "czas sortowania przez wybór: " << czas << " s" << endl;
    if (showArrays) {
        cout << "----------------------------------------" << endl;
        cout << "Tablice po selection sort" << endl;
        printArray(arrForQuicksort, entries);
        printArray(arrForBubblesort, entries);
        printArray(arrForHeapSort, entries);
        printArray(arrForSelectionSort, entries);
    }

    // Bubble sort
    start = clock();
    bubbleSort(arrForBubblesort, entries);
    stop = clock();
    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << endl << "czas sortowania bąbelkowego: " << czas << " s" << endl;
    if (showArrays) {
        cout << "----------------------------------------" << endl;
        cout << "Tablice po bubble sort" << endl;
        printArray(arrForQuicksort, entries);
        printArray(arrForBubblesort, entries);
        printArray(arrForHeapSort, entries);
        printArray(arrForSelectionSort, entries);
    }

    delete[] arrForQuicksort;
    delete[] arrForBubblesort;
    delete[] arrForHeapSort;
    delete[] arrForSelectionSort;
    return 0;
}
