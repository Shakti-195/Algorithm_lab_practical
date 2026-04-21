
// heapsort implementation

#include <stdio.h>

void heapify(int a[], int n, int i){

    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
    largest = r;

    if (largest != i){

        int temp = a[i];
        a[i] = a[largest];
    
        a[largest] = temp;

        heapify(a, n, largest);

    }

}

void heapsort(int a[], int n){

    for (int i = n/2 - 1; i >= 0; i--){
        heapify(a, n, i);

    }

    for(int i = n - 1; i > 0; i--){
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

// int main(){

//     int a[] = {5, 3, 8, 4, 1};
//     int n = 5;

//     heapsort(a, n);

//     for (int i = 0; i < n; i++)
//         printf("%d ", a[i]);


//     return 0;
// }

// user input 

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    heapsort(a, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}