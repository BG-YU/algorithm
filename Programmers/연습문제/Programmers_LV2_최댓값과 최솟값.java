/*
[문제 설명]
문자열 s에는 공백으로 구분된 숫자들이 저장되어 있습니다. str에 나타나는 숫자 중 최소값과 최대값을 찾아 이를 (최소값) (최대값)형태의 문자열을 반환하는 함수, solution을 완성하세요.
예를들어 s가 1 2 3 4라면 1 4를 리턴하고, -1 -2 -3 -4라면 -4 -1을 리턴하면 됩니다.

[제한 조건]
s에는 둘 이상의 정수가 공백으로 구분되어 있습니다.

[입출력 예]
s              return
1 2 3 4	       1 4
-1 -2 -3 -4	  -4 -1
-1 -1         -1 -1	
*/
import java.util.Arrays;
import java.util.Comparator;

public class TestCoding {
	public static void main(String[] args) {
		Solution s = new Solution();
		s.solution("-1 -2 -3 -4");
		return;
	}
}

class Solution {
    public String solution(String s) {
        String answer = "";
        String[] arr = s.split(" ");
        
        Arrays.sort(arr, new Comparator<String>() {
			@Override
			public int compare(String a, String b) {
				int ia = Integer.parseInt(a);
				int ib = Integer.parseInt(b);
				if(ia > ib) return 1;
				if(ia < ib) return -1;
				return 0;
			}
        });

        answer += arr[0];
        answer += " ";
        answer += arr[arr.length - 1];
        return answer;
    }
}