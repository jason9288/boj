import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static ArrayList<Integer> ans;
    static ArrayList<Integer> numList;
    static StringBuilder sb;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        numList = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            numList.add(Integer.parseInt(st.nextToken()));
        }
        numList.sort(null);

        ans = new ArrayList<>();
        backtrack(N, M);

    }

    static void backtrack(int N, int M) {
        if (ans.size() == M) {
            sb = new StringBuilder();
            for (int i = 0; i < ans.size(); i++) {
                sb.append(ans.get(i) + " ");
            }
            System.out.println(sb.toString());
            return;
        }
        for (Integer i : numList) {
            if (!ans.contains(i)) {
                ans.add(i);
                backtrack(N, M);
                ans.remove(ans.size() - 1);
            }
        }
    }
}