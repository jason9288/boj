import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String n = scanner.next();
        int b = Integer.parseInt(scanner.next());
        int sum = 0;

        for (int i = 0; i < n.length(); i++) {
            int k = 1;
            for (int j = n.length()-i-2; j >= 0; j--) {
                k *= b;
            }

            if (Character.isDigit(n.charAt(i))) {
                sum += k * (Character.getNumericValue(n.charAt(i)));
            } else {
                sum += k * (n.charAt(i) - 55);
            }
        }

        System.out.print(sum);
    }
}