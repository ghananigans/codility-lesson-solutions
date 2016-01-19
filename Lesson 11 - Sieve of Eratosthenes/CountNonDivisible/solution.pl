# Code written in Perl
# Correctness: 100 %
# Performance: 100 %
# Time Complexity: O(N*log(N))
# Space Complexity: O(N)

sub solution {
    my (@A)=@_;
    my $N = $#A + 1;
    my @occurrences = (0)x($N * 2 + 1);
    my @factors = (0)x($N * 2 + 1);
    
    for (my $i = 0; $i < $N; $i++) {
        @occurrences[@A[$i]]++;
        @factors[@A[$i]]++;
    }
    
    @factors[1] = 0;

    for (my $i = 2; $i * $i <= $N * 2; $i++) {
        @factors[$i * $i] += @occurrences[$i];
        
        for (my $j = $i * ($i + 1); $j <= $N * 2; $j += $i) {
            @factors[$j] += @occurrences[$i] + @occurrences[$j / $i];
        }
        
    }
    
    my @non_divisible_factors = (0)x$N;
    
    for (my $i = 0; $i < $N; $i++) {
        @non_divisible_factors[$i] = $N - @factors[@A[$i]] - @occurrences[1];
    }
    
    return @non_divisible_factors;
}
