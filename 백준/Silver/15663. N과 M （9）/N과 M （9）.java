import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedHashSet;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static int[] arr, p;
    static boolean[] visited;
    static LinkedHashSet<String> ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[N];
        p = new int[M];
        visited = new boolean[N];
        ans = new LinkedHashSet<>();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);
        perm(0);
        ans.forEach(System.out::println);
    }

    static void perm(int k) {
        if (k == M) {
            StringBuilder sb = new StringBuilder();
            for (int i : p) {
                sb.append(i).append(" ");
            }
            ans.add(sb.toString());
            return;
        }
        for (int i = 0; i < N; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            p[k] = arr[i];
            perm(k + 1);
            visited[i] = false;
        }
    }
}