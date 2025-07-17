import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int cnt = 0;
        boolean new_p = false;
        HashMap<String, Boolean> p_map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            if (line.equals("ENTER")) {
                if (new_p) {
                    p_map.clear();
                }
                new_p = true;
            } else if (!p_map.containsKey(line)) {
                p_map.put(line, true);
                cnt++;
            } else if (p_map.containsKey(line) && !p_map.get(line)) {
                cnt++;
                p_map.replace(line, true);
            }
        }
        System.out.print(cnt);
    }
}