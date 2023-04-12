=head1 rocrail-lib.pl

Functions for the Rocrail Server.

=cut

use WebminCore;

init_config();

=head2 read_rocrail_enable()

Read the enable value from rocrail default file.

=cut
sub read_rocrail_enable
{
   my $file_name = $_[0];
   my %info;

   open(FILE, $file_name);
   for (<FILE>)
   {
      next if /^#/;
      next unless $_;
      chomp;
      my($name,$val) = split '=', $_, 2;
      next unless $val;
      $info{$name} = $val;
   }
   close(FILE);
   return $info{'ENABLED'};
}

=head2 write_rocrail_enable()

Write the enable value from rocrail default file.

=cut
sub write_rocrail_enable
{
   my $file_name = $_[0];
   my $enable = $_[1];

   open(FILE, $file_name);
   open_tempfile(TFILE, ">$file_name");
   for (<FILE>)
   {
      if (substr($_, 0, 1) eq '#')
      {
         print TFILE $_
      }
      elsif (not $_)
      {
         print TFILE "$_\n"
      }
      else
      {
         chomp;
         my($name,$val) = split '=', $_, 2;
         if ($name eq 'ENABLED' )
         {
            print TFILE "$name=$enable\n"
         }
         else
         {
            print TFILE "$_\n"
         }
      }
   }
   close(FILE);
   close_tempfile(TFILE);
}

=head2 print_rocrail_website(&site)

prints the code for rocrail webmin site

=cut
sub print_rocrail_website
{
   my $enable = $_[0];

   ui_print_header(undef, $module_info{'desc'}, "", undef, 1, 1);

   print &ui_tabs_start(\@tabs, 'mode', 'enable');

   #generate service list
   print &ui_tabs_start_tab('mode', 'enable');
   print &ui_form_start('enable.cgi', 'post');
   print "$text{'enable_server'}";
   print &ui_yesno_radio('server', $enable);
   print &ui_form_end([ [ undef, "$text{'save'}" ] ]);
   print &ui_tabs_end_tab('mode', 'enable');

   #generate install form
   print &ui_tabs_start_tab('mode', 'install');
   print &ui_form_start('update.cgi', 'form-data');
   print "$text{'install_server'}";
   print &ui_upload('install_file', 100);
   print "<p>";
   print &ui_form_end([ [ undef, "$text{'install'}" ] ]);
   print &ui_tabs_end_tab('mode', 'install');

   #generate start/stop form
   print &ui_tabs_start_tab('mode', 'restart');
   print &ui_form_start('restart.cgi', 'post');
   print &ui_radio('startstop', 1, [ [ 1, 'start' ], [ 2, 'stop' ], [ 3, 'restart' ] ] );
   print "<p>";
   print &ui_form_end([ [ undef, "$text{'go'}" ] ]);
   print &ui_tabs_end_tab('mode', 'restart');

   print &ui_tabs_end();

   ui_print_footer('/', 'rocrail');
}

1;
