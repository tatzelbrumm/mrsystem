#!/usr/bin/perl

require 'maecanserver-lib.pl';

ReadParse(*in);
write_maecanserver_enable($config{'maecanserver_start'}, $in{'server'});
print_maecanserver_website($in{'server'});
