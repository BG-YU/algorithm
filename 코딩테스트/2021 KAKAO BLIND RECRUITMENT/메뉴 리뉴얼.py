# https://programmers.co.kr/learn/courses/30/lessons/72411

course_map = {}

def dfs(lim, lv, orders, sett, idx):
    if lim == lv:
        temp = ''.join(sorted(sett))
        if temp in course_map:
            course_map[temp] += 1
        else:
            course_map[temp] = 1
        
        return
    
    for i in range(idx, len(orders)):
        sett.append(orders[i]) 
        dfs(lim, lv+1, orders, sett, i+1)
        del sett[len(sett)-1]


def solution(orders, course):
    answer = []
    global course_map

    for i in orders:
        for lv in course:
            dfs(lv, 0, i, [], 0)
    
    temp = [k for k,v in course_map.items() if v == 1]
    
    for i in temp:
        del course_map[i]

    course_map = sorted(course_map.items(), key=lambda x:(len(x[0]), -x[1], x[0]))

    for i in course:
        maxx = max(course_map, key=lambda x:(len(x[0])==i, x[1]))[1]
        for k in course_map:
            if k[1] == maxx and len(k[0]) == i:
                answer.append(k[0])
    
    answer = sorted(answer)

    return answer