class Solution {
    public int numberOfSubstrings(String s) {
        int[] abc = new int[3];
        int start =0,ans =0;
        for(int end =0;end<s.length();end++){
            abc[s.charAt(end)-'a']++;
                while(abc[0]>=1 && abc[1]>=1 && abc[2]>=1){
                    ans +=(s.length() - end);
                    abc[s.charAt(start++) - 'a']--;
                }
        }
        return ans;
    }
}
