import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;

class AbsComparator implements Comparator<Integer> {
    @Override
    public int compare(Integer o1, Integer o2) {
        if (Math.abs(o1) == Math.abs(o2)) {
            return o1 - o2;
        }
        return Math.abs(o1) - Math.abs(o2);
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> absHeap = new PriorityQueue<Integer>(1, new AbsComparator());

        for (int i = 0; i < N; i++) {
            int command = Integer.parseInt(br.readLine());

            if (command == 0) {
                System.out.println(!absHeap.isEmpty() ? absHeap.poll() : 0);
            }
            else {
               absHeap.add(command);
            }
        }
    }
}