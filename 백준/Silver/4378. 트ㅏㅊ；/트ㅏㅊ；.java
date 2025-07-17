import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        String keyboard = " `1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String str = "";

        while ( (str = br.readLine() ) != null ) {
            sb = new StringBuilder(str);

            for (int i = 0; i < str.length(); i++) {
                char c = str.charAt(i);
                if (c == '`' || c == 'Q' || c == 'A' || c == 'Z') {
                    continue;
                }
                if (c != ' ' && keyboard.indexOf(c) != -1) {
                    int newIdx = keyboard.indexOf(c) - 1;
                    sb.setCharAt(i, keyboard.charAt(newIdx));
                }
            }
            System.out.println(sb);
        }
    }
}