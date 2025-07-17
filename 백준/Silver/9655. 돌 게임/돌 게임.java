import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] dp = new int[1001];
        dp[1] = 1;
        dp[2] = 0;
        dp[3] = 1;

        for (int i = 4; i < 1001; i++) {
            if (dp[i-3] == 1 && dp[i-1] == 1) {
                dp[i] = 0;
            } else {
                dp[i] = 1;
            }
        }

        if (dp[n] == 1) {
            System.out.println("SK");
        } else {
            System.out.println("CY");
        }
    }
}