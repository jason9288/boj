import java.awt.desktop.SystemEventListener;
import java.util.Scanner;

public class Main {
    public static int getMaxInt(int n, int m) {
        int i = 0;
        while (true) {
            if (Math.pow(m, i) > n) {
                return i - 1;
            }
            i++;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = Integer.parseInt(scanner.next());
        int b = Integer.parseInt(scanner.next());
        int i = getMaxInt(n, b);
        int k;
        while (i >= 0) {
            k = (int) Math.pow(b, i);
            if (Character.isLetter((n/k)+55)) {
                char c = (char)((n/k)+55);
                System.out.print(c);
            } else {
                System.out.print((n / k));
            }
            n = n%k;
            i--;
        }
    }
}

