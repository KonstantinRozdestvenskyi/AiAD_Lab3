#include<iostream>
const int N = 100000;
using namespace std;
void selectionSort(int* arrSort, int size)
{
    int min, temp; // to find the minimum element and to exchange
    for (int i = 0; i < size - 1; i++)
    {
        min = i; // storing the index of the current element
        // we are looking for the minimum element to put in the place of the i-th
        for (int j = i + 1; j < size; j++)  // for the remaining elements after the i-th
        {
            if (arrSort[j] < arrSort[min]) // if the element is less than the minimum,
                min = j;       // remember its index in min
        }
        temp = arrSort[i];      // swapping the i-th and minimum elements
        arrSort[i] = arrSort[min];
        arrSort[min] = temp;
    }
}
void bubbleSort(int* arrSort, int size)
{
    // For all elements
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = (size - 1); j > i; j--) // for all elements after the ith
        {
            if (arrSort[j - 1] > arrSort[j]) // if the current element is smaller than the previous
            {
                int temp = arrSort[j - 1]; // swap them
                arrSort[j - 1] = arrSort[j];
                arrSort[j] = temp;
            }
        }
    }
}

void mergeSort(int* arrSort, int left, int right)
{
    if (left == right) return; // the borders have closed
    int mid = (left + right) / 2; // we define the middle of the sequence
    // and recursively call the sorting function for each half
    mergeSort(arrSort, left, mid);
    mergeSort(arrSort, mid + 1, right);
    int i = left;  // the beginning of the first path
    int j = mid + 1; // the beginning of the second path
    int* tmp = (int*)malloc(right * sizeof(int)); // additional array
    for (int step = 0; step < right - left + 1; step++) // for all elements of the additional array
    {
        // write the smaller of the elements of the two paths into the generated sequence
        // or the remainder of the first path if j > right
        if ((j > right) || ((i <= mid) && (arrSort[i] < arrSort[j])))
        {
            tmp[step] = arrSort[i];
            i++;
        }
        else
        {
            tmp[step] = arrSort[j];
            j++;
        }
    }
    // rewriting the generated sequence into the original array
    for (int step = 0; step < right - left + 1; step++)
        arrSort[left + step] = tmp[step];
}
void quickSort(int* arrSort, int left, int right)
{
    int pivot; // resolving element
    int l_hold = left; //left border
    int r_hold = right; // right border
    pivot = arrSort[left];
    while (left < right) // until the borders close
    {
        while ((arrSort[right] >= pivot) && (left < right))
            right--; // shift the right border until the [right] element is greater than [pivot]
        if (left != right) // if the borders are not closed
        {
            arrSort[left] = arrSort[right]; // moving the [right] element to the place of the permissive
            left++; // shift the left border to the right
        }
        while ((arrSort[left] <= pivot) && (left < right))
            left++; // shift the left border until the [left] element is less than [pivot]
        if (left != right) // if the borders are not closed
        {
            arrSort[right] = arrSort[left]; // moving the [left] element to the [right] place
            right--; // shift the right border to the left
        }
    }
    arrSort[left] = pivot; // putting the resolving element in place
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot) // Recursively calling sorting for the left and right parts of the array
        quickSort(arrSort, left, pivot - 1);
    if (right > pivot)
        quickSort(arrSort, pivot + 1, right);
}
void insertionSort(int* arrSort, int size) 
{
    int temp, // temporary variable for storing the value of an element of the sorted array
        item; // index of the previous element
    for (int counter = 1; counter < size; counter++)
    {
        temp = arrSort[counter]; // initialize the temporary variable with the current value of the array element
        item = counter - 1; // we remember the index of the previous element of the array
        while (item >= 0 && arrSort[item] > temp) // as long as the index is not equal to 0 and the previous element of the array is larger than the current one
        {
            arrSort[item + 1] = arrSort[item]; // rearranging array elements
            arrSort[item] = temp;
            item--;
        }
    }
}
void shellSort(int* arrSort, int size) {
    int h = 1;
    while (h < size / 2) { //setting the sequence of distances
        h =  2* h + 5;
    }
    while (h > 0) { //perform insertSort at the specified distances
        for (int i = 0; i < h; i++) {
            for (int j = i + h; j < size; j += h) {
                if (arrSort[j] < arrSort[j - h]) {
                    for (int k = j; k >= h; k -= h) {
                        if (arrSort[k] > arrSort[k - h]) break;
                        int t = arrSort[k];
                        arrSort[k] = arrSort[k - h];
                        arrSort[k - h] = t;
                    }
                }

            }
        }
        h /= 2;
    }
}
int main() {
    int arrSort[N];
    int size;
    cout << "enter the size of the array: " << endl;
    cin >> size;
    cout << "enter the element of the array: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arrSort[i];
    }
    int choose = 0;
    while (1) {
        cout << "choose sort:\n"
            << "1 - Insertion sort\n"
            << "2 - Selection sort\n"
            << "3 - Bubble sort\n"
            << "4 - Merge sort\n"
            << "5 - Shell sort\n"
            << "6 - Quick sort\n"
            << "0 - exit\n";
        cin >> choose;
        if (choose == 0)
            break;
        cin >> choose;
        switch (choose) {
        case 1: 
            insertionSort(arrSort, size);
            break;
        case 2:
            selectionSort(arrSort, size);
            break;
        case 3:
            bubbleSort(arrSort, size);
            break;
        case 4:
            mergeSort(arrSort, 0, size);
            break;
        case 5:
            shellSort(arrSort, size);
            break;
        case 6:
            quickSort(arrSort, 0, size);
            break;
        default:
            break;
        }
        cout << "sorted array: " << endl;
        for (int i = 0; i < size; i++) {
            cout << arrSort[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
