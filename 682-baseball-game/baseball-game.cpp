class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> record;
        for(int i = 0; i<operations.size(); i++){
            if(operations[i]=="C"){
                record.pop();
            }else if(operations[i] == "D"){
                record.push(record.top()*2);
            }else if(operations[i] == "+"){
                int top = record.top();
                record.pop();
                int secondTop = record.top();
                record.push(top);
                record.push(top + secondTop);
            }else{
                record.push(stoi(operations[i]));
            }
        }

        int sum = 0;
        while (!record.empty()) {
            sum += record.top();
            record.pop();
        }

        return sum;
    }
};