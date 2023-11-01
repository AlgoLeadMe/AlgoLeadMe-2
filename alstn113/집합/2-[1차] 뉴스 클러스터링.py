def make_two_english_letters_list(s: str):
    """
    두 글자씩 잘라서 영문이면 소문자로 변환하고 리스트에 넣어서 반환
    ex) "Ab3cD+" -> ["ab", "cd"]
    """
    result = []
    for i in range(len(s)-1):
        v = s[i:i+2]
        if v.isalpha():
            result.append(v.lower())
    return result


def make_jacard_intersection(s1, s2, intersection):
    """
    교집합의 값들에서 s1, s2 중 작은 값의 개수를 더해서 반환
    """
    result = 0
    for v in intersection:
        result += min(s1.count(v), s2.count(v))
    return result


def make_jacard_union(s1, s2, union):
    """
    합집합의 값들에서 s1, s2 중 큰 값의 개수를 더해서 반환
    """
    result = 0
    for v in union:
        result += max(s1.count(v), s2.count(v))
    return result


def solution(str1, str2):
    """
    두 문자열의 자카드 유사도를 반환

    ex) s1 = "aa1+aa2", s2 = "AAAA12bb"일 경우
    s1 = ["aa", "aa"]
    s2 = ["aa", "aa", "aa", "bb"]

    intersection = set(["aa"])
    union = set(["aa", "bb"])

    jacard_intersection = 2  -> "aa" 최소는 2개
    jacard_union = 4 -> "aa" 최대는 4개, "bb" 최대는 1개

    return 65536 * (2 / 4) = 32768
    """
    BIG_NUM = 65536
    s1 = make_two_english_letters_list(str1)
    s2 = make_two_english_letters_list(str2)

    intersection = set(s1) & set(s2)
    union = set(s1) | set(s2)

    if len(union) == 0:
        return BIG_NUM

    jacard_intersection = make_jacard_intersection(s1, s2, intersection)
    print(jacard_intersection)
    jacard_union = make_jacard_union(s1, s2, union)
    print(jacard_union)

    return int(BIG_NUM * (jacard_intersection / jacard_union))


if __name__ == '__main__':
    print(solution("aa1+aa2", "AAAA12bb"))
