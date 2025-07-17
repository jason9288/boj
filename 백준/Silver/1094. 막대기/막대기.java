import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class Main {
    static List<Integer> sticks = new ArrayList<Integer>();
    static int x;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        x = Integer.parseInt(br.readLine());
        sticks.add(64);

        System.out.print(f());
    }

    static int f() {
        while (true) {
            if (getSum() > x) {
//                System.out.println("cutting");
                int min = Collections.min(sticks);
                sticks.remove(Integer.valueOf(min));
                sticks.add(min/2);
                sticks.add(min/2);
//                System.out.println(sticks.toString());
                if (getSum()-(min/2) >= x) {
//                    System.out.println("throwing");
                    sticks.remove(Integer.valueOf(min/2));
//                    System.out.println(sticks.toString());
                }
            } else {
                break;
            }
        }

        Collections.sort(sticks, Collections.reverseOrder());

        int sum = 0;
        int cnt = 1;
        for (int i : sticks) {
            if (sum+i < x) {
                sum += i;
                cnt++;
            }
        }
        return cnt;
    }
    static int getSum() {
        return sticks.stream().mapToInt(Integer::intValue).sum();
    }
}