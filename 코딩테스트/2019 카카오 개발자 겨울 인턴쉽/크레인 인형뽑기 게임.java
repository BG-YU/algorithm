/*
카카오 2019 개발자 겨울 인턴쉽
크레인 인형뽑기 게임
https://programmers.co.kr/learn/courses/30/lessons/64061
*/
import java.util.Stack;

public class Test {
	public static void main(String[] args) {
		int[][] board = {
			{0,0,0,0,0},
			{0,0,1,0,3},
			{0,2,5,0,1},
			{4,2,4,4,2},
			{3,5,1,3,1}
		};
		int[] moves = {1,5,3,5,1,2,1,4};
		Solution s = new Solution();
		s.solution(board, moves);
		return;
	}
}

class Solution {
	public int findIndex(int x, int[][] board) {
		for(int i = board.length - 1; i >= 0; i--) {
			if(board[i][x] == 0) {
				return i + 1 >= board.length ? -1 : i + 1;
			}
		}
		return 0;
	}
	
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        Stack<Integer> stck = new Stack<>();
        
        for(int i = 0; i < moves.length; i++) {
        	int index = findIndex(moves[i] - 1, board);
        	if(index == -1) continue;
        	
        	stck.add(board[index][moves[i] - 1]);
        	board[index][moves[i] - 1] = 0;
        	
        	if(stck.size() >= 2) {
        		if(stck.get(stck.size() - 1) == stck.get(stck.size() - 2)) {
        			stck.pop();
        			stck.pop();
        			answer += 2;
        		}
        	}
        }
        
        return answer;
    }
}
