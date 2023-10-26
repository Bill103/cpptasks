#include <pzhelp>
int i;
int opernumber;
int n1, d1, n2, d2, n, d, gcd, m;
char c;
char sign;
PROGRAM{
opernumber = READ_INT();
SKIP_LINE();
for (i = 1; i <= opernumber; i++) {
	c = getchar();
	n1 = READ_INT(); d1 = READ_INT(); n2 = READ_INT(); d2 = READ_INT();
	SKIP_LINE();
	if (d1 !=0 and d2 !=0){
		switch (c) {
		case '*': n = n1 * n2; d = d1 * d2; break;
		case '/': if (n2 != 0) { n = n1 * d2; d = n2 * d1; }
				else WRITELN("error"); break;
		case '+': n = (n1 * d2) + (n2 * d1); d = d1 * d2; break;
		case '-': n = (n1 * d2) - (n2 * d1); d = d1 * d2; break;
		}
		if ((n < 0 and d < 0) or (n>0 and d<0)) {
			sign = '-';
		}
		else sign = ' ';
		if (abs(n) > abs(d)) {
			m = abs(n) / abs(d);
		}
		else
			m = 0;
		n = abs(n) MOD abs(d);


		{int n3, d3;
		n3 = abs(n); d3 = abs(d);
		while (n3 > 0 and d3 > 0)
			if (n3 > d3) n3 = n3 % d3; else d3 = d3 % n3;
		gcd = n3 + d3;
		}
		n = n / gcd; d = d / gcd;
		if (sign == '-') {
			WRITE(sign);
			WRITELN(m, abs(n), abs(d));
		}
		else WRITELN(m, abs(n), abs(d));
	}
	else
		WRITELN("error");
}
}