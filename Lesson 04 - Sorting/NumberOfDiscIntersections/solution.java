// Code written in Java
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N * log(N))
// Space Complexity: O(N)

class Solution {
    public int solution(int[] A) {
        final int N = A.length;
        
        if (N < 2) {
            return 0;
        }

        long[] leftEdges = new long[N];
        long[] rightEdges = new long[N];

        for (int i = 0; i < N; i++) {
            long r = (long)A[i];
            
            long left = i - r;
            leftEdges[i] = left;

            long right = i + r;
            rightEdges[i] = right;
        }

        quicksort(leftEdges, 0, N - 1);
        quicksort(rightEdges, 0, N - 1);

        int counter = 0;
        int previousCircles = 0;
        int leftP = 0;

        for (int rightP = 0; rightP < N; rightP++) {
            while ((leftP < N) && (leftEdges[leftP] <= rightEdges[rightP])) {
                leftP++;
                previousCircles++;
            }

            counter += --previousCircles;

            if (counter > 10000000) {
                return -1;
            }
        }
        return counter;
    }

    private void quicksort(long arr[], int left, int right) {
        int index = partition(arr, left, right);
        
        if (left < index - 1) {
            quicksort(arr, left, index - 1);
        }

        if (index < right) {
            quicksort(arr, index, right);
        }
    }

    private int partition(long arr[], int left, int right) {
        long pivot = arr[(left + right) / 2];

        while (left <= right) {
            while (arr[left] < pivot) {
                left++;
            }

            while (arr[right] > pivot) {
                right--;
            }

            if (left <= right) {
                long tmp = arr[left];
                arr[left++] = arr[right];
                arr[right--] = tmp;
            }
        }

        return left;
    }
}
