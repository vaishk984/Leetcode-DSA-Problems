class Solution {
public:
    string generateTag(string caption) {
        for(int i = 0; i<caption.size(); i++){
            caption[i] = tolower(caption[i]);
        }

        for(int i = 1; i<caption.size(); i++){     
            if(caption[i] == ' '){
                caption[i+1] = toupper(caption[i+1]);
            }
        }
        
        caption.erase(remove(caption.begin(), caption.end(), ' '), caption.end());
        caption.insert(0, 1, '#');
        string result = caption.substr(0, 100);
        
        return result;
    }
};