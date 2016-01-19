<?php
// Code written in PHP
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N)
// Space Complexity: O(1)

function solution($A) {
    $N = count($A);
    
    $size = 0;
    $candidate = -1;
    $candidateIndex = -1;
    
    for ($i = 0; $i < $N; $i++) {
        if ($size == 0) {
            $candidate = $A[$i];
            $candidateIndex = $i;
            $size++;
        } else {
            if ($candidate != $A[$i]) {
                $size--;
            } else {
                $size++;
            }
        }
    }
    
    if ($size <= 0) {
        return -1;
    }
    
    $counter = 0;
    
    for ($i = 0; $i < $N; $i++) {
        if ($candidate == $A[$i]) {
            $counter++;
        }
    }
     
    if ($counter > ($N/2)) {
        return $candidateIndex;
    }
    
    return -1;
}

?>
