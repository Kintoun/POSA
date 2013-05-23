package WB30WorkspaceCreator;

# ************************************************************
# Description   : Wind River Workbench 3.0 generator
# Author        : Adam Mitz (Object Computing, Inc.)
# Create Date   : 07/21/2010
# $Id: WB30WorkspaceCreator.pm 2035 2011-10-06 15:05:21Z johnnyw $
# ************************************************************

# ************************************************************
# Pragmas
# ************************************************************

use strict;

use WB26WorkspaceCreator;
use WB30ProjectCreator;

use vars qw(@ISA);
@ISA = qw(WB26WorkspaceCreator);

# ************************************************************
# Subroutine Section
# ************************************************************

sub get_id_for_comment {
  return '$Id: WB30WorkspaceCreator.pm 2035 2011-10-06 15:05:21Z johnnyw $';
}

sub get_project_prefix {
  return 'wb_';
}

sub get_additional_output {
  ## Create the accompanying list file.  It always goes in the same
  ## directory as the first workspace output file.  See
  ## WorkspaceCreator.pm for a description of the array elements.
  return [[undef, 'wb30projects.lst', \&WB26WorkspaceCreator::list_file_body]];
}


1;
