import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        long a, sum = 0;

        Scanner sc = new Scanner(System.in);
        for(int i = 0 ; i < 3 ; i++) {
            a = Long.parseLong(sc.next());
            sum+=a;
        }

        System.out.println(sum);
    }
}