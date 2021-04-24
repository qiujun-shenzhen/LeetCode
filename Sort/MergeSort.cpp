
void Merge(vector<int>& a, int l, int mid, int r) {
	vector<int> tmp(r - l + 1, 0);
	int i = l, j = mid + 1, k = 0;
	while (i <= mid && j <= r) {
		tmp[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
	}
	while (i <= mid) tmp[k++] = a[i++];
	while (j <= r) tmp[k++] = a[j++];
	for (int n = 0; n < tmp.size(); ++n) {
		a[l + n] = tmp[n];
	}
}
//先分区处理，再合并结果
void MergeSort(vector<int>& a, int l, int r) {
	if (l >= r) return;
	int mid = (l + r) / 2;
	//注意左右下标实参，分区组合是整个序列，要包括mid
	MergeSort(a, l, mid);
	MergeSort(a, mid+1, r);
	Merge(a, l, mid, r);
}
