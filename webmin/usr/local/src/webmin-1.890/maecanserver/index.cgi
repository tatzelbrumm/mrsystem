#!/usr/bin/perl

require 'maecanserver-lib.pl';

my $enabled = read_maecanserver_enable($config{'maecanserver_start'});
print_maecanserver_website($in{'server'});
