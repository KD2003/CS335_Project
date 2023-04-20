public class PrimeExample{
  public static void main(String args[]){ 
    String ans="";   
      int i,m=0,flag=0;      
      int n=3;//it is the number to be checked    
      m=n/2;      
      if(n==0||n==1){  
        ans="NOT";     
      }else{  
        for(i=2;i<=m;i++){      
          if(n%i==0){      
            ans="YES";     
            flag=1;      
            break;      
          }      
        }      
        System.out.println(ans);
      }//end of else  
  }    
}   