public class TypeCoercion {
    public static void main(String[] args) {
        int intVar = 100;
        long longVar = intVar;
        float floatVar = longVar;
        double doubleVar = longVar;

        double dVar = 3;
        long lVar = (long) dVar;
        int iVar = (int) dVar;

        System.out.println((short) 3);

        double exp = intVar + longVar + dVar * floatVar + lVar + doubleVar + iVar;
        System.out.println(exp);
    }
}
