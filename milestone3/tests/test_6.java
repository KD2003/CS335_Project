public class Example1 {
	int x;
    double y;

    Example1(int z, double y) {
    	this.x = z;
        this.y = y;
    }

    public static void main(String[] args /*so that we can compile with javac*/) {
    		Example1 a = new Example1(2,3.14);
        System.out.println(a.x);
        System.out.println(a.y);
    }
}