class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int C[] = new int[A.length];

        for(int i = 0; i<A.length; i++){
            Set<Integer> setA = new HashSet<>();
            Set<Integer> setB = new HashSet<>();
            int count = 0;

            for(int j = 0; j<=i; j++){
                setA.add(A[j]);
                setB.add(B[j]);
            }

            for(int num:setA){
                if(setB.contains(num)){
                    count++;
                }
            }

            C[i] = count;
        }

        return C;
    }
}