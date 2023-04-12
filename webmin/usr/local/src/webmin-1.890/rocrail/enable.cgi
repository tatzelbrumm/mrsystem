#!/usr/bin/perl

require 'rocrail-lib.pl';

@tabs = ( [ 'enable', $text{'enable_tab'} ],
          [ 'install', $text{'install_tab'} ],
          [ 'restart', $text{'restart_tab'} ] );

ReadParse(*in);
write_rocrail_enable($config{'rocrail_start'}, $in{'server'});
print_rocrail_website($in{'server'});
