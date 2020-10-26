import java.util.*;

public class TestCoding {
	public static void main(String[] args) {
		int []arr = {1,1,3,3,0,1,1};
		Solution s = new Solution();
		s.solution(arr);
		return;
	}
}

class Solution {
    public int[] solution(int []arr) {
        int[] answer = {};
        Vector<Integer> vect = new Vector<>(); 
        
        for(int i = 0; i < arr.length; i++) {
        	if(vect.isEmpty()) vect.add(arr[i]);
        	else {
        		if(vect.elementAt(vect.size() - 1) != arr[i]) {
        			vect.add(arr[i]);
        		}
        	}
        }
        
        Integer[] temp = vect.toArray(new Integer[0]);
        answer = Arrays.stream(temp).mapToInt(i->i).toArray();
        
        return answer;
    }
}