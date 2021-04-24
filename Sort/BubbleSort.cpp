
void BubbleSort(vector<int>& a) {
	int n = a.size();
	bool swap = false;
	for (int i = 0; i < n - 1; ++i) {
		swap = false;
		for (int j = 0; j < n - 1 - i; ++j) {
			if (a[j] > a[j + 1]) {
				int tmp = a[j]; a[j] = a[j + 1]; a[j + 1] = tmp;
				swap = true;
			}
		}
		if (!swap) return;
	}
}
