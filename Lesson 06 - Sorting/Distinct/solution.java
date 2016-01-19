// Code written in Java
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N * log(N))
// Space Complexity: O(1)

class Solution {
    public int solution(int[] A) {
        final int A_LENGTH = A.length;
        
        if (A_LENGTH == 0) {
            return 0;
        }
        
        quicksort(A, 0, A_LENGTH - 1);
        
        int counter = 1;
        
        for (int i = 1; i < A_LENGTH; i++) {
            if (A[i] != A[i - 1]) {
                counter++;
            }
        }

        return counter;
    }
    
    private void quicksort(int arr[], int left, int right) {
        int index = partition(arr, left, right);

        if (left < index - 1) {
            quicksort(arr, left, index - 1);
        }

        if (index < right) {
            quicksort(arr, index, right);
        }
    }

    private int partition(int arr[], int left, int right) {
        int pivot = arr[(left + right) / 2];

        while (left <= right) {
            while (arr[left] < pivot) {
                left++;
            }

            while (arr[right] > pivot) {
                right--;
            }

            if (left <= right) {
                int tmp = arr[left];
                arr[left++] = arr[right];
                arr[right--] = tmp;
            }
        }

        return left;
    }
}
