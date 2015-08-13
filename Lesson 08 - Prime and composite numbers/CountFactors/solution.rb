# Code written in Ruby
# Correctness: 100 %
# Performance: 100 %
# Time Complexity: O(sqrt(n))
# Space Complexity: O(1)

def solution(n)
    i = Math.sqrt(n).floor
    factors = 0

    while i > 0 do
        k = n / i

        if k * i == n
            factors += k == i ? 1 : 2
        end

        i -= 1
    end

    return factors
end



