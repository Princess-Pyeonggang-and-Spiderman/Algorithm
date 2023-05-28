package java25206;

import java.io.IOException;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws IOException {

		Scanner sc = new Scanner(System.in);

		double sumOfaverageScore = 0; // 학점의 총합
		double sumOfgrade = 0; // 전공과목별(학점 x 과목평점)의 합
		double answer = 0; // 전공평점 -> 정답

		for(int a = 0; a < 20; a++) {
			String[] input = sc.nextLine().split(" ");

			String name = input[0];
			double averageScore = Double.parseDouble(input[1]);
			double grades = 0;

			switch (input[2]) {
			case "A+":
				grades = 4.5;
				break;
			case "A0":
				grades = 4.0;
				break;
			case "B+":
				grades = 3.5;
				break;
			case "B0":
				grades = 3.0;
				break;
			case "C+":
				grades = 2.5;
				break;
			case "C0":
				grades = 2.0;
				break;
			case "D+":
				grades = 1.5;
				break;
			case "D0":
				grades = 1.0;
				break;
			case "F":
				grades = 0.0;
				break;
			case "P":
				continue;
			}
			
			sumOfaverageScore += averageScore;
			sumOfgrade += averageScore * grades;

		}

		answer = sumOfgrade / sumOfaverageScore; // 전공평점 결과
		// 전공과목별의 합을 학점의 총합으로 나눈 값
		String result = String.format("%.6f", answer);
		System.out.println(result);
		
	}
}
