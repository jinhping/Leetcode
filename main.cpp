#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <climits>



using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
};



int singleNumber(vector<int>& nums) {
        
    sort(nums.begin(), nums.end());

    return 0;

}
bool checkValid(string s ){

    int count1 = 0;
    int count2 = 0;
    bool result = true;
    for(unsigned long i = 0 ; i < s.length(); i++){
        if(s[i] == '('){
            count1 ++;
        }else{
            count2 ++;
        }

        if(count2 > count1){
            result = false;
            return false;
        }
    }

    return true;
}
vector<string> generateParenthesis(int n) {
    vector<string> v;

    string s = "";
    for(int i = 0; i < n; i++ ){
        s = s + "(";
    }
    for(int i = 0; i < n; i++ ){
        s = s + ")";
    }

    do{
        if(s[0] == ')' || s[s.length() -1 ] == '('){
            continue;
        }else{
            bool t = true;
            t = checkValid(s);
            if(t==true){
                v.push_back(s);
            }
            //cout << s << endl;
        }
    }while(next_permutation(s.begin(),s.end()));


    for(unsigned long i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
    return v;

}

struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
};

void travel(TreeLinkNode *root,TreeLinkNode *next, bool isleft, bool beenToLeft){


    if(isleft){
        root->left->next = root -> right;
        root-> right -> next = next -> left;
        beenToLeft = true;
        if(root -> left -> left!= NULL){
            travel(root->left,root->left->next,isleft, beenToLeft);
            travel(root->right,root-> right -> next,0, beenToLeft);
        }
    }
    else{

        root->left ->next = root-> right;
        if(beenToLeft){
            root -> right -> next = next -> left;
        }
        if(root->left -> left != NULL){
            travel(root->left, root->left->next, 1, beenToLeft);
            travel(root->right, root->right->next,0,beenToLeft);
        }
        
       
    }

}
void connect(TreeLinkNode *root) {
    if(root == NULL) return;
    if(root -> left != NULL){
        root -> left -> next = root -> right;
        if(root -> left -> left != NULL){
            travel(root -> left, root->left -> next, 1, 1);
            travel(root -> right, root->right->next,0,0);
        }

    }
}



int maxSubArray(vector<int>& nums) {
    int length = nums.size();
    vector<vector<int> > v(length, vector<int>(length)); 
    int max = 0;
    for(int i = 0; i < length; i++){
        if(nums[i] > max){
            max = nums[i];
        }
    }

    for(int i = 0; i < length; i++){
        v[0][i] = max;
    }

 //   cout << "max: " << max << endl;

    int t_max = max;
    for(int i = 1; i < length;i++){
       // t_max = v[i-1][length-1];
        for(int j = i; j < length; j++){
            int tmp = 0;
            int count = i + 1;
            int j2 = j;
           

                while(count > 0){
                    tmp = tmp + nums[j2];
                    count --;
                    j2 --;
                }

                if(tmp > t_max){
                    v[i][j] = tmp;
                    t_max = tmp;
                }else{
                    
                    v[i][j] = t_max;
                }
            
        }
    }
/*
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            cout << v[i][j] << " " ;
        }
        cout << endl;
    }

*/


    cout <<  v[length-1][length-1] << endl;

    return v[length-1][length-1];

}


int uniquePaths(int m, int n) {
        
    vector <vector<int> > v(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        v[i][0] = 1;
    }
    for(int i = 0; i < n; i++){
        v[0][i] = 1;
    }

    for(int i = 1; i < m ; i++ ){
        for (int j = 1; j < n ; j++ ){
            v[i][j] = v[i-1][j] + v[i][j-1];
        }
    }


    return v[m-1][n-1];
}


int maxProfit(vector<int>& prices) {
/*
    vector<int> v(prices.size(), 0);

    int max = 0;
    for(unsigned long i = 0; i < prices.size(); i++){
        for(int j = i; j >= 0 ; j --){

            int tmp = prices[i] - prices[j];
            if(tmp > max){
                max = tmp;
            } 

        }
    }
    cout << max << endl;

    return max;
*/

/*
    if(prices.size() == 0){
        return 0;
    }
    int max = 0;
    for(unsigned long i = 0 ; i < prices.size() - 1; i++){
        for(unsigned long j = i + 1; j  <prices.size();j++ ){
            int tmp_max = prices[j] - prices[i];
            if(tmp_max > max ){
                max = tmp_max;
            }
        }
    } 

    return max;
*/


    if(prices.size() == 0){
        return 0;
    }
    int max = 0;
    int min = prices[0];

    for(unsigned long i =1; i < prices.size(); i++ ){
        if(min > prices[i] ){
            min = prices[i];
        }
        if(max < prices[i] - min){
            max = prices[i] - min;
        }

    }
    return max;
}

void helper(vector<vector<int> > &result, vector<int> &v, int start, int k, int n){

    if(k == 0 && n == 0){
        result.push_back(v);
        return;
    }
    for (int i = start; i < 10; i ++ ){
        v.push_back(i);
        helper(result, v, start + 1,k -1  ,n - i);
        v.pop_back();
    }
}

vector<vector<int> > combinationSum3(int k, int n) {
        
    vector<vector<int> > result;

    vector<int> v; 
    helper(result, v, 1, k,n);
    return result;

}

vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > result; 
        sort(nums.begin(), nums.end());
        vector<int> v = nums;
        do{ 
            v =nums;
            result.push_back(v);

        }while(next_permutation(nums.begin(),nums.end()));
       
         return result;

}

void helper2(vector<vector<int> > &result, queue<int> &q, int n, int start, int end){
    if(q.empty()){
        return;
    }
           
    for(int i = start; i <= end ; i++ ){


        result[start][i] = q.front();

        q.pop();
    }



    for(int i = start+1; i <= end; i++){
        result[i][end] = q.front();

        q.pop();
    }


    for(int i = end - 1; i >=start; i-- ){
        result[end][i] = q.front();

        q.pop(); 
    }

    for(int i = end -1 ;  i > start;i-- ){
        result[i][start] = q.front();
        q.pop();
    }

    helper2(result,q, n - 2,start+1, end -1);


}
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int> > result(n, vector<int>(n));  
    queue<int> q;
     for(int i = 1; i <=n*n; i++){
        q.push(i);
    } 

    helper2(result,q, n , 0, n-1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return result;
}


int minPathSum(vector<vector<int>>& grid) {
    
    for(unsigned long i = 1; i < grid[0].size(); i++){
        grid[0][i] = grid[0][i-1] + grid[0][i];
    }

    for(unsigned long i = 1; i < grid.size(); i++){
        grid[i][0] = grid[i-1][0] + grid[i][0];
    }
    for(unsigned long i = 1; i < grid.size();i++){
        for(unsigned long j = 1; j < grid[0].size();j++){

            if(grid[i][j-1] > grid[i-1][j]){
                grid[i][j] = grid[i][j] + grid[i-1][j];
            }else{
                grid[i][j] = grid[i][j] + grid[i][j-1];
            }
        }
    }

    return grid[grid.size() - 1][grid[0].size() -1];
}

void sortColors(vector<int>& nums) {
        
    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;
    vector<int> v;
    for(unsigned long i = 0; i < nums.size(); i++){

        if(nums[i] == 0){
            count_0 ++;
        }else if(nums[i] == 1){
            count_1 ++;
        }else{
            count_2 ++;
        }
    }
    
    while(count_0 != 0){
        v.push_back(0);
        count_0--;

    }
    while(count_1 != 0){
        v.push_back(1);
        count_1--;

    }
    while(count_2 != 0){
        v.push_back(2);
        count_2--;

    }

    for(unsigned long i =0 ; i < v.size(); i++){
        nums[i] = v[i];
    }
    return;

}



void rotate(vector<vector<int>>& matrix) {
    vector<vector<int> > v(matrix.size(), vector<int>(matrix.size()));
    int tmp = 0;
    for(int i = matrix[0].size()-1; i >= 0; i--){
        for(unsigned long j = 0; j < matrix.size(); j++){
            v[j][i] = matrix[tmp][j];
        }
        tmp++;
    }
   
    for(unsigned long i = 0; i < v.size(); i++){
        for(unsigned long j = 0; j < v[0].size();j++ ){
            matrix[i][j] = v[i][j];
        }
    }
}



int integerBreak(int n) {
    if(n == 2 )  return 1;
    if(n == 3 )  return 2;
    if(n == 4)  return 4;
    if(n == 5 )  return 6;
    if(n == 6 )  return 9;
    return 3*integerBreak(n-3);
}


bool searchMatrix(vector<vector<int> >& matrix, int target) {
    
    unsigned long i = 0;
    int j = matrix[0].size() - 1;    

    while(i < matrix.size() && j>= 0){
        if(matrix[i][j]  == target){
            return true;
        }

        if(matrix[i][j] < target){
            i++;
        }else{
            j--;
        }
    }
    return false;
}

struct TreeNode {
   int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helperRightSideView(TreeNode * root, unsigned long level, vector<int> &result){

    if(root == NULL) return;
    if( result.size() < level ) result.push_back(root->val);
    helperRightSideView(root -> right, level+1, result);
    helperRightSideView(root -> left, level+1, result);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> result;

    helperRightSideView(root,1,result);

    return result;
}




string reverseString(string s) {
    int length = s.length();
    bool even = true;
    if(length%2 ){
        even = false;
    }
    
    if(even){   
        int end = length; 
        for(int i = 0; i < length/2; i++){
            char tmp = s[i];
            s[i] = s[end-1];
            s[end-1] = tmp;
            end --;
        }
        return s;
    }else{
        int end = length;
        for(int i = 0; i < (length - 1)/2; i++){
            char tmp = s[i];
            s[i] = s[end-1];
            s[end-1] = tmp;
            end --;
        }
        return s;
    }
}



void invertTree_helper(TreeNode * root){
    if(root -> left != NULL && root ->right != NULL){

        TreeNode *tmp = new TreeNode(root->left->val);
        tmp -> left = root -> left -> left;
        tmp -> right = root -> left -> right;
    
        root -> left = root -> right;
        root -> right = tmp;
    }
    if(root -> left !=NULL && root -> right == NULL){
        TreeNode *tmp = new TreeNode(root->left->val);
        tmp -> left = root -> left -> left;
        tmp -> right = root -> left -> right;

        root -> left = NULL;
        root -> right = tmp;
    }else if(root -> right !=NULL && root -> left == NULL){
        TreeNode *tmp = new TreeNode(root->right->val);
        tmp -> left = root -> right -> left;
        tmp -> right = root -> right -> right;

        root -> left = tmp;
        root -> right = NULL;
    }

    if(root -> left != NULL){
       invertTree_helper(root -> left); 
    }
    if(root -> right != NULL){
        invertTree_helper(root -> right);
    }
    return;
}

TreeNode* invertTree(TreeNode* root) {
    if(root == NULL){
        return root;
    }

    if(root -> left != NULL && root ->right != NULL){
        TreeNode *tmp = new TreeNode(root->left->val);
        tmp -> left = root -> left -> left;
        tmp -> right = root -> left -> right;

        root -> left = root -> right;
        root -> right = tmp;
    }

    if(root -> left !=NULL && root -> right == NULL){
        TreeNode *tmp = new TreeNode(root->left->val);
        tmp -> left = root -> left -> left;
        tmp -> right = root -> left -> right;

        root -> left = NULL;
        root -> right = tmp;
    }else if(root -> right !=NULL && root -> left == NULL){
        TreeNode *tmp = new TreeNode(root->right->val);
         tmp -> left = root -> right -> left;
        tmp -> right = root -> right -> right;

        root -> left = tmp;
        root -> right = NULL;
    }
    
    if(root -> left != NULL){
       invertTree_helper(root -> left); 
    }
    if(root -> right != NULL){
        invertTree_helper(root -> right);
    }
    return root;
}


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s1;
    unordered_set<int> s2;
    
    for(unsigned long i = 0; i < nums1.size(); i++){
        s1.insert(nums1[i]);
    }
    for(unsigned long i = 0; i < nums2.size(); i++){
        s2.insert(nums2[i]);
    } 
        vector<int> result;
    for(auto i = s2.begin(); i != s2.end(); i++){
        if(s1.find(*i) != s1.end()){
            result.push_back(*i);

        }
    }


    return result;
}


vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    unordered_map<int ,int> m;
    for(unsigned long i = 0; i < nums1.size(); i++){
        if(m.find(nums1[i] )== m.end()){
            m[nums1[i]] = 1;
        }else{
            m[nums1[i]]++;
        }
    }

    for(unsigned long i = 0; i< nums2.size();i++){
        if(m.find(nums2[i]) != m.end() && m[nums2[i]] != 0){
            result.push_back(nums2[i]);
            m[nums2[i]]--;
        }
    }
    return result;

}

int lengthOfLIS(vector<int>& nums) {
    vector<int> result(nums.size(), 1);
    if(nums.size() == 1 ) return 1;
    if(nums.size() == 0) return 0;
    int min = 0;
    unsigned long i;
    for(i = 1; i < nums.size(); i++){
        if(nums[i] > nums[i-1]){
            min = nums[i-1];
            break;
        }
    }
    cout << "min: " << min << endl; 

    for(unsigned long j = i ; j<nums.size(); j++){

        if(nums[j] > min ){
            result[j] = result[j-1] + 1;
            min = nums[j];
        }else{
            result[j] = result[j-1];
        }

    }
     for(unsigned long k = 0; k < result.size(); k++){
        cout << result[k] <<  " ";

    }
    cout << endl;
    sort(result.begin(), result.end());

    for(unsigned long k = 0; k < result.size(); k++){
        cout << result[k] <<  " ";

    }
    cout << endl;

    return result[result.size()-1];
}

bool binary_search(unsigned long m, unsigned long beginning, unsigned long end, vector<vector<int>> &matrix,  int target, bool &result){
    
    if(end < beginning) return false;
    else if(end == beginning){
        if(matrix[m][beginning] == target){
            result = true;
            return true;
        } 
        else return false;
    }
    int mid = (end+beginning+1)/2;
    cout << "mid: " << mid << endl;
    cout << "8: " << matrix[m][mid] << "99: " << target << endl;
    if(matrix[m][mid] == target){
      //  cout << "10 ---- " << endl;
        result = true;
        return true;
     //   cout << "11 ------  " << endl;
    }
    else if(matrix[m][mid] < target){
      //  cout << "13 ------  " << endl;

        beginning = mid;
        binary_search(m,beginning,end,matrix,target,result);
    }
    else if(matrix[m][mid] > target){

        end = mid -1;
        binary_search(m,beginning,end,matrix,target,result);
    }
    return false;
}

bool searchMatrix_2nd(vector<vector<int>>& matrix, int target) {
    // 先确定哪一行 再做binary search 
    int m = -1; // 哪一个row 的 index
    bool exist = false;
    cout << "1111 " << endl; 
    for(unsigned long i = 0; i < matrix.size();i++){
        if(matrix[i][0] == target){
                cout << "2222 " << endl; 

            return true;
        }
        else if(matrix[i][0] < target){
                cout << "3333 " << endl; 
            exist = true;
            m = i;
        }

    }
        cout << "44444 " << endl; 
    if(exist == false) return false;
    cout << "5555 " << endl;
    cout << "m: " << m << endl;
    cout << matrix[m][matrix[0].size()-1] << endl;
    cout << "target: " << target << endl;
    if(matrix[m][matrix[0].size()-1] == target){
            cout << "6666 " << endl;

        return true;
    }
    else if(matrix[m][matrix[0].size()-1] < target){
            cout << "7777 " << endl;

        return false;
    }


    // 确定可能在 index 为 m 的这一行里 之后做 binary search
    unsigned long n = matrix[0].size()-1;

    cout << "m: " << m << endl;
    cout << "n: " << n << endl;
    bool result = false;
    binary_search(m,0,n,matrix,target,result);
    return result;
}

bool increasingTriplet(vector<int>& nums) {
    int a = INT_MAX;
    int b = INT_MAX;
    for(int x : nums){
        if(x <= a){
            a = x;
        }
        else if( x <= b){
            b = x;
        }
        else return true;
    }
    return false;
}

int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    int size = nums.size();
    return nums[size-k];
            
}

void setZeroes(vector<vector<int>>& matrix) {

    unordered_set<int> column;
    unordered_set<int> row;

    int m = matrix.size();
    int n = matrix[0].size();

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 0){
                row.insert(i);
                column.insert(j);
            }
        }
    }

    for(auto itr = row.begin(); itr != row.end(); itr ++){
        for(int j = 0; j < n ; j++){
            matrix[*itr][j] = 0;
        }
    }

    for(auto itr = column.begin(); itr != column.end(); itr ++){
        for(int i = 0; i < m ; i++){
            matrix[i][*itr] = 0;
        }
    }

    return;

}

int findPeakElement(vector<int>& nums) {

    if(nums.size() == 1 ) return 0;
    int index = 0;
    for(unsigned long i = 1; i < nums.size(); i++){
        if(nums[i] > nums[i-1]){
            index = i;
        }else{
            break;
        }
    }
    return index;
}

int sumNumbers_helper(TreeNode *root, int result){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return result*10 + root -> val;
    }

    return sumNumbers_helper(root->left, result*10 + root->val) + sumNumbers_helper(root->right,result* 10 + root->val);

}
int sumNumbers(TreeNode* root) {
    int result = sumNumbers_helper(root, 0);
    return result;

}



int removeDuplicates(vector<int>& nums) {
    vector<int> tmp; 
    unordered_map<int,int> m;
        cout << "4444  " << endl;

    for(unsigned long i = 0; i < nums.size(); i++){
        if(m.find(nums[i]) != m.end()){
            m[nums[i]] = 2;
        }else{
            m[nums[i]] = 1;
        }
    }

    set<int> s;
    for(unsigned long i =0; i< nums.size(); i++){
        s.insert(nums[i]);
    }


    cout << "11111  " << endl;
    for(auto i = s.begin(); i != s.end(); i++){
        if(m[*i] == 1){
            tmp.push_back(*i);
        }else{
            tmp.push_back(*i);
            tmp.push_back(*i);
        }
    }
    cout << "22222 " << endl;

    int size = tmp.size();
    cout << "size: " << size << endl;
    cout << "tmp.size() " << tmp.size() << endl;
        cout << "33333 " << endl;

    for(unsigned long i = 0; i < tmp.size(); i++){
        nums[i] = tmp[i];
    }

    cout << "5555  " << endl;

    return size;
    
}

//priority_queue 的 练习 + make_pair, pair
vector<int> topKFrequent(vector<int>& nums, int k) {
    
    map<int, int> m;
    for(unsigned long i = 0; i < nums.size(); i++){
        if(m.find(nums[i]) == m.end()){
            m[nums[i]] = 1;
        }else{
            m[nums[i]]++;
        }
    }

    priority_queue< pair<int, int> > pq;
    vector<int> tmp;

    for(auto itr = m.begin(); itr != m.end(); itr ++ ){
      //  cout << "itr->first: " << itr->first << " " << itr -> second << endl; 
        pq.push(make_pair(itr->second, itr->first));
    }

    for(int i = 0; i < k; i++){
        tmp.push_back(pq.top().second);
       // cout << pq.top().second << endl;
        pq.pop();
    }
    return tmp;
}



//这个方法trick了leetcode， 其实应该用一个set 来储存所有出现过的sum,如果已经出现在了set里面，说明这个重复，然后就不会出现1，就return false;
bool isHappy(int n) {

    int tmp = n;
    int result = 0;
    while(tmp){

        result = (tmp%10)*(tmp%10) + result;
        tmp = tmp/10;
    }   
    result = result + tmp*tmp;
    tmp = result;

    int count = 50;
    while(result != 1){
        result = 0;
        while(tmp){

         result = (tmp%10)*(tmp%10) + result;
         tmp = tmp/10;
        }   
        result = result + tmp*tmp;
        tmp =result;

        count --;
        if(count == 0){
            return false;
        }
    }


    if(result == 1 )return true;
    else return false;
}

ListNode* swapPairs(ListNode* head) {
    if(head == NULL) return head;

    ListNode * first = head;
    if(first -> next == NULL) return head;
    ListNode * second = first -> next;
    
    bool exist = false;     
    do{
        exist = false;     
        int tmp = first -> val;
        

        first->val = second -> val;
        second -> val = tmp;
        cout << "first -> val: " << first -> val << endl;
        cout << "second -> val: " << second -> val << endl;
        if(second -> next != NULL && second-> next -> next != NULL){
            first = second -> next;
            second = second -> next -> next;
            exist = true;
        }
    }while(exist);

    return head;
}


string reverseVowels(string s) {
    unsigned long j = s.length() - 1;
    for(unsigned long i = 0 ; i< s.length(); i++){
        while((s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' &&
            s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U') && i < s.length()){
            i++;
        }
        while((s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u' &&
            s[j] != 'A' && s[j] != 'E' && s[j] != 'I' && s[j] != 'O' && s[j] != 'U') && j > 0){
            j--;
        }

        cout << "i: " << i << endl;
        cout << "j: " << j << endl;  
        if(j > i){
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }else{
            break;
        }
        j--;
    }
    cout << s << endl;
    return s;
}

int hIndex(vector<int>& citations) {

    sort(citations.begin(), citations.end());
    unsigned long n = citations.size();
    int h;
    for(h = n; h > 0; h--){
        if(citations[n-h] >= h){
            break;
        }else{
            continue;
        }
    }
    return h; 
}


int hIndex2(vector<int>& citations) {

    int n = citations.size();
    if(n==0) return 0;
    int beginning = 0;
    int ending = n -1 ;
    int h;

    while(ending >= beginning){
        h = (ending + beginning )/2;
        cout << "h: " << h << endl;
        if(citations[h] >= n-h){
            ending = h -1 ;            
        }else{
            beginning = h + 1;
        }
    }

    return n-beginning; 
}

int search(vector<int>& nums, int target) {
    
    for(unsigned long i = 0; i < nums.size(); i++){
        if(nums[i] == target){
            return i;
        }
    }
    return -1;

}

int search2(vector<int>& nums, int target) {
    
    int low = 0;
    int high = nums.size()-1;
    int mid = 0;

    while(low < high ){
        mid = (low + high)/2;
        if(nums[mid]== target) return mid;
        if(nums[mid] > nums[high]){
            if(nums[mid] > target && nums[low] <= target){
                high = mid;
            }else low = mid + 1;
        }
        else if(nums[mid] < nums[high]){
            if(nums[mid] < target && nums[high] >= target){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        else high --;
    }
    return nums[low] == target ? low : -1;

}

vector<vector<int>> subsets(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> subs(1, vector<int>());

    for(unsigned long i = 0; i < nums.size(); i++){
        int n = subs.size();
        for(int j = 0; j < n; j++){
            subs.push_back(subs[j]);
            subs.back().push_back(nums[i]);
        }

    }
    return subs;
}

bool hasCycle(ListNode *head) {
    if(head == NULL) return false;
    unordered_set<ListNode*> s;
    s.insert(head);
    while(head){
        head = head -> next;
        if(s.find(head) == s.end()){
            s.insert(head);
        }else{
            return true;
        }
    }    

    return false;
}

ListNode *detectCycle(ListNode *head) {
    
    bool detect = false;
    detect = hasCycle(head);

    if(detect == true){
        unordered_set<ListNode*> s;
        s.insert(head);
        while(head){
            head = head -> next;
            if(s.find(head) == s.end()){
                s.insert(head);
            }else{
                return head;
            }
        }
        return NULL;    

    }else{
        return NULL;
    }
}


TreeNode *pre = NULL;
void flatten(TreeNode* root) {
    if(root == NULL) return; 
    flatten(root->left);
    flatten(root->right);
    root->right = pre;
    root->left =NULL;
    pre =root;
}

ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL) return NULL;
    int size =0;
    ListNode * tmp = head;
    while(tmp){
        size++;
        tmp = tmp -> next;
    }
    int k2 = k%size; 
    if(k2 == 0) return head;
    else{
        int j = size - k2;
        vector<int> v1;
        vector<int> v2;
        ListNode * tmp2 = head;
        while(j != 0){
            v1.push_back(tmp2->val);
            tmp2 = tmp2->next;
            j--;
        }

        while(k2 != 0){
            v2.push_back(tmp2->val);
            tmp2 = tmp2->next;
            k2 --;
        }

        for(int x : v1){
            v2.push_back(x);
        }

        ListNode *tmp3 = head;
        int i = 0;
        while(tmp3){
            tmp3->val = v2[i];
            i++;
            tmp3=tmp3->next;
        }
    }
    return head;

}

void combinationSum_helper(vector<vector<int>> & result, vector<int> &combine, vector<int> &candidates, int target, int begin ) {
    if(target == 0){
        result.push_back(combine);
        return;
    }

    for(unsigned long i = begin; i < candidates.size() && target >= candidates[i]; i++){
        combine.push_back(candidates[i]);
        combinationSum_helper(result, combine, candidates, target - candidates[i],i);
        combine.pop_back();
    }
}

//backtracking 的题目， 使用backtracking 模板
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> combine; 
    combinationSum_helper(result, combine, candidates, target, 0);
    return result;

}


// 这个有更简单的方法 就是 创建2个ListNode, 一个 小于3， 一个 不小于， 一遍pass 原来的 ListNode, 最后 小于3的那个 next 指向 不小于3的head.
ListNode* partition(ListNode* head, int x) {
           if(head == NULL) return head;
    ListNode *cur = head;
    ListNode * new_head = NULL;
    while(cur){
       if(cur->val < x){
         new_head = new ListNode(cur->val);
         break;
       }else{
         cur = cur -> next;
       }
    }

    if(!cur){
        cout << "111" << endl;
    }
    ListNode * second = new_head;

    if(cur != NULL){
        while(cur->next){
            cur = cur->next;
            if(cur ->val < x){
                second -> next = new ListNode(cur -> val);
                second = second -> next;
            }else{
                continue;
        }
    }

    }

    

    cout << "222" << endl;

    if(second != NULL){
while(head){
        if(head -> val >= x){
            second -> next = new ListNode(head-> val);
            second = second -> next; 
            head = head-> next;
        }else{
            head = head -> next;
        }
    }
    }

    cout << "333" << endl;

    if(new_head != NULL){
        return new_head;
    }else return head;
    }


void postorder(vector<int> &res, TreeNode *root){
    if(root == NULL){
        return;
    }

    postorder(res,root -> left);
    postorder(res,root->right);
    res.push_back(root -> val);

}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    postorder(res,root);
    return res;        
}


//判断是否是 palindrome; 
// aba  aaabbb aaacbbb  abcc  aabb 
//初步判读 数每个char 的个数， 长度是偶数的 就每字母的都是 偶数   长度是odd， 就1个字母不是偶数
bool canPermutePalindrome(string s) {

    int length = s.length();
    if(length % 2 == 0){
        unordered_map<char, int> m;
        for(int i = 0; i < length; i++){
            if(m.find(s[i]) != m.end()){
                m[s[i]] ++;
            }else 
            {
                m[s[i]] = 1;
            }
        }

        for(int i = 0; i < length; i++){
            if(m[s[i]]%2 != 0){
                return false;
            }
        }
        return true;
    }
    else
    {
        unordered_map<char,int> m;
        for(int i = 0; i < length; i++){
            if(m.find(s[i]) != m.end()){
                m[s[i]] ++;
            }else 
            {
                m[s[i]] = 1;
            }
        }

        int count = 0;
        for(auto itr = m.begin(); itr != m.end(); itr++)
        {
            if(itr ->second %2 != 0){
                count ++;
            }
        }
        

        if(count == 1){
            return true;
        }else return false;
    } 


}


int shortestDistance(vector<string>& words, string word1, string word2) {

    int dis1 = -1;
    int dis2 = -1;
    int diff = 0;
    int min = -1;
    for(unsigned long i = 0; i < words.size();i++){

        if(words[i] == word1){
            dis1 = i;
        }
        if(words[i] == word2){
            dis2 = i;
        }
        if(dis1 != -1 && dis2 != -1){
            diff = abs(dis1 - dis2);
            if(min == -1){
                min = diff;
            }
        }
        if(diff < min){
            min = diff;
        }
    }
    return min;
}

struct Interval{
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};

struct myclass{
    bool operator()(Interval a, Interval b){
        return a.start < b.start;
    }
}myobject;


bool canAttendMeetings(vector<Interval>& intervals) {
        
    sort(intervals.begin(), intervals.end(), myobject);
    for(unsigned long i = 1; i < intervals.size(); i++){
        if(intervals[i].start < intervals[i-1].end){
            return false;
        }   
    }
    return true;
}

vector<string> generatePossibleNextMoves(string s) {
        vector<string> result = {};
        if(s.length() == 0 ){
            return result;
        }    for(unsigned long i = 0; i < s.length() -1 ; i++){
        if(s[i] == '+' && s[i+1] == '+') {
            string tmp = s;
            tmp[i] = '-';
            tmp[i+1] = '-';
            result.push_back(tmp);
        }
    } 
    return result;
}

//"66811 11899"  
// 66811 8 or 1 11899
bool isStrobogrammatic(string num) {

    if(num.length()%2 == 0){
        string a = num.substr(0,num.length()/2);
        string b = num.substr(num.length()/2, num.length()/2);
        cout << a << endl;
        cout << b << endl; 

        for(unsigned long i = 0,j = b.length() -1; i < a.length(); i++, j--){
            if(a[i] == '6' && b[j] != '9'){
                return false;
            }else if(a[i] == '9' && b[j] != '6'){
                return false;
            }else if(a[i] == '8' && b[j] != '8'){
                return false;
            }else if(a[i] == '1' && b[j] != '1'){
                return false;
            }else if(a[i] == '0' && b[j] != '0'){
                return false;
            }else if(a[i] == '2' || a[i] == '3' ||a[i] == '4' ||a[i] == '5' ||a[i] == '7' ){
                return false;
            }else if(b[j] == '2' || b[j] == '3' ||b[j] == '4' ||b[j] == '5' ||b[j] == '7' ){
                return false;
            }
        }   
        cout << "dui" << endl;
        return true;
    }else{
        string a = num.substr(0,num.length()/2);
        string b = num.substr(num.length()/2+1, num.length()/2);
        cout << a << endl;
        cout << b << endl; 
        cout << num[num.length()/2] << endl;
        if(num[num.length()/2]!='1' && num[num.length()/2]!='0'&& num[num.length()/2]!='8' ){
            return false;
        }

        cout << "111" << endl;

        for(unsigned long i = 0,j = b.length() -1; i < a.length(); i++, j--){
            if(a[i] == '6' && b[j] != '9'){
                return false;
            }else if(a[i] == '9' && b[j] != '6'){
                return false;
            }else if(a[i] == '8' && b[j] != '8'){
                return false;
            }else if(a[i] == '1' && b[j] != '1'){
                return false;
            }else if(a[i] == '0' && b[j] != '0'){
                return false;
            }else if(a[i] == '2' || a[i] == '3' ||a[i] == '4' ||a[i] == '5' ||a[i] == '7' ){
                return false;
            }else if(b[j] == '2' || b[j] == '3' ||b[j] == '4' ||b[j] == '5' ||b[j] == '7' ){
                return false;
            }
        }   
        cout << "dui" << endl;
        return true;
    }
}


int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    m[0] = -1;
    int sum = 0;
    int maxLen = 0;
    for(unsigned long i = 0; i < nums.size(); i++){
        sum = sum + nums[i];
        if(m.count(sum) == 0){
            m[sum] = i;
        }
        if(m.count(sum - k)){
            maxLen = max(maxLen, int(i - m[sum-k]));
        }
    }

    return maxLen;

}



void preorderBST(TreeNode *root, vector<int> &nums){
    if(root == NULL) return;
    nums.push_back(root -> val);
    preorderBST(root -> left, nums);
    preorderBST(root -> right, nums);

}

int binary_search_min(vector<int> &nums, double target, double &diff, int &low, int &high, int &min, double min_diff){
    int mid = (high + low) / 2;
    diff = nums[mid] - target;
    cout << "low: " << low << endl;
    cout << "high: " << high << endl;
    cout << "mid: " << mid << endl;
    cout << "diff: " << diff << endl;
    cout << "min_diff: " << min_diff << endl;
    if(diff == 0.0){
        cout << "nums[mid] " << nums[mid] << endl;
        min = nums[mid];
        return min;
    }else if(diff > 0){
        cout << "1111" << endl;
        high = mid - 1;
        if(abs(diff) <= min_diff){
            cout << "4444" << endl;
            min_diff = abs(diff);
            min = nums[mid];
            
        }
        if(high >= low){
                  binary_search_min(nums,target,diff,low, high, min,min_diff);
  
        }
    }else if(diff < 0){
        cout << "333333" << endl;
        low = mid + 1;
        if(abs(diff) <= min_diff){
            cout << "2222" << endl;
            min_diff = abs(diff);
            min = nums[mid];
            cout << "min: " << min << endl;
        }
 if(high >= low){
                  binary_search_min(nums,target,diff,low, high, min,min_diff);
  
        }    }
    return min;

}
int closestValue(TreeNode* root, double target){
    vector<int> nums;
    preorderBST(root, nums);
    sort(nums.begin(), nums.end());
    
    for(int i : nums){
        cout << i << endl;
    }
    
    int low = 0;
    int high = nums.size() -1;
    int min = 0;
    double diff = 0.0;
    return binary_search_min(nums, target, diff, low, high, min, 1.79769e+308);
}



vector<vector<int>> levelOrderBottom(TreeNode* root) {

    queue<TreeNode*> q;
    vector<vector<int>> result;
    
    stack<vector<int>> s;

    if(root == NULL) return result;
    
    q.push(root);
    while(!q.empty()){
        vector<int> tmp;
        int size = q.size();
        cout << "size: " << size << endl;

        while(size != 0){
            if(q.front()-> left != NULL){
                q.push(q.front()->left);

            }
            
            if(q.front() -> right != NULL){
                 q.push(q.front()->right);

            }

        
            tmp.push_back(q.front() -> val);
            q.pop();
            size --;
        }

        s.push(tmp);
    }

    while(!s.empty()){
        result.push_back(s.top());
        s.pop();
    }
    return result;
}




vector<int> getRow(int rowIndex) {
    if(rowIndex == 0){
        vector<int> result = {1};
        return result;
    }
    if(rowIndex == 1){
        vector<int> result = {1,1};
        return result;
    }
    if(rowIndex == 2){
        vector<int> result = {1,2,1};
        return result;
    }
    int k = rowIndex;
    vector<int> tmp = {1,2,1};
    vector<int> result;
    while(k != 2){
        vector<int> next;
        next.push_back(1);
        for(unsigned long i = 0; i < tmp.size()-1;i++){
            next.push_back(tmp[i] + tmp[i+1]);
        }
        next.push_back(1);
        k--;
        tmp = next;
        result = next;
    }
    return result;
}
int main(){
    
    vector<int> result = getRow(4);
    for(unsigned long i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}


