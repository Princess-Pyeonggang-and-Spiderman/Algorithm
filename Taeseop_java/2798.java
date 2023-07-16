package java2798;

import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt(); // 놓여진 카드의 개수
		int M = sc.nextInt(); // 기준 숫자
		
		int[] cards = new int[N];
		int sum = 0;
		int max = 0;
		
		for(int a = 0; a < N; a++) {
			cards[a] = sc.nextInt();
		}
		
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
//		
//		int N = Integer.parseInt(st.nextToken());
//		int M = Integer.parseInt(st.nextToken());
// 
//		int[] arr = new int[N];
// 
//		st = new StringTokenizer(br.readLine(), " ");
//		for (int i = 0; i < N; i++) {
//			arr[i] = Integer.parseInt(st.nextToken());
//		}
		
		for(int a = 0; a < N-2; a++) {
			for(int b = a+1; b < N-1; b++) {
				for(int c = b+1; c < N; c++) { // 왜 c를 a+2로 하면 안되는 걸까?
					sum = cards[a]+cards[b]+cards[c];
					if(sum > max && M >= sum) {
						max = sum;
					}
				}
			}
		}
		
		System.out.println(max);
		
	}
}
