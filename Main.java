import SearchAlgorithms.BinarySearch;

public class Main {
    public static void main(String[] args) {
        int[] intArray = {1,2,56,67,93,900,8300,12340,1222222};
        BinarySearch binarySearch = new BinarySearch(intArray);
        int response = binarySearch.binarySearch(56);
        System.out.println(response);
    }
}
