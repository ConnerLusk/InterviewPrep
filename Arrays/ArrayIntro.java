package Arrays;

/**
 * An intro to arrays and their properties
 */
public class ArrayIntro {
    public static void main(String[] args) {
        // Initialization of an int array
        int[] intArray = new int[100];
        int[] intArray2 = { 0, 3, 6, 9, 12, 15, 18, 21, 24, 27 };
        // Finding the length of an array
        int arrayLength = intArray.length;
        // Accessing array elements
        int temp = intArray[3]; // Gets the 4th element
        intArray[3] = 72; // Sets the 4th element to 72
        System.out.println(temp);
    }
}
