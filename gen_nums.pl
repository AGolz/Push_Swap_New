#!/usr/bin/env perl

use strict;
use warnings;
use diagnostics;

my ($num_count, $min, $max) = @ARGV;
my @num_list = ();

if (not defined $num_count)
{
    die "Usage: ./gen_nums.pl num_count [min] [max]\n";
}
elsif ($num_count < 0)
{
    die "Error: num_count can't be negative\n";
}

$min = 0 if (not defined $min);

if (not defined $max)
{
    $max = $min + $num_count;
}
elsif ($num_count >= $max - $min + 1)
{
    die "Error: range too small\n";
}

for (my $i = 0; $i < $num_count; )
{
    my $num = int(rand($max - $min + 1) + $min);
    if (!(grep { $_ == $num } @num_list))
    {
        push @num_list, $num;
        $i++;
    }
}
print "@num_list\n";