import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static long A, B, C;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader((new InputStreamReader(System.in)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        A = (Integer.parseInt(st.nextToken()));
        B = (Integer.parseInt(st.nextToken()));
        C = (Integer.parseInt(st.nextToken()));
        System.out.println(divconQ(B));
    }

    public static long divconQ(long expo) {
        if (expo == 1) {
            return A % C ;
        }
        long half = (divconQ(expo / 2) % C);

        if (expo % 2 == 1) {
            return (half * half % C) * A % C;
        } else {
            return (half * half) % C;
        }
    }
}


