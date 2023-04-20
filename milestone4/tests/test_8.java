//Java Program to demonstrate the use of Nested If Statement.    
public class JavaNestedIfExample2 {      
public static void main(String[] args) {      
	//Creating two variables for age and weight    
	int age=25;    
	String ans="";
	int weight=48;      
	//applying condition on age and weight    
	if(age>=18){      
		if(weight>50){    
			ans="You are eligible to donate blood";    
		} 
		else{  
			ans="You are not eligible to donate blood";    
		}  
	} 
	else{  
		ans="Age must be greater than 18";  
	}  
	System.out.println(ans);
}  
}  