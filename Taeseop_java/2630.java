package java2630;

import java.util.Scanner;

public class Main {
	
	static int[][] arr;
	static int[] answer = {0, 0};
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		arr = new int[N][N];
		
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[i].length; j++) arr[i][j] = sc.nextInt();
		}
		
		colorPaper(N, 0, 0);
		
		System.out.println(answer[0]);
		System.out.println(answer[1]);

	}
	
	public static void colorPaper(int N, int y, int x) {
		boolean tf = true;
		for (int i = y; i < y + N; i++) {
			for (int j = x; j < x + N; j++) {
				if(arr[y][x] != arr[i][j]) {
					tf = false; break;
				}
			}
			
			if(!tf) break;
		}
		
		if(tf) answer[arr[y][x]]++;
		else {
			colorPaper(N/2, y, x);
			colorPaper(N/2, y + N/2, x);
			colorPaper(N/2, y, x + N/2);
			colorPaper(N/2, y + N/2, x + N/2);
		}
	}

}
