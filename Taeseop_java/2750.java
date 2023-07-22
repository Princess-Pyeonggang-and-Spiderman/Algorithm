package java2750;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		int[] array = new int[N];

		for (int a = 0; a < N; a++) {
			array[a] = Integer.parseInt(br.readLine());
		}
		
		 
		for(int i = 0; i < array.length - 1; i++) {
			for(int j = i + 1; j < array.length; j++) {
				if(array[i] > array[j]) {
					// 값 교환
					int temp = array[j];
					array[j] = array[i];
					array[i] = temp;
				}
			}
		}
		
		for(int a = 0; a < N; a++) {
			System.out.println(array[a]);
		}

	}

}
