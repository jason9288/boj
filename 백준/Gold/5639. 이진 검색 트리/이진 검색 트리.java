import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;



public class Main {
    static class Node {
        int val;
        Node left, right;

        Node (int val) {
            this.val = val;
        }
        Node (int val, Node left, Node right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
        void insert (int n) {
            if (n < this.val) {
                if (this.left == null) {
                    this.left = new Node(n);
                } else {
                    this.left.insert(n);
                }
            } else {
                if (this.right == null) {
                    this.right = new Node(n);
                } else {
                    this.right.insert(n);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Node root = new Node(Integer.parseInt(br.readLine()));
        String input;

        while (true) {
            input = br.readLine();
            if (input == null || input.equals("")) {
                break;
            }
            root.insert(Integer.parseInt(input));
        }

        postOrder(root);
    }

    static void postOrder(Node node) {
        if (node.left == null && node.right == null) {
            System.out.println(node.val);
        } else {
            if (node.left != null) {
                postOrder(node.left);
            }
            if (node.right != null) {
                postOrder(node.right);
            }
            System.out.println(node.val);
        }
    }
}