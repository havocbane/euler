#!/usr/bin/env perl

use warnings;
use strict;
use Readonly;

#################
# Project Euler #
# Problem #4    #
##############################################################################
# A palindromic number reads the same both ways. The largest palindrome made #
# from the product of two 2-digit numbers is 9009 = 91 × 99.                 #
#                                                                            #
# Find the largest palindrome made from the product of two 3-digit numbers.  #
##############################################################################

Readonly::Scalar my $numDigits => 3;
Readonly::Scalar my $debug => 0;

# Initialize an array of all numbers with $numDigits number of digits.
my @numbers;
for (10 ** ($numDigits - 1) .. 10 ** $numDigits - 1) {
    push(@numbers, $_);
}

# Debugging - Print out all numbers in array.
if ($debug) {
    foreach (@numbers) {
        print $_ . ' ';
    }
    print "\b\n\n";
}

# Multiply each number by itself and every one larger than it, keeping track of
# only the palindromes.
# This assumes that @numbers is sorted into ascending order.
my %palindromes;
my $c = 0;
foreach my $this (@numbers) {
	for (my $i = $c; $i <= $#numbers; ++$i) {
		if (&isPalindrome(split(//, $this * $numbers[$i]))) {
			$palindromes{$this * $numbers[$i]} = 1;
		}
	}
	++$c;
}

# Debugging - Print out all palindromes found.
if ($debug) {
	foreach (keys(%palindromes)) {
		print $_ . ' ';
	}
	print "\b\n\n";
}

# Output the answer.
print "\nLargest Palindrome = ", &max(keys(%palindromes)), "\n";
exit;

# Determine if the input is a palindrome.
# Returns 1 if it is a palindrome, undef if not.
sub isPalindrome {
	my @reverse = reverse(@_);
	join('', @_) eq join('', @reverse)
}

# Given a list of numbers, return the largest.
# Returns undef on an empty list.
sub max {
	my $maximum = shift;
	foreach (@_) {
		$maximum = $_ if $maximum < $_;
	}
	$maximum
}
