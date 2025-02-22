#include <iostream>

using namespace std;

int myArray[30];  
int numElem = 0;  
int maxElem = 20;

void bubbleSort(){
    int i, j;
    bool swapped;
    for(int i =0; i < numElem - 1; i++){
        swapped = false;
        for(j = 0; j < numElem - i -1; j++){
            if(myArray[j] > myArray [j+1]){
                swap(myArray[j], myArray[j+1]);
                swapped = true;
        }
    }
    if (swapped == false){
        break;
    }
}
}

int binarySearch(int num, int lowest, int highest){
    while(lowest <=highest){
        int middle = lowest + ((highest - 1) /2);
        
        if(myArray[middle] == num){
            return middle;
        }
        
        if(myArray[middle] < num){
            lowest = middle + 1;
        }else{
            highest = middle - 1;
        }
    }
    return -1;
}

void traverseArray() {
    cout << "Showing elements in my array\n";
    for (int i = 0; i < numElem; i++) {
        cout << myArray[i] << " | ";
    }
    cout << "\n";
}
 string insertAtTheEnd(int num){
    if(numElem != maxElem){
        myArray[numElem] = num;
        numElem++;
        return "An element is successfully inserted at the end! \n";
    }
    return "The array is full, Please remove elements before inserting new one. \n";
}

string insertAtTheBeginning(int num) {
    if(numElem != maxElem) {
        for (int i = numElem; i > 0; i--) {  
            myArray[i] = myArray[i-1];  
        }
        myArray[0] = num;  
        numElem++;  
        return "An element is successfully inserted at the beginning! \n";
    }
    return "The array is full. Please remove elements before inserting new one. \n";
}

string insertAtGivenPosition(int num, int elementAfter) {
    bubbleSort();
    int position = binarySearch(elementAfter, 0, numElem);
    if (position == -1) {
        return "Element after which to insert not found.\n";
    }
    if (numElem == maxElem) {
        return "The array is full. Please remove elements before inserting a new one.\n";
    }
    for (int i = numElem; i > position + 1; i--) {
        myArray[i] = myArray[i - 1];
    }
    myArray[position + 1] = num;
    numElem++;
    return "An element is successfully inserted at the specified location!\n";
}

string insertAtSortedarray(int num){
    if(numElem != maxElem){
        bubbleSort();
        int position;
        for(int i= 0; i < numElem; i++){
            if(num < myArray[i]){
                position = i;
                break;
            }
        }
        for(int i = numElem; i>=position; i--){
            myArray[i+1] = myArray [i];
        }
        myArray[position] = num;
        numElem++;
        return "An element is succesfully inserted at a sorted array! \n";
    }
    
    return "The array is full. Please remove elements before insterting new one. \n";
}

string deleteFromTheEnd(){
    if(numElem != 0){
        numElem--;
        return "An element has been deleted from the end!";
    }
    return "The array is underflow! Delete is not possible";
}

string deleteFromTheBeginning(){
    if(numElem !=0){
        for(int i = 0; i<= numElem; i++ ){
            myArray[i] = myArray[i+1];
        }
        numElem--;
        return "An elements has been deleted form the beginning!";
    }
    return "The array is underflow! Delete is not possible";
}

string deleteFromTheGiven(int element){
    bubbleSort();
    int index = binarySearch(element, 0, numElem);
    if (index == -1) {
        return "Element not found. Deletion not possible.\n";
    }
    for (int i = index; i < numElem - 1; i++) {
        myArray[i] = myArray[i + 1];
    }
    numElem--;
    return to_string(element) + " has been deleted!\n";
}

int main() {
    
    
    cout << insertAtTheBeginning(3);
    traverseArray();
    cout << insertAtTheEnd(7);
    traverseArray();
    cout << insertAtTheEnd(9);
    traverseArray();
    cout << insertAtTheBeginning(20);
    traverseArray();
    cout << insertAtGivenPosition(37,7);
    traverseArray();
    cout << insertAtTheBeginning(256);
    traverseArray();
    cout << insertAtGivenPosition(128,9);
    traverseArray();
    cout << insertAtTheBeginning(19);
    traverseArray();


    cout << insertAtSortedarray(3);
    traverseArray();
    cout << insertAtSortedarray(30);
    traverseArray();
    cout << insertAtSortedarray(38);
    traverseArray();
    cout << insertAtSortedarray(19);
    traverseArray();
    
    deleteFromTheBeginning();
    deleteFromTheBeginning();
    deleteFromTheEnd();
    deleteFromTheEnd();
    deleteFromTheGiven(9);
    deleteFromTheGiven(19);
    traverseArray();
    
    cout << binarySearch(20, 0, numElem) << endl;
    cout << binarySearch(38, 0, numElem) << endl;
    


    return 0;
}