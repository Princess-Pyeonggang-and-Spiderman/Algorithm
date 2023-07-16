package java2839;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt(); // 배달해야하는 kg 수
		int cnt = 0;
		
		while(true) {
			if(n % 5 == 0) {
				System.out.println(n/5 + cnt);
				break;
			}
			else if(n < 0) {
				System.out.println(-1);
				break;
			}
			n = n - 3;
			cnt++;
		}
		
//		int min = 0;
//		int sum = 0;
//		int answer = 0;
//
//		for (int a = 0; a <= Math.floor(N / 3); a++) { // a -> 3킬로그램 개수
//			for (int b = 0; b <= Math.floor(N / 5); b++) { // b -> 5킬로그램 개수
//				sum = a * 3 + b * 5;
//				min = a+b;
//				if(sum == N && min > a+b) { // 정확하게 N킬로그램이 만들어졌을때
//					answer = min;
//				}
//			}
//		}
//		// 정수를 0으로 나누는 경우 ArithmeticException이 발생한다.
//		
//		if(min == 0) {
//			System.out.println(-1);
//		} else {
//			System.out.println(answer);
//		}
	}
}
