class Solution {
    int findSlash(int pos,string path){
        while(pos<path.size()){
            if(path[pos]=='/') return pos;
            pos++;
        }
        return pos;
    }
public:
    string simplifyPath(string path) {
        stack<string>S;
        int i = 0;
        while(i<path.size()){
            int j = findSlash(i+1,path);
            string str = path.substr(i+1,j-i-1);
            if((int)str.size()>0 && str!="."){ //str.size()==0 means have multiple slashes,such as"///"
                if(str==".."){
                    if(!S.empty())  S.pop();
                }
                else{
                    S.push(str);
                }
            }
            i = j;
        }
        if(S.empty()) return "/";
        string ret="";
        while(!S.empty()){
            ret = "/"+S.top()+ret;
            S.pop();
        }
        return ret;
    }
};
