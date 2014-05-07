#ifndef _UINT160_H_
#define _UINT160_H_

#include <ostream>
#include <iomanip>
using namespace std;
class uInt160{
	unsigned int num[5];
public:
	uInt160(unsigned int a = 0, unsigned int b = 0, unsigned int c = 0, unsigned int d = 0, unsigned int e = 0) {
		num[0] = a;
		num[1] = b;
		num[2] = c;
		num[3] = d;
		num[4] = e;
	}
	bool at(int p);
	unsigned int atInt(int i);
	friend uInt160 operator^(const uInt160 a, const uInt160 b);
	friend uInt160 operator&(const uInt160 a, const uInt160 b);
	friend uInt160 operator|(const uInt160 a, const uInt160 b);
	friend ostream& operator<<(ostream& ff, uInt160 now);
	//uInt160 operator<<(const int t) const;
};

bool uInt160::at(int p){
	if ((p < 0)||(p >= 160)) return false;
	for (int i = 0; i < 5; i++) {
		if (p < 32 * (i + 1))
			return (num[i] >> p) &  1;
	}
}

unsigned int uInt160::atInt(int i) {
	return num[i];
}

uInt160 operator^(const uInt160 a, const uInt160 b){
	uInt160 ret;
	for (int i = 0; i < 5; i++)
		ret.num[i] = a.num[i] ^ b.num[i];
	return ret;
}

uInt160 operator&(const uInt160 a, const uInt160 b){
	uInt160 ret;
	for (int i = 0; i < 5; i++)
		ret.num[i] = a.num[i] & b.num[i];
	return ret;
}


uInt160 operator|(const uInt160 a, const uInt160 b){
	uInt160 ret;
	for (int i = 0; i < 5; i++)
		ret.num[i] = a.num[i] | b.num[i];
	return ret;
}

ostream& operator<<(ostream& ff, uInt160 now) {
	ff<<uppercase<<hex;
	for (int i = 4; i >=0; i--) {
		unsigned int tmp = 1 << 28;
		while (now.num[i] < tmp) {
			ff << "0";
			tmp = tmp >> 4;
		}
		if (now.num[i])
			ff<<now.num[i];
	}
	ff<<nouppercase<<dec;
	return ff;
}

#endif
