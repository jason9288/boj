import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static boolean[] visited;
    static int[] parentNode;
//    static int[][] graph;
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static int n;
    static Queue<Integer> q;
    public static void bfs() {
        q.add(1);
        visited[1] = true;

        while (!q.isEmpty()) {
            int cur = q.poll();

            for (int nxt : graph.get(cur)) {
                if (!visited[nxt]) {
                    parentNode[nxt] = cur;
                    visited[nxt] = true;
                    q.offer(nxt);
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        visited = new boolean[n+1];
        q = new LinkedList<>();
        parentNode = new int[n+1];

        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<Integer>());
        }

        for (int i = 1; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        bfs();

        for (int i = 2; i <= n; i++) {
            System.out.println(parentNode[i]);
        }
    }
}