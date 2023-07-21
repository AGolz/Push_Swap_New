
use strict;
use warnings;
use diagnostics;

my ($stacksize, $min, $max) = @ARGV;
my @stack = ();

if (not defined $stacksize)
{
	die "Usage: ./genstack.pl stacksize [min] [max]\n";
}
elsif ($stacksize < 0)
{
	die "Error: stacksize can't be negative\n";
}

if (not defined $min)
{
	$min = 0;
}
if (not defined $max)
{
	$max = $min + $stacksize;
}
elsif ($stacksize >= $max - $min + 1)
{
	die "Error: range too small\n";
}


for (my $num = 0; $num < $stacksize; )
{
	my $n = int(srand() % ($max - $min) + $min);
	if (!(grep { $_ eq $n } @stack))
	{
		push @stack, $n;
		$num++;
	}
}
print "@stack\n";
