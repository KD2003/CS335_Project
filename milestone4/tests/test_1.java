class PalindromeExample{
    public static void main(){
        int r, sum=0, temp;
        int n=454;

        temp = 5+n;
        while(n>0){
            r = n%10;
            sum = (sum*10) + r;
            n = n/10;
        }
        if(temp == sum){
            temp=sum/2;
        }
            // System.out.println("Palindrome Number");
        else
            temp=2*sum;
            // System.out.println("Not a palindrome Number");
    }
}