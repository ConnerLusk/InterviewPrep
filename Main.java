import SearchAlgorithms.ArraySearch;

public class Main {
    public static void main(String[] args) {
        int[] intArray = {1,2,56,67,93,900,8300,12340,1222222};
        ArraySearch searchAlgorithms = new ArraySearch(intArray);
        int response = searchAlgorithms.binarySearch(56);
        System.out.println(response);
    }
}
