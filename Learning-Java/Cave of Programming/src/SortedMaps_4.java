import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.TreeMap;
import java.util.Map;


public class SortedMaps_4 {
	public static void main(String[] args) {
		Map<Integer, String> hashMap = new HashMap<>();
		Map<Integer, String> linkedHashMap = new LinkedHashMap<>();
		Map<Integer, String> treeMap = new TreeMap<>();


		System.out.println("hashMap <-----------");
		testMap(hashMap);
		System.out.println("linkedHashMap <--------");
		testMap(linkedHashMap);
		System.out.println("treeMap <---------");
		testMap(treeMap);

	}

	public static void testMap(Map<Integer, String> map){
		map.put(9, "fox");
		map.put(4, "cat");
		map.put(8, "dog");
		map.put(1, "giraffe");
		map.put(0, "swan");
		map.put(15, "bear");
		map.put(6, "snake");

		for (Integer key : map.keySet()) {
			System.out.println(key + ": " + map.get(key));
		}

	}
}
