double diameter(const polygon& p){
	int n = p.size();

	int left = min_element(p.begin(), p.end()) - p.begin();
	int right = max_element(p.begin(), p.end()) - p.begin();


	vector2 calipersA(0,1);
	double ret = (p[right] - p[left]).norm();

	vector<vector2> toNext(n);

	for(int i = 0; i < n; i++){
		toNext[i] = (p[(i+1) % n] - p[i]).normalize();
	}

	int a = left, b = right;

	while(a != right || b != left){

		double cosThetaA = calipersA.dot(toNext[a]);
		double cosThetaB = -calipersA.dot(toNext[b]);

		if(cosThetaA > cosThetaB){
			calipersA = toNext[a];
			a = (a + 1) % n;
		}
		else{
			calipersA = -toNext[b];
			b = (b + 1) % n;
		}

		ret = max(ret, (p[a] - p[b]).norm());
	}
	return ret;
}