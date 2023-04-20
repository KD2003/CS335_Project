public class Example1 {
	int x;
    int y;

    Example1(int z, int b) {//Constructor Being Called
        z-=b+x+y;
    }

    public static void main(String[] args /*so that we can compile with javac*/) {
    	Example1 a = new Example1(2,3);  
    }
}