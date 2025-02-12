#include <stdio.h>

long long merge_and_count(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    
    int j = mid + 1; 
    int k = left;   
    long long inv_count = 0;

   
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); 
        }
    }

    
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

 
    while (j <= right) {
        temp[k++] = arr[j++];
    }

 
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

long long merge_sort_and_count(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        inv_count += merge_sort_and_count(arr, temp, left, mid);
        inv_count += merge_sort_and_count(arr, temp, mid + 1, right);
        inv_count += merge_and_count(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    int N;
    while (1) {
        scanf("%d", &N);
        if (N == 0) break;

        int arr[N];
        int temp[N];

        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        long long inversions = merge_sort_and_count(arr, temp, 0, N - 1);

        if (inversions % 2 == 0) {
            printf("Carlos\n");
        } else {
            printf("Marcelo\n");
        }
    }
    return 0;
}
