import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        HashMap<String, Boolean> p_map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            String p1 = st.nextToken();
            String p2 = st.nextToken();
            if (!p_map.containsKey(p1)) {
                if (!p_map.containsKey(p2)) { // p1 p2 둘다 없음
                    if (p1.equals("ChongChong") || p2.equals("ChongChong")) {
                        p_map.put(p1, true);
                        p_map.put(p2, true);
                    } else {
                        p_map.put(p1, false);
                        p_map.put(p2, false);
                    }
                } else { // p1만 없음
                    if (p1.equals("ChongChong") || p2.equals("ChongChong") || p_map.get(p2)) {
                        p_map.put(p1, true);
                        p_map.put(p2, true);
                    } else {
                        p_map.put(p1, false);
                        p_map.put(p2, false);
                    }
                }
            } else {
                if (!p_map.containsKey(p2)) { // p2만 없음
                    if (p1.equals("ChongChong") || p2.equals("ChongChong") || p_map.get(p1)) {
                        p_map.put(p1, true);
                        p_map.put(p2, true);
                    } else {
                        p_map.put(p1, false);
                        p_map.put(p2, false);
                    }
                } else { // 둘다 있음
                    if (p_map.get(p2)) {
                        p_map.put(p1, true);
                    }
                    if (p_map.get(p1)) {
                        p_map.put(p2, true);
                    }
                }
            }
        }
        int cnt = 0;
        for (String key : p_map.keySet()) {
            if (p_map.get(key)) {
                cnt++;
            }
        }
        System.out.print(cnt);
    }
}