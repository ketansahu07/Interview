/*

Print all jumping numbers less than or
equal to a given number.

Time Complexity: O(K), where k is number 
of Jumping Numbers smaller than or equal to x.

*/

void bfs(int x, int num)
{
    queue<int> q;
    q.push(num);
  
    while (!q.empty()) {
        num = q.front();
        q.pop();
  
        if (num <= x) {
            cout << num << " ";
            int last_dig = num % 10;
  
            if (last_dig == 0)
                q.push((num * 10) + (last_dig + 1));
  
            else if (last_dig == 9)
                q.push((num * 10) + (last_dig - 1));
  
            else {
                q.push((num * 10) + (last_dig - 1));
                q.push((num * 10) + (last_dig + 1));
            }
        }
    }
}

void printJumping(int x)
{
    cout << 0 << " ";
    for (int i = 1; i <= 9 && i <= x; i++)
        bfs(x, i);
}