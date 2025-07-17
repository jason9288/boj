import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    static int[] A;
    static int[] D; // D[i] is length of the longest increasing subsequence that has A[i] for the last element
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        A = new int[N+1];
        D = new int[N+1];
        A[0] = 0;
        D[0] = 0;

        for (int i = 1; i < N+1; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i < N+1; i++) {
            int maxL = -1;
            for (int j = 0; j < i; j++) {
                if (A[i] > A[j]) { // 증가하는 경우!
                    if (maxL < D[j]+1) { 
                        maxL = D[j]+1;
                    }
                }
            }
            D[i] = maxL;
        }

        System.out.println(findMax());
    }

    static int findMax() {
        int max = -1;
        for (int i = 0; i < A.length; i++) {
            if (max < D[i]) {
                max = D[i];
            }
        }
        return max;
    }
}