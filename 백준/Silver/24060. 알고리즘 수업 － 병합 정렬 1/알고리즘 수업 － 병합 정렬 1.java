import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    int[] A;
    static int[] tmp;
    static int result = -1;
    static int cnt = 0;
    static int K;

    static void mergeSort(int[] A, int left, int right) {
        if (cnt > K) return;
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(A, left, mid);
            mergeSort(A, mid+1, right);
            merge(A, left, mid, right);
        }
    }

    static void merge(int[] A, int left, int mid, int right) {
        int i = left, j = mid + 1, t = 0;
        while (i <= mid && j <= right) {
            if (A[i] < A[j]) {
                tmp[t++] = A[i++];
            } else {
                tmp[t++] = A[j++];
            }
        }
        while (i <= mid) {
            tmp[t++] = A[i++];
        }
        while (j <= right) {
            tmp[t++] = A[j++];
        }
        i = left;
        t = 0;
        while (i <= right) {
            cnt++;
            if (cnt == K) {
                result = tmp[t];
                break;
            }
            A[i++] = tmp[t++];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        int[] A = new int[N];
        tmp = new int[N];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        mergeSort(A, 0, N-1);

        System.out.println(result);
    }
}