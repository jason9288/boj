import java.io.*;
import java.util.*;

public class Main {
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static ArrayList<Integer> shortcut = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < 101; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < N+M; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            graph.get(x).add(y);
            shortcut.add(x);
        }
        for (int i = 1; i < 101; i++) {
            if (shortcut.contains(i)) {
                continue;
            }
            for (int j = 1; j <= 6; j++) {
                if (i+j <= 100) {
                    graph.get(i).add(i+j);
                }
            }
        }
        dfs(1, 0);
        System.out.println(cost[100]);

    }

    static int[] cost = new int[101];

    static void dfs(int cur, int cnt) {
        cost[cur] = cnt;
        if (shortcut.contains(cur)) {
            cnt--;
        }
        for (int i : graph.get(cur)) {
            if (cost[i] == 0 || cost[i] > cnt+1) {
                dfs(i, cnt+1);
            }
        }
    }
}