#define KEY (a[i] >> k) & (P - 1)

const int MAX = (int)25e6;
const int P = (1 << 8);
int N, *a, b[MAX], S;

void r_sort(int *a, int *b)
{
	int cnt[P], k, i, *tmp;
	for (k = 0; k < 32; k += 8) { //32bit을 8bit씩 나눠서 radix sort
		for (i = 0; i < P; i++) cnt[i] = 0;	//초기화
		for (i = 0; i < N; i++) cnt[KEY]++; //개수 세기
		for (i = 1; i < P; i++) cnt[i] += cnt[i - 1]; //누적
		for (i = N - 1; i >= 0; i--) b[--cnt[KEY]] = a[i]; //위치에 값 지정
		tmp = a; a = b; b = tmp; //바꾸고.
	}
}

void initUser(int nSize, int *arr) {
	N = nSize;
	a = arr;
	r_sort(a, b);
	for (S = 0; S < N && arr[S] >= 0; S++); //양수의 시작을 찾는 것
}

int query(int idx) {
	return a[(idx - 1 + S) % N]; //음수까지 포함해서 그 위치를 구한다.
}
