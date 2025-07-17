import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        HashSet<String> list = new HashSet<>();

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            String status = st.nextToken();

            if (status.equals("enter")) {
                list.add(name);
            }
            if (status.equals("leave")) {
                list.remove(name);
            }
        }
        ArrayList<String> log = new ArrayList<String>(list);
        log.sort(Collections.reverseOrder());
        for (String s : log) {
            System.out.println(s);
        }
    }
}