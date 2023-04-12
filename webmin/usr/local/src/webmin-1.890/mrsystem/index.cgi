#!/usr/bin/perl

require 'mrsystem-lib.pl';

my $enabled = read_mrsystem_enable($config{'mrsystem_start'});
print_mrsystem_website($enabled);
