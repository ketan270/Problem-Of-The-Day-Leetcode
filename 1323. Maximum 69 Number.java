class Solution {
    public int maximum69Number (int num) {
        StringBuilder str = new StringBuilder(Integer.toString(num));
        for(int i=0;i<str.length();i++){
            if (str.charAt(i) != '9'){
                str.setCharAt(i, '9');
                break;
            }
        }
        return Integer.parseInt(str.toString());
    }
}
