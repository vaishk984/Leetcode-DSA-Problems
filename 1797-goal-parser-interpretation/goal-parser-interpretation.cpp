class Solution {
public:
    string interpret(string command) {
        string newStr = "";
        for(int i = 0; i<command.size(); i++){
            if(command[i]=='G'){
                newStr+="G";
            }else if(command[i]=='(' && command[i+1]==')'){
                newStr+="o";
            }else if(command[i]=='(' && command[i+1] =='a' && command[i+2] == 'l' && command[i+3] == ')'){
                newStr+="al";
            }
        }

        return newStr;
    }
};