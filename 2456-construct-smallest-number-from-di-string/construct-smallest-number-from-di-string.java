class Solution {
    public String smallestNumber(String pattern) {
        StringBuilder result = new StringBuilder();
        java.util.Stack<Integer> stack = new java.util.Stack<>();
        int num = 1; // Digits from 1 to n+1

        for (int i = 0; i <= pattern.length(); i++) {
            stack.push(num++);
            if (i == pattern.length() || pattern.charAt(i) == 'I') {
                while (!stack.isEmpty()) {
                    result.append(stack.pop());
                }
            }
        }
        return result.toString();
    }
}