/**
 * Find the number of days for preceiding the current stock price for which the current price is the largest.
 * Basically find the previous greater element in the array. 
 * 
 * Time Complexity: O(N)
 */

void calculateSpan(int price[], int n, int S[])
{

    stack<int> st;
    st.push(0);
 
    // Span value of first element is always 1
    S[0] = 1;
 
    // Calculate span values for rest of the elements
    for (int i = 1; i < n; i++) {

        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();
 
        // If stack becomes empty, then price[i] is
        // greater than all elements on left of it,
        // Else price[i] is greater than elements 
        // aftertop of stack
        S[i] = (st.empty()) ? (i + 1) : (i - st.top());

        st.push(i);
    }
}