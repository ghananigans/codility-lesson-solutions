# Code written in ruby
# Correctness: 100 %
# Performance: 100 %
# Time Complexity: O(sqrt(n))
# Space Complexity: O(1)

def solution(n)
    i = Math.sqrt(n).floor
    
    while i > 0 do
        k = n / i
        
        if k * i == n
            return 2 * (k + i)
        end
        
        i -= 1
    end
end
