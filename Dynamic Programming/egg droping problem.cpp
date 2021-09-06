/*

Time Complexity: O(N*K*K)

*/
int max(int a, int b)
{
	return (a > b) ? a : b;
}


int eggDrop(int n, int k)
{

	int eggFloor[n + 1][k + 1];	// n -> eggs, k -> floors
	int res;
	int i, j, x;	// i -> eggs, j -> floors

	// We need one trial for one floor and 0
	// trials for 0 floors
	for (i = 1; i <= n; i++) {
		eggFloor[i][1] = 1;
		eggFloor[i][0] = 0;
	}

	// We always need j trials for one egg
	// and j floors.
	for (j = 1; j <= k; j++)
		eggFloor[1][j] = j;

	
	for (i = 2; i <= n; i++) {
		for (j = 2; j <= k; j++) {
			eggFloor[i][j] = INT_MAX;
			for (x = 1; x <= j; x++) {
				res = 1 + max(
							eggFloor[i - 1][x - 1],
							eggFloor[i][j - x]);
				if (res < eggFloor[i][j])
					eggFloor[i][j] = res;
			}
		}
	}

	return eggFloor[n][k];
}
