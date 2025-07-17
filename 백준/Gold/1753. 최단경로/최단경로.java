import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.StringTokenizer;

class Node {
    int idx;
    int cost;

    Node(int idx, int cost) {
        this.idx = idx;
        this.cost = cost;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());
        int start = Integer.parseInt(br.readLine());

        // 인접리스트 활용 그래프 초기화
        ArrayList<ArrayList<Node>> graph = new ArrayList<ArrayList<Node>>();
        for (int i = 0; i < v+1; i++) {
            graph.add(new ArrayList<Node>());
        }
        // 그래프에 값 추가
        for (int i = 0; i < e; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            graph.get(a).add(new Node(b, cost));
        }
        // 방문 여부 확인하는 bool배열, 최소 거리 저장하는 배열 생성
        boolean[] visited = new boolean[v+1];
        int[] dist = new int[v+1];

        for (int i = 0; i < v+1; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        dist[start] = 0;

        // 다익스트라 알고리즘 시작
        for (int i = 0; i < v; i++) {
            int nodeValue = Integer.MAX_VALUE;
            int nodeIndex = 0;
            for (int j = 1; j < v+1; j++) {
                if (!visited[j] && dist[j] < nodeValue) {
                    nodeValue = dist[j];
                    nodeIndex = j;
                }
            }
            visited[nodeIndex] = true;

            for (int j = 0; j < graph.get(nodeIndex).size(); j++) {
                Node adjNode = graph.get(nodeIndex).get(j);
                if (dist[adjNode.idx] > dist[nodeIndex] + adjNode.cost) {
                    dist[adjNode.idx] = dist[nodeIndex] + adjNode.cost;
                }
            }
        }

        for (int i = 1; i < v+1; i++) {
            if (dist[i] == Integer.MAX_VALUE) {
                bw.write("INF\n");
            } else {
                bw.write(dist[i] + "\n");
            }
        }
        bw.flush();
    }
}