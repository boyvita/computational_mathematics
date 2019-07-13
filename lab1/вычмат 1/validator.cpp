#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	int n = inf.readInt(1, 10000, "n");
	inf.readEoln();
	for (int i = 0; i < n + 1; i++) { 
		double x = inf.readDouble();
		inf.readSpace();
		inf.readDouble();
		inf.readEoln();
	}
	inf.readEof();
}