import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        List<Integer> arr = new ArrayList<Integer>();
        arr.add(a);
        arr.add(b);
        arr.add(c);

        Collections.sort(arr);

        for (int i = 0; i < 3; i++) {
            System.out.print(arr.get(i) + " ");
        }
    }
}