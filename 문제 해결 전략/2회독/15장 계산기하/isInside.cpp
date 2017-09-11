
//점 q가 다각형 p 안에 포함되어 있을 경우 참, 아닌 경우 거짓을 반환한다.
//q가 다각형의 경계 위에 있는 경우의 반환 값은 정의되어 있지 않다.
bool isInside(vector2 q, const vector<vector2>& p){

	int crosses = 0;
	for(int i = 0; i < p.size();i ++){
		int j = ( i + 1) % p.size();

		//(p[i], p[j])가 반직선을 세로로 가로지르는가?
		if((p[i].y > q.y) != (p[j].y > q.y)){
			//가로지르는 x좌표를 계산한다.
			double atX = (p[j].x - p[i].x) * (q.y- p[i].y) / (p[j].y - p[i].y) + p[i].x;
			if(q.x < atX)
				crosses++;
		}
	}
	return crosses % 2 > 0;
}