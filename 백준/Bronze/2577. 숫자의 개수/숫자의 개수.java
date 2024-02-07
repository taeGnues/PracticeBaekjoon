import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int[] resArr = new int[10];
        int a = Integer.parseInt(sc.nextLine());
        int b = Integer.parseInt(sc.nextLine());
        int c = Integer.parseInt(sc.nextLine());

        String res = String.valueOf(a*b*c);
        for(char r : res.toCharArray()){
            resArr[r-'0']++;
        }

        for(int i : resArr){
            System.out.println(i);
        }

    }
}
