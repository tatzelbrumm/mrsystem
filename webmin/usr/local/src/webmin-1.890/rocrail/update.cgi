#!/usr/bin/perl

require 'rocrail-lib.pl';

@tabs = ( [ 'enable', $text{'enable_tab'} ],
          [ 'install', $text{'install_tab'} ],
          [ 'restart', $text{'restart_tab'} ] );

ReadParseMime();
my $filename = tempname('install.deb');
open(FILE, ">$filename");
print FILE $in{'install_file'};
close(FILE);
#system("dpkg -i $filename");
unlink_file('$filename');

my $enabled = read_rocrail_enable($config{'rocrail_start'});
print_rocrail_website($enabled);
