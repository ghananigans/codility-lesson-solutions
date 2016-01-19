// Code written in Java
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N * log(N))
// Space Complexity: O(1)

class Solution {
    public int solution(int[] A) {
        final int A_LENGTH = A.length;
        
        if (A_LENGTH < 3) {
            return 0;
        }
        
        quicksort(A, 0, A_LENGTH - 1);
        
        for (int i = 2; i < A_LENGTH; i++) {
            if ((long)A[i] < (long)A[i - 2] + (long)A[i - 1]) {
                return 1;
            }
        }
        
        return 0;
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
