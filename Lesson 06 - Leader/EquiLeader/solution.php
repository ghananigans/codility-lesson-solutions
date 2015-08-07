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

    for ($i = 0; $i < $N; $i++) {
        if ($size == 0) {
            $candidate = $A[$i];
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
        return 0;
    }

    $counter = 0;
    for ($i = 0; $i < $N; $i++) {
        if ($candidate == $A[$i]) {
            $counter++;
        }
    }

    if ($counter <= ($N/2)) {
        return 0;
    }

    $counter2 = 0;
    $equiLeaders = 0;
    for ($i = 0; $i < $N; $i++) {
        if ($A[$i] == $candidate) {
            $counter2++;
        }
        if ((($counter2 * 2) > ($i + 1)) && ((($counter - $counter2) * 2) > ($N - $i - 1))) {
            $equiLeaders++;
        }
    }
    
    return $equiLeaders;
}

?>
