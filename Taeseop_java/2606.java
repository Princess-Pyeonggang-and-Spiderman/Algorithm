package java2606;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int countComp;
	static int pairComp;
	static boolean[][] graph;
	static boolean[] visit;
	static int count;
	
	static void dfs(int v) {
		count++;
		visit[v] = true;
		
		for(int i = 1; i <= countComp; i++) {
			if((!visit[i]&&(graph[v][i]))) { 
				dfs(i);
			}
			// 이전에 방문하지 않은 숫자와 v번 컴퓨터가 i번 컴퓨터와 연결돼있을 경우
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		countComp = Integer.parseInt(br.readLine()); // 컴퓨터의 수
		pairComp = Integer.parseInt(br.readLine());	// 컴퓨터 쌍의 수
		graph = new boolean[countComp + 1][ countComp + 1];
		// 각 숫자끼리 연결돼있는 부분을 2차원 boolean배열로 만든다.
		// 0번은 없기 때문에 +1씩 해준 모습
		visit = new  boolean[countComp + 1];
		
		for(int i = 0; i < pairComp; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a1 = Integer.parseInt(st.nextToken());
			int a2 = Integer.parseInt(st.nextToken());
			
			graph[a1][a2] = true;
			graph[a2][a1] = true;
			// 2개의 숫자를 true로 변경함으로서 연결
		}
		
		count = 0; // count값 초기화
		dfs(1); // 1번 컴퓨터가 웜 바이러스에 걸렸을 경우
		System.out.println(count-1);
		// 1컴퓨터는 제외시키기 때문에 -1
		
	}

}
