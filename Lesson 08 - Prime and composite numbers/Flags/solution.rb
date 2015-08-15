# Code written in Ruby
# Correctness: 100 %
# Performance: 100 %
# Time Complexity: O(N)
# Space Complexity: O(N)

def solution(a)
    _N = a.length

    if _N < 3
        return 0
    end
    
    next_peak = [-1] * _N
    
    i = _N - 2
    
    while i > 0 do
        if a[i - 1] < a[i] && a[i] > a[i + 1]
            next_peak[i - 1] = i
        else
            next_peak[i - 1] = next_peak[i]
        end

        i -= 1
    end
    
    if next_peak[0] == -1
        return 0
    end
    
    flags = 0
    
    max_flags = Math.sqrt(_N).ceil
    
    k = 1
    
    while k <= max_flags do
        last_flagged_peak_index = next_peak[0]
        peak_index = next_peak[0]
        
        flags_detected = 1
        
        while peak_index < _N && flags_detected < k do
            next_peak_index = next_peak[peak_index]
            
            if next_peak_index == -1
                break
            end
            
            if next_peak_index - last_flagged_peak_index >= k
                flags_detected += 1
                last_flagged_peak_index = next_peak_index
            end
            
            peak_index = next_peak_index
        end
        
        if flags_detected > flags 
            flags = flags_detected
        end
        
        k += 1
    end
    
    return flags
end

