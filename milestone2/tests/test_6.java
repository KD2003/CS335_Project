import java.io.*;
class GFG {
	public static void main(String[] args)
	{

		int arr[][][] = new int[2][2][2];


		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				for (int z = 0; z < 2; z++)
					arr[i][j][z]=i+j+z;
	}
}
