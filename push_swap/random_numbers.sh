#!/bin/bash

# 난수 생성할 범위
MIN=1
MAX=100
COUNT=10

# 난수 생성 함수
generate_random_number() {
    echo $((MIN + RANDOM % (MAX - MIN + 1)))
}

# 중복 체크 함수
is_duplicate() {
    local number=$1
    for n in "${numbers[@]}"; do
        if [ "$n" -eq "$number" ]; then
            return 0  # 중복이면 0 반환
        fi
    done
    return 1  # 중복이 아니면 1 반환
}

# 중복이 없는 난수 생성
numbers=()
while [ ${#numbers[@]} -lt $COUNT ]; do
    number=$(generate_random_number)
    if ! is_duplicate "$number"; then
        numbers+=("$number")
    fi
done

# 생성된 난수 출력
echo "생성된 난수: ${numbers[@]}"