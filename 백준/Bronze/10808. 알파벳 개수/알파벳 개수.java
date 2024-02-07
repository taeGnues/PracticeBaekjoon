import java.util.*;

public class Main {
    public static void main(String[] args) {
        int[] alph = new int[26];
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        for(char c : s.toCharArray()){
            alph[c-'a']++;
        }

        for(int i : alph){
            System.out.print(i + " ");
        }
    }
}