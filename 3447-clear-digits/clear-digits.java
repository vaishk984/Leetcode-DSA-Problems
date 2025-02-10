class Solution {
    public String clearDigits(String s) {
        StringBuilder stack = new StringBuilder();

        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                // Remove the closest non-digit character to the left
                stack.setLength(stack.length() - 1);
            } else {
                // Append non-digit characters to the stack
                stack.append(c);
            }
        }

        return stack.toString();
    }
}