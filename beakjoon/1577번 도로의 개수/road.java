import java.util.Scanner;

public class Main {
	static int[][] start;
	static int[][] end;
	static int w;
	static int h;
	static int num;
	static long[][] cache;

	static long solve(int x, int y) {

		if (x > w || y > h)
			return 0;

		if (x == w && y == h) {
			return 1;
		}

		if (cache[x][y] != -1) {
			return cache[x][y];
		}

		cache[x][y] = 0;

		for (int i = 0; i < num; i++) {
			if (x == start[i][0] && y == start[i][1]) {
				if (start[i][0] == end[i][0]) {
					return cache[x][y] += solve(x + 1, y);
				} else {
					return cache[x][y] += solve(x, y + 1);
				}
			}
		}

		cache[x][y] += solve(x, y + 1);
		cache[x][y] += solve(x + 1, y);

		return cache[x][y];
	}

	static void swap(int[][] array, int[][] array2, int x1, int y1) {
		int temp = array[x1][y1];
		array[x1][y1] = array2[x1][y1];
		array2[x1][y1] = temp;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		w = sc.nextInt();
		h = sc.nextInt();

		num = sc.nextInt();

		start = new int[num][2];
		end = new int[num][2];
		cache = new long[101][101];

		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				cache[i][j] = -1;
			}
		}

		for (int i = 0; i < num; i++) {
			for (int j = 0; j < 2; j++) {
				start[i][j] = sc.nextInt();
			}
			for (int k = 0; k < 2; k++) {
				end[i][k] = sc.nextInt();
			}
		}

		for (int i = 0; i < num; i++) {
			if (start[i][0] > end[i][0]) {
				swap(start, end, i, 0);
			}
			
			if (start[i][1] > end[i][1]) {
				swap(start, end, i, 1);
			}
			
		}
		
		System.out.println(solve(0, 0));
		sc.close();
	}
}