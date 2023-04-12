do 'rocrail-lib.pl';

=head2 is_installed(mode)

For mode 1, returns 2 if Rocrail is installed and configured for use by
Webmin, 1 if installed but not configured, or 0 otherwise.
For mode 0, returns 1 if installed, 0 if not

=cut
sub is_installed
{
   my ($mode) = @_;

   if (-e $config{'rocrail_start'})
   {
      return $mode + 1;
   }
   else
   {
      return 0;
   }
}

