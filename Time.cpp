#include "timeh.h"

int main() {
	Time A;
	Time B(2, 80);
	A = 2 * B;
	A.Show();
	cout << "Time A = " << A << "\n";
}