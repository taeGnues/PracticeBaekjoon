import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out)); // buffer에 담아서 속도 향상
        char[] nArr = br.readLine().toCharArray(); // 한줄씩 읽음.
        int[] n = new int[10];

// 0부터 9까지의 플라스틱 세트. 단, 6이랑 9는 호환 가능.
        // 숫자 전부 하나로봄.
        for(char a : nArr){
            int cur = a-'0';
            if(cur == 6 && n[cur] > n[9]){
                n[9]++;
                continue;
            }

            if(cur == 9 && n[cur] > n[6]){
                n[6]++;
                continue;
            }
            n[cur]++;
        }
        int mx = 0;
        for(int i = 0 ; i < 10 ; i++){
            if(mx <= n[i]) {
                mx = n[i];
            }
        }
        bw.write(String.valueOf(mx));
        // 자원 반납
        bw.flush();
        bw.close();
        br.close();
    }
}