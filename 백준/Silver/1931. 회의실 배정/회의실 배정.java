import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[][] time = new int[N][2];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            time[i][0] = Integer.parseInt(st.nextToken()); // start
            time[i][1] = Integer.parseInt(st.nextToken()); // end
        }

        Arrays.sort(time, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[1] == o2[1]) { // end time 이 같은 경우 start 가 빠른 순으로
                    return o1[0] - o2[0]; // o1 < o2 이면 음수 -> o1가 앞으로 감
                }
                return o1[1] - o2[1];
            }
        });

        int cnt = 0;
        int prevEnd = 0;

        for (int i = 0; i < N; i++) {
            if (prevEnd <= time[i][0]) { // 이전의 end time 이 다음 start time 보다 작거나 같으면 가능한 경우임
                prevEnd = time[i][1]; // end time 을 갱신
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}