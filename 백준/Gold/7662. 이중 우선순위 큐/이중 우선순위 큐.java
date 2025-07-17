import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int tc = 0; tc < T; tc++) {
            int size = 0;
            int k = Integer.parseInt(br.readLine());
            PriorityQueue<Integer> MaxHeap = new PriorityQueue<>(Collections.reverseOrder());
            PriorityQueue<Integer> MinHeap = new PriorityQueue<>();
            HashMap<Integer, Integer> map = new HashMap<>();

            for (int cal = 0; cal < k; cal++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                char com = (st.nextToken().charAt(0));
                int n = Integer.parseInt(st.nextToken());


                if (com == 'D') {
                    if (size == 0) {
                        continue;
                    }
                    // Delete Max (1)
                    if (n == 1) {
                        size--;
                        while (true) {
                            int p = MaxHeap.poll();
                            if (!map.containsKey(p)) {
                                continue;
                            } else {
                                if (map.get(p) > 1) { // 해당 수가 중복될 경우
                                    map.put(p, map.get(p) - 1); // 개수 줄이기
                                } else {
                                    map.remove(p);
                                }
                                break;
                            }
                        }
//                        map.forEach((key, value) -> {
//                            System.out.println("최대 삭제 중의 " + key + " " + value);
//                        });
                    }
                    // Delete Min (-1)
                    if (n == -1) {
                        size--;
                        while (true) {
                            int p = MinHeap.poll();
                            if (!map.containsKey(p)) {
                                continue;
                            } else {
                                if (map.get(p) > 1) { // 해당 수가 중복될 경우
                                    map.put(p, map.get(p) - 1); // 개수 줄이기
                                } else {
                                    map.remove(p);
                                }
                                break;
                            }
                        }
//                        map.forEach((key, value) -> {
//                            System.out.println("최소 삭제 중의 " + key + " " + value);
//                        });

                        }
                    }
                    // Insert
                    if (com == 'I') {
                        size++;
                        if (map.containsKey((n))) {
                            map.put(n, map.get(n) + 1);
                        } else {
                            map.put(n, 1);
                        }
                        MaxHeap.offer(n);
                        MinHeap.offer(n);
                    }
                }
            if (size == 0) {
                System.out.println("EMPTY");
            } else {
                int max = 0, min = 0;
                while (true) {
                    max = MaxHeap.poll();
                    if (!map.containsKey(max)) {
                        continue;
                    } else {
                        break;
                    }
                }
                while (true) {
                    min = MinHeap.poll();
                    if (!map.containsKey(min)) {
                        continue;
                    } else {
                        break;
                    }
                }
                System.out.println(max + " " + min);
            }
        }
    }
}

