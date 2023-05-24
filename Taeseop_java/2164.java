package java2164;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Queue<Object> q = new LinkedList<Object>();
		
		Scanner sc = new Scanner(System.in);
		int countCardInQueue = sc.nextInt();
		int count = 1;
		
		while(count <= countCardInQueue) { // queue에 count만큼 삽입
			q.add(count);
			count++;
		}
		
		while(countCardInQueue >= 2) {
			q.remove(); // 제일 앞 요소 삭제
			Object element = q.peek(); // 제일 앞 요소 저장
			q.remove(); // 제일 앞 요소 삭제
			q.add(element); //제일 뒤에 요소 추가
			countCardInQueue--; // queue 요소개수 -1
		}
		
		System.out.println(q.peek()); // 마지막 1개남은 요소 출력
	}

}
