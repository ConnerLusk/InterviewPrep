package SearchAlgorithms;

public class ArraySearch {
    int array[];

    public ArraySearch(int array[]) {
        this.array = array;
    }

    /**
     * 
     * @param value is the value we are searching for
     * @return is the index of the value or -1 if dne
     */
    public int binarySearch(int value) {
        int left = 0;
        int midpoint;
        int right = array.length - 1;
        while (true) {
            midpoint = ( left + right ) / 2;
            int currentValue = array[midpoint];
            if (currentValue == value) {
                return midpoint;
            }
            if (left > right) return -1;
            if (currentValue < value) {
                left = midpoint + 1;
            }
            else{
                right = midpoint - 1;
            }
        }
    }
}
