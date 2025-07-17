import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] strs = bf.readLine().split(" ");
        
        BigInteger a = new BigInteger(strs[0]);
        BigInteger b = new BigInteger(strs[1]);

        System.out.println(a.divide(b));
        System.out.print(a.mod(b));
    }
}
