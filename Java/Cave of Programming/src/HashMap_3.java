import java.util.HashMap;

public class HashMap_3 {
	public static void main(String[] args){
		HashMap<Integer, String> map = new HashMap<>();
		map.put(5, "Five");
		map.put(8, "Eight");
		map.put(6, "Six");
		map.put(4, "Four");
		map.put(2, "Two");

		System.out.println(map);

		map.put(6, "Hello");
		String text = map.get(4);
		System.out.println(text);
		System.out.println(map);
		for(HashMap.Entry<Integer, String> item : map.entrySet() ){
			System.out.println(item.getKey() + item.getValue() + item.hashCode());
 		}

	}

}
