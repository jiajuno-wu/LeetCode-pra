#include<iostream>
#include<vector>
#include <unordered_map>
#include <cassert>
using namespace std;

// design idea: we now that target = c + nums[i];
// if c exist in the vector, then we have find the solution to this problem
// we use a hash_map to save the information we have seen so far
// and every time we will check the c of nums[i] exist in the map? 
// if not we add that nums[i] to the map else return the i,dict[nums[i]]

// loop invariant: NUMS =  dict + nums
// design role of dict: dict cotain all the value that there is no pair add up to the target


// pre-condition: nums is a int vector , target is an int number
vector<int> twoSum(vector<int>& nums , int target){
    unordered_map<int,int> dict;
    int c = 0;
    for(int i=0;i<nums.size();i++){
        c = target - nums[i];
        if(dict.count(c)>0){
            return vector<int> {i,dict[c]};
        }
        dict[nums[i]] = i;
    }
    assert(false);
}
//post-condition: return the 2 elements index that add up to the target value
 
// GCC give a warning control reaches end of non-void function because return may not encounter 
// at the end of the function.

void print(std::vector <int> const &a) {
   std::cout << "The vector elements are : ";

   for(int i=0; i < a.size(); i++)
   std::cout << a.at(i) << ' ';
}


int main(){
   vector<int> nums = {2 ,7, 11, 15};
   int target = 9;
   print(twoSum(nums,target));

   return 0;
}