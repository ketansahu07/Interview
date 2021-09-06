/**
 * Sort a stack using recursion.
 * No loop is allowed. 
 * 
 * The idea of the solution is to hold all values in Function Call Stack until the stack becomes empty. 
 * When the stack becomes empty, insert all held items one by one in sorted order. 
 * Here sorted order is important.
 * 
 * 
 * sortStack(stack S)
    if stack is not empty:
        temp = pop(S);  
        sortStack(S); 
        sortedInsert(S, temp); 
 * 
 * 
 * sortedInsert(Stack S, element)
    if stack is empty OR element > top element
        push(S, elem)
    else
        temp = pop(S)
        sortedInsert(S, element)
        push(S, temp)

 * 
 * Time Complexity: O(N^2) 
 * Space Complexity: O(N)
 */


void sortedInsert(struct stack** s, int x)
{
    // Base case: Either stack is empty or newly inserted
    // item is greater than top (more than all existing)
    if (isEmpty(*s) or x > top(*s)) {
        push(s, x);
        return;
    }
 
    // If top is greater, remove the top item and recur
    int temp = pop(s);
    sortedInsert(s, x);
 
    // Put back the top item removed earlier
    push(s, temp);
}
 
// Function to sort stack
void sortStack(struct stack** s)
{
    // If stack is not empty
    if (!isEmpty(*s)) {
        // Remove the top item
        int x = pop(s);
 
        // Sort remaining stack
        sortStack(s);
 
        // Push the top item back in sorted stack
        sortedInsert(s, x);
    }
}