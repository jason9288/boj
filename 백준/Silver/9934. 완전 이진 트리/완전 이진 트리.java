import java.io.*;
import java.util.*;

public class Main {
    static ArrayList<ArrayList<Integer>> tree;
    static int[] arr;
    static int k;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        k = Integer.parseInt(br.readLine());
        int nodes = (int) Math.pow(2, k) - 1;
        arr = new int[nodes];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < nodes; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        tree = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < nodes; i++) {
            tree.add(new ArrayList<Integer>());
        }

        if (k == 1) {
            System.out.println(arr[0]);
            return;
        }
        else {
            getAns((nodes-1)/2, 1);
        }

        for (int i = 1; i < k+1; i++) {
            for (int j = 0; j < Math.pow(2, i-1); j++) {
                System.out.print(tree.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }
    static void getAns(int midIdx, int depth) {
        if (depth == k) {
            tree.get(depth).add(arr[midIdx]);
            return;
        }
        tree.get(depth).add(arr[midIdx]);
        getAns(midIdx-((int)Math.pow(2, (k-(depth+1)))), depth+1);
        getAns(midIdx+((int)Math.pow(2, (k-(depth+1)))), depth+1);
    }
}