# Code written in Ruby
# Correctness: 100 %
# Performance: 100 %
# Time Complexity: O(N*log(log(N)))
# Space Complexity: O(N)

def solution(a)
    _N = a.length
    
    peaks = Array.new()
    
    i = 1
    
    while i < _N -1 do
        if a[i - 1] < a[i] && a[i] > a[i + 1]
            peaks.push(i)
            i += 2
        else
            i += 1
        end
    end
    
    blocks = peaks.length
    
    while blocks > 0
        if _N % blocks != 0
            blocks -= 1
            next
        end
        
        itemsPerBlock = _N / blocks

        blocksDetected = 0
        
        for peak in peaks
            if peak / itemsPerBlock == blocksDetected
                blocksDetected += 1
            end
        end
        
        if blocksDetected == blocks
            return blocks
        else
            blocks -= 1
        end
    end

    return 0
end

