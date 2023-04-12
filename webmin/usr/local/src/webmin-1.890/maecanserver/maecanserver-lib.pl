=head1 maecanserver-lib.pl

Functions for the maecanserver.

=cut

use WebminCore;

init_config();

=head2 read_maecanserver_enable()

Read the enable value from maecanserver default file.

=cut
sub read_maecanserver_enable
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

=head2 write_maecanserver_enable()

Write the enable value from maecanserver default file.

=cut
sub write_maecanserver_enable
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

=head2 print_maecanserver_website(&site)

prints the code for maecanserver webmin site

=cut
sub print_maecanserver_website
{
   my $enable = $_[0];

   ui_print_header(undef, $module_info{'desc'}, "", undef, 1, 1);
   print &ui_form_start('enable.cgi', 'post');
   print "$text{'enable_server'}";
   print &ui_yesno_radio('server', $enable);
   print &ui_form_end([ [ undef, "$text{'save'}" ] ]);
   ui_print_footer('/', 'mrsystem');
}

1;
