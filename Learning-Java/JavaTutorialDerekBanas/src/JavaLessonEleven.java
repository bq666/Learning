import java.util.ArrayList;
import java.util.Iterator;
import java.util.Arrays;

public class JavaLessonEleven {
	public static void main(String[] args){
		ArrayList arrayListOne = new ArrayList();
		ArrayList<String> names = new ArrayList<>();

		arrayListOne.add(1);
		arrayListOne.add(10);
		arrayListOne.add(100);
		arrayListOne.add(1000);
		arrayListOne.add(10000);
		arrayListOne.add("asdf");


		names.add("Wojtek");
		names.add("Mohamad");
		names.add("Mimek");
		names.add(2, "Janek");

		for(int i = 0; i < names.size(); i++){
			System.out.println(names.get(i));
		}

		names.set(0, "John Adams");
		names.remove(3);

		for(String item : names){
			System.out.println(item);
		}

		for (Object anArrayListOne : arrayListOne) {
			System.out.println(anArrayListOne);
		}

		System.out.println(names);


		int[] numbers = new int[10];
		numbers[0] = 10;

		Iterator indivItems = names.iterator();
		while (indivItems.hasNext()){
			System.out.println(indivItems.next());
		}
		System.out.println("---------------------");

		ArrayList nameCopy = new ArrayList();
		ArrayList nameBackup = new ArrayList();

		nameCopy.addAll(names);
		String paulYoung = "Paul Young";
		names.add(paulYoung);

		System.out.println(nameCopy);
		System.out.println(names);

		if(names.contains("Paul Young")){
			System.out.println("Jest");
		}

		if(nameCopy.containsAll(names)){
			System.out.println("Everyting in nameCopy is in names");
		}

//		names.clear();
		if(names.isEmpty()){
			System.out.println("is empty");
		}
		System.out.println(nameCopy);
		System.out.println(names);

		Object[] moreNames = new Object[4];
		moreNames = names.toArray();

		System.out.println(Arrays.toString(moreNames));




//				ArrayList arrayListOne = new ArrayList();
////		arrayListOne = new ArrayList();
////		ArrayList numbers = new ArrayList();
//		ArrayList<String> names = new ArrayList<>();
//		arrayListOne.add(10);
//
//		for(int item : arrayListOne){
//
//		}

	}
}
