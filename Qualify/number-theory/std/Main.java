import java.util.Scanner;

class GCD {
public static int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
}

public class Main {
    public static void solve(int n, int k, int[] a) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % k == 0) {
                ans = GCD.gcd(ans, a[i]);
            }
        }
        if (ans == k) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int round = 0; round < T; ++round) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            solve(n, k, a);
        }
        sc.close();
    }
}