#include<iostream>
#include<cassert>

using namespace std;

void mergeSort(int array[], int const begin, int const end);
void bubblesort(int arr[], int size);
void sort(int a[], int size);
void merge(int array[], int const left, int const mid, int const right);
void swapInt(int& a, int& b);
int indexKleinsteWaarde(const int a[], int startIndex, int size);
bool isSorted(int a[], int size);
void reverseIntArr(int arr[], int size);
void reverseIntArr(char arr[], int size);
bool sortTesten();

int main (){
    cout << "testen op sorteringsalgoritmen"<< endl;
    sortTesten();
}

/**
 * @brief 
 * https://www.geeksforgeeks.org/merge-sort/
 * @param array De te sorteren array
 * @param left 
 * @param mid 
 * @param right 
 */
void merge(int array[], int const left, int const mid, int const right){
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

/**
 * @brief 
 *  https://www.geeksforgeeks.org/merge-sort/
 *  begin is for left index and end is
 *  right index of the sub-array
 *  of arr to be sorted 
 * @param array 
 * @param begin 
 * @param end 
 */
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
  
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void bubblesort(int arr[], int size){
    for(int i = size - 1; i>0; i--){
        for(int j = 0; j < i; j ++){
            if(arr[j] > arr[j+1]){
                swapInt(arr[j], arr[j+1]);
            }
        }
    }
}

void sort(int a[], int size){
    int indexKleinste;
    for(int i = 0; i < size - 1; i++){
        indexKleinste = indexKleinsteWaarde(a, i, size);
        swap(a[i], a[indexKleinste]);
    }
}

void swapInt(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
    
}

int indexKleinsteWaarde(const int a[], int startIndex, int size){
    int min = a[startIndex];
    int indexKleinste = startIndex;
    for(int i= startIndex; i < size; i++){
        if(a[i] < min){
            min = a[i];
            indexKleinste = i;
        }
    }
    return indexKleinste;
}

bool isSorted(int a[], int size){
    int index = 0;
    while (index < size -2){
        if(a[index] < a[index + 1])
            index ++;
        else 
            return false;
    }
    return true;
}

void reverseIntArr(int arr[], int size){
    for(int i = 0; i < size/2; i++){
        swapInt(arr[i], arr[size - 1 - i]);
    }

}

void reverseIntArr(char arr[], int size){ // overloading
    for(int i = 0; i < size/2; i++){
        //swapInt(arr[i], arr[size - 1 - i]);
    }

}

void weergaveArr(int a[], int size){
    for( int i = 0; i <  size; i++)
        cout << a[i] << ", ";
    cout<< endl;
}

bool sortTesten(){
    int a[] = {3,9,2,6};
    int b[] = {2,3,6,9};
    
    assert(! isSorted(a, 4));
    assert( isSorted(b,4));

    sort(a,4);
    assert( isSorted(a,4));
    weergaveArr(a,4);

    int c[] = {8,6,19,2,16,4,18,14,12,20};
    bubblesort(c, 10);
    assert(isSorted(c,10));
    weergaveArr(c,10);

    reverseIntArr(c, 10);
    weergaveArr(c,10);

    return true;
}