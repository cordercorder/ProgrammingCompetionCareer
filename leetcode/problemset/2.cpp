#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define deb(args...) std::cerr << "DEBUG------" << '\n'; std::cerr << #args << "------>"; err(args)

void err(){
    std::cerr << '\n' << "END OF DEBUG" << '\n' << '\n';
}

template<typename T, typename... Args>
void err(T a, Args... args){
    std::cerr << a << ", ";
    err(args...);
}

template<template<typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args){
    for(auto x: a){
        std::cerr << x << ", ";
    }
    err(args...);
}
//header


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p_l1 = l1;
        ListNode* p_l2 = l2;
        ListNode* result = new ListNode;
        ListNode* p_result = result;
        ListNode* last = NULL;

        int value = 0;
        int carry_bit = 0;
        while( p_l1 != NULL && p_l2 != NULL){
            value = p_l1 -> val + p_l2 -> val + carry_bit;

            p_result -> val = value % 10;
            last = p_result;
            p_result -> next = new ListNode;
            p_result = p_result -> next;

            carry_bit = value / 10;

            p_l1 = p_l1 -> next;
            p_l2 = p_l2 -> next;
        }

        while(p_l1 != NULL){
            value = p_l1 -> val + carry_bit;
            p_result -> val = value % 10;
            last = p_result;
            p_result -> next = new ListNode;
            p_result = p_result -> next;
            carry_bit = value / 10;
            p_l1 = p_l1 -> next;
        }

        while(p_l2 != NULL){
            value = p_l2 -> val + carry_bit;
            p_result -> val = value % 10;
            last = p_result;
            p_result -> next = new ListNode;
            p_result = p_result -> next;
            carry_bit = value / 10;
            p_l2 = p_l2 -> next;
        }

        if(carry_bit > 0){
            p_result -> val = carry_bit;
            last = p_result;
            p_result -> next = new ListNode;
            p_result = p_result -> next;
        }

        last -> next = NULL;

        return result;
    }
};



int main(void){

    
    

    return 0;
}