import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;
    static char[][] tree;
    static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        tree = new char[N][3]; // 0 : name, 1 : left, 2 : right

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            char root = st.nextToken().charAt(0);
            char left = st.nextToken().charAt(0);
            char right = st.nextToken().charAt(0);
            int idx = root - 65;
            tree[idx][0] = root;
            tree[idx][1] = left;
            tree[idx][2] = right;
        }

        sb = new StringBuilder();
        // preorder traversal
        preOrder('A');
        System.out.println(sb);

        sb = new StringBuilder();
        // inorder traversal
        inOrder('A');
        System.out.println(sb);

        sb = new StringBuilder();
        // postorder traversal
        postOrder('A');
        System.out.println(sb);
    }

    public static void preOrder(char node) {
        int idx = node - 65;
        if (tree[idx][1] == '.' && tree[idx][2] == '.') {
            sb.append(tree[idx][0]);
        } else {
            sb.append(tree[idx][0]);
            if (tree[idx][1] != '.') {
                preOrder(tree[idx][1]);
            }
            if (tree[idx][2] != '.') {
                preOrder(tree[idx][2]);
            }
        }
    }

    public static void inOrder(char node) {
        int idx = node - 65;
        if (tree[idx][1] == '.' && tree[idx][2] == '.') {
            sb.append(tree[idx][0]);
        } else {
            if (tree[idx][1] != '.') {
                inOrder(tree[idx][1]);
            }
            sb.append(tree[idx][0]);
            if (tree[idx][2] != '.') {
                inOrder(tree[idx][2]);
            }
        }
    }

    public static void postOrder(char node) {
        int idx = node - 65;
        if (tree[idx][1] == '.' && tree[idx][2] == '.') {
            sb.append(tree[idx][0]);
        } else {
            if (tree[idx][1] != '.') {
                postOrder(tree[idx][1]);
            }
            if (tree[idx][2] != '.') {
                postOrder(tree[idx][2]);
            }
            sb.append(tree[idx][0]);
        }
    }
}