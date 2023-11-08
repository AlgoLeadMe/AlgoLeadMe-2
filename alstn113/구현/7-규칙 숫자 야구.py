answer = list(map(int, list(input())))
guess = list(map(int, list(input())))


def check(answer, guess):
    tmp = []
    strike_cnt = 0
    for i in range(4):
        if answer[i] == guess[i]:
            tmp.append("strike")
            strike_cnt += 1
        elif guess[i] in answer:
            tmp.append("ball")
        else:
            tmp.append("fail")
    return tmp, strike_cnt == 4


attempt_count = 0
while True:
    # 시도 횟수 증가
    attempt_count += 1

    # 판단 후 정답이면 중단
    matched, is_correct = check(answer, guess)
    if is_correct:
        break

    move = []  # ball과 fail의 기존 인덱스 모음
    for i in range(4):
        if matched[i] == "strike":
            continue
        elif matched[i] == "fail":
            while True:
                v = (guess[i] + 1) % 10
                if v in guess:
                    guess[i] = v
                    continue
                guess[i] = v
                break

        # fail, ball이면 위치 변경 대상에 들어감.
        move.append(i)

    if "ball" in matched:
        moved = [move[-1]] + move[:-1]  # 오른쪽으로 한 칸 이동한 인덱스 모음
        tmp = guess[:]
        for i in range(len(moved)):
            guess[move[i]] = tmp[moved[i]]


print(attempt_count)
