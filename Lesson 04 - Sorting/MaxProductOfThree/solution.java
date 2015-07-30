// Code written in Java
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N * log(N))
// Space Complexity: O(1)

class Solution {
    public int solution(int[] A) {
        int N = A.length;
        quicksort(A, 0, N - 1);

        int tmp1 = (A[0] * A[1]);
        int tmp2 = (A[N - 2] * A[N - 3]);

        if (A[N - 1] > 0) {
            return A[N - 1] * ((tmp1 > tmp2) ? tmp1 : tmp2);
        } else {
            return A[N - 1] * ((tmp1 < tmp2) ? tmp1 : tmp2);
        }
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
