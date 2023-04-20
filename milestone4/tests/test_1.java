class PalindromeExample{
    public static void main(){
        int r, sum=0, temp;
        String ans="";
        int n=454;

        temp = 5+n;
        while(n>0){
            r = n%10;
            sum = (sum*10) + r;
            n = n/10;
        }
        if(temp == sum)
            ans="Palindrome Number";
        else
            ans="Not a palindrome Number";
        System.out.println(ans);
    }
}