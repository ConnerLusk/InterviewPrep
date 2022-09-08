package Arrays;

/**
 * An intro to arrays and their properties
 */
public class ArrayIntro {
    public static void main(String[] args) {
        // Initialization
        int[] intArray = new int[100];
        int[] intArray2 = { 0, 3, 6, 9, 12, 15, 18, 21, 24, 27 };

        // Methods to run on an array
        int length = intArray.length; // finds the length
        
        // Accessing array elements
        int temp = intArray[3]; // Gets the 4th element
        intArray[3] = 72; // Sets the 4th element to 72
        System.out.println(temp);
    }
}
