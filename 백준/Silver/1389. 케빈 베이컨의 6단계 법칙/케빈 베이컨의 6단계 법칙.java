import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    static boolean[] visited;
    static LinkedList<Integer>[] adjList;
    static int[] dist;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        adjList = new LinkedList[N+1];
        dist = new int[N+1];
        for (int i = 0; i <= N; i++) {
            adjList[i] = new LinkedList<>();
        }

        visited = new boolean[N+1];

        for (int i = 1; i <= M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            adjList[u].add(v);
            adjList[v].add(u);
        }

        int chk = Integer.MAX_VALUE;
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            int cnt = bfs(i);
            if (chk > cnt) {
                chk = cnt;
                ans = i;
            }
        }
        System.out.println(ans);
    }

    public static int bfs(int start) {
        Arrays.fill(dist, -1);
        int cnt = 0;
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        dist[start] = 0;

        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int nxt : adjList[cur]) {
                if (dist[nxt] != -1) continue;
                dist[nxt] = dist[cur] + 1;
                cnt += dist[nxt];
                q.add(nxt);
            }
        }
        return cnt;
    }
}