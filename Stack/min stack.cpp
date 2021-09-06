/**
 * Extract min element from a stack in O(1) time.
 * 
 * There is a O(N) extra space solution where we use a n auxilary stack
 * and store the current min element corresponding to each element in 
 * the original stack.
 * 
 * O(1) space solution:
 * 
 * Push(x) : Inserts x at the top of stack. 
 

	If stack is empty, insert x into the stack and make minEle equal to x.
	If stack is not empty, compare x with minEle. Two cases arise:
	If x is greater than or equal to minEle, simply insert x.
	If x is less than minEle, insert (2*x – minEle) into the stack and make minEle equal to x. For example, let previous minEle was 3. Now we want to insert 2. We update minEle as 2 and insert 2*2 – 3 = 1 into the stack.
	Pop() : Removes an element from top of stack. 
	 

	Remove element from top. Let the removed element be y. Two cases arise:
	If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
	If y is less than minEle, the minimum element now becomes (2*minEle – y), so update (minEle = 2*minEle – y). This is where we retrieve previous minimum from current minimum and its value in stack. For example, let the element to be removed be 1 and minEle be 2. We remove 1 and update minEle as 2*2 – 1 = 3.
	Important Points: 
	 



	Stack doesn’t hold actual value of an element if it is minimum so far.
	Actual minimum element is always stored in minEle
 */

struct MyStack {
	stack<int> s;
	int minEle;

	void getMIn() {
		if(s.empty())
			cout<<"Stack is empty\n";
		else
			cout<<"Minimum Element in the stack is: "<<minEle<<endl;
	}

	// print top element of the stack
	void peek() {
		if(s.empty()) {
			cout<<"Stack is empty\n";
			return;
		}

		int t = s.top();

		cout<<"Top Most Element is: ";

		// if t < minEle means minEle stores the value of t
		(t < minEle) ? cout<<minEle : cout<<t;
	}

	void pop() {
		if(s.empty()) {
			cout<<"Stack is empty\n";
			return;
		}

		cout<<"Top most element removed: ";

		int t = s.top();
		s.pop();

		// if t < minEle the minimum element will change 
		// as the minimum element of the stack is being removed
		if(t < minEle) {
			cout<<minEle<<"\n";
			minEle = 2*minEle - t;
		}
		else	// minEle remains the same and t is printed
			cout<<t<<"\n";
	}

	void push(int x) {
		if(s.empty()) {
			minEle = x;
			s.push(x);
			return;
		}

		// if new element is less than minEle
		if(x < minEle) {
			s.push(2*x - minEle);
			minEle = x;
		}
		else
			s.push(x);
	}
};