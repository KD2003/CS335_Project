public class Example1 {
	int x;
    int y;

    Example1(int z, int b) {
    	this.x = z;
        this.y = b;
    }

    public static void main(String[] args /*so that we can compile with javac*/) {
    	Example1 a = new Example1(2,3);
        System.out.println(a.x);
        System.out.println(a.y);
    }
}