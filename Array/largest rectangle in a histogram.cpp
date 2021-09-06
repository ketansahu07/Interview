/**
 * Find the largest rectangle in a histogram.
 * width of each bar in the histogram is same.
 * 
 * Logic:
 * 
 * We traverse all bars from left to right, maintain a stack of bars. Every bar is pushed to stack once. A bar is popped from stack when a bar of smaller height is seen. When a bar is popped, we calculate the area with the popped bar as smallest bar. How do we get left and right indexes of the popped bar – the current index tells us the ‘right index’ and index of previous item in stack is the ‘left index’. Following is the complete algorithm.
	1) Create an empty stack.
	2) Start from first bar, and do following for every bar ‘hist[i]’ where ‘i’ varies from 0 to n-1. 
	……a) If stack is empty or hist[i] is higher than the bar at top of stack, then push ‘i’ to stack. 
	……b) If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. Let the removed bar be hist[tp]. Calculate area of rectangle with hist[tp] as smallest bar. For hist[tp], the ‘left index’ is previous (previous to tp) item in stack and ‘right index’ is ‘i’ (current index).
	3) If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.
 */

int getMaxArea(int hist[], int n) {
	stack<int> s;

	int max_area = 0;
	int topOfStack;		// To store top of the stack
	int area_with_top;	// To store area with top bar
						// as the smallest bar

	// Traverse the histogram
	int i = 0;
	while(i < n) {
		if(s.empty() || hist[s.top()] <= hist[i])
			s.push(i++);

		else {
			topOfStack = s.top();
			s.pop();

			area_with_top = hist[topOfStack] * (s.empty() ? i : i - s.top() - 1);

			if(max_area < area_with_top)
				max_area = area_with_top;
		}
	}

	while(s.empty() == false) {
		topOfStack = s.top();
		s.pop();
		area_with_top = hist[topOfStack] * (s.empty() ? i : i - s.top() - 1);

		if(max_area < area_with_top)
			max_area = area_with_top;
	}

	return max_area;
}