import java.io.ObjectInputFilter.Status;
import java.util.Scanner;

public class Selection_S {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the length of the array:");
        int l = sc.nextInt();// Length of array
        int i, j, min = 0, t = 0;// loop controller
        int arr[] = new int[l];// new array
        for (i = 0; i < l; i++)// For user defined elements
        {
            System.out.print("Enter array element:");
            arr[i] = sc.nextInt();// Length of array
        }
        // selection sorting the array
        for (i = 0; i < l - 1; i++) {
            // Find the min
            min = i;// for comparing
            for (j = i + 1; j < l; j++) {
                if (arr[j] < arr[min])// ascending order
                    min = j;
            }
            // swapping done
            t = arr[min];
            arr[min] = arr[i];
            arr[i] = t;
        }
        System.out.println("The resultant sorted array: ");
        for (i = 0; i < l; i++) // Displaying
        {
            System.out.print(arr[i] + "    ");
        }
        sc.close();// scanner closes

    }

}
