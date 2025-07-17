import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int getDist(String p1, String p2, String p3) {
        int dist = 0;
        for (int i = 0; i < 4; i++) { // 4개의 성격 지표를 비교
            dist += (p1.charAt(i) != p2.charAt(i) ? 1 : 0);
            dist += (p2.charAt(i) != p3.charAt(i) ? 1 : 0);
            dist += (p3.charAt(i) != p1.charAt(i) ? 1 : 0);
        }
        return dist;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            int N = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());

            int pigeon = N > 32 ? 33 : N;
            String[] student = new String[pigeon];

            for (int j = 0; j < pigeon; j++) {
                student[j] = st.nextToken();
            }

            int minDist = 12;
            
            outerLoop : 
            for (int a = 0; a < pigeon; a++) {
                for (int b = a + 1; b < pigeon; b++) {
                    for (int c = b + 1; c < pigeon; c++) {
                        minDist = Math.min(minDist, getDist(student[a], student[b], student[c]));
                        if (minDist == 0) {
                            break outerLoop;
                        }
                    }
                }
            }

            System.out.println(minDist);
        }
    }
}