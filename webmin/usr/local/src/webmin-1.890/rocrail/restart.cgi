#!/usr/bin/perl

require 'rocrail-lib.pl';

@tabs = ( [ 'enable', $text{'enable_tab'} ],
          [ 'install', $text{'install_tab'} ],
          [ 'restart', $text{'restart_tab'} ] );

ReadParse(*in);
if ($in{'startstop'} == 1)
{
#system("/etc/init.d/rocrail start");
}
elsif ($in{'startstop'} == 2)
{
#system("/etc/init.d/rocrail stop");
}
elsif ($in{'startstop'} == 3)
{
#system("/etc/init.d/rocrail restart");
}

my $enabled = read_rocrail_enable($config{'rocrail_start'});
print_rocrail_website($enabled);
