class bubbleSort{
	
	public static void main (String []args){
	int tempVariable;
	int []Array= {9,8,7,6,5};
	for (int j=0; j<Array.length; j++){
		for (int i = j+1; i<Array.length; i++){
			//compare adjacent values
			if (Array[i]<(Array[j])){
			tempVariable = Array[j];
			Array[j] = Array[i];
			Array [i] = tempVariable;

			}
		}
		// print the array using println
		System.out.println(Array[j]);
	}

	}
}
