/*
 https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
 http://my.oschina.net/Tsybius2014/blog/497645?fromerr=58jwp9GH
 */
class Solution {
public:
    int addDigits(int num) { return 1 + (num - 1) % 9; }
};