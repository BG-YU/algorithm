/*
n = 10
[[1,5],[2,7],[4,8],[3,6]]의 2차원 배열이 주어진다.

전구가 n개 만큼 있고
1 => 1번~5번 전구를 킨다. 
2 => 2번~7번 전구를 킨다. 
3 => 4번~8번 전구를 킨다.
4 => 3번~6번 전구를 킨다.
위와 같이 작업을 수행한다.

1과 3의 작업을 수행하고 나머지 전구를 한번씩 키면 4번만에 전구를 다 킬수가 있다.

2차원 배열과 n이 주어질때 최소 몇번만에 전구를 다 킬수가 있는지 구하시오

*/
public class Test {
	public static void main(String[] args) {
		int[][] groups = {{1, 50},{1,100},{51, 100 }}; // 100 1
//		int[][] groups = {{1,5},{2,7},{4,8},{3,6}}; // 10 4
//		int[][] groups = {{6,7},{1,4},{2,4}}; // 7 3
		Solution s = new Solution();
		s.solution(100, groups);
		return;
	}
}

class Solution {
	int used[];
	int map[];
	int minn = 999;
	int off = 0;
	
    public int solution(int n, int[][] groups) {
        int answer = 0;
        int len = groups.length;
        used = new int[groups.length];
        map = new int[n];
        off = n;
        
        dfs(0,1,0,len, groups);
        answer = minn;
        return answer;
    }
    
    public void dfs(int lv, int cnt, int sum, int limit, int[][] groups) {
    	if(lv == limit) return;
    	for(int i = 0; i < groups.length; i++) {
    		if(used[i] == 1) continue;
    		used[i] = 1;
    		for(int k = groups[i][0] - 1; k <= groups[i][1] - 1; k++) {
    			if(map[k] == 0) off--;
    			map[k] = 1;
    		}
    		if(minn > cnt + off) minn = cnt + off;
    		dfs(lv + 1, cnt + 1, cnt + off, limit, groups);
    		used[i] = 0;
    		for(int k = groups[i][0] - 1; k <= groups[i][1] - 1; k++) {
    			if(map[k] == 1) off++;
    			map[k] = 0;
    		}
    	}
    }
}