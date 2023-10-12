import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            String s = sc.next();
            //System.out.printf("%s\n",s);
            int p = 1;
            boolean flag = false;
            if (s.length() != 2){
                for (int j = 0; j < n ; j++) {
                    if (p % 2 == 1){
                        p++;
                    }
                    else{
                        if (j + 1 < s.length() && s.charAt(j) == s.charAt(j+1)){
                            p++;
                            j += 1;
                        }
                        else{
                            System.out.printf("NO\n");
                            flag = true;
                            break;
                        }
                    }
                }
                if (!flag){
                    System.out.printf("YES\n");
                    flag = true;
                }
            }
            if (!flag)
                System.out.printf("NO\n");
           
        }

        sc.close();
    }
}