import java.util.Scanner;
import java.util.*;

public class I {
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int n = sc.nextInt();
        double[] ar = new double[n];
        for (int i = 0; i < n; i++) {
            double temp = sc.nextDouble();
            ar[i] = temp;
        }
        Arrays.sort(ar);
        double ans = n + 1;
        for (int i = 0; i < n; i++) {
            if (i + 1 < ar[i]){
                ans = -1;
                break;
            }
            else{
                //System.out.printf("%f\n",ar[i]/(i+1));
                ans = (ar[i] / (i + 1) < ans ? ar[i] / (i + 1) : ans);
            }
        }
        System.out.println(ans == -1 ? "-1" : ans);
    }
}
//1 2 2 3 3 6
//1 2 3 4 5 6 