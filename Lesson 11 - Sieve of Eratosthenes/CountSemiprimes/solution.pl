# Code written in Perl
# Correctness: 100 %
# Performance: 100 %
# Time Complexity: O(N*log(log(N)) + M)
# Space Complexity: O(N + M)

sub solution {
    my ($N, $P, $Q)=@_; my @P=@$P; my @Q=@$Q;

    my $M = $#P + 1;

    if ($N < 4) {
        return (0)x$M;
    }

    my @sieve = (1)x($N + 1);
    @sieve[0] = @sieve[1] = 0;

    for (my $i = 2; $i * $i <= $N; $i++) {
        if (@sieve[$i]) {
            for (my $k = $i * $i; $k <= $N; $k += $i) {
                @sieve[$k] = 0;
            }
        }
    }

    my @semiprimes_count = (0)x($N + 1);
    
    for (my $i = 2; $i * $i <= $N; $i++) {
        if (@sieve[$i]) {
            for (my $k = $i; $k * $i <= $N; $k++) {
                if (@sieve[$k]) {
                    @semiprimes_count[$k * $i] = 1;
                }
            }
        }
    }
    
    for (my $i = 1; $i <= $N; $i++) {
        @semiprimes_count[$i] = @semiprimes_count[$i] + @semiprimes_count[$i - 1];
    }

    my @semiprimes = (0)x$M;

    for ($m = 0; $m < $M; $m++) {
        @semiprimes[$m] = @semiprimes_count[@Q[$m]] - @semiprimes_count[@P[$m] - 1];
    }

    return @semiprimes;
}

