#include <iostream>
#include <math.h>
#include <stdint.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <hash_map>
#include <set>
#include <stack>
#include <map>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution { 
public:
    ListNode* reverseList(ListNode* head) {
		ListNode *p,*tmp;
		//if only one node  return node
		if(head->next == NULL)
			return head;
		p=head->next;	
		head->next=NULL;
		// insert currend node in head 
		while(p)
		{
			tmp=p;
			p=p->next;
			tmp->next=head;
			head=tmp;
		}
		return head;
    }
	Solution(int x){}  ;

	bool isIsomorphic(string s, string t) {
		if(s.length() !=t.length()) return false;
        map<char,char>  Ismorphic;
		map<char,char>::iterator it;
		return true ;
		
    }
	int countPrimes(int n) {
		int sql=sqrt(n);
		int * flag = (int *)malloc(sizeof(int)*(n+1));
		if(flag)
		{
		for(int i = 1 ; i <=n ; i ++)
			*(flag +i)=1;
		}
		for(int i = 2 ; i <sql+1; i ++)
		{
			if(IsPrimes(i))
			{
				for(int j = 2*i  ; j <= n  ; j+=i )
					*(flag +j) = 0;
			}
		}
		int sum(0);
		for(int i = 2 ; i <=n ; i ++)
			sum+=*(flag +i);
		free(flag);
		return sum;
			
    }
	bool IsPrimes(int n){
		if(n == 2 || n == 3) return true;
		int sql = sqrt(n);
		for(int i = 2 ; i <=sql ; i ++)
			if(n % i == 0)
				 return false;
		return true;
	}
	 ListNode* removeElements(ListNode* head, int val) {
		 if(head ==NULL ) return head;
		 if(head->next == NULL && head->val == val)
		 {
			 free(head);
			 return NULL;
		 }

		 ListNode *  p,*tmp;

		 p->next = head;
		 head=p;

		 while(p->next)
		 {
			 tmp=p->next;
			 if(tmp->val == val)
			 {
				 p->next=tmp->next;
				 free(tmp);
				 continue;
			 }
			 p=p->next;
		 }
         return head->next;
    }
// move 31  and the 
	 uint32_t reverseBits(uint32_t n) {
          uint32_t result = 0 ; 
		  for(uint32_t i = 1 ; i <32 ;i++ )
		  {
			  result |=n&1;
			  n>>=1;
			  result<<=1;
		  }
		  return result|=n&1;
    }


	 int reverse(int x) {
     int result = 0 ; 
	 int tmp = abs(x);
	 while(true)
	 {
		 result += tmp%10;
		 tmp/=10;
		 if(tmp == 0)break;
		 if(result *10 /10  != result) return 0;
		 result*=10;
	 }
	 if(result < 0) return 0;
	 if(x > 0)
	  return result;
	 else
	  return -result;
    }
	 string largestNumber(vector<int>& nums) {
		 vector<int> num;
		 for(int i = 0 ; i <nums.size() ; i++)
		 {
			 int tmp = nums[i];
			 while(true)
			 {
				 tmp/=10;
				 if(tmp < 10)
				 {
					 num.push_back(int(tmp));
					 break;
				 }
			 }
		 }
    }

	 int titleToNumber(string s) {
		 int result(0);
		 for(int i = 0 ; i <s.length()-1; i ++)
		 {
            result+=(s[i]-'A'+1);
			result*=26;
		 }
		 result+=(s[s.length()-1]-'A'+1);
		 return result;
    }
	 int majorityElement(vector<int>& nums) {
        map<int ,int> key;
		for(int i = 0 ; i <nums.size() ; i ++)
			++key[nums[i]];
		map<int ,int>::iterator it;
		int  count(0),result;
		for(it = key.begin() ; it !=key.end(); it++)
			if(count <it->second )
			{
				result=it->first;
				count=it->second;
			}
			return result;
/*	int  count(0), result=nums[0];
	 for(int i =1 ; i <nums.size(); i ++)
	 {
		 if(count == 0) 
		    {
				result= nums[i];
				count++;
				continue;
		    }
		 if(result == nums[i]) 
				 count++;
		 else
			 count--;         
	 }
	 return result;*/
    }

	 string convertToTitle(int n) {
        string result;
		char tmp;
		while (true)
		{
			tmp=((n-1)%26 +'A');
			result=tmp+result;
			n=(n-1)/26;
			if(n == 0) break;
		};   
		return result;
    }

	 ListNode* deleteDuplicates(ListNode* head) {
		 if(nullptr == head) return head ;
		 vector<int > key ;
		 ListNode* cur(head), *post(cur->next);
		 while (post  && cur)
		 {
			 if(cur->val == post->val)
			 {
				 key.push_back(cur->val);
				 while (post && cur->val == post->val)
				 {
					 ListNode * tmp = post;
					 post=post->next;
					 cur->next=post;
					 free(tmp);
				 }

			 }
			 if(post == nullptr) break ;
			 cur = post;
			 post =post->next;
		 }

		 if(key.size() > 0)
		 {
		    ListNode * pre = new ListNode(0);
		    pre->next=head;
	    	cur = pre;
		   for(int i = 0 ; i <key.size() ; i ++)
		  {
			 while(cur->next  && cur->next->val != key[i] )
				 cur=cur->next;
			 ListNode * tmp = cur->next;
			 if (tmp ->next == nullptr)
			 {
				 cur->next = nullptr;
			 }
			 else
			 {
			    cur->next = tmp->next;
			 }
			 free(tmp);
		  }
		  head = pre->next;
		  free(pre);
		 }
		 return head;
    }

	  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		  if( (l1 == nullptr) && (l2 = nullptr)) return nullptr;
		  ListNode *p(l1),*q(l2),*l;
		  int carry(0),sum;
		  ListNode * head = (ListNode *)malloc(sizeof(ListNode));
		  l=head;
		  while (p && q)
		  {
				  l->next=(ListNode*)malloc(sizeof(ListNode));
				  l=l->next;
				  l->next = nullptr;
				  sum = carry+p->val+q->val;
				  l->val=sum%10;
				  carry=sum/10;
				  p=p->next;
				  q=q->next;
		  }
		     if(!q) q=p ;	    
			  while (q)
			  {
				  l->next=(ListNode *) malloc(sizeof(ListNode));
				  l=l->next;
				  l->next=nullptr;
				  sum = carry+q->val;
				  l->val=sum%10;
				  carry=sum/10;
				  q=q->next;
			  }
			  if(carry >0)
			  {
				  l->next=(ListNode *) malloc(sizeof(ListNode));
			      l=l->next;
				  l->val=carry;
				  l->next=nullptr;
			  }		  
		  return head->next;
    }

	  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		  if(headA == nullptr || headB == nullptr) return nullptr ;
           int length(0);
		   ListNode * pA(headA), *pB(headB);
		   while (pA)
		  {
			  pA = pA->next;
			  length++;
		  }
		   while (pB)
		   {
			   pB = pB->next;
			   length--;
		   }
		   if (pA != pB ) return nullptr;
		   pA = headA ;pB=headB;
		   if(length > 0)
			   for(int i = 0 ; i <length ; i++)
				   pA=pA->next;
		   else
		       for(int i = 0 ; i > length ; i--)
				   pB=pB->next;
		   while (pA !=pB)
		   {
			   pA=pA->next;
			   pB=pB->next;
		   }
		   return pA;
		    
    }
	  int lengthOfLastWord(string s) {
		  if(s.size() ==0) return 0;
		  int p, i =s.size()-1;
		  while (i >= 0 &&s[i]==' ')
		  {
			 i--;
		  }
		  p=0;
		  if(i  < 0 ) return 0 ;
		  while (i >= 0  && s[i--]!=' ')p++;		 
		  return p;
    }

	  vector<int> twoSum(vector<int>& nums, int target) {
       vector<int > result;
	   hash_map<int ,int > key;
	   hash_map<int,int >::iterator it;
	   int val ; 
	   for(int i = 0 ; i <nums.size() ; i ++)
		   key[nums[i]]=i;
		for ( int i = 0; i < nums.size() - 1; i++)
		{
			val= target - nums[i];
			it = key.find(val);
			if(it == key.end()  || it->second == i)  continue;
				result.push_back(int(i + 1));
				result.push_back(int(key[val] +1));
				return result;
		} 
    }
	  ListNode * createlist(vector<int > & nums)
	  {
		  if(nums.size() == 0 ) return nullptr;
		  ListNode * head   = new ListNode(nums[0]);
		  ListNode *p(head);
		  for(int i = 0 ; i < nums.size(); i ++)
			 { 
				 p->next=new ListNode(nums[i]);
		         p=p->next;
		      }
		  p->next=nullptr;
		  return head;
 
	  }

	  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		  double re(0);
		  if(nums1.size() == 0)
          return re;
    }
	   vector<int> preorderTraversal(TreeNode* root) {
		   TreeNode * p;
		   stack<TreeNode * >  s ;
		   vector<int > re ;
		   if(root == nullptr ) return re ;
		   s.push(root);
		   while(!s.empty())
		   {
			   p=s.top();
			   s.pop();
			   while (p)
			   { 
				re.push_back(p->val);
				if(p->right) s.push(p->right);
                p=p->left;			   
			   }			  
		   }
		   return re;
		 
    }
      vector<int> postorderTraversal(TreeNode* root) {
          /* 
		  
		  TreeNode * p;
		   stack<TreeNode * >  s ;
		   vector<int > re ;
		   if(root == nullptr ) return re ;
		   p=root ;
		   while (true)
		   {
            while(p)
		   {
		    s.push(p);
			if(p->right) s.push(p->right);
            p=p->left;			   
		    }
			if(s.empty()) break;
            p=s.top();
		    }
		   return re;
		   */

		  vector <int > re ;
		  postRecurse(root,re);
		  return re;
    }
	  void postRecurse(TreeNode *node,vector<int> &onePath)  
    {  
        if(node == nullptr) return;  
        postRecurse(node->left, onePath);  
        postRecurse(node->right, onePath);  
        onePath.push_back(node->val);  
    }  
};
  class MinStack {
private:
	  vector<int > stack;
	  set<int > min;
	  map<int,int> count;
public:
    void push(int x) {
		stack.push_back(int(x));
		min.insert(int(x));
		count[(int)x]++;
		
    }


    int top() {
		if(stack.size()>0) return stack[stack.size()-1];
    }

    int getMin() {
		set<int >::iterator it;
		it=min.begin();
		if(it!= min.end())
			return *it;
    }
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
    }
	 ListNode* insertionSortList(ListNode* head) {
		 if(head == nullptr)  return head ;
		 ListNode *p,*q, *re=new ListNode(0);
		 re->next = head;
		 p=head->next;
		 head->next =nullptr;
		 while (p)
		 {
			 q =re;
			 while(q->next && p->val >= q->next->val) q=q->next;
			 if(q == p)
			 {
				 p=p->next;
				 continue;
			 }
			 if(q->next  == nullptr) 
				{
					q->next=p;
					p=p->next;
					q->next->next=nullptr;
			    }
			 else
			  {
			  ListNode * tmp =p;
		    	p=p->next;
			    tmp->next=q->next;
		    	q->next=tmp ; 
			 }
		 }
		 return re->next;
    }

	 vector<vector<int>> generate(int numRows) {
     vector <vector <int>>re;
	 for(int i = 1 ; i <=numRows ; i ++)
	 {
		 vector<int> row;
		 row.push_back((int)1);
		 vector<vector<int>>::iterator it = re.begin();
		 int count(i-1);
		 while(it !=re.end() && --count) it++;
		 for(int j = 0 ; j <i-2 ; j ++)
		 {
			 row.push_back((*it)[j] + (*it)[j+1]);
		 }
		 if(i >1)
		 row.push_back(int(1));
		 re.push_back(row);
	 } 
	 return re;
    }

   vector<int> getRow(int rowIndex) {
	   ++rowIndex;
       vector <int >re;
	   for(int i = 1 ; i <= rowIndex ; i ++)
	   { 
		   vector<int > tmp(re);
		   re.clear();
		   re.push_back(int(1));
		   for(int j = 1 ;j <=i-2 ; j++)
		   {
			   re.push_back(tmp[j-1]+tmp[j]);
		   }
		   if(i >1)
			re.push_back(int(1));
	   }
	 return re;
    }

   void reorderList(ListNode* head) {
	   vector<ListNode *> key ;
	   if(head == nullptr || head->next == nullptr ) return ;
	   ListNode * p = head;
	   while(p)
	   {
		   key.push_back(p);
		   p=p->next;
	   }
	   
	   for(int i = 0 ; i <key.size(); i ++)
	   {
		   int t= key.size() - i-1;
		   if(t == i)
		   {
			   key[i]->next=nullptr;
		   }
		   else
		   {
			   key[i]->next=key[t];
			   key[t]->next=key[i+1];
		   }

	   }
	   head=key[0];

    }
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	   if(nums1.size() == 0 && nums2.size() == 0)   return NULL;
	   if(nums1.size() == 0)
		   if(nums2.size() %2 == 0)
			   return ((double)nums2[nums2.size()/2] + (double)nums2[(nums2.size()+1)/2]) /2;
		   else
			   return (double)nums2[nums2.size()/2];
	   if(nums2.size() == 0)
		   if(nums1.size() %2 == 0 )
			   return((double)nums1[nums1.size()/2] + (double)nums1[(nums1.size()+1)/2]) /2;
		   else
			   return (double)nums1[nums1.size()/2];

	   int num1start(0),num2start(0),num1end(nums1.size()-1),num2end(nums2.size()-1);
	   while (num2end - num2start >1  || num1end - num1start >1 )
	   {
		   double median1(0),median2(0);
		   if((num2end -num2start +1) %2 == 0 )
			   median2 =( (double)nums2[(num2end -num2start)/2+num2start ] +(double)nums2[(num2end -num2start)/2+num2start +1 ]) / 2  ;
		   else
			   median2 = nums2[((num2end -num2start )/2+num2start)] ;

		   if((num1end-num1start +1) %2 == 0)
			   median1 =((double) nums1[(num1end -num1start)/2+num1start ] +(double)nums1[(num1end -num1start)/2+num1start +1 ]) / 2 ;
		   else
			   median1 = nums1[((num1end -num1start )/2+num1start)] ;

		   if(median1 == median2) return median1;
		   else
		   {
			   if( median1 > median2)
			   {				 				   
				   num2start = (num2end - num2start) /2 + num2start;
				   num1end = (num1end - num1start) /2 + num1start;
			   }
			   else
			   {
				   num2end = (num2end - num2start) /2 + num2start;
				   num1start = (num1end - num1start) /2 + num1start;
			   }     
		   }		   
	   }


    }
   string addBinary(string a, string b) {

	   if(a.length() < 1 && b.length() < 1 ) return NULL;
	   if( a .length() <1)  return b;
	   if( b.length() <1) return a;

	   size_t len = a.length() <b.length() ? a.length() :b.length();
	   string re; 

	   int carry(0),current(0);

	   for(int i = 1; i <=len ; i ++)
	   {		
		  int bita = a[a.length()-i]-48;
		  int bitb = b[b.length()-i]-48;
		  current=(bita+bitb+carry)%2;
		  carry=(bita +bitb+carry) >=2 ?1:0;		  
		  char tmp=current+48;
		  re=tmp+re;
	   }
	   string c=b;
	   if(a.length() > b.length()) c=a;
	   for(int i = c.length()-len-1; i >= 0 ; i--)
	   {
		   int bita =c[i]-48;
		   current=(bita +carry)%2;
		   carry=(bita+carry) >=2? 1:0 ;
		   char tmp = current + 48;
		   re=tmp+re;
	   }
	   if(carry >0) re='1'+re;
	   return re;
    }

   bool isBalanced(TreeNode* root) {
	   if(root == nullptr) return true;
	   if(!isBalanced(root->left) || !isBalanced(root->left)) return false;
	   int leftheight=height(root->left);
	   int rightheight=height(root->right);
	   if(  abs(leftheight - rightheight) <=1) return true;
	   return false;
    }
   int height(TreeNode* root)
   {
	   if(root == nullptr) return 0;
	   if(root->left == nullptr && root->right ==nullptr) return 1;
	   int subheight = height(root->left) <height(root->right) ? height(root->right):height(root->left);
	   return subheight+1;
   }
   int maxProfit(vector<int>& prices) {
	   if(prices.size() ==0) return 0;
	   int buy(0),sell(prices.size()-1);
	   while(buy < sell)
	   {
		  int iter =buy+1;
		  while(prices[buy]<prices[iter++]  );
		  atoi("53");
		  
	   }
	   
         
	   
        
    }

   bool wordBreak(string s, set<string>& wordDict) {
	   if(s.size() <1 ) return false;
	   int start = 0 ; 
	   while(true)
	   { 
		   for( int len = 1 ; len <=s.length()-start ; len++)
		   {
			   string word =s.substr(start,len);
		       set<string>::iterator it=wordDict.find(word);
			   if(it !=wordDict.end())
			   {
				   start=start+len;
				   if(start == s.length()) return true;
				   break;
			   }
			   if(len == s.length()-start) return false;
		   }		   
	    }			   
    }
   int removeElement(vector<int>& nums, int val) {
	   if(nums.size() == 0) return 0;
	   vector<int> new_nums;
	   for(int i = 0 ; i <nums.size() ; i ++)
		   if(nums[i] != val) new_nums.push_back(nums[i]);
	   nums=new_nums;
	   return nums.size();
    }
   ListNode* removeNthFromEnd(ListNode* head, int n) {
	   if(head == nullptr) return nullptr ;
	   int len(0);
	   ListNode * p(head);
		while (p)
		{
		  len++;
		  p=p->next;
			   
	    }
		
		if(n==len)
	    {
	     ListNode *tmp = head;
	     head=head->next;
	     free(tmp);
	     return head;
	    }

	   int delposition =len-n;	  
	   p=head;
	   for(int i = 1; i <delposition ;i ++) p=p->next;

	   ListNode *tmp = p->next;
	   p->next=tmp->next;
	   free(tmp);
	   return head;
    }
   int climbStairs(int n) {
	   if(n==1) return 1;
	   if(n==2) return 2;
	   vector<int> count;
	   count.push_back(1);
	   count.push_back(2);
	   for(int i =3; i <=n ;i ++)
		   count.push_back(count[i-2]+count[i-3]);
	   return count[n-1];
    }
   int minDistance(string word1, string word2) {
	   if(word1.size() ==0 && word2.size() == 0) return 0;
	   if(word1.size() == 0) return word2.size();
	   if(word2.size() == 0 ) return word1.size();
	   vector<int> cu;
	   vector<int> pr;
	   for(int i = 0 ; i <=word2.size(); i++) 
		  { 
			  pr.push_back(i);
	          cu.push_back(i);
	       }
	   for(int i = 1 ; i <=word1.size(); i++)
	   {
		   cu[0]=i;
		   for(int j = 1 ; j <=word2.size() ; j ++)
		   {
			   if(word1[i-1] == word2[j-1])
				 cu[j]=pr[j-1];
			   else
			   {
			     int min = cu[j-1]> pr[j]? pr[j]:cu[j-1];
				     min=min>pr[j-1]? pr[j-1]:min;
				 cu[j] =min+1;
			   }
		   }
		  pr=cu;
	   }
	   int len =cu[word2.size()];
	   return len;
    }
   bool containsDuplicate(vector<int>& nums) {	
     	 if(nums.size() < 2) return false;
    bool *a = new bool[INT_MAX];
	 bool *b = new bool[INT_MAX];
	 for(int i=0;i<INT_MAX;i++)
		 a[i]=b[i]=false;
	 for(int i = 0 ; i <nums.size() ; ++i)
	 {	if (nums[i] >= 0) 
		{
			if (a[nums[i]]==true) return true;
			a[nums[i]] = true;
		}
		else
		{	if (b[-nums[i]==true]) return true;
			b[-nums[i]] = true;
		}
	 }
	 return false;
   }

    

   int myAtoi(string str) {
	   if(str.size() == 0 ) return 0;
	   int re(0),cur(0), flag=1;
	   while (cur <str.size() && str[cur] == ' ' )cur++;
	   flag = str[cur] == '-' ? -1:1;
	   if(str[cur] == '-' || str[cur] == '+') cur++;
	   while(cur <str.size() && str[cur] >='0' && str[cur] <='9')
	   {
		   int digit = str[cur] - '0';
		   if (INT_MAX /10 >= re)
			   re *=10;
		   else
			   return flag == -1 ? INT_MIN:INT_MAX;

		   if(INT_MAX -digit >= re)
			   re +=digit;
		   else
			   return flag == -1? INT_MIN :INT_MAX;
		   cur++;
	   }
	   return flag*re;

    }
    int numDecodings(string s) {
		if(s.size() == 0 ) return 0;
		if(s[0] == '0' ) return 0;
		return nuDecodingsSize(s,0);
    }
	int  nuDecodingsSize(string s,int i){
		if((s.size() -i) < 2) return 1;	
		if(s[i] == '1' ||s[i+1] == '0') 
			return nuDecodingsSize(s,i+2);
		if(s[i] == '0') return 0;
	    if((s[i] == '1') ||( s[i] = '2'  && s[i+1] <= '6')) 
		{
			int len1=nuDecodingsSize(s,i+2);
		    int len2 = nuDecodingsSize(s,i+1);
			if( len1 == 0 || len2 ==0) return 0;
			return len1+len2;
		}			
		else
		{
			int len2 = nuDecodingsSize(s,i+1);
			if(len2 == 0) return 0;
			return nuDecodingsSize(s,i+1);
		}
	
	}
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(l1 == nullptr) return l2;
		if(l2 == nullptr) return l1;
		ListNode * p1(l1), *p2(l2);
		ListNode *head = new ListNode(0);
		ListNode *q = head;
		while (p1 && p2)
		{
			if(p1->val <= p2->val) 
			{
				q->next=p1;
				p1=p1->next;
			}
			else
			{
				q->next=p2;
				p2=p2->next;
			}
			q=q->next;
		}
		if(p1) 
		   q->next=p1;
		else
			q->next=p2;
		q=head->next;
		delete head;
		return q;
    }

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.size() == 0) return nullptr ;
		vector<ListNode *> pre(lists),cur;
		while(pre.size() >1 )
		{
		 for(int i = 0 ; i < pre.size() ;i+=2)
		 {
			ListNode * result (nullptr);
			if(i+1 < pre.size())
			 result = mergeTwoLists(pre[i],pre[i+1]);
			else
			 result=pre[i];
			cur.push_back(result);
		 }
		 pre=cur;
		 cur.clear();
		}
		return pre[0];
    }

	ListNode* swapPairs(ListNode* head) {
		if(head == nullptr) return nullptr;   
		ListNode * p(head), *tmp(head),*pre(nullptr);
		ListNode *re = new ListNode(0);
		re->next=head;
		p=re;
		while (p->next  && p->next->next)
		{
			pre=p;
			p=p->next;
			tmp=p->next;
			p->next=tmp->next;
			tmp->next=p;
			pre->next=tmp;
		}
		tmp=re->next;
		free(re);
		return tmp;
    }

/*
	ListNode* deleteDuplicates(ListNode* head) {

        if(head == nullptr) return head;
		ListNode *cur(head),*pre(head),*nex(head);
		ListNode *re = new ListNode(0);
		re->next = head;
		pre=re;
		cur=head;
		nex=cur->next;

		while(cur && nex)
		{
		  if(cur->val != nex->val)
	     	{
		      pre=cur;
	    	  cur=nex;
	    	  nex=cur->next;
	     	}
	     	else
	    	{
	    	 while(nex && cur->val == nex->val) 
	    	 {
		 	    ListNode *tmp = nex;
		     	nex=nex->next;
		    	free(tmp);
		      }		 
	         	ListNode *tmp =cur;
		        pre->next=nex;
		        cur=pre->next;
		    	nex=cur->next;
	            free(tmp);
	       	}
	    }
		ListNode * tmp = re->next;
		free(re);
		return tmp;
    }
*/


	 bool canJump(vector<int>& nums) {
		 if( nums.size() == 0 || nums.size() == 1) return true;
	size_t  currentsize(0),step(0);
	 while(true)
	 {
		 if(currentsize >= nums.size() || step== 0) return false;
		 step=nums[currentsize];
		 currentsize+=step;
		 if(currentsize == nums.size()-1) return true;
	 }
    }

	 void rotate(vector<int>& nums, int k) {
		 if(nums.size() > 1)
		 {   int tmp(0);
			 for(size_t i = 1 ; i <= k ; i ++)
			 {
				 tmp=nums[nums.size()-1];
				 nums.pop_back();
				 nums.insert(nums.begin(),1,tmp);
			 }
		 }
    }

	 ListNode* rotateRight(ListNode* head, int k) {
       size_t len(0);
	   if(head == nullptr || head->next == nullptr) return head;
	   ListNode *p(head);	  
	   while (p && p->next)
	   {
		   p=p->next;
		   len++;
	   }
	   p->next=head;
	   len=len-k%len;
	   p=head;
	   while (--len)p=p->next;
	   head=p->next;
	   p->next=nullptr;
	   return head;
    }

	ListNode* partition(ListNode* head, int x) {
		if(head  == nullptr || head->next == nullptr) return head ;
		ListNode * grater = new ListNode(0);
		ListNode * lesser = new ListNode(0);
		lesser->next = head;
		ListNode *p(lesser),*q(grater);
		while(p && p->next)
		{
			if(p->next->val >=x)
			{
				q->next=p->next;
				q=q->next;
				p->next=p->next->next;
				q->next=nullptr;
			}
			else
			p=p->next;
		}
		p->next=grater->next;
		head=lesser->next;
		delete(grater);
		delete(lesser);
		return head;
    }
	/*
	first divid the list into two sub list
	//sort two sub list
	//merge tow sub list
	*/
	ListNode* sortList(ListNode* head) {
		if(head ==nullptr || head ->next ==nullptr) return head;
		ListNode *p(head),*q(head),*tmp(head);
		while(p && q)
		{
			tmp=p;
			p=p->next;
			q=q->next;
			if(q)
			q=q->next;
			else
			break;
		}
		tmp->next=nullptr;
		head=sortList(head);
		p=sortList(p);
		head =mergeTwoLists(head,p);
		return head;
    }

	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if(head == nullptr) return head;		
		ListNode *new_head= new ListNode(0);
		new_head->next=head;
		ListNode *p(new_head);
		int len(n-m);
		while(--m) p=p->next;
		ListNode *q(p->next),*tmp(q);
		for(int i = 1 ; i <=len ; i++)
		{
			tmp=q->next;
			q->next=tmp->next;
			tmp->next=p->next;
			p->next=tmp;
		}
		head=new_head->next;
		delete(new_head);
		return head;
    }

	bool isPalindrome(int x) {
        if(x <0) return false;
		if(x <10) return true;
	    size_t len(0),tmp(x);
		while(tmp)
		{
			tmp/=10;
			len++;
		}		
    }

    int findKthLargest(vector<int>& nums, int k) {
		/*
		for(int i = 0 ; i <k ; i ++)
			for (int j = nums.size() -2 ; j>=i; j--)
			{
				if(nums[j] > nums[j+1]) continue;
				nums[j]+=nums[j+1];
				nums[j+1]=nums[j]-nums[j+1];
				nums[j]=nums[j]-nums[j+1];
			}
		return nums[k-1];
		*/

    }
   vector<int> singleNumber(vector<int>& nums) {
	   /*
	   map<int,int> key;
	   for(int i = 0 ; i <nums.size() ; i ++)
		   key[nums[i]]++;
	   for(int i = 0 ; i < nums.size() ; i ++)
		   if (1 == key[nums[i]]  )
			   return nums[i];
			   */
	   map<int,int> key;
	   for(int i = 0 ; i <nums.size() ; ++i)
		   key[nums[i]]++;
	   vector<int> result;
	   for(map<int,int>::iterator it= key.begin(); it!=key.end() ;++it)
		   if(it->second == 1)
			   result.push_back(it->first);
    }
   TreeNode * subtree(vector<int> & preorder, vector<int > & inorder, int left, int right)
   {
	       if(left > right ) return nullptr;
		   TreeNode * root = new TreeNode(preorder[left]);
		   if(left == right)
		     return root;

	       int i(0);
	       while(preorder[0] != inorder[i]) i++;
		   root->left= subtree(preorder, inorder, left+1,i -1);
		   root->right = subtree(preorder, inorder, i,inorder.size()-1);
		   return root;
   }
   TreeNode * Create(vector<int> & preorder, vector<int> & inorder)
   {
	   if(preorder.size() < 1 )
		   return nullptr ;

	    TreeNode  * root = new TreeNode(preorder[0]);
		int i(0);
		while(preorder[0] != inorder[i]) i++;
		root->left = subtree(preorder, inorder, 1,i -1);
		root->right = subtree(preorder, inorder, i,inorder.size()-1);
	    return root;
   }
   bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
			n = n&(n-1);
		if(0 == n) return true;
		return false;
    }
   void subtree(ListNode * head, TreeNode * root)
   {
	   if (head == nullptr ) return ;
	   if (head ->next == nullptr )
	   {
		   TreeNode *left = new TreeNode(head->val);
		   root = left;
		   return ;
	   }
	   ListNode *fast (head) , *slow(head) , * pre_slow(head);
	   while(fast)
		{
			if(fast->next == nullptr) break;
				fast=fast->next;
			pre_slow = slow;
			slow=slow->next;
			fast=fast->next;
		}
		root = new TreeNode(slow->val);
		pre_slow->next =nullptr;
		subtree(head , root->left);
		subtree(slow->next , root->right);
   }
     TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr ;
		if (head ->next == nullptr )
	    {
		   TreeNode *root = new TreeNode(head->val);
		   return root;
	   }
		ListNode * fast(head), *slow(head) ,*pre_slow(head);
		while(fast)
		{
			if(fast->next == nullptr) break;
				fast=fast->next;
			pre_slow = slow;
			slow=slow->next;
			fast=fast->next;
		}
		TreeNode * root = new TreeNode(slow->val);
		pre_slow->next =nullptr;
		root->left = sortedListToBST(head);
		root->right=sortedListToBST(slow->next);
		return root;

    }
	 bool isPalindrome(ListNode* head) {
		 if (head == nullptr ) return  true;
		 if (head ->next == nullptr) return true ;
		 ListNode *slow(head), *fast(head), *pre_slow(head);
		 while(fast)
		 {
			 if(fast->next == nullptr) break;
			   fast=fast->next;
			 pre_slow = slow;
			 slow=slow->next;
			 fast=fast->next ;
		 }
		 ListNode *p(pre_slow->next);
		 pre_slow->next =nullptr;
		 while (p)
		 {
			 ListNode * tmp(p);
			 p=p->next;
			 tmp->next=pre_slow->next;
			 pre_slow->next= tmp;
		 }
		 p=pre_slow->next;
		 pre_slow->next = nullptr;
		 bool result(true);
		 while(p && head)
		 {
			 if(p->val  != head->val)
			 {
				 result = false;
				 break;
			 }
			 p=p->next;
			 head = head->next;
		 }

		 p=pre_slow->next;
		 pre_slow->next =nullptr;
		 while (p)
		 {
			 ListNode * tmp(p);
			 p=p->next;
			 tmp->next=pre_slow->next;
			 pre_slow->next= tmp;
		 }

		 return result;
    }

	 int findMin(vector<int>& nums) {
	   if(0 == nums.size() ) return 0;
	   if(  1 == nums.size() ) return nums[0];
	   if( nums[0] < nums[nums.size() -1 ] ) return nums[0];
	   int left(0),right(nums.size()-1 );
	   while(right > left +1)
	   {
		   if ( nums[left] < nums[(left+right) /2 ])
		   {
				   left = (left+right )/ 2 ;
		   }
		   else
		   {
			   right = (left+right )/ 2 ;
		   }
	   }
	   return nums[right] > nums[left] ? nums[left] : nums[right]; 
    }

	 vector<vector<int>> subsets(vector<int>& nums) {
     vector<vector<int >> result;

	   sort(nums.begin(),nums.end());
	   for(int i = 0 ; i <(int) pow(2,nums.size()); i++)
	   {
		   vector<int > subset;
		   for(int j = 0 ; j <nums.size() ; j++)
		   {
			   unsigned int bit(1);
			   bit =bit<<j;
			   if(bit > i ) break;
			   if((bit & i))
				 subset.push_back(nums[j]);
		   }
		   result.push_back(subset);
	   }	 
	 return result;
    }

	 vector<int> plusOne(vector<int>& digits) {
		 if(digits.size() == 0)
		 {
			 vector<int > result(1,1);
			 return result;
		 }
		 unsigned int carry(1);
		 for(int i = digits.size()-1 ; i >=0 ; i --)
		 {
			 int bit = digits[i]+carry;
			 digits[i] = bit%10;
			 carry=bit/10;
		 }
		 vector<int > result;
		 if(carry > 0)
		 {
			 result.push_back(carry);
		 }
		 for(int i = 0 ; i <digits.size() ; i ++)
			 result.push_back(digits[i]);
		 return result;
    }

	 int maxSubArray(vector<int>& nums) {
		 /*
		 if(nums.size() == 1) return nums[0];
		 int middle = (nums.size()-1) /2;
		 
		 vector<int > leftsubarray,rightsubarray;
		 */
		 int sum(0),max_sum(0);
		 for(int i = 0 ; i <nums.size() ; i ++)
		 {
			 
            if(sum < 0) sum = 0;
			sum+=nums[i];
			if(sum >max_sum) max_sum = sum ;
		 }
		 return max_sum;
    }
	 int mySqrt(int x)
	 {
		 if(x > 0)
		 {
			 double pre((long long)x/2);
			 double cur=(pre + x/pre) /2; 
			 while(pre-cur > 0.00001  || pre-cur < -0.00001)
			 {
                pre=cur;
				cur=(pre+x/pre)/2;
			 }
			 return (int)cur;
		 }
		 return 0;
	 }

	 TreeNode* invertTree(TreeNode* root) {
        if (nullptr == root ) return nullptr;
		if ( nullptr == root->left && nullptr == root->right) return root;
		TreeNode * tmp(root->left);
		root->left = root->right;
		root->right = tmp;
		invertTree(root->left);
		invertTree(root->right);
		return root;

    }

	 vector<vector<int>> levelOrder(TreeNode* root) {
		 vector<vector<int>> result ;
		 if(nullptr == root) 
	     {
				 vector<int > tmp;
				 result.push_back(tmp);
				 return result;
		 }
		 deque<TreeNode * > key ;
		 key.push_back(root);
		 int currentnum(0), nextnum(1);
		 while(nextnum)
		 {
			 currentnum = nextnum;
			 nextnum = 0;
		    vector<int> level;
		     for(int i = 0 ; i <currentnum ; i ++)
		     {
			 
			  TreeNode * p = key.front();
			  key.pop_front();
			  level.push_back(p->val);

     			 if(p->left )
	    		 {
		   		    nextnum++;
			    	 key.push_back(p->left);
			       }
			      if(p->right) 
		          {
				    nextnum++;
				    key.push_back(p->right);
			       }
		       }
			 result.push_back(level);
		     }
		 return result ;
    }

	 int minDepth(TreeNode* root) {
		 if(nullptr == root) return 0 ;
		 deque<TreeNode * > key ;
		 int high(0);
		 key.push_back(root);
		 int currentnum(0), nextnum(1);
		 while(nextnum)
		 {
			 currentnum = nextnum;
			 nextnum = 0;
			 high++;
		     for(int i = 0 ; i <currentnum ; i ++)
		     {			 
			  TreeNode * p = key.front();
			  key.pop_front();
			  if(p->left == nullptr && p->right == nullptr ) return high ;

			   if(p ->left)
	    		{
		   		    nextnum++;
			    	key.push_back(p->left);
			     }

			    if(p->right) 
		        {
				   nextnum++;
				   key.push_back(p->right);
			    }

		       }
		    }
    }



	 int maxDepth(TreeNode* root) {
         if(nullptr == root) return 0 ;
		 deque<TreeNode * > key ;
		 int high(0);
		 key.push_back(root);
		 int currentnum(0), nextnum(1);
		 while(nextnum)
		 {
			 currentnum = nextnum;
			 nextnum = 0;
			 high++;
		     for(int i = 0 ; i <currentnum ; i ++)
		     {			 
			  TreeNode * p = key.front();
			  key.pop_front();
			   if(p ->left)
	    		{
		   		    nextnum++;
			    	key.push_back(p->left);
			     }

			    if(p->right) 
		        {
				   nextnum++;
				   key.push_back(p->right);
			    }

		       }
		    }
		 return high;
    }

	 vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result ;
		 if(nullptr == root) 
	     {
			return result;
		 }
		 deque<TreeNode * > key ;
		 key.push_back(root);
		 int currentnum(0), nextnum(1);
		 while(nextnum)
		 {
			 currentnum = nextnum;
			 nextnum = 0;
		    vector<int> level;
		     for(int i = 0 ; i <currentnum ; i ++)
		     {
			 
			  TreeNode * p = key.front();
			  key.pop_front();
			  level.push_back(p->val);

     			 if(p->left )
	    		 {
		   		    nextnum++;
			    	key.push_back(p->left);
			     }
			     if(p->right) 
		         {
				    nextnum++;
				    key.push_back(p->right);
			     }
		     }
		     result.push_back(level);
		  }
		
		 vector<vector<int >> re ;
		 for(int i = result.size()-1 ; i >= 0 ; i --)
			 re.push_back(result[i]);
    }

	 bool isValidBST(TreeNode* root) {
        TreeNode * p ;
		 std::stack<TreeNode *  > s;
		 vector<int >re;
		 if(nullptr == root) return true;
		 s.push(root);
		 bool left(true);
		 while(!s.empty())
		 {
			 p=s.top();
			 while(left && p->left ) 
			 {
				 p=p->left;
				 s.push(p);
			 }
			 p=s.top();
			 s.pop();
			 re.push_back(p->val);
			 if(p->right)
			 {
			   s.push(p->right);
			   left =true;
			 }
			 else
			 {
				 left = false;
			 }

		 }
		   for(int i = 0 ; i <re.size()-1 ; i++)
		   {
			   if(re[i]  >= re[i+1])
				   return false;
		   }
		   return true;
	 }

	 vector<int> inorderTraversal(TreeNode* root) {
		 TreeNode * p ;
		 std::stack<TreeNode *  > s;
		 vector<int >re;
		 if(nullptr == root) return re;
		 s.push(root);
		 bool left(true);
		 while(!s.empty())
		 {
			 p=s.top();
			 while(left && p->left ) 
			 {
				 p=p->left;
				 s.push(p);
			 }
			 p=s.top();
			 s.pop();
			 re.push_back(p->val);
			 if(p->right)
			 {
			   s.push(p->right);
			   left =true;
			 }
			 else
			 {
				 left = false;
			 }

		 }
		 return re;
    }


	 vector<int> rightSideView(TreeNode* root) {
		  vector<int > result ;
        if(nullptr == root) return  result;

		 deque<TreeNode * > key ;
		 key.push_back(root);
		 int currentnum(0), nextnum(1);
		 while(nextnum)
		 {
			 currentnum = nextnum;
			 nextnum = 0;
		    vector<int> level;
		     for(int i = 0 ; i <currentnum ; i ++)
		     {
			  
			  TreeNode * p = key.front();
			  key.pop_front();
			  if( currentnum -1 == i)
				  result.push_back(p->val);
     			 if(p->left )
	    		 {
		   		    nextnum++;
			    	key.push_back(p->left);
			     }
			     if(p->right) 
		         {
				    nextnum++;
				    key.push_back(p->right);
			     }
		     }
		   
		  }
		 return result;
    }

	 struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    };

	 void connect(TreeLinkNode *root) {
        if(nullptr == root) return  ;
		 deque<TreeLinkNode * > key ;
		 key.push_back(root);
		 int currentnum(0), nextnum(1);
		 while(nextnum)
		 {
			 currentnum = nextnum;
			 nextnum = 0;
			 vector<TreeLinkNode*> level;
		     for(int i = 0 ; i <currentnum ; i ++)
		     {			
			  TreeLinkNode * p = key.front();
			  level.push_back(p);
			  key.pop_front();
     			 if(p->left )
	    		 {
		   		    nextnum++;
			    	key.push_back(p->left);
			     }
			     if(p->right) 
		         {
				    nextnum++;
				    key.push_back(p->right);
			     }
		     }	
			 for(int i = 0 ; i  < level.size()-1 ;  i++)
				 level[i]->next =level[i+1];
			 level[level.size()-1]->next =nullptr ;
		  }
    }

	 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result ;
		 if(nullptr == root) 
	     {
			return result;
		 }
		 deque<TreeNode * > key ;
		 key.push_back(root);
		 bool zigzag(true);
		 int currentnum(0), nextnum(1);
		 while(nextnum)
		 {
			 currentnum = nextnum;
			 nextnum = 0;
		    vector<int> level;
		     for(int i = 0 ; i <currentnum ; i ++)
		     {
			 
			  TreeNode * p = key.front();
			  key.pop_front();
			  level.push_back(p->val);

     			 if(p->left )
	    		 {
		   		    nextnum++;
			    	key.push_back(p->left);
			     }
			     if(p->right) 
		         {
				    nextnum++;
				    key.push_back(p->right);
			     }
		     }
			 if(false == zigzag )
			 {
				 for(int i = 0 ; i < level.size() /2 ; i++)
				 {
					 int tmp =  level[i];
					 level[i] = level[level.size()-i-1];
					 level[level.size()-i-1] = tmp ;
				 }
			 }
		     result.push_back(level);
			 zigzag = !zigzag ;
		  }
		 return result ;
    }

/*
		 return inbuildTree(preorder,inorder,0,preorder.size() -1,0,preorder.size()-1 );
    }
	 	 TreeNode* inbuildTree(vector<int>& preorder, vector<int>& inorder , int leftpreorder, int rightpreorder,int leftinorder,int rightinorder) {		
		 if(leftpreorder >= preorder.size() || leftpreorder > rightpreorder) return nullptr ;
		 TreeNode * root = new TreeNode(preorder[leftpreorder]);
		 if ( leftpreorder == rightpreorder ) return root ;

		 int val = preorder[leftpreorder];
		 int i = leftinorder ;
		 while (val != inorder[i]) i++;
		 root->left = inbuildTree(preorder, inorder,leftpreorder+1, leftpreorder+i-leftinorder,leftinorder,i-1);
		 root->right = inbuildTree(preorder, inorder,leftpreorder+i-leftinorder+1,rightpreorder,i+1,rightinorder);
		 return root;
    }*/

		 TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         if( postorder.size () < 1  || inorder.size() < 1  ) return nullptr ;
		 TreeNode * root = new TreeNode(postorder[postorder.size()-1]);
		 if (postorder.size() == 1 ) return root ;

		 return inbuildTree(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
	 	 TreeNode* inbuildTree(vector<int>& inorder, vector<int>& postorder , int leftinorder, int rightinorder,int leftpostorder, int rightpostorder) {		
		 if(leftinorder >= inorder.size() || leftinorder > rightinorder) return nullptr ;
		 TreeNode * root = new TreeNode(postorder[rightpostorder]);
		 if ( leftpostorder == rightpostorder ) return root ;

		 int val = postorder[rightpostorder];
		 int i = rightinorder;
		 while (val != inorder[i]) i--;
		 root->left = inbuildTree(inorder, postorder,leftinorder, i-1,leftpostorder,leftpostorder+i-leftinorder-1);
		 root->right = inbuildTree(inorder, postorder,i+1,rightinorder,rightpostorder-1- (rightinorder-i-1),rightpostorder-1);
		 return root;
    }
	int countNodes(TreeNode* root) {
        if(nullptr == root) return 0; 
		if (root->left == nullptr && root->right  == nullptr ) return 1 ;
		int left(0), right(0);
		TreeNode * p(root);
		while(p)
		{
			++left;
			p=p->left;
		}
		p=root;
		while(p)
		{
			++right;
		    p=p->right;
		}
		if( left == right) return pow(2,left)-1;
		return countNodes(root->left)+countNodes(root->right) +1;
    }
	int addDigits(int num) {
      if(num < 10) return num ; 
	  int result(0);
	  while(num)
	  {
		  result+=num%10;
		  num/=10;          
	  }
	  if(result < 10) return result;
	  return addDigits(result);
    }
	vector<string> binaryTreePaths(TreeNode* root) {
		/*
		vector<string> result;
		if(nullptr == root) return result ;
		vector<int> path;
		std::stack<TreeNode * > s;
		TreeNode *p(root);
		while(true)
		{
		    while (p)
		   {
			path.push_back(p->val);
			s.push(p);
			p=p->left;
		    }
			p=s.top();
	     	if(p->right == nullptr)
		    {			
			string one_path; 
			char tmp[10];
			for(int i = 0 ; i < path.size()-1; i++)
			{   
			    sprintf(tmp,"%d",path[i]);
				string val(tmp);
				one_path=one_path+val+"->";
			 }
			sprintf(tmp,"%d",path[path.size()-1]);
			string val(tmp);
			one_path+=val;
			result.push_back(one_path);
			if(s.empty()) return result;			
			TreeNode * right = s.top();
			s.pop();
			if(s.empty()) return result;
			p=s.top();
			s.pop();
			path.pop_back();
			while (right == p->right  || p->right == nullptr)
			{				
				if(s.empty()) return result;
				path.pop_back();
				right = p;
				p=s.top();
				s.pop();
			}
			
			p=p->right;
			s.push(p);
		   }
		   else
		   {	
			p=p->right;
		   }		
		   }
		   */
	   vector<string> result;
	   string s;
	   path(root,result,s);
	   return result;
	}
     void  path(TreeNode * root , vector<string > & result, string  s)
	 {

		if( root == nullptr)  return ;
		char tmp[10];
		sprintf(tmp,"%d",root->val);
		string val(tmp);
		if(s.size())
		{
		s=s+"->";
		}
        s=s+val;
		if( root ->left == nullptr  && root->right == nullptr)
		{
			result.push_back(s);
			return ;
		}
		path(root->left,result,s);
		path(root->right,result,s);

	}

	 bool hasPathSum(TreeNode* root, int sum) {
		 if(root == nullptr) return false;
		 return value(root, sum, 0);
    }

	 bool value(TreeNode * root ,int sum ,int currentsum)
	 {
		 if(root == nullptr) return false;
		 if( root->left == nullptr  && root->right == nullptr && root->val + currentsum  == sum) return true;
		 bool left(false),right(false);
		 left = value(root->left,sum,currentsum+root->val);
		 right = value(root->right,sum,root->val+currentsum);
		 return left || right;
	}

	 vector<vector<int>> pathSum(TreeNode* root, int sum) {
         vector<vector<int>> result ;
		 if(root == nullptr) return result;
		 vector<int> oneresult;
		 Sum(root, result,oneresult ,sum,0);
		 return result;
     }
	 void Sum(TreeNode * root , vector<vector<int>>& result, vector<int > one,int sum, int currentsum)
	 {
		 if(root == nullptr) return ;
		 one.push_back(root->val);
		 if(root->left == nullptr && root->right== nullptr  && root->val+currentsum == sum)			 
			 result.push_back(one);
		 Sum(root->left,result,one,sum,currentsum+root->val);
		 Sum(root->right,result,one,sum,currentsum+root->val);
	 }
/*
	 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		 if( root == nullptr) return nullptr;
		 if(p  == nullptr && q == nullptr) return nullptr;
		 int min(p->val <= q->val ?  p->val :q->val),max(p->val > q->val ?  p->val : q->val);
		 TreeNode * it(root);
		 while(it)
		 {
			 if(it->val> max)
		     {
					 it=it->left;
					 continue;
			 }
			 if(it->val < min) 
			 {
				 it = it->right ;
				 continue;
			 }
			 return it;
		 }
		 return nullptr;
    }
*/
	 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
		if(p == nullptr && q == nullptr) return nullptr;
		vector<TreeNode *> ancesstors_p, ancesstors_q;
		ancesstors_p = getancesstor(root,p);
		ancesstors_q = getancesstor(root,q);
    }
	 vector<TreeNode *> & getancesstor(TreeNode * root, TreeNode * child)
	 {

	 }

	 int numTrees(int n) {
     if(n == 1) return 1;
     vector<int> key;
	 key.push_back(1);
	 key.push_back(1);
	 for(int i = 2; i <=n ; i ++)
	 {
		int sum(0);
	    for(int j = 0 ; j < i ; j++)
			sum+=key[i-j-1]*key[j];
		key.push_back(sum);
	 }
	 return key[n];
    }

	 int uniquePaths(int m, int n) {
		if(m == 1) return 1;
        vector<int > pre;
		for(int i = 1; i <=n ; i ++) pre.push_back(i);
		for(int i = 3 ; i <=m ;i++)
		{
			vector<int> cur;
			cur.push_back(1);
			for(int j = 1 ; j <n ; j++)
			{
				cur.push_back(pre[j]+cur[cur.size()-1]);
			}
			pre=cur;
		}
		return pre[pre.size()-1];
    }

	 int minimumTotal(vector<vector<int>>& triangle) {
		 if(triangle.size() == 1) return triangle[0][0];
		 vector<int > presum;
		 presum.push_back(triangle[0][0]);
		 for(int i = 1 ; i <triangle.size() ; i++)
		 {
			 vector<int > row = triangle[i];
			 vector <int> cursum;
			 cursum.push_back(presum[0]+row[0]);
			 for(int j = 1 ; j < row.size()-1 ; j ++)
			 {
			   int minsum=presum[j-1] > presum[j] ? presum[j] :presum[j-1];
			   cursum.push_back(minsum+row[j]);
			 }
			 cursum.push_back(row[row.size()-1] +presum[presum.size()-1]);
			 presum = cursum;
		 }
		 int minsum=presum[0];
		 for(int i = 1 ; i < presum.size() ; i ++)
			 if(minsum >presum[i])
				 minsum = presum[i];
		 return minsum;

    }
	 vector<int> productExceptSelf(vector<int>& nums) {
		 vector<int > result(nums.size(),1);
		 for(int i= 1 ; i <nums.size() ; i++)
			 result[i]= result[i-1] *nums[i-1];
		 int right(1);
		 for(int i =nums.size()-1 ; i >=0 ; i--)
		 {
			 result[i] *=right;
			 right*=nums[i];
		 }
		 return result;
    }

    void sortColors(vector<int>& nums) {
		std::map<int,int> key;
		for(int i = 0 ; i <nums.size() ; ++i)
			++key[nums[i]];
		for(int i = 0 ; i <key[0]; ++i)
			nums[i]=0;
		for(int i = 0; i <key[1]; ++i)
			nums[key[0]+i]=1;
		for(int i = 0 ; i <key[2]; ++i)
			nums[key[0]+key[1]+i] =2 ;
    }
  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
	vector<Interval> merge(vector<Interval>& intervals) {
        
    }

	string largestNumber(vector<int>& nums) {
		string result;
		if(nums.size() == 0) return result;
		result=to_string(nums[0]);
		for(int i = 1 ; i <nums.size() ; ++i)
		{
			string val =to_string(nums[i]);
		    result = compare(result,val)? result+val:val+result;
		}
	    return result;
		
    }
	bool compare(string a,string b)
	{
       string value1(a+b),value2(b+a);
	   for(int i = 0 ; i <value1.size() ; ++i)
	   {
		   if(value1[i] >value2[i]) return true;
		   if(value1[i] <value2[i]) return false;
	   }
	   return false;
	}
	// a >= b return true
	bool isValid(string s) {
		if(s.size() == 0) return true;
		std::stack<char> key;
		for(int i = 0 ; i <s.size() ; ++i)
		{
			char current_val = s[i];
			if( current_val == '('  || current_val == '['  || current_val == '{')
			{
				key.push(current_val);
				continue ;
			}
			char pre_val = key.top();
			if( pre_val == '('  && current_val == ')' )
			{
				key.pop();
				continue ;
			}
			if( pre_val == '['  && current_val == ']' )
			{
				key.pop();
				continue ;
			}
			if( pre_val == '{'  && current_val == '}' )
			{
				key.pop();
				continue ;
			}
			return false;
		}
		if(key.size()  == 0) return true;
		return false;
    }

	int trap(vector<int>& height) {
        int leftwall(0);
		std::stack <int > key;
		for(int i = 0 ; i <height.size() ; ++i)
		{
           int high = height[i];
		}
    }

	string simplifyPath(string path) {
        vector<string> key ;
		int i(0);
		while(i<path.size())
		{
			string dir;
			while(i < path.size()  && path[i] == '/') ++i;
			while (i < path.size() && path[i] != '/')
			{
				dir=dir+path[i];
				++i;
			}			
			if(dir.compare("..") == 0)
			{
				if(!key.empty())
				   key.pop_back();
				continue ;
			}
			if(dir == ".") continue ;
			if(dir.size())
			key.push_back(dir);
			if(i >= path.size()) break;		
		}
		string result("/");
		for(int i = 0 ; i < (int)key.size()-1 ; ++i)
		{
			result+=key[i];
			result+="/";
		}
		if(!key.empty())
		   result+=key[key.size()-1];
		return result;
	}

	int calculate(string s) {
      vector<char > oper;
	  vector<int> val;
	  int i(0);
	  while (true)
	  {
		  while(i< s.size() &&s[i] == ' ') ++i;
		  if( i < s.size() && (s[i] == '+'  || s[i] == '-' ||s[i] == '('  ) )
		  {
			  oper.push_back(s[i]);
			  ++i;
			  continue ;
		  }
		  int current_val(0),tmpi(i);
		  while(i < s.size() && s[i] <= '9'  && s[i] >= '0' )
		  {
			  current_val*=10;
			  current_val+=(s[i]-'0');
			  ++i;
		  }
		  if(tmpi != i ) 
		  {
			  val.push_back(current_val);
			  continue;
		  }
		  if( s[i] == ')' )
		  {
			      int j(oper.size()-1);
				  vector<int> tmp_val,tmp_oper;
				  while(j>=0 && oper[j] != '(') --j;
				  int opit(j+1);
				  int totaliter(val.size()-(oper.size()-j));
				  for(int iter((val.size()-(oper.size()-j)+1)); iter <(int)val.size(); ++iter)
				  {
                     if(oper[opit] == '+')
					 {
						 val[totaliter]+=val[iter];
						 ++opit;
						 continue;
						 
					 }
					 if(oper[opit] == '-')
					 {
						 val[totaliter]-=val[iter];
						 ++opit;
						 continue;						 
					 }
				    }
				  for(int iter = j;  iter< opit ;++iter)
					  oper.pop_back();
				  for(int iter = j; iter<opit-1 ; ++iter)
					  val.pop_back();
				  ++i;
				  continue;
		    }
		    if(i >=s.size())break;
	  }
	    if(val.size() == 1 ) return val[0];
	    for(int j = 0 ; j<oper.size() ; ++j)
			  {
				  if(oper[j] == '+')
				  {
					  val[0]+=val[j+1];
					  continue;
				  }
				  if(oper[j] == '-')
				  {
					  val[0]-=val[j+1];
					  continue;
				  }
			   }
		return val[0];
    }

	int evalRPN(vector<string>& tokens) {
        vector<int> result;
		for(int i = 0 ; i <tokens.size() ; ++i)
		{
			string current(tokens[i]);
			if(current == "+")
			{
				result[result.size()-2]+=result[result.size()-1];
				result.pop_back();
				continue;
			}
			if( current =="-")
			{
				result[result.size()-2]-=result[result.size()-1];
				result.pop_back();
				continue;
			}
			if(current == "*")
			{
                result[result.size()-2]*=result[result.size()-1];
				result.pop_back();
				continue;
			}
			if(current == "/")
			{
				result[result.size()-2]/=result[result.size()-1];
				result.pop_back();
				continue;
			}
			if(current.empty()) continue;
			int val =atoi(current.c_str());
			result.push_back(val);
		}
		return result[0];
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
		if(k <= 1) return head;
		ListNode * newhead = new ListNode(0);
		newhead->next=head ;
		ListNode * p(newhead);
		ListNode *pre(p), *cur(pre->next) ;
		while(cur)
		{		
			
			ListNode * check(cur);
			for(int i = 1 ; i <k ; i ++)
				if(check)check=check->next;
			if(!check) break;
			for(int i = 1 ; i <k ; i ++)
			{
				ListNode * nex(cur->next);
				if(!nex) break;
				cur->next=nex->next;
				nex->next=pre->next;
				pre->next=nex;
			}
			for(int i =0;  i <k ; i++)
				if(pre->next)
			    	pre=pre->next;
			cur=pre->next;
		}

		ListNode * result = newhead->next;
		free(newhead);
		return result;
    }

	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.size() <1 ) return 0;
		int m(obstacleGrid.size()) ,n(obstacleGrid[0].size());
		if(n == 0) return 0;
        vector<int > pre;
		int i(0);
		while(i <n &&obstacleGrid[0][i] == 0 ) ++i;
		if(i >=n)
		{
		 for(int j = 0 ; j < n ; ++j)
			 pre.push_back(1);
		}
		else
		{
		 for(int j = 0 ; j<i ;  ++ j )
			pre.push_back(1);
		 for(int j = i ; j <n; ++j)
			pre.push_back(0);
		}
		i=0;
		
	     while(i< m &&obstacleGrid[i][0] ==0)++i;
		
		for(int iter = 1 ; iter <m ;++iter)
		{
			vector<int> cur;
			if(i >=m) cur.push_back(1);
			else
			{
			   if(iter <i )
				   cur.push_back(1);
			   else
				   cur.push_back(0);
			}
			for(int j = 1 ; j <n ; ++j)
			{
				if(obstacleGrid[iter][j])
				 cur.push_back(0);
				else
				 cur.push_back(pre[j]+cur[cur.size()-1]);
			}
			pre=cur;
		}
		return pre[pre.size()-1];  
    }

	void reverseWords(string &s) {
        string result;
		
		int i(s.size()-1);
		while(i >= 0)
		{
			string word;
			while(i >=0 && s[i] ==' ') --i;
			if(i == 0 && s[i] == ' ') break;
			while(i >=0 &&s[i] !=' ') 
			{
				word=s[i]+word;
				--i;
			}
			if(word.size() == 0) break;
			if(result.empty()) 
			   result=word;
			else
			{
				result+=' ';
				result+=word;
			}
		}
		s=result;
		return ;
    }

	int compareVersion(string version1, string version2) {
		unsigned int it_version1(0),it_version2(0);
		while(it_version1 <version1.size() && version1[it_version1] == ' ')++it_version1;
		while(it_version2 <version2.size() && version2[it_version2] == ' ')++it_version2;
		int mainversion1(0),mainversion2(0);
		while(it_version1<version1.size() && version1[it_version1] != '.')
		{
			mainversion1*=10;
			mainversion1+=(version1[it_version1]-'0');
			++it_version1;
		}
		while(it_version2<version2.size() && version2[it_version2] != '.')
		{
			mainversion2*=10;
			mainversion2+=(version2[it_version2]-'0');
			++it_version2;
		}
		if(mainversion1 >mainversion2 ) return 1;
		if(mainversion1 <mainversion2)  return -1;
		++it_version2;
		++it_version1;
		mainversion1=0;
		mainversion2=0;
		int bita(0),bitb(0);
		while(it_version1<version1.size() && version1[it_version1] != ' ')
		{
			mainversion1*=10;
			mainversion1+=(version1[it_version1]-'0');
			++it_version1;
		}
		while(it_version2<version2.size() && version2[it_version2] != ' ')
		{
			mainversion2*=10;
			mainversion2+=(version2[it_version2]-'0');
			++it_version2;
		}
		if(mainversion1 >mainversion2) return 1;
		if(mainversion1 <mainversion2) return -1;
		return 0;
    }
	bool exist(vector<string>& board, string word) {
		if(word.size() == 0) return true;
		if(board.size() == 0) return false;
		int m(board.size()), n(board[0].size());
		if(n == 0 ) return false;
		int iter(0);
		while (iter < n*m)
		{
			int pos(iter);
			if(board[pos/n][pos%n] != word[0])
			{
				++iter;
				continue;
			}
			++pos;
			for(int i = 1 ; i<word.size();++i)
			{
			    
				if(word[i] == board[(pos+1)/n][(pos+1)%n])
				{
					++pos;
					continue;
				}
				if(word[i] == board[(pos+n)/n][(pos)%n])
				{
					pos+=n;
					continue;
				}
				break;			    
			}
			if(word[word.size()] == board[(pos)/n][(pos)%n]) return true;
			++iter;
			
		}
		return false;

    }
	bool isUgly(int num) {
		if(num<1) return false;
        while(num>1)
		{
			if(num %2 ==0)
			{
				num=num>>1;
				continue;
			}
			if(num %3 ==0)
			{
				num/=3;
				continue;
			}
			if(num %5 ==0)
			{
				num/=5;
				continue;
			}
			return false;
		}
		return true;
    }

	int missingNumber(vector<int>& nums) {
		if(nums.size() <=0) return 0;
		int sum(0);
		for(auto i :nums)
			sum+=i;
		return (nums.size()+1)*nums.size()/2 - sum;
    }



	 TreeNode* sortedArrayToBST(vector<int>& nums) {
		 TreeNode * root =sortedArrayToBst(nums,0,nums.size()-1);
		 return root;

    }
	 TreeNode * sortedArrayToBst(vector<int>& nums, int left,int right)
	 {
		 if(left > right) return nullptr;
		 if(left == right) 
		 {
			 TreeNode * root = new TreeNode(nums[left]);
			 return root;
		 }
		 int mid=(left +right)/2;
		 TreeNode * root = new TreeNode(nums[mid]);
		 root->left=sortedArrayToBst(nums,left,mid-1);
		 root->right = sortedArrayToBst(nums,mid+1,right);
		 return root;
	 }
	 string countAndSay(int n) {
		 string result;
         if(n <= 0) return result;
		 string tmp("1");
		 int i(1);
		 while(i++ < n)
		 {
			result="";
			int count(1);
			char key(tmp[0]);
			for(int j = 1 ; j<tmp.size() ; j++)
			{
              if(key == tmp[j])
			  {
				  ++count;
			  }
			  else
			  {
				  char t[64];
				  sprintf(t,"%d",count);
				  string s(t);
				  result+=s;
			      result+=key;
				  key=tmp[j];
				  count=1;
			  }
			}
			 char t[64];
			 sprintf(t,"%d",count);
			 string s(t);
			 result+=s;
			 result+=key;
			 tmp=result;
		 }
		 result=tmp;
		 return result;
    }

	 bool isPalindrome(string s) {
		 if(s.empty()) return true;
		 int left(0),right(s.size()-1);
		 while(left < right)
		 {
            while(left < s.size() && (!isalpha(s[left]) &&( s[left] <'0'|| s[left] >'9' ))) ++left;
			while(right >= 0 &&( !isalpha(s[right])  && (s[right] < '0' || s[right] > '9'))) --right;
			if(left >= right) break ;
			if(s[left] == s[right] || 32 == abs(s[left]-s[right]))
			{
				++left;
				--right;
				continue ;
			}
			return false;
		 }
		 return true;
    }

	 string multiply(string num1, string num2) {
		 string result("0");
    }
	 bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	  if (numCourses <= 0  || prerequisites.empty() ) return true;
	  vector<int> indegree(numCourses,0);
	  map<int,vector<int>> outdegree;
	  for( auto it : prerequisites)
	  {
			++indegree[it.first];
			outdegree[it.second].push_back(it.first);
	  }
	  set<int> max;
	  vector<int> tmp;
	  for(int i = 0 ; i<numCourses ;++i)
		  max.insert(i);
	  while(true)
	  {
		  tmp.clear();
	      for(auto it :max)
		  {
			  if(0 == indegree[it])
				  tmp.push_back(it);
		  }

		  if(tmp.empty() && !max.empty()) 
			  return false;
		  for (auto it :tmp)
			  max.erase(it);
		  if(max.empty())
			  return true;
		  for (auto i:tmp)
			  for(auto it :outdegree[i])
				  --indegree[it];
	  }		 
    }

	 vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
	   vector<int> result ;
	  if (numCourses <= 0  || prerequisites.empty() ) return result;
	  vector<int> indegree(numCourses,0);
	  map<int,vector<int>> outdegree;
	  for( auto it : prerequisites)
	  {
			++indegree[it.first];
			outdegree[it.second].push_back(it.first);
	  }
	  set<int> max;
	  vector<int> tmp;
	  for(int i = 0 ; i<numCourses ;++i)
		  max.insert(i);
	  while(true)
	  {
		  tmp.clear();
	      for(auto it :max)
			  if(0 == indegree[it])
			  {
				  tmp.push_back(it);
				  result.push_back(it);
			  }			     
		  if(tmp.empty() && !max.empty()) 
		  {
			  result.clear();
			  return result;
		  }
		  for (auto it :tmp)
			  max.erase(it);
		  if(max.empty())
			  return result;
		  for (auto i:tmp)
			  for(auto it :outdegree[i])
				  --indegree[it];
	  }		 
    }

    vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode *> result;
		 return result;
		
    }
	 bool containsNearbyDuplicate(vector<int>& nums, int k) {
		 if(nums.size() <= 0  ||  k <= 0 ) return false;
		 map<int ,vector<int>> val ;
		 for(int i = 0 ; i <nums.size() ; ++i)
		 {
			 val[nums[i]].push_back(i);			
			 if( val[nums[i]].size() <=1 )continue;
			 if(val[nums[i]][val[nums[i]].size()-1] - val[nums[i]][val[nums[i]].size()-2] <=k) 
				 return true;			
		 }
		 return false;   
    }
};
class Stack {
private:
	 std::deque<int > pri_queue;
	 std::deque<int>  ass_queue;
public:
    // Push element x onto stack.
    void push(int x) {
		pri_queue.push_back(x);
    }

    // Removes the element on top of the stack.
    void pop() {
		if( !empty())
		{
			while(1 != pri_queue.size())
			{
				int val =pri_queue.front();
				ass_queue.push_back(val);
				pri_queue.pop_front();
			}
			pri_queue.pop_front();
			while(!ass_queue.empty())
			{
				int val = ass_queue.front();
				pri_queue.push_back(val);
				ass_queue.pop_front();					
			}
			
		}
    }

    // Get the top element.
    int top() {
       if( !empty())
		{
		    int result ;
			while(!pri_queue.empty())
			{
				result =pri_queue.front();
				ass_queue.push_back(result);
				pri_queue.pop_front();
			}
			while(!ass_queue.empty())
			{
				int val = ass_queue.front();
				pri_queue.push_back(val);
				ass_queue.pop_front();					
			}
			return result;			
		}
    }

    // Return whether the stack is empty.
    bool empty() {
		return pri_queue.empty();    
    }
};

class A  
{  
public:  
    A():i(0)  
    {  
       cout <<"zheshi a de gouzao hanshu"<<endl;  //here:在构造函数中调用了虚函数  
    }  
    ~A()  
    {  
    }  
    void fun1()  
       {  
           i *= 10;  
           fun2();  
       }  
    int getValue(){  
        return i;  
    }  
protected:  
    virtual void fun2()  
    {  
        i++;  
    }  
private:  
    int i;  
};  
  
class B 
{  
public:  
    B() 
    {
		cout << "zhe shi b de gouzaohanshu"<<endl;
    }  
    virtual ~B()  
    {  
    }  
    void fun1()  
      {  
          i *= 100;  
          fun2();  
      }  
protected:  
    void fun2()  
    {  
        i += 2;  
    }  
private:  
    int i;  
};  
class test :public  A ,B{
public:
	test(){};
	~test(){
		cout<<"xigou"<<endl;
	};
	test(const test & a )
	{
		cout << "zheshi kaobeigouzaohanshu" <<endl;
	}
	test & operator=(const test & a)
	{
		cout <<"zheshi fuzhi gouzaohanshu"<<endl;
	}

};

test t(test q)
{
	test v(q);
	v.~test();
	test w=q;
	return w;
}
class LRUCache{
	hash_map<int , int > Cache;
	deque<int> User;
	int size;
public:
    LRUCache(int capacity):size(capacity) {
    }
    
    int get(int key) {
		if(Cache[key] != 0) 
			return -1;
		else
			return Cache[key];
    }
    
    void set(int key, int value) {
		if( Cache.size() < size)
		{
			Cache[key]=value;
		}
		else
		{
            
		}
    }
};
class  Mystring{
	char *s_star;
	size_t len;
	size_t capality;
public:
	Mystring():s_star(nullptr),len(0),capality(0){};
	~Mystring()
	{
		if(this->s_star)delete [] this->s_star;
	}

	Mystring(size_t capality):len(0),capality(capality)
	{
		s_star = new char[capality];
	}
	Mystring(char c, size_t cs):
		len(cs),capality(cs)
	{
		s_star = new char[cs];
		memset(s_star,c,sizeof(capality));
	}
	Mystring(const Mystring& rval)
	{
		Mystring(rval.capality);
		memcpy(this->s_star,rval.s_star,rval.len);
		this->len=rval.len;
	}
	Mystring & operator = (const Mystring & rval)
	{
	   if(this != &(rval))
	   {
		   if(this->s_star != nullptr)
			   delete [] s_star;
		   s_star = new char[rval.capality];
		   strcpy(s_star,rval.s_star);
	   }
	   return *this;
	}
	size_t size()const{return len;};

	size_t length()const{return len;};
	size_t push_back(char s)
	{
		if(len = capality -1)
			resize(size() +size());
		this->s_star[len] = s;
		++len;

	}
	size_t pop_back()
	{
		if(len > 0 ) 
		{
			--len;
			return 1;
		}
		return -1;

	}
	Mystring & operator+(Mystring & rval)
	{
		if(0 == this->size())  return rval;
		if(0 == rval.size())  return * this;
		char * tmp = new char[rval.size() +this->capality];
		strcpy(tmp,this->s_star);
		strcpy(tmp+this->len,rval.s_star);
		delete [] this->s_star;
		this->s_star = tmp;
		this->len+=rval.len;
		return *this;
	}
	void clear(){len = 0;}
	size_t cab(){return this->capality;};
private:
	void resize(size_t s)
	{
		if(s < this->size()) throw ;
		char * tmp = new char[s];
		if(this->s_star)
		{
		  strcpy(tmp,this->s_star);
		  delete [] this->s_star;
		}
		this->s_star = tmp;
		
	}
	vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result ;
		if( s.size() < 10) return result;
		vector<vector<int>> next;
		for(unsigned int  i= 0 ; i < s.length()-10; ++i)
		{ 
			vector<int> pnext(10);
			pnext.push_back(-1);
			int j(-1),k(0);
			while(k < 10);
			{
				if( j == -1 || s[j] == s[k] )
				{
					++k;
					++j;
					pnext[k] = j;
				}
				else
				{
					j=pnext[j];
				}
			}
			next.push_back(pnext);

		}
    }

	public:
    int  count(int &lval , int & rval, char & ch)
	{
		switch (ch)
		{
			 case '+':
				return lval+rval;
				break;
		  case '-':
				 return lval-rval;
				 break;
		  default:
				 return lval*rval;
				 break;
		}
	}
	/*
	vector<int> diffWaysToCompute(string input) {	
      vector<int> result;
	  int count(0);	  
	  for( auto it : input)
		  if( it  == '+' || it == '-' || it == '*')
			  ++count;
	  if(count == 0)
	  {	   
		result.push_back(stoi(input.c_str()));
		return result;		
	  }
	  if( count == 1)
	  {
		  int i(0);
		  for( i = 0 ; i < input.size() ; ++i)
			  if( input[i]  == '+' || input[i] == '-' || input[i] == '*')
				  break;
		  int ilval = stoi(input.substr(0,i).c_str());
		  int irval = stoi(input.substr(i+1 ,input.size()).c_str());
		  result.push_back(this->count(ilval , irval, input[i]));
		  return result;

	  }
	  for( int i = 0 ; i < input.size() ; ++i )
	  {
		  if(input[i] == '+' || input[i] == '-' || input[i] == '*')
		   {
			   string lval = input.substr(0,i);
			   vector<int> left = diffWaysToCompute(lval);
			   string rval = input.substr(i+1 , input.size());
			   vector<int> right = diffWaysToCompute(rval);
              for(auto  leftval :left )
				  for(auto rightval : right)
					  result.push_back(this->count(leftval , rightval, input[i]));		   
		   }
	  }            
	  return result;
    }
	*/
	vector<int> calculate(vector <int> & nums, vector<char> & op , size_t left, size_t right, size_t l, size_t r)
	{
		vector<int> result ;
		if( l < r ) return result;
		if( left == right ) result.push_back(nums[left]);
		return result;
	}
	vector<int> diffWaysToCompute(string input) {
		vector <int > result , nums;
		vector <char> op;
		int num(0);
		for(auto it :input)
		{
			if(it == '+'  || it =='-' || it == '*')
			{
				nums.push_back(num);
				num = 0 ;
				op.push_back(it);
				continue ;
			}
			if(it <= '9'  && it >= '0')
			{
				num*=10;
				num+=(it - '0');
				continue ;
			}
		}
		if( op.size() == 0 )
		{
			if(nums.size() == 0) return result;
			if(nums.size() == 1) return nums;
		}
		if( op.size() == 1 )
		{
			result.push_back(count(nums[0] , nums[1] , op[0]));
			return result;
		}
		for( int i = 0 ; i < op.size() ; ++i)
		{
           
		}
	    

	}
	int findDuplicate(vector<int>& nums) {
	   unsigned int sum(0);
        for(auto it : nums)
           sum += it ;
		for(int i = 1 ; i < nums.size() ; ++i)
		   sum -= i;
		return sum;
    }

	void moveZeroes(vector<int>& nums) {
		if(nums.size() <= 1 )  return ; 
		size_t left(0) , right(0);
		while(right < nums.size())
		{
          if(nums[right] != 0 && right != left)
              nums[left++]  = nums[right] ;
            ++ right;		      
		}
		for(int i =left ; i  <nums.size () ; ++i)
			nums[i] =0;

    }
	struct comp{
		bool operator()(string lval,string rval)const{
			int left = stoi((lval+rval));
			int right = stoi(rval+lval);
			return left>right;
		}
	};
	string largestNumber(vector<int>& nums) {
		string result;
		if(nums.size() == 0) return result;
		vector<string> key;
		for( auto it : nums)
		{
			string val =to_string(it);
			key.push_back(val);
		}
		struct comp c ;
		sort(key.begin(), key.end(), c);
		for( auto it : key)
			result+=it;
		int i(0);
		for(int i = 0 ; i <= result.size()  ; ++i)
			if( result[i] != '0')
				break;

		return result.substr(i,result.size());
		
    }

	int countCacheMiss(int max_cache_size, int *page_requests, int len)
{
    if( max_cache_size <= 0  ) return len;
    if( max_cache_size >= len) return 0;
	deque<int> cache;
	int count(0);
	for(int i = 0 ; i < len ;++i)
	{
		if(cache.size() <max_cache_size)
		{
			cache.push_back(page_requests[i]);
				++count;
				continue;
		}
		deque<int>::iterator it = cache.begin();
		for( it = cache.begin () ; it != cache.end() ; ++it)
			if( *it == page_requests[i])
				 break ;
		if( it == cache.end())
		{
			++count;
			cache.pop_front();
			cache.push_back(page_requests[i]);
		}
	}
	return  count;
}
	bool wordPattern(string pattern, string str) {
       map<char, string> key;
	   map<string,char> unkey;
	   vector<string> word;
	   string tmp;
	   for(auto it : str)
	   {
		   if( it != ' ')
			   tmp+=it;
		   else
		   {
			   word.push_back(tmp);
			   tmp.clear();
		   }
	   }
	   word.push_back(tmp);
	   if(pattern.size () != word.size()) return false;
	   typedef map<char, string>::iterator  iter;
	   for(int i = 0 ; i < pattern.size() ; ++i)
	   {
		   iter it = key.find(pattern[i]);
		   if(it == key.end())
			   key[pattern[i]]=word[i];
		   else
			   if(0 != word[i].compare(key[pattern[i]]))
				  return false;
	   }
	   typedef map<string, char>::iterator itera;
	   for(int i = 0 ; i < word.size(); ++i)
	   {
		   itera it = unkey.find(word[i]);
		   if( it == unkey.end())
			   unkey[word[i]] = pattern[i];
		   else
			   if(it->second  != pattern[i] )
				   return false;
	   }
	   return true;	   
    }
	int divide(int dividend, int divisor) {
		if( 0 == divisor) return INT_MAX;
		long long div(abs(dividend)), diver(abs(divisor));
		int result(0);
		while(div >= diver)
		{
			long long a(diver);
			unsigned int i(0);
			for(i = 1; a<=div ; ++i)
				a <<=1;
			div-=(div<<(i-2));
			result+=(1<<(i-2));
		}
		return (dividend > 0 ? 1:0) ^ (divisor > 0 ? 1:0) ? -result:result; 
    }

};
class mclass{
public:
	mclass(){cout<<"construct"<<endl;}
};
int main() {
	vector<int > ss;
	auto_ptr<Mystring> ptr(new Mystring());
	int a(-101036938),b(-214748364);
	ptr->divide(a,b);
    unsigned int x = 6;
	int y = -20 ;
	cout<<x+y<<endl;
	getchar();

}



