package java2751;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
//		int[] arr = new int[N];
//
//		for (int a = 0; a < N; a++) {
//			arr[a] = Integer.parseInt(br.readLine());
//		}

//		//버블 정렬 -> 시간 복잡도 O(n*n)
//		for (int a = 0; a < N; a++) {
//			for (int t = a + 1; t < N; t++) {
//				if(arr[a] > arr[t]) {
//					int temp = arr[a];
//					arr[a] = arr[t];
//					arr[t] = temp;
//				}
//			}
//		}
		
//		for (int a = 0; a < N; a++) {
//			int comparisons = a;
//			// 배열에서 가장 작은 숫자가 있는 index
//			for (int t = a + 1; t < N; t++) {
//				// 선택 정렬 -> 시간 복잡도 O(n*n)
//				if(arr[a] > arr[t]){
//					comparisons = t;
//				}
//			}
//			int temp = arr[a];
//			arr[a] = arr[comparisons];
//			arr[comparisons] = temp;
//		}
		
//		for (int a = 0; a < N; a++) {
//			System.out.println(arr[a]);
//		}
		
		StringBuilder sb = new StringBuilder();
		ArrayList<Integer> list = new ArrayList<>();
		
		for(int i = 0; i < N; i++) {
			list.add(Integer.parseInt(br.readLine()));
		}
		
		Collections.sort(list);
		// Arrays.sort()의 경우 평균 시간복잡도가 O(nlogn)이고 매우 빠른 알고리즘이지만, 
		// 최악의 경우 시간복잡도는 O(n^2)
		// Integer와 같은 객체일 때는 Merge sort를 사용하기 때문에
		// Arrays.sort(Integer)를 사용해서 풀 수도 있다
		// Collections.sort()
		// https://codingnojam.tistory.com/38
		
		for(int val : list) {
			sb.append(val).append('\n');
		}
		
		System.out.println(sb);

		

	}
}
