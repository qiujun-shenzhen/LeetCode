
int partition(vector<int>& a, int l, int r) {
	int key = a[l];
	while (l < r) {
		while (l < r && a[r] > key) --r;
		if (l < r) a[l++] = a[r];
		while (l < r && a[l] < key) ++l;
		if (l < r) a[r--] = a[l];
	}
	a[l] = key;
	return l;
}
void QuickSort(vector<int>& a, int l, int r) {
	if (l >= r) return;
	int pivot = partition(a, l, r);
	//注意左右下标实参，分区不需包括pivot
	QuickSort(a, l, pivot - 1);
	QuickSort(a, pivot + 1, r);
}
