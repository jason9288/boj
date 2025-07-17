import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        String input = sc.nextLine();
        int len = input.length();
        int[] charNum = new int[26];
        for (int i = 0; i < len; i++) {
            charNum[input.charAt(i)-65]++;
        }

        if (len % 2 == 0) {
            for (int i = 0; i < 26; i++) {
                if (charNum[i] % 2 != 0) {
                    System.out.println("I'm Sorry Hansoo");
                    return;
                }
            }

            for (int j = 0; j < 26; j++) {
                if (charNum[j] != 0) {
                    for (int k = 0; k < (charNum[j]/2); k++) {
                        sb.append((char)(j+65));
                    }
                    charNum[j] /= 2;
                }
            }

            for (int j = 25; j >= 0; j--) {
                if (charNum[j] != 0) {
                    for (int k = 0; k < charNum[j]; k++) {
                        sb.append((char)(j+65));
                    }
                }
            }

        } else {
            // 홀수개인 알파벳이 두 종류 이상 --> error
            int tempcnt = 0;
            int tempchar = 65;
            for (int i = 0; i < 26; i++) {
                if (charNum[i] % 2 != 0) {
                    tempcnt++;
                    tempchar = i;
                    if (tempcnt >= 2) {
                        System.out.println("I'm Sorry Hansoo");
                        return;
                    }
                }
            }

            for (int i = 0; i < 26; i++) {
                if (charNum[i] != 0) {
                    int cnt = 0;
                    if (charNum[i] % 2 != 0) {
                        cnt = 0;
                        for (int j = 0; j < (int) Math.floor(charNum[i]/2); j++) {
                            sb.append((char) (i + 65));
                            cnt++;
                        }
                    } else {
                        cnt = 0;
                        for (int j = 0; j < charNum[i]/2; j++) {
                            sb.append((char) (i+65));
                            cnt++;
                        }
                    }
                    charNum[i] -= cnt;
                }
            }
            if (charNum[tempchar] != 0) {
                sb.append((char)(tempchar+65));
                charNum[tempchar]--;
            }
            for (int i = 25; i >= 0; i--) {
                if (charNum[i] != 0) {
                    for (int k = 0; k < charNum[i]; k++) {
                        sb.append((char)(i+65));
                    }
                }
            }
        }
        System.out.println(sb);
    }
}