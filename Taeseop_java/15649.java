package java15649;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static StringBuilder sb = new StringBuilder();
    static int n, m;
    static boolean[] visit;
    static int[] arr;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        visit = new boolean[n];
        arr = new int[m];
        dfs(0);
        System.out.println(sb);
    }

    private static void dfs(int depth) {
    	
      // if와 for문이 dfs의 기본 형식	
      // 깊이가 어느정도 깊어지면 해당 dfs를 끝내는 문장
        if (depth == m) {
            for (int val : arr) {
                sb.append(val).append(" ");
            }
            sb.append("\n");
            return;
        }
        
      // 재귀를 위한 문장 -> 백트래킹의 주요기술 
        for (int i = 0; i < n; i++) {
            // 해당 노드를 방문하지 않았다면
            if (!visit[i]) {
                visit[i] = true; // 해당 노드 방문상태 변경
                arr[depth] = i + 1; // 해당 깊이를 index로 하여 i+1 값 저장
                dfs(depth + 1);// 다음 자식 노드 방문 위해 depth 1 증가시키며 재귀 호출
                visit[i] = false; // 자식노드 방문이 끝나고 돌아오면 방문노드를 방문하지 않은 상태로 변경
           }
        }
    }
}