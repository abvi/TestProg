int getBit(int num, int index) {
	return (num & (0x1 << index)) >> (index-1);
}

void setBit(int N, int nIndex, int M, int mIndex) {
	N |= (getBit(M, mIndex) << nIndex);
}

void setBits(int N, int M, int i, int j) {
	for (int index = i; index < j; index++) {
		setBit(N, index, M, index-i);
	}
}