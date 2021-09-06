/*

An array of {dist, petrol} value is given find the minimum number of refueling stops required
for the car to reach the given target distance.

*/

int minRefuelStops(int target, int fuel, vector<vector<int>> &st) {
 	int curr = 0;
 	
	sort(st.begin(), st.end());
  	
  	priority_queue<int> pq;
  	int i = 0;
  	int cnt = 0;
  	
  	curr += fuel;
  	while (curr < target) {
	 	cnt++;
	 	
	 	while (i < st.size() && st[i][0] <= curr) {
	    	pq.push(st[i][1]);
	    	i++;
	 	}
	 	
	 	if (pq.empty())
	    	break;
	 	
	 	curr += pq.top();
	 	pq.pop();
  	}
  	
  	return curr >= target ? cnt : -1;
}