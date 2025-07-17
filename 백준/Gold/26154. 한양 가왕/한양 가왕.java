import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static List<PriorityQueue<Integer>> p;
    static int rounds;
    static int machines;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        machines = Integer.parseInt(st.nextToken());
        rounds = Integer.parseInt(st.nextToken());
        p = new ArrayList<>();
        p.add(new PriorityQueue<>());
        for (int i = 1; i < machines; i++) {
            p.add(new PriorityQueue<>(Collections.reverseOrder()));
        }

        for (int i = 0; i < machines; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            p.get(i).add(x);
            p.get(i).add(y);
        }


        for (int i = 0; i < machines-2; i++) {
            OneRound();
        }

        int opt;
        if (rounds > 1) {
            int a = rounds - (machines-2);
            if (a % machines != 0) {
                opt = a%machines;
            } else {
                opt = machines;
            }
            for (int i = 0; i < opt; i++) {
                OneRound();
            }
        }

//        for (int i = 0; i < rounds; i++) {
//            OneRound();
//        }


        int larger = 0;
        int smaller = 0;
        System.out.println(p.get(0).poll() + " " + p.get(0).poll());
        for (int i = 1; i < machines; i++) {
            larger = p.get(i).poll();
            smaller = p.get(i).poll();

            System.out.print(smaller + " " + larger);
            System.out.println();
        }


    }
    static void OneRound() {
        int temp = p.get(0).poll();
        for (int i = 1; i < machines; i++) {
            p.get(i-1).add(p.get(i).poll());
        }
        p.get(machines-1).add(temp);
    }
}