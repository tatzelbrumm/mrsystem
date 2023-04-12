#!/usr/bin/perl

require 'rocrail-lib.pl';

@tabs = ( [ 'enable', $text{'enable_tab'} ],
          [ 'install', $text{'install_tab'} ],
          [ 'restart', $text{'restart_tab'} ] );

my $enabled = read_rocrail_enable($config{'rocrail_start'});
print_rocrail_website($enabled);
