#!/usr/bin/perl

require 'mrsystem-lib.pl';

ReadParse(*in);
write_mrsystem_enable($config{'mrsystem_start'}, $in{'server'});
print_mrsystem_website($in{'server'});
